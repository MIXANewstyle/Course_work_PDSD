#include "UnorderedMapSet.h"

UnorderedMapSet::UnorderedMapSet() {
	// Конструктор по умолчанию
}

//F4: Конструктор для создания N элементов
UnorderedMapSet::UnorderedMapSet(int countOfElements, int minValue, int maxValue) {
	int i = 0;
	while (i < countOfElements) {
		// Логика добавления сама обработает дубликаты
		if (AddToBegin(GetRandomInt(minValue, maxValue))) i++;
	}
}

//F8: Деструктор
UnorderedMapSet::~UnorderedMapSet() {
	// unordered_map очистится сам
}

//F2: Проверка на пустоту
bool UnorderedMapSet::IsEmpty() {
	return unorderedMapSet.empty();
}

//F3: Добавление элемента
bool UnorderedMapSet::AddToBegin(int valueOfElem) {
	if (IsInSet(valueOfElem)) return false; // Элемент уже есть

	// Добавляем элемент. Используем 0 как "заглушку"
	unorderedMapSet.insert({ valueOfElem, 0 });
	return true;
}

//F5: Печать множества
string UnorderedMapSet::PrintSet(string separator) {
	stringstream streamStr;
	// Итерация по unordered_map 
	for (auto elem : unorderedMapSet) {
		streamStr << elem.first; // elem.first - это ключ (элемент)
		streamStr << separator;
	}
	string result = streamStr.str();
	if (!result.empty()) { 
		result.pop_back(); 
	}
	return result;
}

//F6: Проверка на вхождение
bool UnorderedMapSet::IsInSet(int valueOfElem) {
	// find у unordered_map работает в среднем за O(1)
	return unorderedMapSet.find(valueOfElem) != unorderedMapSet.end();
}

//F7: Мощность множества
int UnorderedMapSet::GetPowerOfSet() {
	return unorderedMapSet.size();
}

//F8: Очистка множества
void UnorderedMapSet::DeleteSet() {
	unorderedMapSet.clear();
}

//F9: Проверка на подмножество (this ⊂ underSet)
bool UnorderedMapSet::IsUnderSet(UnorderedMapSet underSet) {
	// Проверяем, что каждый элемент из 'this' есть в 'underSet'
	for (auto elem : unorderedMapSet) {
		if (!underSet.IsInSet(elem.first)) return false;
	}
	return true;
}

//F10: Проверка на равенство
bool UnorderedMapSet::IsEqualitySets(UnorderedMapSet Set) {
	//  A=B если (A ⊂ B) и (B ⊂ A)
	return IsUnderSet(Set) && Set.IsUnderSet(*this);
}

//F11: Объединение
UnorderedMapSet UnorderedMapSet::CombiningTwoSets(UnorderedMapSet Set) {
	UnorderedMapSet result;

	// Добавляем все из 'this'
	for (auto elem : unorderedMapSet) result.AddToBegin(elem.first);
	// Добавляем все из 'Set' (AddToBegin сам справится с дубликатами)
	for (auto elem : Set.unorderedMapSet) result.AddToBegin(elem.first);

	return result;
}

//F12: Пересечение
UnorderedMapSet UnorderedMapSet::IntersectionTwoSets(UnorderedMapSet Set) {
	UnorderedMapSet result;

	// Добавляем, только если элемент есть в 'Set'
	for (auto elem : unorderedMapSet) {
		if (Set.IsInSet(elem.first)) result.AddToBegin(elem.first);
	}

	return result;
}

//F13: Разность (this - Set)
UnorderedMapSet UnorderedMapSet::DifferenceTwoSets(UnorderedMapSet Set) {
	UnorderedMapSet result;

	// Добавляем, только если элемента НЕТ в 'Set'
	for (auto elem : unorderedMapSet) {
		if (!Set.IsInSet(elem.first)) {
			result.AddToBegin(elem.first);
		}
	}
	return result;
}

//F14: Симметричная разность
UnorderedMapSet UnorderedMapSet::SymmetricalDifferenceTwoSets(UnorderedMapSet Set) {
	// Логика полностью идентична вашей
	return DifferenceTwoSets(Set).CombiningTwoSets(Set.DifferenceTwoSets(*this));
}

int UnorderedMapSet::GetRandomInt(int minValue, int maxValue) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(minValue, maxValue);
	int randomValue = dist(gen);
	return randomValue;
}