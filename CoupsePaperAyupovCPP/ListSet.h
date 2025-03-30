#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include <list>

using namespace std;

class ListSet
{
public:
	list<int> listSet;

	// описание методов...

	ListSet();
	//F4
	ListSet(int countOfElements, int minValue, int maxValue);

	//F8
	~ListSet();

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
	bool IsUnderSet(ListSet underSet);

	//F10
	bool IsEqualitySets(ListSet Set);

	//F11
	ListSet CombiningTwoSets(ListSet Set);

	//F12
	ListSet IntersectionTwoSets(ListSet Set);

	//F13
	ListSet DifferenceTwoSets(ListSet Set);

	//F14
	ListSet SymmetricalDifferenceTwoSets(ListSet Set);

	int GetRandomInt(int minValue, int maxValue);
};

