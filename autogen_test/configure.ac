
#                     -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
 
AC_PREREQ([2.69])
AC_INIT([auto_test],[1.0],[stevexyh@hotmail.com])
 
AC_SUBST([PACKAGE_RELEASE],[1.0],[stevexyh@hotmail.com])
 
AM_INIT_AUTOMAKE(auto_test,1.0)
AC_CONFIG_SRCDIR([src/auto_test.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile
           	src/Makefile])
 
# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL
 
# Checks for libraries.
 
# Checks for header files.
AC_CHECK_HEADERS([stddef.h string.h])
 
# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_TYPE_SIZE_T
 
# Checks for library functions.
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset socket])
 
AC_OUTPUT
