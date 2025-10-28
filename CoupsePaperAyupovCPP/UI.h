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
	int _powerOfSetA;
	int _powerOfSetB;
	void showTable();
	void enterPowerOfSets();
	void clearConsole();
};

