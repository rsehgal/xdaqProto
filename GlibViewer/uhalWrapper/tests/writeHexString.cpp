#include "glib.h"
#include "iostream"
#include "sstream"
int main(int argc , char *argv[])
{
GLIB obj("file://myconnections.xml");
int val=obj.HexStringToInt(argv[1]);
obj.writeTest("test_REG",val);
return 0;
}

