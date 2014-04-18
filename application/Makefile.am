ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I$(top_srcdir)/application

noinst_HEADERS = \
	BasicDemo.h \
	OpenGLMotionState.h \
	BulletOpenGLApplication.h \
	FreeGLUTCallbacks.h \
	GameObject.h

nodist_noinst_HEADERS = \
	config.h

#ltlibraries
noinst_LTLIBRARIES = \
	libapplication.la
		
libapplication_la_SOURCES = \
	BasicDemo.cpp \
	BulletOpenGLApplication.cpp \
	GameObject.cpp

#programs
bin_PROGRAMS = bulletopengl

bulletopengl_LDADD = \
	libapplication.la
		
bulletopengl_SOURCES = \
	main.cpp
