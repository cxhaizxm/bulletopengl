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
AC_INIT([bulletopengl], [1.0], [consultit@katamail.com])
AM_INIT_AUTOMAKE
LT_PREREQ([2.2])
LT_INIT([dlopen])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/ch1/main.cpp])
:${CXXFLAGS=""}
AC_CONFIG_HEADERS([src/config.h])
AC_PREFIX_DEFAULT([/usr])

# checks for programs.
:${CXXFLAGS=""}
AC_PROG_CXX
AC_LANG([C++])
#AM_SILENT_RULES
#
CXXFLAGSS_CMDLINE=${CXXFLAGS}
# checks for programs.
CXXFLAGS="-O3 -w -fmessage-length=0 ${CXXFLAGSS_CMDLINE}"

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
    CXXFLAGS="-O0 -g3 -Wall -fmessage-length=0 ${CXXFLAGSS_CMDLINE}"
fi

CPPFLAGS_CMDLINE=${CPPFLAGS}
# Checks for header files.
BULLET_CPPFLAGS="-I/usr/include/bullet -I/usr/local/include/bullet"
CPPFLAGS="${BULLET_CPPFLAGS} ${CPPFLAGS_CMDLINE}"
AC_CHECK_HEADERS([float.h limits.h memory.h stdlib.h sys/time.h])
AX_CXX_HEADER_STDCXX_98
required_headers=
AC_CHECK_HEADER([btBulletDynamicsCommon.h],[],[required_headers=${required_headers}" Bullet2 "])
AC_CHECK_HEADER([GL/gl.h],[],[required_headers=${required_headers}" OpenGL "])
AC_CHECK_HEADER([GL/glu.h],[],[required_headers=${required_headers}" Glu "])
AC_CHECK_HEADER([GL/freeglut.h],[],[required_headers=${required_headers}" Free glut "])
if test -n "${required_headers}" ; then
	AC_MSG_ERROR([
	----------------------------------------
	The ${required_headers} headers are 
	required to build BGL. Stopping...
	Check 'config.log' for more information.
	----------------------------------------])
fi

LDFLAGS_CMDLINE=${LDFLAGS}
LIBS_CMDLINE=${LIBS}
# check for Bullet libraries
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
#
# checks for other libraries.
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
		src/Makefile
		])

AC_OUTPUT
