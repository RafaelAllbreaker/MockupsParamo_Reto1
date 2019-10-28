/**
 * Autogenerated by Thrift Compiler (Shiyao Modified base on 0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef OpenVRDriver_Service_H
#define OpenVRDriver_Service_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "Service_Driver_types.h"

namespace mixcast { namespace thrift {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class OpenVRDriver_ServiceIf {
 public:
  virtual ~OpenVRDriver_ServiceIf() {}
  virtual void validate_ping() = 0;
  virtual void validate_function_list(std::vector<std::string> & _return) = 0;
  virtual void DriverPoseRequest( ::mixcast::thrift::Pose& _return) = 0;
};

class OpenVRDriver_ServiceIfFactory {
 public:
  typedef OpenVRDriver_ServiceIf Handler;

  virtual ~OpenVRDriver_ServiceIfFactory() {}

  virtual OpenVRDriver_ServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(OpenVRDriver_ServiceIf* /* handler */) = 0;
};

class OpenVRDriver_ServiceIfSingletonFactory : virtual public OpenVRDriver_ServiceIfFactory {
 public:
  OpenVRDriver_ServiceIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<OpenVRDriver_ServiceIf>& iface) : iface_(iface) {}
  virtual ~OpenVRDriver_ServiceIfSingletonFactory() {}

  virtual OpenVRDriver_ServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(OpenVRDriver_ServiceIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<OpenVRDriver_ServiceIf> iface_;
};

class OpenVRDriver_ServiceNull : virtual public OpenVRDriver_ServiceIf {
 public:
  virtual ~OpenVRDriver_ServiceNull() {}
  void validate_ping() {
    return;
  }
  void validate_function_list(std::vector<std::string> & /* _return */) {
    return;
  }
  void DriverPoseRequest( ::mixcast::thrift::Pose& /* _return */) {
    return;
  }
};


class OpenVRDriver_Service_validate_ping_args {
 public:

  OpenVRDriver_Service_validate_ping_args(const OpenVRDriver_Service_validate_ping_args&);
  OpenVRDriver_Service_validate_ping_args& operator=(const OpenVRDriver_Service_validate_ping_args&);
  OpenVRDriver_Service_validate_ping_args() {
  }

  virtual ~OpenVRDriver_Service_validate_ping_args() throw();

