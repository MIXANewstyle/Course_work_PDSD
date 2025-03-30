#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include <map>

using namespace std;

class MultimapSet
{
public:
	multimap<int, int> multimapSet;

	// описание методов...
	MultimapSet();
	//F4
	MultimapSet(int countOfElements, int minValue, int maxValue);

	//F8
	~MultimapSet();

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
	bool IsUnderSet(MultimapSet underSet);

	//F10
	bool IsEqualitySets(MultimapSet Set);

	//F11
	MultimapSet CombiningTwoSets(MultimapSet Set);

	//F12
	MultimapSet IntersectionTwoSets(MultimapSet Set);

	//F13
	MultimapSet DifferenceTwoSets(MultimapSet Set);

	//F14
	MultimapSet SymmetricalDifferenceTwoSets(MultimapSet Set);

	int GetRandomInt(int minValue, int maxValue);
};




