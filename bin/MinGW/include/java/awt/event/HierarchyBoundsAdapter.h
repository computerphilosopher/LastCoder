// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_event_HierarchyBoundsAdapter__
#define __java_awt_event_HierarchyBoundsAdapter__

#pragma interface

#include <java/lang/Object.h>

extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace event
      {
        class HierarchyBoundsAdapter;
        class HierarchyEvent;
      }
    }
  }
}

class java::awt::event::HierarchyBoundsAdapter : public ::java::lang::Object
{
public:
  HierarchyBoundsAdapter ();
  virtual void ancestorMoved (::java::awt::event::HierarchyEvent *) { }
  virtual void ancestorResized (::java::awt::event::HierarchyEvent *) { }

  static ::java::lang::Class class$;
};

#endif /* __java_awt_event_HierarchyBoundsAdapter__ */