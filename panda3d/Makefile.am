ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = -I$(top_srcdir)/panda3d -I/usr/include/panda3d \
	-I/usr/include/python2.7 -I/usr/include/eigen3
	
AM_LDFLAGS = -L/usr/lib/panda3d

nodist_noinst_HEADERS = 
	
#ltlibraries
noinst_LTLIBRARIES = libpanda3d.la
		
nodist_libpanda3d_la_SOURCES = 

#programs
noinst_PROGRAMS = bulletpanda3d

bulletpanda3d_LDADD = \
	-lp3framework -lpython2.7
	
nodist_bulletpanda3d_SOURCES = \
	main.cpp
		
		