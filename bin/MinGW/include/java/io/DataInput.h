// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_io_DataInput__
#define __java_io_DataInput__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

class java::io::DataInput : public ::java::lang::Object
{
public:
  virtual jboolean readBoolean () = 0;
  virtual jbyte readByte () = 0;
  virtual jint readUnsignedByte () = 0;
  virtual jchar readChar () = 0;
  virtual jshort readShort () = 0;
  virtual jint readUnsignedShort () = 0;
  virtual jint readInt () = 0;
  virtual jlong readLong () = 0;
  virtual jfloat readFloat () = 0;
  virtual jdouble readDouble () = 0;
  virtual ::java::lang::String *readLine () = 0;
  virtual ::java::lang::String *readUTF () = 0;
  virtual void readFully (jbyteArray) = 0;
  virtual void readFully (jbyteArray, jint, jint) = 0;
  virtual jint skipBytes (jint) = 0;

  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif /* __java_io_DataInput__ */
