#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([wl-test-app], [0.1.4], [])
AM_INIT_AUTOMAKE([foreign])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES([WAYLAND_CLIENT], [wayland-client])
PKG_CHECK_MODULES(WAYLAND_CURSOR, wayland-cursor)
PKG_CHECK_MODULES(WAYLAND_EGL, wayland-egl)
PKG_CHECK_MODULES(EGL, [egl >= 7.10 glesv2])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT32_T
AC_TYPE_UINT32_T

# Checks for library functions.
AC_CHECK_FUNCS([gettimeofday strstr])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
