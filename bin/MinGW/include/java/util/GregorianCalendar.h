// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_GregorianCalendar__
#define __java_util_GregorianCalendar__

#pragma interface

#include <java/util/Calendar.h>
#include <gcj/array.h>

class java::util::GregorianCalendar : public ::java::util::Calendar
{
private:
  static ::java::util::ResourceBundle *getBundle (::java::util::Locale *);
public:
  GregorianCalendar ();
  GregorianCalendar (::java::util::TimeZone *);
  GregorianCalendar (::java::util::Locale *);
  GregorianCalendar (::java::util::TimeZone *, ::java::util::Locale *);
  GregorianCalendar (jint, jint, jint);
  GregorianCalendar (jint, jint, jint, jint, jint);
  GregorianCalendar (jint, jint, jint, jint, jint, jint);
  virtual void setGregorianChange (::java::util::Date *);
  ::java::util::Date *getGregorianChange ();
  virtual jboolean isLeapYear (jint);
private:
  jlong getLinearTime (jint, jint, jint);
  jint getWeekDay (jint, jint);
  jintArray getDayOfYear (jint);
public:  // actually protected
  virtual void computeTime ();
private:
  jboolean isLeapYear (jint, jboolean);
  jint getLinearDay (jint, jint, jboolean);
  void calculateDay (jint, jboolean);
public:  // actually protected
  virtual void computeFields ();
public:
  virtual jboolean equals (::java::lang::Object *);
  virtual void add (jint, jint);
  virtual void roll (jint, jboolean);
private:
  void cleanUpAfterRoll (jint, jint);
public:
  virtual void roll (jint, jint);
  virtual jint getMinimum (jint);
  virtual jint getMaximum (jint);
  virtual jint getGreatestMinimum (jint);
  virtual jint getLeastMaximum (jint);
  virtual jint getActualMinimum (jint);
  virtual jint getActualMaximum (jint);
  static const jint BC = 0L;
  static const jint AD = 1L;
private:
  jlong __attribute__((aligned(__alignof__( ::java::util::Calendar ))))  gregorianCutover;
public: // actually package-private
  static const jlong serialVersionUID = -8125100834729963327LL;
private:
  static ::java::lang::String *bundleName;
  static jintArray minimums;
  static jintArray maximums;
public:

  static ::java::lang::Class class$;
};

#endif /* __java_util_GregorianCalendar__ */
