#pragma once
#include <string>
#include <sstream>]
#include <random>

using namespace std;

struct Node
{
	int val;
	Node* next = nullptr;
	Node(int _val) : val(_val), next(nullptr) {}
};

Node* createEmptySet();

//F2
bool isEmpty(Node* elem);

//F3
Node* addToBegin(Node* firstElem, int valueOfElem);

//F4
Node* createNewSet(int countOfElements, int minValue, int maxValue);

//F5
string printSet(Node* firstElem, string separator);

//F6
bool isInSet(Node* firstElem, int valueOfElem);

//F7
int getPowerOfSet(Node* firstElem);

int getRandomInt(int minValue, int maxValue);

//F8
Node* deleteSet(Node* firstElem);

//F9
bool isUnderSet(Node* underSet, Node* set);

//F10
bool isEqualitySets(Node* firstElemA, Node* firstElemB);

//F11
Node* combiningTwoSets(Node* firstElemA, Node* firstElemB);

//F12
Node* intersectionTwoSets(Node* firstElemA, Node* firstElemB);

//F13
Node* differenceTwoSets(Node* firstElemA, Node* firstElemB);

//F14
Node* symmetricalDifferenceTwoSets(Node* firstElemA, Node* firstElemB);