#pragma once
#include <iostream>
#include "MySet.h"
#include "Node.h"
#include "ListSet.h"
#include "SetSet.h"
#include "MapSet.h"
#include "MultimapSet.h"

using namespace std; 

class MeasureStructs
{
public:
	MeasureStructs(int powerOfNode, int powerOfMySet, int powerOfList, int powerOfSet, int powerOfMap, int powerOfMultimap);
	int measureCreateTime();
	int measureSizeTime();
	int measureSubsetAATime();
	int measureSubsetABTime();
	int measureEqualityAATime();
	int measureEqualityABTime();
	int measureCombiningTime();
	int measureIntersectionTime();
	int measureDifferenceTime();
	int measureSymmetricDifferenceTime();

private:

	Node* _myNodeA;
	Node* _myNodeB;

	MySet _mySetA;
	MySet _mySetB;

	ListSet _listSetA;
	ListSet _listSetB;

	SetSet _setSetA;
	SetSet _setSetB;

	MapSet _mapSetA;
	MapSet _mapSetB;

	MultimapSet _multimapSetA;
	MultimapSet _multimapSetB;

};

