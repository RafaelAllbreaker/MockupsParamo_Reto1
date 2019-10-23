/**
 * Autogenerated by Thrift Compiler (Shiyao Modified base on 0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ExperienceMetadata_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace mixcast { namespace data {


ExperienceMetadata::~ExperienceMetadata() throw() {
}


void ExperienceMetadata::__set_experienceExePath(const std::string& val) {
  this->experienceExePath = val;
}

void ExperienceMetadata::__set_experienceTitle(const std::string& val) {
  this->experienceTitle = val;
}

void ExperienceMetadata::__set_organizationName(const std::string& val) {
  this->organizationName = val;
}

void ExperienceMetadata::__set_mixcastVersion(const std::string& val) {
  this->mixcastVersion = val;
}

void ExperienceMetadata::__set_engineVersion(const std::string& val) {
  this->engineVersion = val;
}

void ExperienceMetadata::__set_projectId(const std::string& val) {
  this->projectId = val;
}

void ExperienceMetadata::__set_alphaIsPremultiplied(const bool val) {
  this->alphaIsPremultiplied = val;
}

void ExperienceMetadata::__set_colorSpaceIsLinear(const bool val) {
  this->colorSpaceIsLinear = val;
}
std::ostream& operator<<(std::ostream& out, const ExperienceMetadata& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ExperienceMetadata::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->experienceExePath);
          this->__isset.experienceExePath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->experienceTitle);
          this->__isset.experienceTitle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->organizationName);
          this->__isset.organizationName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->mixcastVersion);
          this->__isset.mixcastVersion = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->engineVersion);
          this->__isset.engineVersion = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->projectId);
          this->__isset.projectId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->alphaIsPremultiplied);
          this->__isset.alphaIsPremultiplied = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->colorSpaceIsLinear);
          this->__isset.colorSpaceIsLinear = true;
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

uint32_t ExperienceMetadata::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ExperienceMetadata");

  xfer += oprot->writeFieldBegin("experienceExePath", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->experienceExePath);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("experienceTitle", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->experienceTitle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("organizationName", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->organizationName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mixcastVersion", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->mixcastVersion);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("engineVersion", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->engineVersion);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("projectId", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeString(this->projectId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("alphaIsPremultiplied", ::apache::thrift::protocol::T_BOOL, 7);
  xfer += oprot->writeBool(this->alphaIsPremultiplied);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("colorSpaceIsLinear", ::apache::thrift::protocol::T_BOOL, 8);
  xfer += oprot->writeBool(this->colorSpaceIsLinear);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ExperienceMetadata &a, ExperienceMetadata &b) {
  using ::std::swap;
  swap(a.experienceExePath, b.experienceExePath);
  swap(a.experienceTitle, b.experienceTitle);
  swap(a.organizationName, b.organizationName);
  swap(a.mixcastVersion, b.mixcastVersion);
  swap(a.engineVersion, b.engineVersion);
  swap(a.projectId, b.projectId);
  swap(a.alphaIsPremultiplied, b.alphaIsPremultiplied);
  swap(a.colorSpaceIsLinear, b.colorSpaceIsLinear);
  swap(a.__isset, b.__isset);
}

ExperienceMetadata::ExperienceMetadata(const ExperienceMetadata& other0) {
  experienceExePath = other0.experienceExePath;
  experienceTitle = other0.experienceTitle;
  organizationName = other0.organizationName;
  mixcastVersion = other0.mixcastVersion;
  engineVersion = other0.engineVersion;
  projectId = other0.projectId;
  alphaIsPremultiplied = other0.alphaIsPremultiplied;
  colorSpaceIsLinear = other0.colorSpaceIsLinear;
  __isset = other0.__isset;
}
ExperienceMetadata& ExperienceMetadata::operator=(const ExperienceMetadata& other1) {
  experienceExePath = other1.experienceExePath;
  experienceTitle = other1.experienceTitle;
  organizationName = other1.organizationName;
  mixcastVersion = other1.mixcastVersion;
  engineVersion = other1.engineVersion;
  projectId = other1.projectId;
  alphaIsPremultiplied = other1.alphaIsPremultiplied;
  colorSpaceIsLinear = other1.colorSpaceIsLinear;
  __isset = other1.__isset;
  return *this;
}
void ExperienceMetadata::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ExperienceMetadata(";
  out << "experienceExePath=" << to_string(experienceExePath);
  out << ", " << "experienceTitle=" << to_string(experienceTitle);
  out << ", " << "organizationName=" << to_string(organizationName);
  out << ", " << "mixcastVersion=" << to_string(mixcastVersion);
  out << ", " << "engineVersion=" << to_string(engineVersion);
  out << ", " << "projectId=" << to_string(projectId);
  out << ", " << "alphaIsPremultiplied=" << to_string(alphaIsPremultiplied);
  out << ", " << "colorSpaceIsLinear=" << to_string(colorSpaceIsLinear);
  out << ")";
}

}} // namespace
