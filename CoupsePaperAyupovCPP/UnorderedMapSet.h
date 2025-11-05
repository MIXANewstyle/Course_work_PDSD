#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include <unordered_map> 
#include <map>

using namespace std;

class UnorderedMapSet
{
public:
	// Используем unordered_map.
	// Ключ (int) - это элемент.
	// Значение (int) - это "заглушка"


	unordered_map<int, int> unorderedMapSet;


	// --- Описания методов 
	UnorderedMapSet();
	//F4
	UnorderedMapSet(int countOfElements, int minValue, int maxValue);

	//F8
	~UnorderedMapSet();

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
	bool IsUnderSet(UnorderedMapSet underSet);

	//F10
	bool IsEqualitySets(UnorderedMapSet Set);

	//F11
	UnorderedMapSet CombiningTwoSets(UnorderedMapSet Set);

	//F12
	UnorderedMapSet IntersectionTwoSets(UnorderedMapSet Set);

	//F13
	UnorderedMapSet DifferenceTwoSets(UnorderedMapSet Set);

	//F14
	UnorderedMapSet SymmetricalDifferenceTwoSets(UnorderedMapSet Set);

	int GetRandomInt(int minValue, int maxValue);
};