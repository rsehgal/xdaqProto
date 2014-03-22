#ifndef VFAT_H
#define VFAT_H


#include <string>

//taken from mytest.cxx
#include "uhal/uhal.hpp"
//#include "../uhal/tests/tools.hpp"
//#include <boost/filesystem.hpp>

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace uhal;

class VFAT
{
    ConnectionManager *manager;
    std::string uhalConnectionFile;	
    ChipProp chip;

public:
    VFAT();
    ~VFAT();	
    VFAT(std::string fileName);

public:
//Core Function to fill DataMembers
    

//Member functions for users
public:
    
};

#endif // VFAT_H
