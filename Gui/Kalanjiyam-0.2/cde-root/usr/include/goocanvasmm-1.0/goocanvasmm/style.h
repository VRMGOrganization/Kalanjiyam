// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GOOCANVASMM_STYLE_H
#define _GOOCANVASMM_STYLE_H


#include <glibmm.h>


/* Copyright (C) 1998-2006 The gtkmm Development Team
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
#include <cairomm/context.h>
#include <cairomm/refptr.h>

#include <gdkmm.h>
#include <goocanvasstyle.h> //For the template implementations.


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GooCanvasStyle GooCanvasStyle;
typedef struct _GooCanvasStyleClass GooCanvasStyleClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Goocanvas
{ class Style_Class; } // namespace Goocanvas
namespace Goocanvas
{


class Style : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Style CppObjectType;
  typedef Style_Class CppClassType;
  typedef GooCanvasStyle BaseObjectType;
  typedef GooCanvasStyleClass BaseClassType;

private:  friend class Style_Class;
  static CppClassType style_class_;

private:
  // noncopyable
  Style(const Style&);
  Style& operator=(const Style&);

protected:
  explicit Style(const Glib::ConstructParams& construct_params);
  explicit Style(GooCanvasStyle* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Style();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GooCanvasStyle*       gobj()       { return reinterpret_cast<GooCanvasStyle*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GooCanvasStyle* gobj() const { return reinterpret_cast<GooCanvasStyle*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GooCanvasStyle* gobj_copy();

private:

protected:
  Style();

public:
  
  static Glib::RefPtr<Style> create();

  
  template<typename PropertyType>
  void get_property(GQuark property_id, PropertyType& value) const;
  

  template<typename PropertyType>
  void set_property(GQuark property_id, const PropertyType& value);
  

  /** Copies the given Goo::CanvasStyle, by copying all of its properties.
   * Though the parent of the new style is left unset.
   * @return A copy of the given Goo::CanvasStyle.
   */
  Glib::RefPtr<Style> copy() const;
  
  /** Gets the parent of the style.
   * @return The parent of the given style, or <tt>0</tt>.
   */
  Glib::RefPtr<Style> get_parent() const;
  
  /** Sets the parent of the style.
   * @param parent The new parent.
   */
  void set_parent(const Glib::RefPtr<Style>& style);
  
  /** Sets the standard cairo stroke options using the given style.
   * @param cr A cairo context.
   * @return <tt>true</tt> if a paint source is set, or <tt>false</tt> if the stroke should
   * be skipped.
   */
  bool set_stroke_options(const Cairo::RefPtr<Cairo::Context>& context);
  
  /** Sets the standard cairo fill options using the given style.
   * @param cr A cairo context.
   * @return <tt>true</tt> if a paint source is set, or <tt>false</tt> if the fill should
   * be skipped.
   */
  bool set_fill_options(const Cairo::RefPtr<Cairo::Context>& context);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

template<typename PropertyType> inline
void Style::get_property(GQuark property_id, PropertyType& value) const
{
  Glib::Value<PropertyType> property_value(goo_canvas_style_get_property(const_cast<GooCanvasStyle*>(gobj()), property_id));
  value = property_value.get();
}

template<typename PropertyType> inline
void Style::set_property(GQuark property_id, const PropertyType& value)
{
  Glib::Value<PropertyType> property_value;
  property_value.init(Glib::Value<PropertyType>::value_type());
  property_value.set(value);
  goo_canvas_style_set_property(gobj(), property_id, property_value.gobj());
}

}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Goocanvas::Style
   */
  Glib::RefPtr<Goocanvas::Style> wrap(GooCanvasStyle* object, bool take_copy = false);
}


#endif /* _GOOCANVASMM_STYLE_H */

