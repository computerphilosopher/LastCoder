// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_HashMap__
#define __java_util_HashMap__

#pragma interface

#include <java/util/AbstractMap.h>
#include <gcj/array.h>

class java::util::HashMap : public ::java::util::AbstractMap
{
public:
  HashMap ();
  HashMap (::java::util::Map *);
  HashMap (jint);
  HashMap (jint, jfloat);
  virtual jint size () { return size__; }
  virtual jboolean isEmpty ();
  virtual ::java::lang::Object *get (::java::lang::Object *);
  virtual jboolean containsKey (::java::lang::Object *);
  virtual ::java::lang::Object *put (::java::lang::Object *, ::java::lang::Object *);
  virtual void putAll (::java::util::Map *);
  virtual ::java::lang::Object *remove (::java::lang::Object *);
  virtual void clear ();
  virtual jboolean containsValue (::java::lang::Object *);
  virtual ::java::lang::Object *clone ();
  virtual ::java::util::Set *keySet ();
  virtual ::java::util::Collection *values ();
  virtual ::java::util::Set *entrySet ();
public: // actually package-private
  virtual void addEntry (::java::lang::Object *, ::java::lang::Object *, jint, jboolean);
  ::java::util::HashMap$HashEntry *getEntry (::java::lang::Object *);
  jint hash (::java::lang::Object *);
  virtual ::java::util::Iterator *iterator (jint);
  virtual void putAllInternal (::java::util::Map *);
private:
  void rehash ();
  void writeObject (::java::io::ObjectOutputStream *);
  void readObject (::java::io::ObjectInputStream *);
public: // actually package-private
  static const jint DEFAULT_CAPACITY = 11L;
  static const jfloat DEFAULT_LOAD_FACTOR = 0x1.800000p-1f;
private:
  static const jlong serialVersionUID = 362498820763181265LL;
  jint __attribute__((aligned(__alignof__( ::java::util::AbstractMap ))))  threshold;
public: // actually package-private
  jfloat loadFactor;
  JArray< ::java::util::HashMap$HashEntry *> *buckets;
  jint modCount;
  jint size__;
private:
  ::java::util::Set *entries;

  friend class java_util_HashMap$HashIterator;
  friend class java_util_HashMap$3;
  friend class java_util_HashMap$2;
  friend class java_util_HashMap$1;
  friend class java_util_HashMap$HashEntry;
public:

  static ::java::lang::Class class$;
};

#endif /* __java_util_HashMap__ */
