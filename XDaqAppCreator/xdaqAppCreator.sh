#!/bin/sh
mkdir -p $1/$2/include/$2
mkdir -p $1/$2/src/common
mkdir -p $1/$2/xml
h=".h"
cc=".cc"
xmlfile=$1/$2/xml/$2.xml
className=$2
platform=$XDAQ_PLATFORM
libdir=$PWD/$1/$2/lib
headerfile=$1/$2/include/$2/$className$h
sourcefile=$1/$2/src/common/$className$cc
srcdir=$SRCDIR
echo "#Sample Make File" > $1/$2/Makefile
sed 's/projectName/'$1'/g' $srcdir/MakefileTemp >> $1/$2/Makefile
sed 's/className/'$2'/g' $1/$2/Makefile > Makefile.2
mv Makefile.2 $1/$2/Makefile
sed -i 's/packageName/'$2'/g' $1/$2/Makefile

echo "/* Sample Header File */"> $headerfile
cat $srcdir/tempHeaderfile >> $headerfile
sed -i 's/packageName/'$2'/g' $headerfile
sed -i 's/className/'$2'/g' $headerfile
 
echo "/* Sample version File */" > $1/$2/include/$2/version$h
echo "/* Sample Version Source File */" > $1/$2/src/common/version$cc

echo "/* Sample Source File */" > $sourcefile
cat $srcdir/tempSourcefile >> $sourcefile
sed -i 's/packageName/'$2'/g' $sourcefile
sed -i 's/className/'$2'/g' $sourcefile

echo "<!-- Sample Xml file -->" > $xmlfile
cat $srcdir/tempXML.xml >> $xmlfile
sed -i 's/packageName/'$2'/g' $xmlfile
sed -i 's/className/'$2'/g' $xmlfile
sed -i 's/platform/'$platform'/g' $xmlfile
sed -i 's#libdir#'$libdir'#g' $xmlfile


#copying necessary config files required to build XDAQ app
cp -rf $srcdir/config .
