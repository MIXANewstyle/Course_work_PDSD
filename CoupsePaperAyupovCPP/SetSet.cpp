#include "SetSet.h"

SetSet::SetSet() {

}
//F4
SetSet::SetSet(int countOfElements, int minValue, int maxValue) {
	int i = 0;
	while (i < countOfElements) {
		if (AddToBegin(GetRandomInt(minValue, maxValue))) i++;
	}
}

//F8
SetSet::~SetSet() {

}

//F2
bool SetSet::IsEmpty() {
	return setSet.empty();
}

//F3
bool SetSet::AddToBegin(int valueOfElem) {
	if (IsInSet(valueOfElem)) return false;
	setSet.insert(valueOfElem);
	return true;
}

//F5
string SetSet::PrintSet(string separator) {
	stringstream streamStr;
	for (int elem : setSet) {
		streamStr << elem;
		streamStr << separator;
	}
	string result = streamStr.str();
	result.pop_back();
	return result;
}

//F6
bool SetSet::IsInSet(int valueOfElem) {
	if (setSet.find(valueOfElem) != setSet.end()) return true;
	return false;
}

//F7
int SetSet::GetPowerOfSet() {
	return setSet.size();
}

//F8
void SetSet::DeleteSet() {
	return setSet.~set();
}

//F9
bool SetSet::IsUnderSet(SetSet underSet) {
	for (int elem : setSet) {
		if (!underSet.IsInSet(elem)) return false;
	}
	return true;
}

//F10
bool SetSet::IsEqualitySets(SetSet Set) {
	return IsUnderSet(Set) && Set.IsUnderSet(*this);
}

//F11
SetSet SetSet::CombiningTwoSets(SetSet Set) {
	SetSet result;

	for (int elem : setSet) result.AddToBegin(elem);
	for (int elem : Set.setSet) result.AddToBegin(elem);

	return result;
}

//F12
SetSet SetSet::IntersectionTwoSets(SetSet Set) {
	SetSet result;

	for (int elem : setSet) if (Set.IsInSet(elem)) result.AddToBegin(elem);

	return result;
}

//F13
SetSet SetSet::DifferenceTwoSets(SetSet Set) {
	SetSet result;

	for (int elem : setSet) {
		if (!Set.IsInSet(elem)) {
			result.AddToBegin(elem);
		}
	}

	return result;
}

//F14
SetSet SetSet::SymmetricalDifferenceTwoSets(SetSet Set) {
	return DifferenceTwoSets(Set).CombiningTwoSets(Set.DifferenceTwoSets(*this));
}

int SetSet::GetRandomInt(int minValue, int maxValue) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(minValue, maxValue);
	int randomValue = dist(gen);
	return randomValue;
}