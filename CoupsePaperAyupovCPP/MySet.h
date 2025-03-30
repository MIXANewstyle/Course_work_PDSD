#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include "Node.h"

using namespace std;


class MySet {
public:
	Node* _head = nullptr;

	// объ€вление методов ...
	
	//F1
	MySet();

	//F4
	MySet(int countOfElements, int minValue, int maxValue);

	//F8
	~MySet();

	//F2
	bool IsEmpty();

	//F3
	void AddToBegin(int valueOfElem);

	//F5
	string PrintSet(string separator);

	//F6
	bool IsInSet(int valueOfElem);

	//F7
	int GetPowerOfSet();

	//F8
	void DeleteSet();

	//F9
	bool IsUnderSet(MySet underSet);

	//F10
	bool IsEqualitySets(MySet Set);

	//F11
	MySet CombiningTwoSets(MySet Set);

	//F12
	MySet IntersectionTwoSets(MySet Set);

	//F13
	MySet DifferenceTwoSets(MySet Set);

	//F14
	MySet SymmetricalDifferenceTwoSets(MySet Set);

	int GetRandomInt(int minValue, int maxValue);
};

