#!/bin/sh
h=".h"
cc=".cc"
className=$2

headerfile=$1/$2/include/$className$h
sourcefile=$1/$2/src/common/$className$cc


echo "/* Sample Header File */"> $headerfile
cat /home/rasehgal/XDaqAppCreator/tempAddHeaderfile >> $headerfile
sed -i 's/packageName/'$2'/g' $headerfile
sed -i 's/className/'$2'/g' $headerfile
 

echo "/* Sample Source File */" > $sourcefile
cat /home/rasehgal/XDaqAppCreator/tempAddSourcefile >> $sourcefile
sed -i 's/packageName/'$2'/g' $sourcefile
sed -i 's/className/'$2'/g' $sourcefile

