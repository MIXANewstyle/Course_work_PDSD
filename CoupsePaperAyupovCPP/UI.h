#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib> 
#include "MeasureStructs.h"

using namespace std;
#pragma once
class UI
{
public:
	void run();
private:
	bool _programEnd = false;
	int _powerOfNode;
	int _powerOfMySet;
	int _powerOfList;
	int _powerOfSet;
	int _powerOfMap;
	int _powerOfMultimap;
	void showTable();
	void showMenu();
	void enterPowerOfSets();
	void createSets();
	void clearConsole();
};

