// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GIOMM_VOLUMEMONITOR_H
#define _GIOMM_VOLUMEMONITOR_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

// -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2 -*-

/* Copyright (C) 2007 The gtkmm Development Team
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

 
#include <giomm/drive.h>
#include <giomm/volume.h>
#include <giomm/mount.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GVolumeMonitor GVolumeMonitor;
typedef struct _GVolumeMonitorClass GVolumeMonitorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gio
{ class VolumeMonitor_Class; } // namespace Gio
namespace Gio
{

/** Monitors a file or directory for changes.
 * VolumeMonitor is for listing the user-interesting devices and volumes on the 
 * computer. In other words, what a file selector or file manager would show in 
 * a sidebar.
 *
 * @newin{2,16}
 */

class VolumeMonitor : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef VolumeMonitor CppObjectType;
  typedef VolumeMonitor_Class CppClassType;
  typedef GVolumeMonitor BaseObjectType;
  typedef GVolumeMonitorClass BaseClassType;

private:  friend class VolumeMonitor_Class;
  static CppClassType volumemonitor_class_;

private:
  // noncopyable
  VolumeMonitor(const VolumeMonitor&);
  VolumeMonitor& operator=(const VolumeMonitor&);

protected:
  explicit VolumeMonitor(const Glib::ConstructParams& construct_params);
  explicit VolumeMonitor(GVolumeMonitor* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~VolumeMonitor();

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GVolumeMonitor*       gobj()       { return reinterpret_cast<GVolumeMonitor*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GVolumeMonitor* gobj() const { return reinterpret_cast<GVolumeMonitor*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GVolumeMonitor* gobj_copy();

private:

protected:

public:

  
  /** Gets the volume monitor used by gio.
   * @return A reference to the VolumeMonitor used by gio. Call
   * Glib::object_unref() when done with it.
   */
  static Glib::RefPtr<VolumeMonitor> get();

 
  /** Gets a list of drives connected to the system.
   * 
   * The returned list should be freed with Glib::list_free(), after
   * its elements have been unreffed with Glib::object_unref().
   * @return A List of connected Drive objects.
   */
  Glib::ListHandle< Glib::RefPtr<Drive> > get_connected_drives();

 
  /** Gets a list of the volumes on the system.
   * 
   * The returned list should be freed with Glib::list_free(), after
   * its elements have been unreffed with Glib::object_unref().
   * @return A List of Volume objects.
   */
  Glib::ListHandle< Glib::RefPtr<Volume> > get_volumes();

 
  /** Gets a list of the mounts on the system.
   * 
   * The returned list should be freed with Glib::list_free(), after
   * its elements have been unreffed with Glib::object_unref().
   * @return A List of Mount objects.
   */
  Glib::ListHandle< Glib::RefPtr<Mount> > get_mounts();

  
  /** Finds a Volume object by its UUID (see g_volume_get_uuid())
   * @param uuid The UUID to look for.
   * @return A Volume or <tt>0</tt> if no such volume is available.
   * Free the returned object with Glib::object_unref().
   */
  Glib::RefPtr<Volume> get_volume_for_uuid(const std::string& uuid);
  
  /** Finds a Mount object by its UUID (see g_mount_get_uuid())
   * @param uuid The UUID to look for.
   * @return A Mount or <tt>0</tt> if no such mount is available.
   * Free the returned object with Glib::object_unref().
   */
  Glib::RefPtr<Mount> get_mount_for_uuid(const std::string& uuid);

#ifndef GIOMM_DISABLE_DEPRECATED


  /** This function should be called by any VolumeMonitor
   * implementation when a new Mount object is created that is not
   * associated with a Volume object. It must be called just before
   * emitting the @a mount_added signal.
   * 
   * If the return value is not <tt>0</tt>, the caller must associate the
   * returned Volume object with the Mount. This involves returning
   * it in its g_mount_get_volume() implementation. The caller must
   * also listen for the "removed" signal on the returned object
   * and give up its reference when handling that signal
   * 
   * Similary, if implementing g_volume_monitor_adopt_orphan_mount(),
   * the implementor must take a reference to @a mount and return it in
   * its g_volume_get_mount() implemented. Also, the implementor must
   * listen for the "unmounted" signal on @a mount and give up its
   * reference upon handling that signal.
   * 
   * There are two main use cases for this function.
   * 
   * One is when implementing a user space file system driver that reads
   * blocks of a block device that is already represented by the native
   * volume monitor (for example a CD Audio file system driver). Such
   * a driver will generate its own Mount object that needs to be
   * associated with the Volume object that represents the volume.
   * 
   * The other is for implementing a VolumeMonitor whose sole purpose
   * is to return Volume objects representing entries in the users
   * "favorite servers" list or similar.
   * 
   * Deprecated: 2.20: Instead of using this function, VolumeMonitor
   * implementations should instead create shadow mounts with the URI of
   * the mount they intend to adopt. See the proxy volume monitor in
   * gvfs for an example of this. Also see g_mount_is_shadowed(),
   * g_mount_shadow() and g_mount_unshadow() functions.
   * @param mount A Mount object to find a parent for.
   * @return The Volume object that is the parent for @a mount or <tt>0</tt>
   * if no wants to adopt the Mount.
   */
  static Glib::RefPtr<Volume> adopt_orphan_mount(const Glib::RefPtr<Mount>& mount);

#endif // GIOMM_DISABLE_DEPRECATED


/**
   * @par Slot Prototype:
   * <tt>void on_my_%volume_added(const Glib::RefPtr<Volume>& volume)</tt>
   *
   * Emitted when a mountable volume is added to the system.
   * @param volume A Volume that was added.
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<Volume>& > signal_volume_added();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%volume_removed(const Glib::RefPtr<Volume>& volume)</tt>
   *
   * Emitted when a mountable volume is removed from the system.
   * @param volume A Volume that was removed.
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<Volume>& > signal_volume_removed();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%volume_changed(const Glib::RefPtr<Volume>& volume)</tt>
   *
   * Emitted when mountable volume is changed.
   * @param volume A Volume that changed.
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<Volume>& > signal_volume_changed();


/**
   * @par Slot Prototype:
   * <tt>void on_my_%mount_added(const Glib::RefPtr<Mount>& mount)</tt>
   *
   * Emitted when a mount is added.
   * @param mount A Mount that was added.
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<Mount>& > signal_mount_added();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%mount_removed(const Glib::RefPtr<Mount>& mount)</tt>
   *
   * Emitted when a mount is removed.
   * @param mount A Mount that was removed.
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<Mount>& > signal_mount_removed();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%mount_pre_unmount(const Glib::RefPtr<Mount>& mount)</tt>
   *
   * Emitted when a mount is about to be removed.
   * @param mount A Mount that is being unmounted.
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<Mount>& > signal_mount_pre_unmount();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%mount_changed(const Glib::RefPtr<Mount>& mount)</tt>
   *
   * Emitted when a mount changes.
   * @param mount A Mount that changed.
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<Mount>& > signal_mount_changed();


/**
   * @par Slot Prototype:
   * <tt>void on_my_%drive_connected(const Glib::RefPtr<Drive>& drive)</tt>
   *
   * Emitted when a drive is connected to the system.
   * @param drive A Drive that was connected.
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<Drive>& > signal_drive_connected();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%drive_disconnected(const Glib::RefPtr<Drive>& drive)</tt>
   *
   * Emitted when a drive is disconnected from the system.
   * @param drive A Drive that was disconnected.
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<Drive>& > signal_drive_disconnected();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%drive_changed(const Glib::RefPtr<Drive>& drive)</tt>
   *
   * Emitted when a drive changes.
   * @param drive The drive that changed.
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<Drive>& > signal_drive_changed();


  //TODO: Remove no_default_handler when we can break ABI:
  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%drive_eject_button(const Glib::RefPtr<Drive>& drive)</tt>
   *
   * Emitted when the eject button is pressed on @a drive.
   * 
   * @newin{2,18}
   * @param drive The drive where the eject button was pressed.
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<Drive>& > signal_drive_eject_button();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%drive_stop_button(const Glib::RefPtr<Drive>& drive)</tt>
   *
   * Emitted when the stop button is pressed on @a drive.
   * 
   * @newin{2,22}
   * @param drive The drive where the stop button was pressed.
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<Drive>& > signal_drive_stop_button();


  //TODO: Use ListHandle?
  //_WRAP_VFUNC(GList* get_volumes(), get_volumes)
  //_WRAP_VFUNC(GList* get_mounts(), get_mounts)

 
  //_WRAP_VFUNC(Glib::RefPtr<Volume> get_volume_for_uuid(const std::string& uuid), get_volume_for_uuid)

 
  //_WRAP_VFUNC(Glib::RefPtr<Mount> get_mount_for_uuid(const std::string& uuid), get_mount_for_uuid)

  //There are no properties.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_volume_added().
  virtual void on_volume_added(const Glib::RefPtr<Volume>& volume);
  /// This is a default handler for the signal signal_volume_removed().
  virtual void on_volume_removed(const Glib::RefPtr<Volume>& volume);
  /// This is a default handler for the signal signal_volume_changed().
  virtual void on_volume_changed(const Glib::RefPtr<Volume>& volume);
  /// This is a default handler for the signal signal_mount_added().
  virtual void on_mount_added(const Glib::RefPtr<Mount>& mount);
  /// This is a default handler for the signal signal_mount_removed().
  virtual void on_mount_removed(const Glib::RefPtr<Mount>& mount);
  /// This is a default handler for the signal signal_mount_pre_unmount().
  virtual void on_mount_pre_unmount(const Glib::RefPtr<Mount>& mount);
  /// This is a default handler for the signal signal_mount_changed().
  virtual void on_mount_changed(const Glib::RefPtr<Mount>& mount);
  /// This is a default handler for the signal signal_drive_connected().
  virtual void on_drive_connected(const Glib::RefPtr<Drive>& drive);
  /// This is a default handler for the signal signal_drive_disconnected().
  virtual void on_drive_disconnected(const Glib::RefPtr<Drive>& drive);
  /// This is a default handler for the signal signal_drive_changed().
  virtual void on_drive_changed(const Glib::RefPtr<Drive>& drive);


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
   * @relates Gio::VolumeMonitor
   */
  Glib::RefPtr<Gio::VolumeMonitor> wrap(GVolumeMonitor* object, bool take_copy = false);
}


#endif /* _GIOMM_VOLUMEMONITOR_H */

