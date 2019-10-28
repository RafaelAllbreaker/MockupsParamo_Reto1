/**
 * Autogenerated by Thrift Compiler (Shiyao Modified base on 0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "VirtualCamera_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace mixcast { namespace data {


VirtualCamera::~VirtualCamera() throw() {
}


void VirtualCamera::__set_identifier(const std::string& val) {
  this->identifier = val;
}

void VirtualCamera::__set_fieldOfView(const double val) {
  this->fieldOfView = val;
}

void VirtualCamera::__set_currentPosition(const  ::mixcast::thrift::Vector3& val) {
  this->currentPosition = val;
}

void VirtualCamera::__set_currentRotation(const  ::mixcast::thrift::Quaternion& val) {
  this->currentRotation = val;
}

void VirtualCamera::__set_videoInputIds(const std::vector<std::string> & val) {
  this->videoInputIds = val;
}

void VirtualCamera::__set_renderResolutionWidth(const int32_t val) {
  this->renderResolutionWidth = val;
}

void VirtualCamera::__set_renderResolutionHeight(const int32_t val) {
  this->renderResolutionHeight = val;
}

void VirtualCamera::__set_renderFramerate(const int32_t val) {
  this->renderFramerate = val;
}

void VirtualCamera::__set_externalComposite(const bool val) {
  this->externalComposite = val;
}

void VirtualCamera::__set_frameBufferDelay(const double val) {
  this->frameBufferDelay = val;
}

void VirtualCamera::__set_outputPtr(const int64_t val) {
  this->outputPtr = val;
}

void VirtualCamera::__set_autoSnapshotEnabled(const bool val) {
  this->autoSnapshotEnabled = val;
}

void VirtualCamera::__set_videoRecordingEnabled(const bool val) {
  this->videoRecordingEnabled = val;
}

void VirtualCamera::__set_videoRecordingOutputPath(const std::string& val) {
  this->videoRecordingOutputPath = val;
}

void VirtualCamera::__set_videoStreamingEnabled(const bool val) {
  this->videoStreamingEnabled = val;
}
std::ostream& operator<<(std::ostream& out, const VirtualCamera& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t VirtualCamera::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->identifier);
          this->__isset.identifier = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->fieldOfView);
          this->__isset.fieldOfView = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->currentPosition.read(iprot);
          this->__isset.currentPosition = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->currentRotation.read(iprot);
          this->__isset.currentRotation = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->videoInputIds.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->videoInputIds.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += iprot->readString(this->videoInputIds[_i4]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.videoInputIds = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->renderResolutionWidth);
          this->__isset.renderResolutionWidth = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->renderResolutionHeight);
          this->__isset.renderResolutionHeight = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->renderFramerate);
          this->__isset.renderFramerate = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->externalComposite);
          this->__isset.externalComposite = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->frameBufferDelay);
          this->__isset.frameBufferDelay = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->outputPtr);
          this->__isset.outputPtr = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->autoSnapshotEnabled);
          this->__isset.autoSnapshotEnabled = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 13:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->videoRecordingEnabled);
          this->__isset.videoRecordingEnabled = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 14:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->videoRecordingOutputPath);
          this->__isset.videoRecordingOutputPath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 15:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->videoStreamingEnabled);
          this->__isset.videoStreamingEnabled = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t VirtualCamera::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("VirtualCamera");

  xfer += oprot->writeFieldBegin("identifier", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->identifier);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("fieldOfView", ::apache::thrift::protocol::T_DOUBLE, 2);
  xfer += oprot->writeDouble(this->fieldOfView);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("currentPosition", ::apache::thrift::protocol::T_STRUCT, 3);
  xfer += this->currentPosition.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("currentRotation", ::apache::thrift::protocol::T_STRUCT, 4);
  xfer += this->currentRotation.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("videoInputIds", ::apache::thrift::protocol::T_LIST, 5);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->videoInputIds.size()));
    std::vector<std::string> ::const_iterator _iter5;
    for (_iter5 = this->videoInputIds.begin(); _iter5 != this->videoInputIds.end(); ++_iter5)
    {
      xfer += oprot->writeString((*_iter5));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("renderResolutionWidth", ::apache::thrift::protocol::T_I32, 6);
  xfer += oprot->writeI32(this->renderResolutionWidth);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("renderResolutionHeight", ::apache::thrift::protocol::T_I32, 7);
  xfer += oprot->writeI32(this->renderResolutionHeight);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("renderFramerate", ::apache::thrift::protocol::T_I32, 8);
  xfer += oprot->writeI32(this->renderFramerate);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("externalComposite", ::apache::thrift::protocol::T_BOOL, 9);
  xfer += oprot->writeBool(this->externalComposite);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("frameBufferDelay", ::apache::thrift::protocol::T_DOUBLE, 10);
  xfer += oprot->writeDouble(this->frameBufferDelay);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("outputPtr", ::apache::thrift::protocol::T_I64, 11);
  xfer += oprot->writeI64(this->outputPtr);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("autoSnapshotEnabled", ::apache::thrift::protocol::T_BOOL, 12);
  xfer += oprot->writeBool(this->autoSnapshotEnabled);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("videoRecordingEnabled", ::apache::thrift::protocol::T_BOOL, 13);
  xfer += oprot->writeBool(this->videoRecordingEnabled);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("videoRecordingOutputPath", ::apache::thrift::protocol::T_STRING, 14);
  xfer += oprot->writeString(this->videoRecordingOutputPath);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("videoStreamingEnabled", ::apache::thrift::protocol::T_BOOL, 15);
  xfer += oprot->writeBool(this->videoStreamingEnabled);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(VirtualCamera &a, VirtualCamera &b) {
  using ::std::swap;
  swap(a.identifier, b.identifier);
  swap(a.fieldOfView, b.fieldOfView);
  swap(a.currentPosition, b.currentPosition);
  swap(a.currentRotation, b.currentRotation);
  swap(a.videoInputIds, b.videoInputIds);
  swap(a.renderResolutionWidth, b.renderResolutionWidth);
  swap(a.renderResolutionHeight, b.renderResolutionHeight);
  swap(a.renderFramerate, b.renderFramerate);
  swap(a.externalComposite, b.externalComposite);
  swap(a.frameBufferDelay, b.frameBufferDelay);
  swap(a.outputPtr, b.outputPtr);
  swap(a.autoSnapshotEnabled, b.autoSnapshotEnabled);
  swap(a.videoRecordingEnabled, b.videoRecordingEnabled);
  swap(a.videoRecordingOutputPath, b.videoRecordingOutputPath);
  swap(a.videoStreamingEnabled, b.videoStreamingEnabled);
  swap(a.__isset, b.__isset);
}

VirtualCamera::VirtualCamera(const VirtualCamera& other6) {
  identifier = other6.identifier;
  fieldOfView = other6.fieldOfView;
  currentPosition = other6.currentPosition;
  currentRotation = other6.currentRotation;
  videoInputIds = other6.videoInputIds;
  renderResolutionWidth = other6.renderResolutionWidth;
  renderResolutionHeight = other6.renderResolutionHeight;
  renderFramerate = other6.renderFramerate;
  externalComposite = other6.externalComposite;
  frameBufferDelay = other6.frameBufferDelay;
  outputPtr = other6.outputPtr;
  autoSnapshotEnabled = other6.autoSnapshotEnabled;
  videoRecordingEnabled = other6.videoRecordingEnabled;
  videoRecordingOutputPath = other6.videoRecordingOutputPath;
  videoStreamingEnabled = other6.videoStreamingEnabled;
  __isset = other6.__isset;
}
VirtualCamera& VirtualCamera::operator=(const VirtualCamera& other7) {
  identifier = other7.identifier;
  fieldOfView = other7.fieldOfView;
  currentPosition = other7.currentPosition;
  currentRotation = other7.currentRotation;
  videoInputIds = other7.videoInputIds;
  renderResolutionWidth = other7.renderResolutionWidth;
  renderResolutionHeight = other7.renderResolutionHeight;
  renderFramerate = other7.renderFramerate;
  externalComposite = other7.externalComposite;
  frameBufferDelay = other7.frameBufferDelay;
  outputPtr = other7.outputPtr;
  autoSnapshotEnabled = other7.autoSnapshotEnabled;
  videoRecordingEnabled = other7.videoRecordingEnabled;
  videoRecordingOutputPath = other7.videoRecordingOutputPath;
  videoStreamingEnabled = other7.videoStreamingEnabled;
  __isset = other7.__isset;
  return *this;
}
void VirtualCamera::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "VirtualCamera(";
  out << "identifier=" << to_string(identifier);
  out << ", " << "fieldOfView=" << to_string(fieldOfView);
  out << ", " << "currentPosition=" << to_string(currentPosition);
  out << ", " << "currentRotation=" << to_string(currentRotation);
  out << ", " << "videoInputIds=" << to_string(videoInputIds);
  out << ", " << "renderResolutionWidth=" << to_string(renderResolutionWidth);
  out << ", " << "renderResolutionHeight=" << to_string(renderResolutionHeight);
  out << ", " << "renderFramerate=" << to_string(renderFramerate);
  out << ", " << "externalComposite=" << to_string(externalComposite);
  out << ", " << "frameBufferDelay=" << to_string(frameBufferDelay);
  out << ", " << "outputPtr=" << to_string(outputPtr);
  out << ", " << "autoSnapshotEnabled=" << to_string(autoSnapshotEnabled);
  out << ", " << "videoRecordingEnabled=" << to_string(videoRecordingEnabled);
  out << ", " << "videoRecordingOutputPath=" << to_string(videoRecordingOutputPath);
  out << ", " << "videoStreamingEnabled=" << to_string(videoStreamingEnabled);
  out << ")";
}

}} // namespace