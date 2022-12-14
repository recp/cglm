#*****************************************************************************
# Copyright (c), Recep Aslantas.                                             *
#                                                                            *
# MIT License (MIT), http://opensource.org/licenses/MIT                      *
# Full license can be found in the LICENSE file                              *
#                                                                            *
#*****************************************************************************

AC_PREREQ([2.69])
AC_INIT([cglm], [0.8.9], [info@recp.me])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects serial-tests])

# Don't use the default cflags (-O2 -g), we set ours manually in Makefile.am.
: ${CFLAGS=""}

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/])
AC_CONFIG_HEADERS([config.h])

# Dependencies for pkg-config.
PKG_PROG_PKG_CONFIG
# Ancient versions of pkg-config (such as the one used in Travis CI)
# don't have this macro, so we need to do it manually.
m4_ifdef([PKG_INSTALLDIR], [
    PKG_INSTALLDIR
], [
    AC_ARG_WITH([pkgconfigdir],
        [AS_HELP_STRING([--with-pkgconfigdir],
                        [pkg-config installation directory ['${libdir}/pkgconfig']])],,
        [with_pkgconfigdir=]'${libdir}/pkgconfig')
    AC_SUBST([pkgconfigdir], [$with_pkgconfigdir])
])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O

AC_PROG_INSTALL
AM_PROG_AR

AC_ENABLE_SHARED
AC_ENABLE_STATIC

LT_INIT

# Checks for libraries.
AC_CHECK_LIB([m], [floor])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AC_SYS_LARGEFILE

# Checks for header files.
AC_CHECK_HEADERS([limits.h \
                  stddef.h \
                  stdint.h \
                  stdlib.h \
                  string.h ])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE

AC_CONFIG_FILES([Makefile cglm.pc])

AC_OUTPUT
