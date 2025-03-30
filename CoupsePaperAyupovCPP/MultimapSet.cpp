#include "MultimapSet.h"

MultimapSet::MultimapSet() {

}
//F4
MultimapSet::MultimapSet(int countOfElements, int minValue, int maxValue) {
	int i = 0;
	while (i < countOfElements) {
		if (AddToBegin(GetRandomInt(minValue, maxValue))) i++;
	}
}

//F8
MultimapSet::~MultimapSet() {

}

//F2
bool MultimapSet::IsEmpty() {
	return multimapSet.empty();
}

//F3
bool MultimapSet::AddToBegin(int valueOfElem) {
	if (IsInSet(valueOfElem)) return false;
	multimapSet.insert({ valueOfElem, 0 });
	return true;
}

//F5
string MultimapSet::PrintSet(string separator) {
	stringstream streamStr;
	for (auto elem : multimapSet) {
		streamStr << elem.first;
		streamStr << separator;
	}
	string result = streamStr.str();
	result.pop_back();
	return result;
}

//F6
bool MultimapSet::IsInSet(int valueOfElem) {
	return multimapSet.find(valueOfElem) != multimapSet.end();
}

//F7
int MultimapSet::GetPowerOfSet() {
	return multimapSet.size();
}

//F8
void MultimapSet::DeleteSet() {
	return multimapSet.~multimap();
}

//F9
bool MultimapSet::IsUnderSet(MultimapSet underSet) {
	for (auto elem : multimapSet) {
		if (!underSet.IsInSet(elem.first)) return false;
	}
	return true;
}

//F10
bool MultimapSet::IsEqualitySets(MultimapSet Set) {
	return IsUnderSet(Set) && Set.IsUnderSet(*this);
}

//F11
MultimapSet MultimapSet::CombiningTwoSets(MultimapSet Set) {
	MultimapSet result;

	for (auto elem : multimapSet) result.AddToBegin(elem.first);
	for (auto elem : Set.multimapSet) result.AddToBegin(elem.first);

	return result;
}

//F12
MultimapSet MultimapSet::IntersectionTwoSets(MultimapSet Set) {
	MultimapSet result;

	for (auto elem : multimapSet) if (Set.IsInSet(elem.first)) result.AddToBegin(elem.first);

	return result;
}

//F13
MultimapSet MultimapSet::DifferenceTwoSets(MultimapSet Set) {
	MultimapSet result;

	for (auto elem : multimapSet) {
		if (!Set.IsInSet(elem.first)) {
			result.AddToBegin(elem.first);
		}
	}

	return result;
}

//F14
MultimapSet MultimapSet::SymmetricalDifferenceTwoSets(MultimapSet Set) {
	return DifferenceTwoSets(Set).CombiningTwoSets(Set.DifferenceTwoSets(*this));
}

int MultimapSet::GetRandomInt(int minValue, int maxValue) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(minValue, maxValue);
	int randomValue = dist(gen);
	return randomValue;
}