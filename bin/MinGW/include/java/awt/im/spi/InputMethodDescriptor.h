// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_im_spi_InputMethodDescriptor__
#define __java_awt_im_spi_InputMethodDescriptor__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace im
      {
        namespace spi
        {
          class InputMethodDescriptor;
          class InputMethod;
        }
      }
      class Image;
    }
  }
}

class java::awt::im::spi::InputMethodDescriptor : public ::java::lang::Object
{
public:
  virtual JArray< ::java::util::Locale *> *getAvailableLocales () = 0;
  virtual jboolean hasDynamicLocaleList () = 0;
  virtual ::java::lang::String *getInputMethodDisplayName (::java::util::Locale *, ::java::util::Locale *) = 0;
  virtual ::java::awt::Image *getInputMethodIcon (::java::util::Locale *) = 0;
  virtual ::java::awt::im::spi::InputMethod *createInputMethod () = 0;

  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif /* __java_awt_im_spi_InputMethodDescriptor__ */