  bool operator == (const OpenVRDriver_Service_validate_ping_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const OpenVRDriver_Service_validate_ping_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OpenVRDriver_Service_validate_ping_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class OpenVRDriver_Service_validate_ping_pargs {
 public:


  virtual ~OpenVRDriver_Service_validate_ping_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class OpenVRDriver_Service_validate_ping_result {
 public:

  OpenVRDriver_Service_validate_ping_result(const OpenVRDriver_Service_validate_ping_result&);
  OpenVRDriver_Service_validate_ping_result& operator=(const OpenVRDriver_Service_validate_ping_result&);
  OpenVRDriver_Service_validate_ping_result() {
  }

  virtual ~OpenVRDriver_Service_validate_ping_result() throw();

  bool operator == (const OpenVRDriver_Service_validate_ping_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const OpenVRDriver_Service_validate_ping_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OpenVRDriver_Service_validate_ping_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class OpenVRDriver_Service_validate_ping_presult {
 public:


  virtual ~OpenVRDriver_Service_validate_ping_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class OpenVRDriver_Service_validate_function_list_args {
 public:

  OpenVRDriver_Service_validate_function_list_args(const OpenVRDriver_Service_validate_function_list_args&);
  OpenVRDriver_Service_validate_function_list_args& operator=(const OpenVRDriver_Service_validate_function_list_args&);
  OpenVRDriver_Service_validate_function_list_args() {
  }

  virtual ~OpenVRDriver_Service_validate_function_list_args() throw();

  bool operator == (const OpenVRDriver_Service_validate_function_list_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const OpenVRDriver_Service_validate_function_list_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OpenVRDriver_Service_validate_function_list_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class OpenVRDriver_Service_validate_function_list_pargs {
 public:


  virtual ~OpenVRDriver_Service_validate_function_list_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _OpenVRDriver_Service_validate_function_list_result__isset {
  _OpenVRDriver_Service_validate_function_list_result__isset() : success(false) {}
  bool success :1;
} _OpenVRDriver_Service_validate_function_list_result__isset;

class OpenVRDriver_Service_validate_function_list_result {
 public:

  OpenVRDriver_Service_validate_function_list_result(const OpenVRDriver_Service_validate_function_list_result&);
  OpenVRDriver_Service_validate_function_list_result& operator=(const OpenVRDriver_Service_validate_function_list_result&);
  OpenVRDriver_Service_validate_function_list_result() {
  }

  virtual ~OpenVRDriver_Service_validate_function_list_result() throw();
  std::vector<std::string>  success;

  _OpenVRDriver_Service_validate_function_list_result__isset __isset;

  void __set_success(const std::vector<std::string> & val);

  bool operator == (const OpenVRDriver_Service_validate_function_list_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const OpenVRDriver_Service_validate_function_list_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OpenVRDriver_Service_validate_function_list_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _OpenVRDriver_Service_validate_function_list_presult__isset {
  _OpenVRDriver_Service_validate_function_list_presult__isset() : success(false) {}
  bool success :1;
} _OpenVRDriver_Service_validate_function_list_presult__isset;

class OpenVRDriver_Service_validate_function_list_presult {
 public:


  virtual ~OpenVRDriver_Service_validate_function_list_presult() throw();
  std::vector<std::string> * success;

  _OpenVRDriver_Service_validate_function_list_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class OpenVRDriver_Service_DriverPoseRequest_args {
 public:

  OpenVRDriver_Service_DriverPoseRequest_args(const OpenVRDriver_Service_DriverPoseRequest_args&);
  OpenVRDriver_Service_DriverPoseRequest_args& operator=(const OpenVRDriver_Service_DriverPoseRequest_args&);
  OpenVRDriver_Service_DriverPoseRequest_args() {
  }

  virtual ~OpenVRDriver_Service_DriverPoseRequest_args() throw();

  bool operator == (const OpenVRDriver_Service_DriverPoseRequest_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const OpenVRDriver_Service_DriverPoseRequest_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OpenVRDriver_Service_DriverPoseRequest_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class OpenVRDriver_Service_DriverPoseRequest_pargs {
 public:


  virtual ~OpenVRDriver_Service_DriverPoseRequest_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _OpenVRDriver_Service_DriverPoseRequest_result__isset {
  _OpenVRDriver_Service_DriverPoseRequest_result__isset() : success(false) {}
  bool success :1;
} _OpenVRDriver_Service_DriverPoseRequest_result__isset;

class OpenVRDriver_Service_DriverPoseRequest_result {
 public:

  OpenVRDriver_Service_DriverPoseRequest_result(const OpenVRDriver_Service_DriverPoseRequest_result&);
  OpenVRDriver_Service_DriverPoseRequest_result& operator=(const OpenVRDriver_Service_DriverPoseRequest_result&);
  OpenVRDriver_Service_DriverPoseRequest_result() {
  }

  virtual ~OpenVRDriver_Service_DriverPoseRequest_result() throw();
   ::mixcast::thrift::Pose success;

  _OpenVRDriver_Service_DriverPoseRequest_result__isset __isset;

  void __set_success(const  ::mixcast::thrift::Pose& val);

  bool operator == (const OpenVRDriver_Service_DriverPoseRequest_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const OpenVRDriver_Service_DriverPoseRequest_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OpenVRDriver_Service_DriverPoseRequest_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _OpenVRDriver_Service_DriverPoseRequest_presult__isset {
  _OpenVRDriver_Service_DriverPoseRequest_presult__isset() : success(false) {}
  bool success :1;
} _OpenVRDriver_Service_DriverPoseRequest_presult__isset;

class OpenVRDriver_Service_DriverPoseRequest_presult {
 public:


  virtual ~OpenVRDriver_Service_DriverPoseRequest_presult() throw();
   ::mixcast::thrift::Pose* success;

  _OpenVRDriver_Service_DriverPoseRequest_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class OpenVRDriver_ServiceClient : virtual public OpenVRDriver_ServiceIf {
 public:
  OpenVRDriver_ServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  OpenVRDriver_ServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void validate_ping();
  void send_validate_ping();
  void recv_validate_ping();
  void validate_function_list(std::vector<std::string> & _return);
  void send_validate_function_list();
  void recv_validate_function_list(std::vector<std::string> & _return);
  void DriverPoseRequest( ::mixcast::thrift::Pose& _return);
  void send_DriverPoseRequest();
  void recv_DriverPoseRequest( ::mixcast::thrift::Pose& _return);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class OpenVRDriver_ServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<OpenVRDriver_ServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (OpenVRDriver_ServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_validate_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_validate_function_list(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_DriverPoseRequest(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  OpenVRDriver_ServiceProcessor(::apache::thrift::stdcxx::shared_ptr<OpenVRDriver_ServiceIf> iface) :
    iface_(iface) {
    processMap_["validate_ping"] = &OpenVRDriver_ServiceProcessor::process_validate_ping;
    processMap_["validate_function_list"] = &OpenVRDriver_ServiceProcessor::process_validate_function_list;
    processMap_["DriverPoseRequest"] = &OpenVRDriver_ServiceProcessor::process_DriverPoseRequest;
  }

  virtual ~OpenVRDriver_ServiceProcessor() {}
};

class OpenVRDriver_ServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  OpenVRDriver_ServiceProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< OpenVRDriver_ServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< OpenVRDriver_ServiceIfFactory > handlerFactory_;
};

class OpenVRDriver_ServiceMultiface : virtual public OpenVRDriver_ServiceIf {
 public:
  OpenVRDriver_ServiceMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<OpenVRDriver_ServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~OpenVRDriver_ServiceMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<OpenVRDriver_ServiceIf> > ifaces_;
  OpenVRDriver_ServiceMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<OpenVRDriver_ServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void validate_ping() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->validate_ping();
    }
    ifaces_[i]->validate_ping();
  }

  void validate_function_list(std::vector<std::string> & _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->validate_function_list(_return);
    }
    ifaces_[i]->validate_function_list(_return);
    return;
  }

  void DriverPoseRequest( ::mixcast::thrift::Pose& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->DriverPoseRequest(_return);
    }
    ifaces_[i]->DriverPoseRequest(_return);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class OpenVRDriver_ServiceConcurrentClient : virtual public OpenVRDriver_ServiceIf {
 public:
  OpenVRDriver_ServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  OpenVRDriver_ServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void validate_ping();
  int32_t send_validate_ping();
  void recv_validate_ping(const int32_t seqid);
  void validate_function_list(std::vector<std::string> & _return);
  int32_t send_validate_function_list();
  void recv_validate_function_list(std::vector<std::string> & _return, const int32_t seqid);
  void DriverPoseRequest( ::mixcast::thrift::Pose& _return);
  int32_t send_DriverPoseRequest();
  void recv_DriverPoseRequest( ::mixcast::thrift::Pose& _return, const int32_t seqid);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

}} // namespace

#endif