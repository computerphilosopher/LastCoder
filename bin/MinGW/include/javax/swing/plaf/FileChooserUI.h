// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_plaf_FileChooserUI__
#define __javax_swing_plaf_FileChooserUI__

#pragma interface

#include <javax/swing/plaf/ComponentUI.h>

extern "Java"
{
  namespace javax
  {
    namespace swing
    {
      namespace plaf
      {
        class FileChooserUI;
      }
      namespace filechooser
      {
        class FileView;
        class FileFilter;
      }
      class JFileChooser;
    }
  }
}

class javax::swing::plaf::FileChooserUI : public ::javax::swing::plaf::ComponentUI
{
public:
  FileChooserUI ();
  virtual ::javax::swing::filechooser::FileFilter *getAcceptAllFileFilter (::javax::swing::JFileChooser *) = 0;
  virtual ::javax::swing::filechooser::FileView *getFileView (::javax::swing::JFileChooser *) = 0;
  virtual ::java::lang::String *getApproveButtonText (::javax::swing::JFileChooser *) = 0;
  virtual ::java::lang::String *getDialogTitle (::javax::swing::JFileChooser *) = 0;
  virtual void rescanCurrentDirectory (::javax::swing::JFileChooser *) = 0;
  virtual void ensureFileIsVisible (::javax::swing::JFileChooser *, ::java::io::File *) = 0;

  static ::java::lang::Class class$;
};

#endif /* __javax_swing_plaf_FileChooserUI__ */
