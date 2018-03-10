// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_nio_DoubleBuffer__
#define __java_nio_DoubleBuffer__

#pragma interface

#include <java/nio/Buffer.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace nio
    {
      class ByteOrder;
      class DoubleBuffer;
    }
  }
}

class java::nio::DoubleBuffer : public ::java::nio::Buffer
{
public: // actually package-private
  DoubleBuffer (jint, jint, jint, jint);
  DoubleBuffer (jdoubleArray, jint, jint, jint, jint, jint);
public:
  static ::java::nio::DoubleBuffer *allocate (jint);
  static ::java::nio::DoubleBuffer *wrap (jdoubleArray, jint, jint);
  static ::java::nio::DoubleBuffer *wrap (jdoubleArray);
  virtual ::java::nio::DoubleBuffer *get (jdoubleArray, jint, jint);
  virtual ::java::nio::DoubleBuffer *get (jdoubleArray);
  virtual ::java::nio::DoubleBuffer *put (::java::nio::DoubleBuffer *);
  virtual ::java::nio::DoubleBuffer *put (jdoubleArray, jint, jint);
  ::java::nio::DoubleBuffer *put (jdoubleArray);
  jboolean hasArray ();
  jdoubleArray array ();
  jint arrayOffset ();
  virtual jint hashCode ();
  virtual jboolean equals (::java::lang::Object *);
  virtual jint compareTo (::java::lang::Object *);
  virtual ::java::nio::ByteOrder *order () = 0;
  virtual jdouble get () = 0;
  virtual ::java::nio::DoubleBuffer *put (jdouble) = 0;
  virtual jdouble get (jint) = 0;
  virtual ::java::nio::DoubleBuffer *put (jint, jdouble) = 0;
  virtual ::java::nio::DoubleBuffer *compact () = 0;
  virtual jboolean isDirect () = 0;
  virtual ::java::nio::DoubleBuffer *slice () = 0;
  virtual ::java::nio::DoubleBuffer *duplicate () = 0;
  virtual ::java::nio::DoubleBuffer *asReadOnlyBuffer () = 0;
public: // actually package-private
  jint __attribute__((aligned(__alignof__( ::java::nio::Buffer ))))  array_offset;
  jdoubleArray backing_buffer;
public:

  static ::java::lang::Class class$;
};

#endif /* __java_nio_DoubleBuffer__ */
