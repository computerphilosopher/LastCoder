// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_JViewport__
#define __javax_swing_JViewport__

#pragma interface

#include <javax/swing/JComponent.h>

extern "Java"
{
  namespace javax
  {
    namespace swing
    {
      class JViewport;
    }
  }
  namespace java
  {
    namespace awt
    {
      class Graphics;
      class Container;
      class Component;
    }
  }
}

class javax::swing::JViewport : public ::javax::swing::JComponent
{
public: // actually package-private
  JViewport ();
  virtual void setView (::java::awt::Component *);
public:
  virtual ::java::lang::String *getUIClassID ();
  virtual void updateUI ();
public: // actually package-private
  virtual ::java::awt::Container *GetHeavy (::java::awt::Container *);
public:
  virtual void paint (::java::awt::Graphics *);
public: // actually package-private
  ::java::awt::Component * __attribute__((aligned(__alignof__( ::javax::swing::JComponent )))) c;
public:

  static ::java::lang::Class class$;
};

#endif /* __javax_swing_JViewport__ */
