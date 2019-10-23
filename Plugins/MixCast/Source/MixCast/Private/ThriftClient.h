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

#include "Thrift/protocol/TBinaryProtocol.h"
#include "Thrift/transport/TPipe.h"
#include "Thrift/transport/TTransportUtils.h"

#include "CoreMinimal.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

template<typename ServiceType>
class MIXCAST_API TThriftClient
{
public:
	explicit TThriftClient(const std::string& PipeName)
		: Transport(std::make_shared<TPipe>(ThriftUtil::GetFullPipeName(PipeName)))
	{
		const auto protocol = std::make_shared<TBinaryProtocol>(Transport);
		ServiceClient = new ServiceType(protocol);
	}

	~TThriftClient()
	{
		Transport->close();

		delete ServiceClient;
		ServiceClient = nullptr;
	}

	void EnsureTransportIsOpen() const
	{
		if (Transport->isOpen())
		{
			return;
		}

		Transport->open();
	}

	void EnsureTransportIsClosed() const
	{
		if (!Transport->isOpen())
		{
			return;
		}

		Transport->close();
	}

	// Runs a Thrift function after ensuring that the underlying transport is open.
	template<typename ReturnType>
	ReturnType Run(TFunction<ReturnType(ServiceType&)>&& Action) const
	{
		EnsureTransportIsOpen();
		return Action(*ServiceClient);
	}

private:
	ServiceType* ServiceClient;
	std::shared_ptr<TTransport> Transport;
};
