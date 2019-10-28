/**
 * Autogenerated by Thrift Compiler (Shiyao Modified base on 0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef VirtualCamera_TYPES_H
#define VirtualCamera_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>
#include "Math_types.h"


namespace mixcast { namespace data {

class VirtualCamera;

typedef struct _VirtualCamera__isset {
  _VirtualCamera__isset() : identifier(false), fieldOfView(false), currentPosition(false), currentRotation(false), videoInputIds(false), renderResolutionWidth(false), renderResolutionHeight(false), renderFramerate(false), externalComposite(false), frameBufferDelay(false), outputPtr(false), autoSnapshotEnabled(false), videoRecordingEnabled(false), videoRecordingOutputPath(false), videoStreamingEnabled(false) {}
  bool identifier :1;
  bool fieldOfView :1;
  bool currentPosition :1;
  bool currentRotation :1;
  bool videoInputIds :1;
  bool renderResolutionWidth :1;
  bool renderResolutionHeight :1;
  bool renderFramerate :1;
  bool externalComposite :1;
  bool frameBufferDelay :1;
  bool outputPtr :1;
  bool autoSnapshotEnabled :1;
  bool videoRecordingEnabled :1;
  bool videoRecordingOutputPath :1;
  bool videoStreamingEnabled :1;
} _VirtualCamera__isset;

class VirtualCamera : public virtual ::apache::thrift::TBase {
 public:

  VirtualCamera(const VirtualCamera&);
  VirtualCamera& operator=(const VirtualCamera&);
  VirtualCamera() : identifier(), fieldOfView(0), renderResolutionWidth(0), renderResolutionHeight(0), renderFramerate(0), externalComposite(0), frameBufferDelay(0), outputPtr(0), autoSnapshotEnabled(0), videoRecordingEnabled(0), videoRecordingOutputPath(), videoStreamingEnabled(0) {
  }

  virtual ~VirtualCamera() throw();
  std::string identifier;
  double fieldOfView;
   ::mixcast::thrift::Vector3 currentPosition;
   ::mixcast::thrift::Quaternion currentRotation;
  std::vector<std::string>  videoInputIds;
  int32_t renderResolutionWidth;
  int32_t renderResolutionHeight;
  int32_t renderFramerate;
  bool externalComposite;
  double frameBufferDelay;
  int64_t outputPtr;
  bool autoSnapshotEnabled;
  bool videoRecordingEnabled;
  std::string videoRecordingOutputPath;
  bool videoStreamingEnabled;

  _VirtualCamera__isset __isset;

  void __set_identifier(const std::string& val);

  void __set_fieldOfView(const double val);

  void __set_currentPosition(const  ::mixcast::thrift::Vector3& val);

  void __set_currentRotation(const  ::mixcast::thrift::Quaternion& val);

  void __set_videoInputIds(const std::vector<std::string> & val);

  void __set_renderResolutionWidth(const int32_t val);

  void __set_renderResolutionHeight(const int32_t val);

  void __set_renderFramerate(const int32_t val);

  void __set_externalComposite(const bool val);

  void __set_frameBufferDelay(const double val);

  void __set_outputPtr(const int64_t val);

  void __set_autoSnapshotEnabled(const bool val);

  void __set_videoRecordingEnabled(const bool val);

  void __set_videoRecordingOutputPath(const std::string& val);

  void __set_videoStreamingEnabled(const bool val);

  bool operator == (const VirtualCamera & rhs) const
  {
    if (!(identifier == rhs.identifier))
      return false;
    if (!(fieldOfView == rhs.fieldOfView))
      return false;
    if (!(currentPosition == rhs.currentPosition))
      return false;
    if (!(currentRotation == rhs.currentRotation))
      return false;
    if (!(videoInputIds == rhs.videoInputIds))
      return false;
    if (!(renderResolutionWidth == rhs.renderResolutionWidth))
      return false;
    if (!(renderResolutionHeight == rhs.renderResolutionHeight))
      return false;
    if (!(renderFramerate == rhs.renderFramerate))
      return false;
    if (!(externalComposite == rhs.externalComposite))
      return false;
    if (!(frameBufferDelay == rhs.frameBufferDelay))
      return false;
    if (!(outputPtr == rhs.outputPtr))
      return false;
    if (!(autoSnapshotEnabled == rhs.autoSnapshotEnabled))
      return false;
    if (!(videoRecordingEnabled == rhs.videoRecordingEnabled))
      return false;
    if (!(videoRecordingOutputPath == rhs.videoRecordingOutputPath))
      return false;
    if (!(videoStreamingEnabled == rhs.videoStreamingEnabled))
      return false;
    return true;
  }
  bool operator != (const VirtualCamera &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const VirtualCamera & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(VirtualCamera &a, VirtualCamera &b);

std::ostream& operator<<(std::ostream& out, const VirtualCamera& obj);

}} // namespace

#endif