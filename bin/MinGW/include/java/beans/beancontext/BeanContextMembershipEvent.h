// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_beans_beancontext_BeanContextMembershipEvent__
#define __java_beans_beancontext_BeanContextMembershipEvent__

#pragma interface

#include <java/beans/beancontext/BeanContextEvent.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace beans
    {
      namespace beancontext
      {
        class BeanContextMembershipEvent;
        class BeanContext;
      }
    }
  }
}

class java::beans::beancontext::BeanContextMembershipEvent : public ::java::beans::beancontext::BeanContextEvent
{
public:
  BeanContextMembershipEvent (::java::beans::beancontext::BeanContext *, ::java::util::Collection *);
  BeanContextMembershipEvent (::java::beans::beancontext::BeanContext *, JArray< ::java::lang::Object *> *);
  virtual jint size ();
  virtual ::java::util::Iterator *iterator ();
  virtual JArray< ::java::lang::Object *> *toArray ();
  virtual jboolean contains (::java::lang::Object *);
public:  // actually protected
  ::java::util::Collection * __attribute__((aligned(__alignof__( ::java::beans::beancontext::BeanContextEvent )))) children;
public:

  static ::java::lang::Class class$;
};

#endif /* __java_beans_beancontext_BeanContextMembershipEvent__ */
