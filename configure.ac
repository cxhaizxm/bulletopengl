#                                               -*- Autoconf -*-
# Process this file with auto(re)conf to produce a configure script.

###Standard `configure.ac' Layout###
# Autoconf requirements
# `AC_INIT(PACKAGE, VERSION, BUG-REPORT-ADDRESS)'
# information on the package
# checks for programs
# checks for libraries
# checks for header files
# checks for types
# checks for structures
# checks for compiler characteristics
# checks for library functions
# checks for system services
# `AC_CONFIG_FILES([FILE...])'
# `AC_OUTPUT'

AC_PREREQ([2.67])
AC_INIT([bullet-opengl], [1.0], [consultit@katamail.com])
AM_INIT_AUTOMAKE
LT_PREREQ([2.2])
LT_INIT([dlopen])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([ch1/main.h])
AC_CONFIG_HEADERS([config.h])
AC_PREFIX_DEFAULT([/usr])
#AM_SILENT_RULES

#
BGL_CPPFLAGS=""
# checks for programs.
:${CXXFLAGS=""}
AC_PROG_CXX
AC_PROG_CC
AC_LANG([C++])
# default BGL CXXFLAGS (release mode)
BGL_CXXFLAGS="-O3 -w -fmessage-length=0"

# checks/sets options
# BGL_DEVEL
AC_ARG_ENABLE([bgl-devel],
	AS_HELP_STRING([--enable-bgl-devel],
		[@<:@=yes@:>@ enable BGL development mode (disabled by default)]),
    [bgl_devel=${enableval}], [bgl_devel=no])
AM_CONDITIONAL([BGL_DEVEL], [test "x${bgl_devel}" != xno])
# BGL_DEBUG
AC_ARG_ENABLE([bgl-debug],
	AS_HELP_STRING([--enable-bgl-debug],
		[@<:@=yes@:>@ enable BGL debug mode (disabled by default)]),
    [bgl_debug=${enableval}], [bgl_debug=no])
if test "x${bgl_debug}" != xno; then
    AC_DEFINE([BGL_DEBUG],[1],[debug mode enabled])
    BGL_CXXFLAGS="-O0 -g3 -Wall -fmessage-length=0"
fi

AC_SUBST(BGL_CPPFLAGS)
AC_SUBST(BGL_CXXFLAGS)

# Checks for header files.
AC_CHECK_HEADERS([float.h limits.h memory.h stdlib.h sys/time.h])
AX_CXX_HEADER_STDCXX_98
required_headers=
AC_CHECK_HEADER([bullet/btBulletDynamicsCommon.h],[],[required_headers=${required_headers}" Bullet2 "])
AC_CHECK_HEADER([GL/gl.h],[],[required_headers=${required_headers}" OpenGL "])
AC_CHECK_HEADER([GL/glu.h],[],[required_headers=${required_headers}" Glu "])
AC_CHECK_HEADER([GL/glut.h],[],[required_headers=${required_headers}" glut "])
if test -n "${required_headers}" ; then
	AC_MSG_ERROR([
	----------------------------------------
	The ${required_headers} headers are 
	required to build BGL. Stopping...
	Check 'config.log' for more information.
	----------------------------------------])
fi

# check for Bullet libraries
CPPFLAGS_CMDLINE=${CPPFLAGS}
LDFLAGS_CMDLINE=${LDFLAGS}
AC_MSG_NOTICE([Looking for Bullet libraries...])
BULLET_LDFLAGS=""
BULLET_LIBS="-lBulletCollision -lBulletDynamics -lLinearMath -lBulletSoftBody"
			
LDFLAGS="${BULLET_LDFLAGS} ${LDFLAGS_CMDLINE}"
LIBS="${BULLET_LIBS} ${LIBS}"
required_libraries=yes
bullet_prologue="#include <bullet/btBulletDynamicsCommon.h>"
bullet_body="
	int argc=1;
	char** argv=0;
	btDiscreteDynamicsWorld world(NULL,NULL,NULL,NULL);
  	"  	
AC_LINK_IFELSE(
  [AC_LANG_PROGRAM([$bullet_prologue],[$bullet_body])],
  AC_MSG_NOTICE([Bullet libraries... yes]) 
  AC_DEFINE([HAVE_BULLET], 1, [Bullet enabled]),
  [required_libraries="Bullet"]
)
if test "x${required_libraries}" != xyes; then
	AC_MSG_ERROR([
	----------------------------------------
	The ${required_libraries} libraries are
	required to build Ely. Stopping...
	Check 'config.log' for more information.
	----------------------------------------])
fi
CPPFLAGS=${CPPFLAGS_CMDLINE}
LDFLAGS=${LDFLAGS_CMDLINE}
#
# checks for libraries.
required_libraries=
AC_SEARCH_LIBS([glDrawBuffer], [GL], [], [required_libraries=${required_libraries}" OpenGL "])
AC_SEARCH_LIBS([gluProject], [GLU], [], [required_libraries=${required_libraries}" GLU "])
AC_SEARCH_LIBS([glutInit], [glut], [], [required_libraries=${required_libraries}" glut "])
if test -n "${required_libraries}" ; then
	AC_MSG_ERROR([
	----------------------------------------
	The ${required_libraries} libraries are 
	required to build BGL. Stopping...
	Check 'config.log' for more information.
	----------------------------------------])
fi

# checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([floor gettimeofday pow sqrt])

AC_CONFIG_FILES([
		Makefile
		])

AC_OUTPUT
