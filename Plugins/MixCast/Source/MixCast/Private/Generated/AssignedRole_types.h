/**
 * Autogenerated by Thrift Compiler (Shiyao Modified base on 0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef AssignedRole_TYPES_H
#define AssignedRole_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>


namespace mixcast { namespace data {

struct AssignedRole {
  enum type {
    UNKNOWN = 0,
    HEAD = 1,
    LEFT_HAND = 2,
    RIGHT_HAND = 3
  };
};

extern const std::map<int, const char*> _AssignedRole_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const AssignedRole::type& val);

}} // namespace

#endif