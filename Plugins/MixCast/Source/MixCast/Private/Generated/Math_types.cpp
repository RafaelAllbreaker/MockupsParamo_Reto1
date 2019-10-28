/**
 * Autogenerated by Thrift Compiler (Shiyao Modified base on 0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "Math_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace mixcast { namespace thrift {


Quaternion::~Quaternion() throw() {
}


void Quaternion::__set_w(const double val) {
  this->w = val;
}

void Quaternion::__set_x(const double val) {
  this->x = val;
}

void Quaternion::__set_y(const double val) {
  this->y = val;
}

void Quaternion::__set_z(const double val) {
  this->z = val;
}
std::ostream& operator<<(std::ostream& out, const Quaternion& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t Quaternion::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_w = false;
  bool isset_x = false;
  bool isset_y = false;
  bool isset_z = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->w);
          isset_w = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->x);
          isset_x = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->y);
          isset_y = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->z);
          isset_z = true;
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

  if (!isset_w)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_x)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_y)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_z)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Quaternion::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Quaternion");

  xfer += oprot->writeFieldBegin("w", ::apache::thrift::protocol::T_DOUBLE, 1);
  xfer += oprot->writeDouble(this->w);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("x", ::apache::thrift::protocol::T_DOUBLE, 2);
  xfer += oprot->writeDouble(this->x);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("y", ::apache::thrift::protocol::T_DOUBLE, 3);
  xfer += oprot->writeDouble(this->y);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("z", ::apache::thrift::protocol::T_DOUBLE, 4);
  xfer += oprot->writeDouble(this->z);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Quaternion &a, Quaternion &b) {
  using ::std::swap;
  swap(a.w, b.w);
  swap(a.x, b.x);
  swap(a.y, b.y);
  swap(a.z, b.z);
}

Quaternion::Quaternion(const Quaternion& other0) {
  w = other0.w;
  x = other0.x;
  y = other0.y;
  z = other0.z;
}
Quaternion& Quaternion::operator=(const Quaternion& other1) {
  w = other1.w;
  x = other1.x;
  y = other1.y;
  z = other1.z;
  return *this;
}
void Quaternion::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Quaternion(";
  out << "w=" << to_string(w);
  out << ", " << "x=" << to_string(x);
  out << ", " << "y=" << to_string(y);
  out << ", " << "z=" << to_string(z);
  out << ")";
}


Vector3::~Vector3() throw() {
}


void Vector3::__set_x(const double val) {
  this->x = val;
}

void Vector3::__set_y(const double val) {
  this->y = val;
}

void Vector3::__set_z(const double val) {
  this->z = val;
}
std::ostream& operator<<(std::ostream& out, const Vector3& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t Vector3::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_x = false;
  bool isset_y = false;
  bool isset_z = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->x);
          isset_x = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->y);
          isset_y = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->z);
          isset_z = true;
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

  if (!isset_x)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_y)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_z)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Vector3::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Vector3");

  xfer += oprot->writeFieldBegin("x", ::apache::thrift::protocol::T_DOUBLE, 1);
  xfer += oprot->writeDouble(this->x);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("y", ::apache::thrift::protocol::T_DOUBLE, 2);
  xfer += oprot->writeDouble(this->y);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("z", ::apache::thrift::protocol::T_DOUBLE, 3);
  xfer += oprot->writeDouble(this->z);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Vector3 &a, Vector3 &b) {
  using ::std::swap;
  swap(a.x, b.x);
  swap(a.y, b.y);
  swap(a.z, b.z);
}

Vector3::Vector3(const Vector3& other2) {
  x = other2.x;
  y = other2.y;
  z = other2.z;
}
Vector3& Vector3::operator=(const Vector3& other3) {
  x = other3.x;
  y = other3.y;
  z = other3.z;
  return *this;
}
void Vector3::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Vector3(";
  out << "x=" << to_string(x);
  out << ", " << "y=" << to_string(y);
  out << ", " << "z=" << to_string(z);
  out << ")";
}


Pose::~Pose() throw() {
}


void Pose::__set_position(const Vector3& val) {
  this->position = val;
}

void Pose::__set_rotation(const Quaternion& val) {
  this->rotation = val;
}
std::ostream& operator<<(std::ostream& out, const Pose& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t Pose::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_position = false;
  bool isset_rotation = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->position.read(iprot);
          isset_position = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->rotation.read(iprot);
          isset_rotation = true;
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

  if (!isset_position)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_rotation)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Pose::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Pose");

  xfer += oprot->writeFieldBegin("position", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->position.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("rotation", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->rotation.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Pose &a, Pose &b) {
  using ::std::swap;
  swap(a.position, b.position);
  swap(a.rotation, b.rotation);
}

Pose::Pose(const Pose& other4) {
  position = other4.position;
  rotation = other4.rotation;
}
Pose& Pose::operator=(const Pose& other5) {
  position = other5.position;
  rotation = other5.rotation;
  return *this;
}
void Pose::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Pose(";
  out << "position=" << to_string(position);
  out << ", " << "rotation=" << to_string(rotation);
  out << ")";
}

}} // namespace