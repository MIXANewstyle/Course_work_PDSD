#pragma once
#include <iostream>
#include <chrono>
#include "MySet.h"
#include "Node.h"
#include "ListSet.h"
#include "SetSet.h"
#include "MapSet.h"
#include "MultimapSet.h"
#include "Times.h"

using namespace std;
using namespace chrono;

class MeasureStructs
{
public:
	MeasureStructs(int powerOfSetA, int powerOFSetB);
	Times* getCreateTime();
	Times* getSizeTime();
	Times* getUnderAATime();
	Times* getUnderABTime();
	Times* getEqualityAATime();
	Times* getEqualityABTime();
	Times* getCombiningTime();
	Times* getIntersectionTime();
	Times* getDifferenceTime();
	Times* get2DifferenceTime();
	Times* getSymmetricDifferenceTime();
private:
	int _powerOfSetA;
	int _powerOfSetB;

	Node* _myNodeA;
	Node* _myNodeB;

	MySet* _mySetA;
	MySet* _mySetB;

	ListSet* _listSetA;
	ListSet* _listSetB;

	SetSet* _setSetA;
	SetSet* _setSetB;

	MapSet* _mapSetA;
	MapSet* _mapSetB;

	MultimapSet* _multimapSetA;
	MultimapSet* _multimapSetB;

};

