#include "MapSet.h"


MapSet::MapSet() {

}
//F4
MapSet::MapSet(int countOfElements, int minValue, int maxValue) {
	int i = 0;
	while (i < countOfElements) {
		if (AddToBegin(GetRandomInt(minValue, maxValue))) i++;
	}
}

//F8
MapSet::~MapSet() {

}

//F2
bool MapSet::IsEmpty() {
	return mapSet.empty();
}

//F3
bool MapSet::AddToBegin(int valueOfElem) {
	if (IsInSet(valueOfElem)) return false;
	mapSet[valueOfElem] = 0;
	return true;
}

//F5
string MapSet::PrintSet(string separator) {
	stringstream streamStr;
	for (auto elem : mapSet) {
		streamStr << elem.first;
		streamStr << separator;
	}
	string result = streamStr.str();
	result.pop_back();
	return result;
}

//F6
bool MapSet::IsInSet(int valueOfElem) {
	return mapSet.find(valueOfElem) != mapSet.end();
}

//F7
int MapSet::GetPowerOfSet() {
	return mapSet.size();
}

//F8
void MapSet::DeleteSet() {
	return mapSet.~map();
}

//F9
bool MapSet::IsUnderSet(MapSet underSet) {
	for (auto elem : mapSet) {
		if (!underSet.IsInSet(elem.first)) return false;
	}
	return true;
}

//F10
bool MapSet::IsEqualitySets(MapSet Set) {
	return IsUnderSet(Set) && Set.IsUnderSet(*this);
}

//F11
MapSet MapSet::CombiningTwoSets(MapSet Set) {
	MapSet result;

	for (auto elem : mapSet) result.AddToBegin(elem.first);
	for (auto elem : Set.mapSet) result.AddToBegin(elem.first);

	return result;
}

//F12
MapSet MapSet::IntersectionTwoSets(MapSet Set) {
	MapSet result;

	for (auto elem : mapSet) if (Set.IsInSet(elem.first)) result.AddToBegin(elem.first);

	return result;
}

//F13
MapSet MapSet::DifferenceTwoSets(MapSet Set) {
	MapSet result;

	for (auto elem : mapSet) {
		if (!Set.IsInSet(elem.first)) {
			result.AddToBegin(elem.first);
		}
	}

	return result;
}

//F14
MapSet MapSet::SymmetricalDifferenceTwoSets(MapSet Set) {
	return DifferenceTwoSets(Set).CombiningTwoSets(Set.DifferenceTwoSets(*this));
}

int MapSet::GetRandomInt(int minValue, int maxValue) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(minValue, maxValue);
	int randomValue = dist(gen);
	return randomValue;
}