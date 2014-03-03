// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GIOMM_SOCKETADDRESS_H
#define _GIOMM_SOCKETADDRESS_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

// -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2 -*-

/* Copyright (C) 2007 The giomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <glibmm/object.h>

#include <giomm/asyncresult.h>
#include <giomm/cancellable.h>
#include <giomm/socketconnectable.h>
#include <giomm/enums.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSocketAddress GSocketAddress;
typedef struct _GSocketAddressClass GSocketAddressClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{ class SocketAddress_Class; } // namespace Gio
namespace Gio
{

/** Abstract base class representing endpoints for socket communication
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class SocketAddress : public Glib::Object,
    public SocketConnectable
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef SocketAddress CppObjectType;
  typedef SocketAddress_Class CppClassType;
  typedef GSocketAddress BaseObjectType;
  typedef GSocketAddressClass BaseClassType;

private:  friend class SocketAddress_Class;
  static CppClassType socketaddress_class_;

private:
  // noncopyable
  SocketAddress(const SocketAddress&);
  SocketAddress& operator=(const SocketAddress&);

protected:
  explicit SocketAddress(const Glib::ConstructParams& construct_params);
  explicit SocketAddress(GSocketAddress* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~SocketAddress();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GSocketAddress*       gobj()       { return reinterpret_cast<GSocketAddress*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GSocketAddress* gobj() const { return reinterpret_cast<GSocketAddress*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GSocketAddress* gobj_copy();

private:

  
    explicit SocketAddress(gpointer native, gsize len);


public:
  
  static Glib::RefPtr<SocketAddress> create(gpointer native, gsize len);

  
  /** Gets the socket family type of @a address.
   * 
   * @newin{2,22}
   * @return The socket family type of @a address.
   */
  SocketFamily get_family() const;
  
  /** Converts a SocketAddress to a native <type>struct
   * sockaddr</type>, which can be passed to low-level functions like
   * connect() or bind().
   * 
   * If not enough space is available, a IO_ERROR_NO_SPACE error is
   * returned. If the address type is not known on the system
   * then a IO_ERROR_NOT_SUPPORTED error is returned.
   * 
   * @newin{2,22}
   * @param dest A pointer to a memory location that will contain the native
   * <type>struct sockaddr</type>.
   * @param destlen The size of @a dest. Must be at least as large as
   * g_socket_address_get_native_size().
   * @return <tt>true</tt> if @a dest was filled in, <tt>false</tt> on error.
   */
  bool to_native(gpointer dest, gsize destlen);
  
  /** Gets the size of @a address's native <type>struct sockaddr</type>.
   * You can use this to allocate memory to pass to
   * g_socket_address_to_native().
   * 
   * @newin{2,22}
   * @return The size of the native <type>struct sockaddr</type> that
   *  @a address represents.
   */
  gssize get_native_size() const;

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The family of the socket address.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SocketFamily> > property_family() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::SocketAddress
   */
  Glib::RefPtr<Gio::SocketAddress> wrap(GSocketAddress* object, bool take_copy = false);
}


#endif /* _GIOMM_SOCKETADDRESS_H */

