#Sample Make File
BUILD_HOME:=$(shell pwd)/../..

include $(XDAQ_ROOT)/config/mfAutoconf.rules
include $(XDAQ_ROOT)/config/mfDefs.$(XDAQ_OS)

Project=myPProj
Package=myPPackage

Sources= myPPackage.cc version.cc

DynamicLibrary=myPPackage

include $(XDAQ_ROOT)/config/Makefile.rules
include $(XDAQ_ROOT)/config/mfRPM.rules
