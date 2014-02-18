/* Sample Source File */
#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "myPPackage/myPPackage.h"
#include "xdata/UnsignedLong.h"

XDAQ_INSTANTIATOR_IMPL(myPPackage::myPPackage)

myPPackage::myPPackage::myPPackage(xdaq::ApplicationStub * s)
  throw (xdaq::exception::Exception): xdaq::Application(s)
{
//  LOG4CPLUS_INFO(this->getApplicationLogger(),"Hello !"); 
 xgi::bind(this,&myPPackage::Default, "Default");
 xgi::bind(this,&myPPackage::Test, "Test");
}

void myPPackage::myPPackage::Default(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception)
{
 *out << cgicc::HTMLDoctype(cgicc::HTMLDoctype::eStrict) << std::endl;
  *out << cgicc::html().set("lang", "en").set("dir","ltr") << std::endl;
  *out << cgicc::title("Test Simple Web") << std::endl;
  *out << cgicc::body()<<std::endl;
  *out << cgicc::b("This is default functionality....") << std::endl;
  *out << cgicc::body() << std::endl;
  *out << cgicc::html() << std::endl;
}

void myPPackage::myPPackage::Test(xgi::Input * in, xgi::Output * out )
  throw (xgi::exception::Exception)
{
  *out << cgicc::HTMLDoctype(cgicc::HTMLDoctype::eStrict) << std::endl;
  *out << cgicc::html().set("lang", "en").set("dir","ltr") << std::endl;
  *out << cgicc::title("Test Simple Web") << std::endl;
  *out << cgicc::body()<<std::endl;
  *out << cgicc::b("Hello there...") << std::endl;
  *out << cgicc::body() << std::endl;
  *out << cgicc::html() << std::endl;
}


