ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I$(top_srcdir)/application_p3d -I/usr/include/panda3d \
	-I/usr/include/python2.7 -I/usr/include/eigen3
	
AM_LDFLAGS = -L/usr/lib/panda3d -L/usr/lib64/panda3d

nodist_noinst_HEADERS = \
	BulletLocal/common.h \
	BulletLocal/BulletWorld.h
	
#ltlibraries
noinst_LTLIBRARIES = libbulletlocal.la
		
nodist_libbulletlocal_la_SOURCES = \
	BulletLocal/BulletWorld.cpp

#programs
noinst_PROGRAMS = bulletpanda3d

bulletpanda3d_LDADD = \
	libbulletlocal.la \
	-lp3framework -lpython2.7
	
nodist_bulletpanda3d_SOURCES = \
	main.cpp
		
		