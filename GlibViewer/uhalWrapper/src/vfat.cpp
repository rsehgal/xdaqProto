#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <stdio.h>
#include <stdlib.h>

#include "vfat.h"
#include "ChipProp.h"

VFAT::VFAT(){
DetectChipId(); //It will set the ChipId for chip class
SetChipName();  //It will set the ChipName for chip class
}

VFAT::VFAT(std::string fileName){
uhalConnectionFile=filename;
std::cout<<"Connectionfile : "<<uhalConnectionFile<<std::endl;
manager=new ConnectionManager(uhalConnectionFile);
}


VFAT::~VFAT(){

}

void VFAT::GotoRunMode()
{
  HwInterface hw = manager->getDevice ( chip.GetChipName);
  _ContReg0 |= 0x01;
  hw.getNode( "ContReg0" ).write( _ContReg0 );
  hw.dispatch();
  return;
}

void VFAT::GotoSleepMode()
{
  HwInterface hw = manager->getDevice ( chip.GetChipName );
  _ContReg0 &= 0x00;
  hw.getNode( "ContReg0" ).write( _ContReg0 );
  hw.dispatch();
  return;
}

void VFAT::SetChipName(){
  chip.SetChipName();
  return;
}


void VFAT::DetectChipId()
{//returns the 24 bit value of the chipID register
  HwInterface hw = manager->getDevice ( chip.GetChipName );
  ValWord< uint32_t > tmpChipID0   = hw.getNode( "ChipID0" ).read();
  ValWord< uint32_t > tmpChipID1   = hw.getNode( "ChipID1" ).read();
  hw.dispatch();
  _ChipID0      = tmpChipID0.value();
  _ChipID1      = tmpChipID1.value();
  uint32_t chipID = 0;
  chipID = chipID<<8+_ChipID1;
  chipID = chipID<<8+_ChipID0;
  //chip._chipId = chipID;
  chip.SetChipId(chipID);
  return;
}

std::string VFAT::GetChipId()
{
  return chip.GetChipId();
}

std::string VFAT::GetChipName(){
  return chip.GetChipName();
}

