/* A Class to Store Chip Properties
** Author : Raman Sehgal
** email : raman.sehgal@cern.ch
*/
#ifndef CHIPPROP_H
#define CHIPPROP_H
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


class ChipProp
{
    int _col;
    int _row;
    std::string _name; 
    std::string _chipId;

    public:
	ChipProp();
	void SetChipId();
	void SetChipId(std::string chipId);
	void SetChipId(uint32_t chipId);
	std::string GetChipId();
	void SetChipName();
	void SetChipName(std::string name);
	std::string GetChipName();

    //Some Helper Functions
    public:
	std::string ConvertInt(int number);
};

#endif //CHIPPROP_H
