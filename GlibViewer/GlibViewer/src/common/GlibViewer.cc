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
#include "GlibViewer/GlibViewer.h"
#include "xdata/UnsignedLong.h"
#include "xdata/String.h"
#include "glib.h"
#include "sstream"

using namespace cgicc;

ConnectionManager *manager=new ConnectionManager("file://myconnections.xml");
HwInterface hw=manager->getDevice ( "dummy.udp.0" );

XDAQ_INSTANTIATOR_IMPL(GlibViewer::GlibViewer)

GlibViewer::GlibViewer::GlibViewer(xdaq::ApplicationStub * s)
  throw (xdaq::exception::Exception): xdaq::Application(s)
{
//  LOG4CPLUS_INFO(this->getApplicationLogger(),"Hello !"); 
 xgi::bind(this,&GlibViewer::Default, "Default");
 xgi::bind(this,&GlibViewer::Test, "Test");
 xgi::bind(this,&GlibViewer::BasicGLIBInfo, "BasicGLIBInfo");
 xgi::bind(this,&GlibViewer::showRegisTable, "showRegisTable");
 xgi::bind(this,&GlibViewer::insertBoards,"insertBoards");
 xgi::bind(this,&GlibViewer::ChangeBoard,"ChangeBoard");
 xgi::bind(this,&GlibViewer::NodesInfo,"NodesInfo");
 xgi::bind(this,&GlibViewer::MyNodes,"MyNodes");
 xgi::bind(this,&GlibViewer::setParameter,"setParameter");
}

void GlibViewer::GlibViewer::Default(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception)
{
 *out << cgicc::HTMLDoctype(cgicc::HTMLDoctype::eStrict) << std::endl;
  *out << cgicc::html().set("lang", "en").set("dir","ltr") << std::endl;
  *out << cgicc::title("Test Simple Web") << std::endl;
  *out << cgicc::body()<<std::endl;
  *out << cgicc::b("This is default functionality....") << std::endl;
  *out << cgicc::body() << std::endl;
  *out << cgicc::html() << std::endl;
}

void GlibViewer::GlibViewer::Test(xgi::Input * in, xgi::Output * out )
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

void GlibViewer::GlibViewer::BasicGLIBInfo(xgi::Input * in, xgi::Output * out )
  throw (xgi::exception::Exception)
{
  *out << cgicc::HTMLDoctype(cgicc::HTMLDoctype::eStrict) << std::endl;
  *out << cgicc::html().set("lang", "en").set("dir","ltr") << std::endl;
  GLIB obj("file://myconnections.xml");
  *out << cgicc::title("GLIB Supervisor Page") << std::endl;
  *out << cgicc::body()<<std::endl;
  *out << cgicc::b(obj.GetSystemDetails()) << std::endl;
  *out << cgicc::b(obj.GetBoardDetails()) << std::endl;
  obj.FetchFirmWare();
  *out << cgicc::b(obj.GetFirmwareVersion()) << " : "<<cgicc::b(obj.GetFirmwareDate())  << std::endl;


  *out << cgicc::body() << std::endl;
  *out << cgicc::html() << std::endl;
}

int GlibViewer::GlibViewer::HexStringToInt(std::string hexString)
{
   std::stringstream sstr;
   sstr << hexString;
   sstr << std::hex;
   int f;
   sstr >> f;
   return f;
}

void GlibViewer::GlibViewer::showRegisTable(xgi::Input * in, xgi::Output * out )
  throw (xgi::exception::Exception)
{
*out << cgicc::HTMLDoctype(cgicc::HTMLDoctype::eStrict) << std::endl;
*out << cgicc::html().set("lang", "en").set("dir","ltr") << std::endl;
*out << cgicc::head(cgicc::title("GLIB Page")) << std::endl;
*out << cgicc::body() <<std::endl;
*out << "RegisTable Function"<<std::endl;

*out << cgicc::body();
*out<< cgicc::html();
}

void GlibViewer::GlibViewer::insertBoards(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception){
	*out << cgicc::HTMLDoctype(cgicc::HTMLDoctype::eStrict) << std::endl;
	*out << cgicc::html().set("lang", "en").set("dir","ltr") << std::endl;
        *out << cgicc::head(cgicc::title("GLIB Page")) << std::endl;
	*out << cgicc::body() <<std::endl;

	 uhal::ConnectionManager lConnectionManager ( "file://myconnections.xml" );
        std::vector< std::string > arrBoards= lConnectionManager.getDevices();
        *out<<"Connection file: "<<"myconnections.xml"<<cgicc::br()<<std::endl;
        *out<<cgicc::h3(std::string("Connections"))<<std::endl;
        *out<<cgicc::ol()<<std::endl;
        for(std::vector<std::string>::iterator it = arrBoards.begin(); it != arrBoards.end(); ++it){
                //if (strBoard.toString() == *it)
                 //       *out<<cgicc::li(cgicc::strong(*it))<<std::endl;
                //else
                        //*out<<"<li><a href='ChangeBoard?connection="<<(*it)<<"'>"<<(*it)<<"</a></li>"<<std::endl;
                        *out<<"<li><a href='NodesInfo?connection="<<(*it)<<"'>"<<(*it)<<"</a></li>"<<std::endl;
        }
	
        *out<<cgicc::ol()<<std::endl;
	*out << cgicc::body();
*out<< cgicc::html();
}

