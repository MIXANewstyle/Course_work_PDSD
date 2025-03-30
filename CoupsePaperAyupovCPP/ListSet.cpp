#include "ListSet.h"

ListSet::ListSet() {

}
//F4
ListSet::ListSet(int countOfElements, int minValue, int maxValue) {
	int i = 0;
	while (i < countOfElements) {
		if (AddToBegin(GetRandomInt(minValue, maxValue))) i++;
	}
}

//F8
ListSet::~ListSet() {

}

//F2
bool ListSet::IsEmpty() {
	return listSet.empty();
}

//F3
bool ListSet::AddToBegin(int valueOfElem) {
	if (IsInSet(valueOfElem)) return false;
	listSet.push_front(valueOfElem);
	return true;
}

//F5
string ListSet::PrintSet(string separator) {
	stringstream streamStr;
	for(int elem : listSet){
		streamStr << elem;
		streamStr << separator;
	}
	string result = streamStr.str();
	result.pop_back();
	return result;
}

//F6
bool ListSet::IsInSet(int valueOfElem) {
	for (int elem : listSet) {
		if (elem == valueOfElem) return true;
	}
	return false;
}

//F7
int ListSet::GetPowerOfSet() {
	return listSet.size();
}

//F8
void ListSet::DeleteSet() {
	return listSet.~list();
}

//F9
bool ListSet::IsUnderSet(ListSet underSet) {
	for (int elem : listSet) {
		if (!underSet.IsInSet(elem)) return false;
	}
	return true;
}

//F10
bool ListSet::IsEqualitySets(ListSet Set) {
	return IsUnderSet(Set) && Set.IsUnderSet(*this);
}

//F11
ListSet ListSet::CombiningTwoSets(ListSet Set) { 
	ListSet result;

	for (int elem : listSet) result.AddToBegin(elem);
	for (int elem : Set.listSet) result.AddToBegin(elem);

	return result;
}

//F12
ListSet ListSet::IntersectionTwoSets(ListSet Set) { 
	ListSet result;

	for (int elem : listSet) if (Set.IsInSet(elem)) result.AddToBegin(elem);
	
	return result;
}

//F13
ListSet ListSet::DifferenceTwoSets(ListSet Set) { 
	ListSet result;

	for(int elem : listSet){
		if (!Set.IsInSet(elem)) {
			result.AddToBegin(elem);
		}
	}

	return result;
}

//F14
ListSet ListSet::SymmetricalDifferenceTwoSets(ListSet Set) {
	return DifferenceTwoSets(Set).CombiningTwoSets(Set.DifferenceTwoSets(*this));
}

int ListSet::GetRandomInt(int minValue, int maxValue) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(minValue, maxValue);
	int randomValue = dist(gen);
	return randomValue;
}