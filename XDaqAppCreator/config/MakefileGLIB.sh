#!/bin/sh
rm -rf outlist
LFLAGS="$CACTUSCORE/uhal/log/lib $CACTUSCORE/uhal/grammars/lib $CACTUSCORE/uhal/uhal/lib $CACTUSCORE/extern/boost/RPMBUILD/SOURCES/lib $CACTUSCORE/extern/pugixml/RPMBUILD/SOURCES/lib /home/rasehgal/XDAQ/GLIB"
echo $LFLAGS

for libpath in $LFLAGS
do
    ls $libpath/*.so >> outlist 
done

temp=""
cat outlist | while read LINE
    do
    	temp="$temp $LINE "

    	echo $temp
	echo "-----------------------------------------------------------------------------------------"
    done

echo "-------------------------------------------------------------------------"

echo $temp
