#include "glib.h"
#include "iostream"
int main()
{
GLIB obj("file://myconnections.xml");
obj.writeTest("test_REG");
return 0;
}

