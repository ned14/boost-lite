/* import.hpp
Convenience macros for importing local namespace binds
(C) 2014-2016 Niall Douglas http://www.nedprod.com/
File Created: Aug 2014


Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef BOOSTLITE_IMPORT_HPP
#define BOOSTLITE_IMPORT_HPP

#include "cpp_feature.h"

#ifndef BOOSTLITE_DISABLE_NAMESPACE_MODIFIERS
#ifndef __cpp_inline_namespaces
#define BOOSTLITE_DISABLE_NAMESPACE_MODIFIERS
#endif
#endif

/* 2014-10-9 ned: I lost today figuring out the below. I really hate the C preprocessor now.
 *
 * Anyway, infinity = 8. It's easy to expand below if needed.
 */
#include "detail/preprocessor_macro_overload.h"

#define BOOSTLITE_STRINGIZE(a) #a
#define BOOSTLITE_STRINGIZE2(a) BOOSTLITE_STRINGIZE(a)
#define BOOSTLITE_NAMESPACE_VERSION8(a, b, c, d, e, f, g, h) a##_##b##_##c##_##d##_##e##_##f##_##g##_##h
#define BOOSTLITE_NAMESPACE_VERSION7(a, b, c, d, e, f, g) a##_##b##_##c##_##d##_##e##_##f##_##g
#define BOOSTLITE_NAMESPACE_VERSION6(a, b, c, d, e, f) a##_##b##_##c##_##d##_##e##_##f
#define BOOSTLITE_NAMESPACE_VERSION5(a, b, c, d, e) a##_##b##_##c##_##d##_##e
#define BOOSTLITE_NAMESPACE_VERSION4(a, b, c, d) a##_##b##_##c##_##d
#define BOOSTLITE_NAMESPACE_VERSION3(a, b, c) a##_##b##_##c
#define BOOSTLITE_NAMESPACE_VERSION2(a, b) a##_##b
#define BOOSTLITE_NAMESPACE_VERSION1(a) a
//! Concatenates each parameter with _
#define BOOSTLITE_NAMESPACE_VERSION(...) BOOSTLITE_CALL_OVERLOAD(BOOSTLITE_NAMESPACE_VERSION, __VA_ARGS__)

#ifdef BOOSTLITE_DISABLE_NAMESPACE_MODIFIERS
#define BOOSTLITE_NAMESPACE_SELECT_2(name, modifier)
#define BOOSTLITE_NAMESPACE_SELECT2(name, modifier)
#else
#define BOOSTLITE_NAMESPACE_SELECT_2(name, modifier) name
#define BOOSTLITE_NAMESPACE_SELECT2(name, modifier) ::name
#endif
#define BOOSTLITE_NAMESPACE_SELECT_1(name) name
#define BOOSTLITE_NAMESPACE_SELECT1(name) ::name
#define BOOSTLITE_NAMESPACE_SELECT_(...) BOOSTLITE_CALL_OVERLOAD_(BOOSTLITE_NAMESPACE_SELECT_, __VA_ARGS__)
#define BOOSTLITE_NAMESPACE_SELECT(...) BOOSTLITE_CALL_OVERLOAD_(BOOSTLITE_NAMESPACE_SELECT, __VA_ARGS__)
#define BOOSTLITE_NAMESPACE_EXPAND8(a, b, c, d, e, f, g, h) BOOSTLITE_NAMESPACE_SELECT_ a BOOSTLITE_NAMESPACE_SELECT b BOOSTLITE_NAMESPACE_SELECT c BOOSTLITE_NAMESPACE_SELECT d BOOSTLITE_NAMESPACE_SELECT e BOOSTLITE_NAMESPACE_SELECT f BOOSTLITE_NAMESPACE_SELECT g BOOSTLITE_NAMESPACE_SELECT h
#define BOOSTLITE_NAMESPACE_EXPAND7(a, b, c, d, e, f, g) BOOSTLITE_NAMESPACE_SELECT_ a BOOSTLITE_NAMESPACE_SELECT b BOOSTLITE_NAMESPACE_SELECT c BOOSTLITE_NAMESPACE_SELECT d BOOSTLITE_NAMESPACE_SELECT e BOOSTLITE_NAMESPACE_SELECT f BOOSTLITE_NAMESPACE_SELECT g
#define BOOSTLITE_NAMESPACE_EXPAND6(a, b, c, d, e, f) BOOSTLITE_NAMESPACE_SELECT_ a BOOSTLITE_NAMESPACE_SELECT b BOOSTLITE_NAMESPACE_SELECT c BOOSTLITE_NAMESPACE_SELECT d BOOSTLITE_NAMESPACE_SELECT e BOOSTLITE_NAMESPACE_SELECT f
#define BOOSTLITE_NAMESPACE_EXPAND5(a, b, c, d, e) BOOSTLITE_NAMESPACE_SELECT_ a BOOSTLITE_NAMESPACE_SELECT b BOOSTLITE_NAMESPACE_SELECT c BOOSTLITE_NAMESPACE_SELECT d BOOSTLITE_NAMESPACE_SELECT e
#define BOOSTLITE_NAMESPACE_EXPAND4(a, b, c, d) BOOSTLITE_NAMESPACE_SELECT_ a BOOSTLITE_NAMESPACE_SELECT b BOOSTLITE_NAMESPACE_SELECT c BOOSTLITE_NAMESPACE_SELECT d
#define BOOSTLITE_NAMESPACE_EXPAND3(a, b, c) BOOSTLITE_NAMESPACE_SELECT_ a BOOSTLITE_NAMESPACE_SELECT b BOOSTLITE_NAMESPACE_SELECT c
#define BOOSTLITE_NAMESPACE_EXPAND2(a, b) BOOSTLITE_NAMESPACE_SELECT_ a BOOSTLITE_NAMESPACE_SELECT b
#define BOOSTLITE_NAMESPACE_EXPAND1(a) BOOSTLITE_NAMESPACE_SELECT_ a
//! Expands into a::b::c:: ...
#define BOOSTLITE_NAMESPACE(...) BOOSTLITE_CALL_OVERLOAD(BOOSTLITE_NAMESPACE_EXPAND, __VA_ARGS__)

