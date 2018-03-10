// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_ComponentDataBlitOp__
#define __gnu_java_awt_ComponentDataBlitOp__

#pragma interface

#include <java/lang/Object.h>

extern "Java"
{
  namespace java
  {
    namespace awt
    {
      class RenderingHints;
      namespace geom
      {
        class Point2D;
        class Rectangle2D;
      }
      namespace image
      {
        class WritableRaster;
        class Raster;
      }
    }
  }
  namespace gnu
  {
    namespace java
    {
      namespace awt
      {
        class ComponentDataBlitOp;
      }
    }
  }
}

class gnu::java::awt::ComponentDataBlitOp : public ::java::lang::Object
{
public:
  virtual ::java::awt::image::WritableRaster *filter (::java::awt::image::Raster *, ::java::awt::image::WritableRaster *);
  virtual ::java::awt::geom::Rectangle2D *getBounds2D (::java::awt::image::Raster *);
  virtual ::java::awt::image::WritableRaster *createCompatibleDestRaster (::java::awt::image::Raster *);
  virtual ::java::awt::geom::Point2D *getPoint2D (::java::awt::geom::Point2D *, ::java::awt::geom::Point2D *);
  virtual ::java::awt::RenderingHints *getRenderingHints ();
  ComponentDataBlitOp ();
  static ::gnu::java::awt::ComponentDataBlitOp *INSTANCE;

  static ::java::lang::Class class$;
};

#endif /* __gnu_java_awt_ComponentDataBlitOp__ */