/* Sample Header File */
#ifndef _myPPackage_myPPackage_h_
#define _myPPackage_myPPackage_h_

#include "xdaq/Application.h"
#include "xgi/Method.h"
#include "xgi/Utils.h"
#include "xdata/String.h"
#include "xdata/UnsignedLong.h"

namespace myPPackage {
class myPPackage: public xdaq::Application
{
  protected:
    //Define your data members here

  public:

    XDAQ_INSTANTIATOR();

    myPPackage(xdaq::ApplicationStub * s)
      throw (xdaq::exception::Exception);

    //Default function to execute on application loading
    void Default(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception); 
    
    //Other function for the application  
    void Test(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception);


};
}

#endif
