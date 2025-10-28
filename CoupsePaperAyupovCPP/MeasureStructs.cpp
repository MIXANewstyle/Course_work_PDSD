#include "MeasureStructs.h"

MeasureStructs::MeasureStructs(int powerOfSetA, int powerOfSetB) {
	_powerOfSetA = powerOfSetA;
	_powerOfSetB = powerOfSetB;
}

Times* MeasureStructs::getCreateTime() {
	auto start = high_resolution_clock::now();
	_myNodeA = createNewSet(_powerOfSetA, 0, 999);
	auto end = high_resolution_clock::now();
	auto nodeTime = duration_cast<microseconds>(end - start);
	
	start = high_resolution_clock::now();
	_mySetA = new MySet(_powerOfSetA, 0, 999);
	end = high_resolution_clock::now();
	auto mySetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_listSetA = new ListSet(_powerOfSetA, 0, 999);
	end = high_resolution_clock::now();
	auto listSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_setSetA = new SetSet(_powerOfSetA, 0, 999);
	end = high_resolution_clock::now();
	auto setSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mapSetA = new MapSet(_powerOfSetA, 0, 999);
	end = high_resolution_clock::now();
	auto mapSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_multimapSetA = new MultimapSet(_powerOfSetA, 0, 999);
	end = high_resolution_clock::now();
	auto multimapSetTime = duration_cast<microseconds>(end - start);

	_myNodeB = createNewSet(_powerOfSetB, 0, 999);
	_mySetB = new MySet(_powerOfSetB, 0, 999);
	_listSetB = new ListSet(_powerOfSetB, 0, 999);
	_setSetB = new SetSet(_powerOfSetB, 0, 999);
	_mapSetB = new MapSet(_powerOfSetB, 0, 999);
	_multimapSetB = new MultimapSet(_powerOfSetB, 0, 999);

	return new Times(nodeTime, mySetTime, listSetTime, setSetTime, mapSetTime, multimapSetTime);
}
Times* MeasureStructs::getSizeTime() {
	auto start = high_resolution_clock::now();
	getPowerOfSet(_myNodeA);
	auto end = high_resolution_clock::now();
	auto nodeTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mySetA->GetPowerOfSet();
	end = high_resolution_clock::now();
	auto mySetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_listSetA->GetPowerOfSet();
	end = high_resolution_clock::now();
	auto listSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_setSetA->GetPowerOfSet();
	end = high_resolution_clock::now();
	auto setSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mapSetA->GetPowerOfSet();
	end = high_resolution_clock::now();
	auto mapSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_multimapSetA->GetPowerOfSet();
	end = high_resolution_clock::now();
	auto multimapSetTime = duration_cast<microseconds>(end - start);

	return new Times(nodeTime, mySetTime, listSetTime, setSetTime, mapSetTime, multimapSetTime);
}
Times* MeasureStructs::getUnderAATime() {
	auto start = high_resolution_clock::now();
	isUnderSet(_myNodeA, _myNodeA);
	auto end = high_resolution_clock::now();
	auto nodeTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mySetA->IsUnderSet(*_mySetA);
	end = high_resolution_clock::now();
	auto mySetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_listSetA->IsUnderSet(*_listSetA);
	end = high_resolution_clock::now();
	auto listSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_setSetA->IsUnderSet(*_setSetA);
	end = high_resolution_clock::now();
	auto setSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mapSetA->IsUnderSet(*_mapSetA);
	end = high_resolution_clock::now();
	auto mapSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_multimapSetA->IsUnderSet(*_multimapSetA);
	end = high_resolution_clock::now();
	auto multimapSetTime = duration_cast<microseconds>(end - start);

	return new Times(nodeTime, mySetTime, listSetTime, setSetTime, mapSetTime, multimapSetTime);
}
Times* MeasureStructs::getUnderABTime() {
	auto start = high_resolution_clock::now();
	isUnderSet(_myNodeA, _myNodeB);
	auto end = high_resolution_clock::now();
	auto nodeTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mySetA->IsUnderSet(*_mySetB);
	end = high_resolution_clock::now();
	auto mySetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_listSetA->IsUnderSet(*_listSetB);
	end = high_resolution_clock::now();
	auto listSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_setSetA->IsUnderSet(*_setSetB);
	end = high_resolution_clock::now();
	auto setSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mapSetA->IsUnderSet(*_mapSetB);
	end = high_resolution_clock::now();
	auto mapSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_multimapSetA->IsUnderSet(*_multimapSetB);
	end = high_resolution_clock::now();
	auto multimapSetTime = duration_cast<microseconds>(end - start);

	return new Times(nodeTime, mySetTime, listSetTime, setSetTime, mapSetTime, multimapSetTime);
}
Times* MeasureStructs::getEqualityAATime() {
	auto start = high_resolution_clock::now();
	isEqualitySets(_myNodeA, _myNodeA);
	auto end = high_resolution_clock::now();
	auto nodeTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mySetA->IsEqualitySets(*_mySetA);
	end = high_resolution_clock::now();
	auto mySetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_listSetA->IsEqualitySets(*_listSetA);
	end = high_resolution_clock::now();
	auto listSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_setSetA->IsEqualitySets(*_setSetA);
	end = high_resolution_clock::now();
	auto setSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mapSetA->IsEqualitySets(*_mapSetA);
	end = high_resolution_clock::now();
	auto mapSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_multimapSetA->IsEqualitySets(*_multimapSetA);
	end = high_resolution_clock::now();
	auto multimapSetTime = duration_cast<microseconds>(end - start);

	return new Times(nodeTime, mySetTime, listSetTime, setSetTime, mapSetTime, multimapSetTime);
}
Times* MeasureStructs::getEqualityABTime() {
	auto start = high_resolution_clock::now();
	isEqualitySets(_myNodeA, _myNodeB);
	auto end = high_resolution_clock::now();
	auto nodeTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mySetA->IsEqualitySets(*_mySetB);
	end = high_resolution_clock::now();
	auto mySetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_listSetA->IsEqualitySets(*_listSetB);
	end = high_resolution_clock::now();
	auto listSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_setSetA->IsEqualitySets(*_setSetB);
	end = high_resolution_clock::now();
	auto setSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mapSetA->IsEqualitySets(*_mapSetB);
	end = high_resolution_clock::now();
	auto mapSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_multimapSetA->IsEqualitySets(*_multimapSetB);
	end = high_resolution_clock::now();
	auto multimapSetTime = duration_cast<microseconds>(end - start);

	return new Times(nodeTime, mySetTime, listSetTime, setSetTime, mapSetTime, multimapSetTime);
}
Times* MeasureStructs::getCombiningTime() {
	auto start = high_resolution_clock::now();
	combiningTwoSets(_myNodeA, _myNodeB);
	auto end = high_resolution_clock::now();
	auto nodeTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mySetA->CombiningTwoSets(*_mySetB);
	end = high_resolution_clock::now();
	auto mySetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_listSetA->CombiningTwoSets(*_listSetB);
	end = high_resolution_clock::now();
	auto listSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_setSetA->CombiningTwoSets(*_setSetB);
	end = high_resolution_clock::now();
	auto setSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mapSetA->CombiningTwoSets(*_mapSetB);
	end = high_resolution_clock::now();
	auto mapSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_multimapSetA->CombiningTwoSets(*_multimapSetB);
	end = high_resolution_clock::now();
	auto multimapSetTime = duration_cast<microseconds>(end - start);

	return new Times(nodeTime, mySetTime, listSetTime, setSetTime, mapSetTime, multimapSetTime);
}
Times* MeasureStructs::getIntersectionTime() {
	auto start = high_resolution_clock::now();
	intersectionTwoSets(_myNodeA, _myNodeB);
	auto end = high_resolution_clock::now();
	auto nodeTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mySetA->IntersectionTwoSets(*_mySetB);
	end = high_resolution_clock::now();
	auto mySetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_listSetA->IntersectionTwoSets(*_listSetB);
	end = high_resolution_clock::now();
	auto listSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_setSetA->IntersectionTwoSets(*_setSetB);
	end = high_resolution_clock::now();
	auto setSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mapSetA->IntersectionTwoSets(*_mapSetB);
	end = high_resolution_clock::now();
	auto mapSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_multimapSetA->IntersectionTwoSets(*_multimapSetB);
	end = high_resolution_clock::now();
	auto multimapSetTime = duration_cast<microseconds>(end - start);

	return new Times(nodeTime, mySetTime, listSetTime, setSetTime, mapSetTime, multimapSetTime);
}
Times* MeasureStructs::getDifferenceTime() {
	auto start = high_resolution_clock::now();
	differenceTwoSets(_myNodeA, _myNodeB);
	auto end = high_resolution_clock::now();
	auto nodeTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mySetA->DifferenceTwoSets(*_mySetB);
	end = high_resolution_clock::now();
	auto mySetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_listSetA->DifferenceTwoSets(*_listSetB);
	end = high_resolution_clock::now();
	auto listSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_setSetA->DifferenceTwoSets(*_setSetB);
	end = high_resolution_clock::now();
	auto setSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mapSetA->DifferenceTwoSets(*_mapSetB);
	end = high_resolution_clock::now();
	auto mapSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_multimapSetA->DifferenceTwoSets(*_multimapSetB);
	end = high_resolution_clock::now();
	auto multimapSetTime = duration_cast<microseconds>(end - start);

	return new Times(nodeTime, mySetTime, listSetTime, setSetTime, mapSetTime, multimapSetTime);
}

