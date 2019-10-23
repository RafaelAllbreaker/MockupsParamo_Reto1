/**********************************************************************************
* Blueprint Reality Inc. CONFIDENTIAL
* 2019 Blueprint Reality Inc.
* All Rights Reserved.
*
* NOTICE:  All information contained herein is, and remains, the property of
* Blueprint Reality Inc. and its suppliers, if any.  The intellectual and
* technical concepts contained herein are proprietary to Blueprint Reality Inc.
* and its suppliers and may be covered by Patents, pending patents, and are
* protected by trade secret or copyright law.
*
* Dissemination of this information or reproduction of this material is strictly
* forbidden unless prior written permission is obtained from Blueprint Reality Inc.
***********************************************************************************/

#pragma once

#include "Utility/ThriftUtil.hpp"

#include "Thrift/server/TSimpleServer.h"
#include "Thrift/server/TThreadedServer.h"
#include "Thrift/transport/TBufferTransports.h"
#include "Thrift/transport/TPipeServer.h"
#include  "Thrift/windows/OverlappedSubmissionThread.h"

#include "Runtime/Engine/Public/EngineGlobals.h"
#include "Async/Async.h"
#include "HAL/Runnable.h"
#include "HAL/RunnableThread.h"

using namespace apache::thrift::protocol;
using namespace apache::thrift::server;
using namespace apache::thrift::transport;

class MIXCAST_API TUnrealThriftServerEventHandler : public TServerEventHandler
{
public:
	bool shouldKill;
	virtual void processContext(void* serverContext, stdcxx::shared_ptr<TTransport> transport) {
		if (shouldKill)
		{
			throw TTransportException(TTransportException::INTERRUPTED, "TPipeServer: server interrupted");
		}
	};
};

template<typename ProcessorType, typename HandlerType>
class MIXCAST_API TThriftServer : public FRunnable
{
public:
	TThriftServer(const std::string& PipeName, std::shared_ptr<HandlerType> Handler)
		: Server(
			std::make_shared<ProcessorType>(Handler),
			std::make_shared<TPipeServer>(ThriftUtil::GetFullPipeName(PipeName)),
			std::make_shared<TBufferedTransportFactory>(),
			std::make_shared<TBinaryProtocolFactory>()),
		EventHandler(std::make_shared<TUnrealThriftServerEventHandler>())
	{
		EventHandler->shouldKill = false;
		Server.setServerEventHandler(EventHandler);
		Thread = FRunnableThread::Create(this, TEXT("TThriftServer"), 0, TPri_BelowNormal);
	}

	~TThriftServer()
	{
		delete Thread;
		Thread = nullptr;
	}

	// FRunnable overrides:

	uint32 Run() override
	{
		Server.serve();
		return 0;
	}

	void Stop() override
	{
		EventHandler->shouldKill = true;
		Server.stop();
	}

private:
	FRunnableThread* Thread;

	TSimpleServer Server;
	std::shared_ptr<TUnrealThriftServerEventHandler> EventHandler;
};