void GlibViewer::GlibViewer::MyNodes(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception)
{
*out << cgicc::HTMLDoctype(cgicc::HTMLDoctype::eStrict) << std::endl;
        *out << cgicc::html().set("lang", "en").set("dir","ltr") << std::endl;
        *out << cgicc::head(cgicc::title("GLIB Page")) << std::endl;
        *out << cgicc::body() <<std::endl;

*out<<"Hello Raman"<<std::endl;
*out << cgicc::body();
*out<< cgicc::html();

}


void GlibViewer::GlibViewer::setParameter(xgi::Input * in, xgi::Output * out )
  throw (xgi::exception::Exception)
{
GLIB obj("file://myconnections.xml");
cgicc::Cgicc cgi(in);
std::string regname = cgi["regname"]->getValue();
std::string hexString=cgi["value"]->getValue();
int val=HexStringToInt(hexString);
obj.writeTest(regname,val);
*out << "Set Parameter Called with : "<<regname<<" : "<<hexString<<std::endl;
}

void GlibViewer::GlibViewer::NodesInfo(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception)
{
*out << cgicc::HTMLDoctype(cgicc::HTMLDoctype::eStrict) << std::endl;
        *out << cgicc::html().set("lang", "en").set("dir","ltr") << std::endl;
        *out << cgicc::head(cgicc::title("GLIB Page")) << std::endl;
        *out << cgicc::body() <<std::endl;
int clr=0;
std::string method = toolbox::toString("/%s/setParameter",getApplicationDescriptor()->getURN().c_str());
//method.append("?regname=udpppp");

cgicc::Cgicc cgi(in);
strBoard = cgi["connection"]->getValue();
//hw=manager->getDevice ( "dummy.udp.0" );
*out<<"<center><hr/>";
*out<<"<h3>Info for Board : "<<strBoard.toString()<<"</h3>";
*out<<"<hr/>";

hw=manager->getDevice (strBoard.toString());
std::vector<std::string> nodeString=hw.getNodes();
//*out<<"<table border=2>";
*out<<table().set("border","0");
//std::cout<<"REACH"<<std::endl;
for (std::vector<std::string>::iterator it = nodeString.begin(); it != nodeString.end(); ++it)
 { clr++;
  std::cout << ' ' << *it<<"  :: 0x"<<std::hex<<std::setfill('0')<<std::setw(8)<<hw.getNode(*it).getAddress()<<"  ::  0x"<< std::hex<<std::setfill('0')<<std::setw(8)<<hw.getNode(*it).getMask()<<"  ::  ";//<<hw.getNode(*it).read()<<std::endl;
   uhal::ValWord< uint32_t > reg = hw.getNode (*it).read();
   hw.dispatch();
  std::cout<<reg.value()<<std::endl;


//CREATING FORMS 
std::string hexPref="0x";
std::stringstream addStr,maskStr,valueStr;
addStr<<std::hex<<std::setfill('0')<<std::setw(8)<<hw.getNode(*it).getAddress();
std::string hexAddStr="0x";hexAddStr.append(addStr.str());
maskStr<<std::hex<<std::setfill('0')<<std::setw(8)<<hw.getNode(*it).getMask();
std::string hexMaskStr="0x";hexMaskStr.append(maskStr.str());
valueStr<<std::hex<<std::setfill('0')<<std::setw(8)<<reg.value();
std::string hexValueStr="0x"; hexValueStr.append(valueStr.str());
*out<< cgicc::form().set("method","GET").set("action", method) << std::endl;    
*out<<tr()
    <<td(input().set("type","text").set("name","regname").set("value",*it))
    <<td(input().set("type","text").set("name","address").set("value",hexAddStr))
    <<td(input().set("type","text").set("name","mask").set("value",hexMaskStr))
    <<td(input().set("type","text").set("name","value").set("value",hexValueStr))
    <<td(input().set("type","submit").set("value","Set")) 
    <<tr()<<std::endl;

*out << cgicc::form() << std::endl;

}
//  std::cout << '\n';
//*out<<"</table></center>";
table();

*out<< "<a href='NodesInfo?connection=dummy.udp.0'>Refresh</a>" << std::endl;
*out << cgicc::body();
*out<< cgicc::html();

}


void GlibViewer::GlibViewer::ChangeBoard(xgi::Input * in, xgi::Output * out )throw (xgi::exception::Exception) {
        cgicc::Cgicc cgi(in);
        //uhal::ConnectionManager lConnectionManager ( strUhalConnection.toString() );
	uhal::ConnectionManager lConnectionManager ( "file://myconnections.xml" );
	std::cout<<cgi["connection"]->getValue()<<std::endl;      
  strBoard = cgi["connection"]->getValue();
  hwBoard = new uhal::HwInterface(lConnectionManager.getDevice ( strBoard.toString() ));
/*
    if (pSetHtml)
        loadHtmlValues();
    else
        loadParams();

        Default(in, out);
*/
}
