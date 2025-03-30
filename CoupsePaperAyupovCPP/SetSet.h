#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include <set>

using namespace std;

class SetSet
{
public:
	set<int> setSet;

	// описание методов...
	SetSet();
	//F4
	SetSet(int countOfElements, int minValue, int maxValue);

	//F8
	~SetSet();

	//F2
	bool IsEmpty();

	//F3
	bool AddToBegin(int valueOfElem);

	//F5
	string PrintSet(string separator);

	//F6
	bool IsInSet(int valueOfElem);

	//F7
	int GetPowerOfSet();

	//F8
	void DeleteSet();

	//F9
	bool IsUnderSet(SetSet underSet);

	//F10
	bool IsEqualitySets(SetSet Set);

	//F11
	SetSet CombiningTwoSets(SetSet Set);

	//F12
	SetSet IntersectionTwoSets(SetSet Set);

	//F13
	SetSet DifferenceTwoSets(SetSet Set);

	//F14
	SetSet SymmetricalDifferenceTwoSets(SetSet Set);

	int GetRandomInt(int minValue, int maxValue);
};

