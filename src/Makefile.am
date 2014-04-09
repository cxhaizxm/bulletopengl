ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I$(top_srcdir)/src/application

noinst_HEADERS = \
		application/BulletOpenGLApplication.h \
		application/FreeGLUTCallbacks.h

#ltlibraries
noinst_LTLIBRARIES = \
		libapplication.la
		
libapplication_la_SOURCES = \
		application/BulletOpenGLApplication.cpp

#programs
bin_PROGRAMS = bulletopengl

bulletopengl_LDADD = \
		libapplication.la
		
bulletopengl_SOURCES = \
		main.cpp
		