Times* MeasureStructs::get2DifferenceTime() {
	auto start = high_resolution_clock::now();
	differenceTwoSets(_myNodeB, _myNodeA);
	auto end = high_resolution_clock::now();
	auto nodeTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mySetB->DifferenceTwoSets(*_mySetA);
	end = high_resolution_clock::now();
	auto mySetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_listSetB->DifferenceTwoSets(*_listSetA);
	end = high_resolution_clock::now();
	auto listSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_setSetB->DifferenceTwoSets(*_setSetA);
	end = high_resolution_clock::now();
	auto setSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mapSetB->DifferenceTwoSets(*_mapSetA);
	end = high_resolution_clock::now();
	auto mapSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_multimapSetB->DifferenceTwoSets(*_multimapSetA);
	end = high_resolution_clock::now();
	auto multimapSetTime = duration_cast<microseconds>(end - start);

	return new Times(nodeTime, mySetTime, listSetTime, setSetTime, mapSetTime, multimapSetTime);
}
Times* MeasureStructs::getSymmetricDifferenceTime() {
	auto start = high_resolution_clock::now();
	symmetricalDifferenceTwoSets(_myNodeA, _myNodeB);
	auto end = high_resolution_clock::now();
	auto nodeTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mySetA->SymmetricalDifferenceTwoSets(*_mySetB);
	end = high_resolution_clock::now();
	auto mySetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_listSetA->SymmetricalDifferenceTwoSets(*_listSetB);
	end = high_resolution_clock::now();
	auto listSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_setSetA->SymmetricalDifferenceTwoSets(*_setSetB);
	end = high_resolution_clock::now();
	auto setSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_mapSetA->SymmetricalDifferenceTwoSets(*_mapSetB);
	end = high_resolution_clock::now();
	auto mapSetTime = duration_cast<microseconds>(end - start);

	start = high_resolution_clock::now();
	_multimapSetA->SymmetricalDifferenceTwoSets(*_multimapSetB);
	end = high_resolution_clock::now();
	auto multimapSetTime = duration_cast<microseconds>(end - start);

	return new Times(nodeTime, mySetTime, listSetTime, setSetTime, mapSetTime, multimapSetTime);
}