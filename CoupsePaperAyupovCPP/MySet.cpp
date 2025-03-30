#include "MySet.h"

//F1
MySet::MySet() {
	_head = nullptr;
}

//F4
MySet::MySet(int countOfElements, int minValue, int maxValue) {
	int randomInt = GetRandomInt(minValue, maxValue);
	_head = new Node(randomInt);

	int i = 0;
	while (i < countOfElements)
	{
		Node* oldHead = _head;
		this->AddToBegin(GetRandomInt(minValue, maxValue));
		if (oldHead != _head) {
			i++;
		}
	}
}

MySet::~MySet() {
	int count = GetPowerOfSet();
	Node* current = _head;

	while (current != nullptr) {
		Node* next = current->next;
		current = nullptr;
		current = next;
	}
}

//F2
bool MySet::IsEmpty()
{
	return _head == nullptr;
}

//F3
void MySet::AddToBegin(int valueOfElem)
{
	if (IsInSet(valueOfElem)) {
		return;
	}
	Node* newElem = new Node(valueOfElem);
	newElem->next = _head;
	_head = newElem;
}

//F5
string MySet::PrintSet(string separator)
{
	if (!IsEmpty()) {
		stringstream streamStr;
		Node* current = _head;

		while (current != nullptr)
		{
			streamStr << current->val;
			streamStr << separator;
			current = current->next;
		}
		string result = streamStr.str();
		result.pop_back();
		return result;
	}
	return "Множество пустое!";
}

//F6
bool MySet::IsInSet(int valueOfElem)
{
	Node* current = _head;

	if (this->IsEmpty()) { return false; }

	do
	{
		if (valueOfElem != current->val)
		{
			current = current->next;
		}
		else { return true; }

	} while (current != nullptr);

	return false;
}

//F7
int MySet::GetPowerOfSet()
{
	int value = 0;
	Node* current = _head;

	if (IsEmpty()) { return value; }

	do
	{
		value++;
		current = current->next;

	} while (current != nullptr);

	return value;
}

int MySet::GetRandomInt(int minValue, int maxValue) {
	random_device rd;  
	mt19937 gen(rd());  
	uniform_int_distribution<> dist(minValue, maxValue); 
	int randomValue = dist(gen);
	return randomValue;
}

//F8
void MySet::DeleteSet()
{
	int count = GetPowerOfSet();

	while (_head != nullptr) {
		Node* next = _head->next;
		_head = nullptr;
		_head = next;
	}
}

//F9
bool MySet::IsUnderSet(MySet underSet)
{
	Node* current = underSet._head;
	if (underSet.IsEmpty()) return true;
	if (current == _head) return true;

	Node* currentUnder = current;
	do
	{
		if (IsInSet(currentUnder->val)) {
			currentUnder = currentUnder->next;
		}
		else return false;

	} while (currentUnder->next != nullptr);

	return true;
}

//F10
bool MySet::IsEqualitySets(MySet Set)
{
	return this->IsUnderSet(Set) && Set.IsUnderSet(*this);
}

//F11
MySet MySet::CombiningTwoSets(MySet Set)
{
	MySet result; // Óêàçàòåëü íà ðåçóëüòèðóþùèé ñïèñîê
	Node* firstElemA = Set._head;

	while (firstElemA)
	{
		result.AddToBegin(firstElemA->val);
		firstElemA = firstElemA->next;
	}

	Node* current = this->_head;
	while (current)
	{
		result.AddToBegin(current->val);
		current = current->next;
	}

	return result;
}

//F12
MySet MySet::IntersectionTwoSets(MySet Set)
{
	MySet result;

	Node* current = Set._head;
	while (current) {

		if (IsInSet(current->val)) result.AddToBegin(current->val);

		current = current->next;
	}

	return result;
}

//F13
MySet MySet::DifferenceTwoSets(MySet Set)
{
	MySet result;

	Node* current = _head;
	Node* currentB = Set._head;
	while (current != nullptr) {

		if (!Set.IsInSet(current->val)) {
			result.AddToBegin(current->val);
		}
		current = current->next;
	}

	return result;
}

//F14
MySet MySet::SymmetricalDifferenceTwoSets(MySet Set)
{
	return DifferenceTwoSets(Set).CombiningTwoSets(Set.DifferenceTwoSets(*this));
}