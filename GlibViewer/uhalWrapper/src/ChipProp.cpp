#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <typeinfo>
#include <stdio.h>
#include <stdlib.h>


#include "ChipProp.h"

ChipProp::ChipProp(){
_col=0;_row=0;
_name="chip_";

}

void ChipProp::SetChipId(){

}


void ChipProp::SetChipId(std::string chipId){
_chipId=chipId;
}

void SetChipId(uint32_t chipId){
_chipId=ConvertInt(chipId);
}

std::string ChipProp::GetChipId(){
return _chipId;
}

void ChipProp::SetChipName(){
_name.append(ConvertInt(_col));
_name.append("_");
_name.append(ConvertInt(_row));

}

void ChipProp::SetChipName(std::string name){
_name=name;
}

std::string ChipProp::GetChipName(){
return _name;
}


std::string ChipProp::ConvertInt(int number)
{
   stringstream ss;
   ss << number;
   return ss.str();
}
