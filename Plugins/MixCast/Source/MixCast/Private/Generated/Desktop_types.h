/**
 * Autogenerated by Thrift Compiler (Shiyao Modified base on 0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Desktop_TYPES_H
#define Desktop_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>


namespace mixcast { namespace data {

class Desktop;

typedef struct _Desktop__isset {
  _Desktop__isset() : hideMixCastOutput(false), maxDisplayingCameras(false), displayingCameraIds(false), hideMixCastUI(false), uiZoomFactor(false) {}
  bool hideMixCastOutput :1;
  bool maxDisplayingCameras :1;
  bool displayingCameraIds :1;
  bool hideMixCastUI :1;
  bool uiZoomFactor :1;
} _Desktop__isset;

class Desktop : public virtual ::apache::thrift::TBase {
 public:

  Desktop(const Desktop&);
  Desktop& operator=(const Desktop&);
  Desktop() : hideMixCastOutput(0), maxDisplayingCameras(0), hideMixCastUI(0), uiZoomFactor(0) {
  }

  virtual ~Desktop() throw();
  bool hideMixCastOutput;
  int32_t maxDisplayingCameras;
  std::vector<std::string>  displayingCameraIds;
  bool hideMixCastUI;
  double uiZoomFactor;

  _Desktop__isset __isset;

  void __set_hideMixCastOutput(const bool val);

  void __set_maxDisplayingCameras(const int32_t val);

  void __set_displayingCameraIds(const std::vector<std::string> & val);

  void __set_hideMixCastUI(const bool val);

  void __set_uiZoomFactor(const double val);

  bool operator == (const Desktop & rhs) const
  {
    if (!(hideMixCastOutput == rhs.hideMixCastOutput))
      return false;
    if (!(maxDisplayingCameras == rhs.maxDisplayingCameras))
      return false;
    if (!(displayingCameraIds == rhs.displayingCameraIds))
      return false;
    if (!(hideMixCastUI == rhs.hideMixCastUI))
      return false;
    if (!(uiZoomFactor == rhs.uiZoomFactor))
      return false;
    return true;
  }
  bool operator != (const Desktop &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Desktop & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Desktop &a, Desktop &b);

std::ostream& operator<<(std::ostream& out, const Desktop& obj);

}} // namespace

#endif
