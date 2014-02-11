#Sample Make File
BUILD_HOME:=$(shell pwd)/../..

include $(XDAQ_ROOT)/config/mfAutoconf.rules
include $(XDAQ_ROOT)/config/mfDefs.$(XDAQ_OS)

Project=GlibViewer
Package=GlibViewer

Sources= GlibViewer.cc version.cc

GLIB_ROOT = /home/rasehgal/XDAQ/UHAL-CMAKE/GLIB
IncludeDirs = \
	$(GLIB_ROOT)/include \
	$(CACTUSCORE)/uhal/tests/include \
	$(CACTUSCORE)/uhal/log/include \
	$(CACTUSCORE)/uhal/grammars/include \
	$(CACTUSCORE)/extern/boost/RPMBUILD/SOURCES/include \
	$(CACTUSCORE)/extern/pugixml/RPMBUILD/SOURCES/include \
	$(CACTUSCORE)/uhal/uhal/include \
	$(GLIB_ROOT)/include

LibraryDirs = \
	$(GLIB_ROOT)/lib 

UserDynamicLinkFlags = \
	-lglib

DynamicLibrary=GlibViewer

include $(XDAQ_ROOT)/config/Makefile.rules
include $(XDAQ_ROOT)/config/mfRPM.rules
