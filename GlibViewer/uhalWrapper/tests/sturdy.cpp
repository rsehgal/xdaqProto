#include <iostream>
#include "uhal/uhal.hpp"

using namespace uhal;

int main()
{
  try
  {
    //setLogLevelTo(uhal::Debug());  // Maximise uHAL logging



    setLogLevelTo(uhal::Error());  // Minimise uHAL logging




    ConnectionManager connectionManager(
"file://myconnections.xml;" );

    HwInterface hw = connectionManager.getDevice("dummy.udp.0");

    ValWord< uint32_t > reg = hw.getNode ( "system_REG_1" ).read();
    hw.dispatch();
    std::cout << "system_REG_1 = " << reg.value() << std::endl;
  }
  catch ( const std::exception& e )
  {
                std::cout << "Something went wrong: " << e.what() <<
std::endl;
  }
  return 0;
}
