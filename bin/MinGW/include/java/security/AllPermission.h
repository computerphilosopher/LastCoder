// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_security_AllPermission__
#define __java_security_AllPermission__

#pragma interface

#include <java/security/Permission.h>

extern "Java"
{
  namespace java
  {
    namespace security
    {
      class AllPermission;
      class PermissionCollection;
      class Permission;
    }
  }
}

class java::security::AllPermission : public ::java::security::Permission
{
public:
  AllPermission ();
  AllPermission (::java::lang::String *, ::java::lang::String *);
  jboolean implies (::java::security::Permission *);
  jboolean equals (::java::lang::Object *);
  jint hashCode ();
  ::java::lang::String *getActions ();
  ::java::security::PermissionCollection *newPermissionCollection ();
private:
  static const jlong serialVersionUID = -2916474571451318075LL;
public:

  static ::java::lang::Class class$;
};

#endif /* __java_security_AllPermission__ */