#ifdef BOOSTLITE_DISABLE_NAMESPACE_MODIFIERS
#define BOOSTLITE_NAMESPACE_BEGIN_NAMESPACE_SELECT2(name, modifier)
#else
#define BOOSTLITE_NAMESPACE_BEGIN_NAMESPACE_SELECT2(name, modifier)                                                                                                                                                                                                                                                            \
  modifier namespace name                                                                                                                                                                                                                                                                                                      \
  {
#endif
#define BOOSTLITE_NAMESPACE_BEGIN_NAMESPACE_SELECT1(name)                                                                                                                                                                                                                                                                      \
  namespace name                                                                                                                                                                                                                                                                                                               \
  {
#define BOOSTLITE_NAMESPACE_BEGIN_NAMESPACE_SELECT(...) BOOSTLITE_CALL_OVERLOAD_(BOOSTLITE_NAMESPACE_BEGIN_NAMESPACE_SELECT, __VA_ARGS__)
#define BOOSTLITE_NAMESPACE_BEGIN_EXPAND8(a, b, c, d, e, f, g, h) BOOSTLITE_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_BEGIN_EXPAND7(b, c, d, e, f, g, h)
#define BOOSTLITE_NAMESPACE_BEGIN_EXPAND7(a, b, c, d, e, f, g) BOOSTLITE_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_BEGIN_EXPAND6(b, c, d, e, f, g)
#define BOOSTLITE_NAMESPACE_BEGIN_EXPAND6(a, b, c, d, e, f) BOOSTLITE_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_BEGIN_EXPAND5(b, c, d, e, f)
#define BOOSTLITE_NAMESPACE_BEGIN_EXPAND5(a, b, c, d, e) BOOSTLITE_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_BEGIN_EXPAND4(b, c, d, e)
#define BOOSTLITE_NAMESPACE_BEGIN_EXPAND4(a, b, c, d) BOOSTLITE_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_BEGIN_EXPAND3(b, c, d)
#define BOOSTLITE_NAMESPACE_BEGIN_EXPAND3(a, b, c) BOOSTLITE_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_BEGIN_EXPAND2(b, c)
#define BOOSTLITE_NAMESPACE_BEGIN_EXPAND2(a, b) BOOSTLITE_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_BEGIN_EXPAND1(b)
#define BOOSTLITE_NAMESPACE_BEGIN_EXPAND1(a) BOOSTLITE_NAMESPACE_BEGIN_NAMESPACE_SELECT a

//! Expands into namespace a { namespace b { namespace c ...
#define BOOSTLITE_NAMESPACE_BEGIN(...) BOOSTLITE_CALL_OVERLOAD(BOOSTLITE_NAMESPACE_BEGIN_EXPAND, __VA_ARGS__)

#ifdef BOOSTLITE_DISABLE_NAMESPACE_MODIFIERS
#define BOOSTLITE_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT2(name, modifier)
#else
#define BOOSTLITE_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT2(name, modifier)                                                                                                                                                                                                                                                            \
  modifier namespace name                                                                                                                                                                                                                                                                                                      \
  {
#endif
#define BOOSTLITE_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT1(name)                                                                                                                                                                                                                                                                      \
  export namespace name                                                                                                                                                                                                                                                                                                               \
  {
#define BOOSTLITE_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT(...) BOOSTLITE_CALL_OVERLOAD_(BOOSTLITE_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT, __VA_ARGS__)
#define BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND8(a, b, c, d, e, f, g, h) BOOSTLITE_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND7(b, c, d, e, f, g, h)
#define BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND7(a, b, c, d, e, f, g) BOOSTLITE_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND6(b, c, d, e, f, g)
#define BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND6(a, b, c, d, e, f) BOOSTLITE_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND5(b, c, d, e, f)
#define BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND5(a, b, c, d, e) BOOSTLITE_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND4(b, c, d, e)
#define BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND4(a, b, c, d) BOOSTLITE_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND3(b, c, d)
#define BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND3(a, b, c) BOOSTLITE_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND2(b, c)
#define BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND2(a, b) BOOSTLITE_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND1(b)
#define BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND1(a) BOOSTLITE_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a

//! Expands into export namespace a { namespace b { namespace c ...
#define BOOSTLITE_NAMESPACE_EXPORT_BEGIN(...) BOOSTLITE_CALL_OVERLOAD(BOOSTLITE_NAMESPACE_EXPORT_BEGIN_EXPAND, __VA_ARGS__)

#ifdef BOOSTLITE_DISABLE_NAMESPACE_MODIFIERS
#define BOOSTLITE_NAMESPACE_END_NAMESPACE_SELECT2(name, modifier)
#else
#define BOOSTLITE_NAMESPACE_END_NAMESPACE_SELECT2(name, modifier) }
#endif
#define BOOSTLITE_NAMESPACE_END_NAMESPACE_SELECT1(name) }
#define BOOSTLITE_NAMESPACE_END_NAMESPACE_SELECT(...) BOOSTLITE_CALL_OVERLOAD_(BOOSTLITE_NAMESPACE_END_NAMESPACE_SELECT, __VA_ARGS__)
#define BOOSTLITE_NAMESPACE_END_EXPAND8(a, b, c, d, e, f, g, h) BOOSTLITE_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_END_EXPAND7(b, c, d, e, f, g, h)
#define BOOSTLITE_NAMESPACE_END_EXPAND7(a, b, c, d, e, f, g) BOOSTLITE_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_END_EXPAND6(b, c, d, e, f, g)
#define BOOSTLITE_NAMESPACE_END_EXPAND6(a, b, c, d, e, f) BOOSTLITE_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_END_EXPAND5(b, c, d, e, f)
#define BOOSTLITE_NAMESPACE_END_EXPAND5(a, b, c, d, e) BOOSTLITE_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_END_EXPAND4(b, c, d, e)
#define BOOSTLITE_NAMESPACE_END_EXPAND4(a, b, c, d) BOOSTLITE_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_END_EXPAND3(b, c, d)
#define BOOSTLITE_NAMESPACE_END_EXPAND3(a, b, c) BOOSTLITE_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_END_EXPAND2(b, c)
#define BOOSTLITE_NAMESPACE_END_EXPAND2(a, b) BOOSTLITE_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_NAMESPACE_END_EXPAND1(b)
#define BOOSTLITE_NAMESPACE_END_EXPAND1(a) BOOSTLITE_NAMESPACE_END_NAMESPACE_SELECT a

//! Expands into } } ...
#define BOOSTLITE_NAMESPACE_END(...) BOOSTLITE_CALL_OVERLOAD(BOOSTLITE_NAMESPACE_END_EXPAND, __VA_ARGS__)

//! Expands into a static const char string array used to mark BindLib compatible namespaces
#define BOOSTLITE_DECLARE(decl, desc) static const char *boost_bindlib_out[] = {#decl, desc};

#ifdef _MSC_VER
#define BOOSTLITE_MESSAGE_PRAGMA2(x) __pragma(message(x))
#define BOOSTLITE_MESSAGE_PRAGMA(x) BOOSTLITE_MESSAGE_PRAGMA2(x)
#define BOOSTLITE_MESSAGE_PREFIX(type) __FILE__ "(" BOOSTLITE_STRINGIZE2(__LINE__) "): " type ": "
#define BOOSTLITE_MESSAGE_(type, prefix, msg) BOOSTLITE_MESSAGE_PRAGMA(prefix msg)
#else
#define BOOSTLITE_MESSAGE_PRAGMA2(x) _Pragma(#x)
#define BOOSTLITE_MESSAGE_PRAGMA(type, x) BOOSTLITE_MESSAGE_PRAGMA2(type x)
#define BOOSTLITE_MESSAGE_(type, prefix, msg) BOOSTLITE_MESSAGE_PRAGMA(type, msg)
#endif
//! Have the compiler output a message
#define BOOSTLITE_MESSAGE(msg) BOOSTLITE_MESSAGE_(message, BOOSTLITE_MESSAGE_PREFIX("message"), msg)
//! Have the compiler output a note
#define BOOSTLITE_NOTE(msg) BOOSTLITE_MESSAGE_(message, BOOSTLITE_MESSAGE_PREFIX("note"), msg)
//! Have the compiler output a warning
#define BOOSTLITE_WARNING(msg) BOOSTLITE_MESSAGE_(GCC warning, BOOSTLITE_MESSAGE_PREFIX("warning"), msg)
//! Have the compiler output an error
#define BOOSTLITE_ERROR(msg) BOOSTLITE_MESSAGE_(GCC error, BOOSTLITE_MESSAGE_PREFIX("error"), msg)

#if defined(BOOSTLITE_DISABLE_NAMESPACE_MODIFIERS) && !defined(BOOSTLITE_SUPPRESS_WARNINGS)
BOOSTLITE_WARNING("Boost.BindLib: inline namespace support not available or disabled, therefore ABI versioning inhibited")
#endif

#endif
