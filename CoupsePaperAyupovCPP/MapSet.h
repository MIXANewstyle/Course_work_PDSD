#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include <map>

using namespace std;

class MapSet
{
public:
	map<int, int> mapSet;

	// описание матодов...
	MapSet();
	//F4
	MapSet(int countOfElements, int minValue, int maxValue);

	//F8
	~MapSet();

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
	bool IsUnderSet(MapSet underSet);

	//F10
	bool IsEqualitySets(MapSet Set);

	//F11
	MapSet CombiningTwoSets(MapSet Set);

	//F12
	MapSet IntersectionTwoSets(MapSet Set);

	//F13
	MapSet DifferenceTwoSets(MapSet Set);

	//F14
	MapSet SymmetricalDifferenceTwoSets(MapSet Set);

	int GetRandomInt(int minValue, int maxValue);
};



