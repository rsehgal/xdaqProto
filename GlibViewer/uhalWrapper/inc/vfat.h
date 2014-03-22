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

    //VFAT Registers
    uint8_t _ContReg0;
    uint8_t _ContReg1;
    uint8_t _ChipID0;
    uint8_t _ChipID1;

public:
    VFAT();
    ~VFAT();	
    VFAT(std::string fileName);
    void GotoRunMode();
    void GotoSleepMode();

    void GetChipId();
    void DetectChipId();
    void SetChipName();
    std::string GetChipName()

public:
//Core Function to fill DataMembers
    

//Member functions for users
public:
    
};

#endif // VFAT_H
