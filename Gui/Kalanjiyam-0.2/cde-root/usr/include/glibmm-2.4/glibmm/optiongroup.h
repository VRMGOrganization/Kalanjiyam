// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GLIBMM_OPTIONGROUP_H
#define _GLIBMM_OPTIONGROUP_H


/* Copyright (C) 2004 The glibmm Development Team
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


#include <glibmm/ustring.h>
#include <sigc++/slot.h>
#include <map>
#include <vector>
#include <glib.h> //TODO: Try to hide this.


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GOptionGroup GOptionGroup; }
#endif //DOXYGEN_SHOULD_SKIP_THIS


namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
class OptionEntry;
class OptionContext;
#endif //DOXYGEN_SHOULD_SKIP_THIS

/** An OptionGroup defines the options in a single group. 
 * Libraries which need to parse commandline options are expected to provide a function that allows their OptionGroups to
 * be added to the application's OptionContext.
 */
class OptionGroup
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef OptionGroup CppObjectType;
  typedef GOptionGroup BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:
  /** For example Glib::ustring on_translate(const Glib::ustring& original);.
   */
  typedef sigc::slot<Glib::ustring, const Glib::ustring&> SlotTranslate;

  /** For example bool on_option_arg_string(const Glib::ustring& option_name,
   *  const Glib::ustring& value, bool has_value);.
   */
  typedef sigc::slot<bool, const Glib::ustring&, const Glib::ustring&, bool> SlotOptionArgString;
   
  /** For example bool on_option_arg_filename(const Glib::ustring& option_name,
   *  const std::string& value, bool has_value);.
   */
  typedef sigc::slot<bool, const Glib::ustring&, const std::string&, bool> SlotOptionArgFilename;

  OptionGroup(const Glib::ustring& name, const Glib::ustring& description, const Glib::ustring& help_description = Glib::ustring());

  /** This always takes ownership of the underlying GOptionGroup, 
   * so it is only useful with C functions that return newly-allocated GOptionGroups. 
   */
  explicit OptionGroup(GOptionGroup* castitem);  
  

  virtual ~OptionGroup();
  

  virtual bool on_pre_parse(OptionContext& context, OptionGroup& group);
  virtual bool on_post_parse(OptionContext& context, OptionGroup& group);
  virtual void on_error(OptionContext& context, OptionGroup& group);
  

  void add_entry(const OptionEntry& entry);
  

  typedef std::vector<Glib::ustring> vecustrings;
  typedef std::vector<std::string> vecstrings;

  void add_entry(const OptionEntry& entry, bool& arg);
  void add_entry(const OptionEntry& entry, int& arg);
  void add_entry(const OptionEntry& entry, double& arg);
  void add_entry(const OptionEntry& entry, Glib::ustring& arg);
  void add_entry_filename(const OptionEntry& entry, std::string& arg);  
  void add_entry(const OptionEntry& entry, vecustrings& arg);
  void add_entry_filename(const OptionEntry& entry, vecstrings& arg);
  void add_entry(const OptionEntry& entry, const SlotOptionArgString& slot);
  void add_entry_filename(const OptionEntry& entry, const SlotOptionArgFilename& slot);

  /** Sets the function which is used to translate user-visible strings, for
   * --help output. Different groups can use a different SlotTranslate. If a
   * translate function is not set, strings are not translated.
   *
   * If you are using gettext(), you only need to set the translation domain,
   * see set_translation_domain().
   *
   * @param slot the slot to be used for translation.
   *
   * @newin{2,28}
   */
  void set_translate_func(const SlotTranslate& slot);
  

  /** A convenience function to use gettext() for translating
   * user-visible strings.
   * 
   * @newin{2,6}
   * @param domain The domain to use.
   */
  void set_translation_domain(const Glib::ustring& domain);

  GOptionGroup*       gobj()       { return gobject_; }
  const GOptionGroup* gobj() const { return gobject_; }
  GOptionGroup* gobj_give_ownership();

protected:

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** This is not public API. It is an implementation detail.
   */
  class CppOptionEntry
  {
  public:
    CppOptionEntry();

    void allocate_c_arg();
    void set_c_arg_default(void* cpp_arg);
    void convert_c_to_cpp();
    void release_c_arg();

    GOptionArg carg_type_;
    void* carg_;
    void* cpparg_;
    OptionEntry* entry_;
  };

  void add_entry_with_wrapper(const OptionEntry& entry, GOptionArg arg_type, void* cpp_arg);

  static gboolean post_parse_callback(GOptionContext* context,
    GOptionGroup* group, gpointer data, GError** error);

  static gboolean option_arg_callback(const gchar* option_name, const gchar* value,
    gpointer data, GError** error);

  //Map of entry names to CppOptionEntry:
  typedef std::map<Glib::ustring, CppOptionEntry> type_map_entries;
  type_map_entries map_entries_;

  GOptionGroup* gobject_;
  bool has_ownership_; //Whether the gobject_ belongs to this C++ instance.
#endif //DOXYGEN_SHOULD_SKIP_THIS


};

} // namespace Glib


#endif /* _GLIBMM_OPTIONGROUP_H */

