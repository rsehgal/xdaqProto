
/* Sample Header File */
#ifndef _GlibViewer_GlibViewer_h_
#define _GlibViewer_GlibViewer_h_

#include "xdaq/Application.h"
#include "xgi/Method.h"
#include "xgi/Utils.h"
#include "xdata/String.h"
#include "xdata/UnsignedLong.h"
#include "glib.h"

namespace GlibViewer {
class GlibViewer: public xdaq::Application
{
  protected:
    //Define your data members here

  public:

    XDAQ_INSTANTIATOR();

	xdata::String strBoard;
        uhal::HwInterface *hwBoard;


    GlibViewer(xdaq::ApplicationStub * s) throw (xdaq::exception::Exception);

    //Default function to execute on application loading
    void Default(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception); 
    
    //Other function for the application  
    void Test(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception);
    void BasicGLIBInfo(xgi::Input * in, xgi::Output * out) throw (xgi::exception::Exception);
    void showRegisTable(xgi::Input * in, xgi::Output * out) throw (xgi::exception::Exception);
//    void status(xgi::Input * in, xgi::Output * out )throw (xgi::exception::Exception);
//    void GetValues(xgi::Input * in, xgi::Output * out )throw (xgi::exception::Exception);	
    void insertBoards(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception);		
     void ChangeBoard(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception);
     void NodesInfo(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception);

private:
	void loadHtmlValues();




};
}

#endif
