#include "UI.h"

void UI::showTable() {
	// Заголовки столбцов
	vector<string> headers = { "Односвязный список", "Класс 'Список'", "List", "Set", "Map", "Unorderedmap" };

	MeasureStructs* measureStructs = new MeasureStructs(_powerOfSetA, _powerOfSetB);
	Times* createTimes = measureStructs->getCreateTime();
	Times* sizeTimes = measureStructs->getSizeTime();
	Times* underAATimes = measureStructs->getUnderAATime();
	Times* underABTimes = measureStructs->getUnderABTime();
	Times* isEqualAATimes = measureStructs->getEqualityAATime();
	Times* isEqualABTimes = measureStructs->getEqualityABTime();
	Times* combiningTimes = measureStructs->getCombiningTime();
	Times* intersectionTimes = measureStructs->getIntersectionTime();
	Times* differenceTimes = measureStructs->getDifferenceTime();
	Times* difference2Times = measureStructs->get2DifferenceTime();
	Times* symDifferenceTimes = measureStructs->getSymmetricDifferenceTime();

	vector<vector<string>> data = {
		{"Создание множества (мкс)", createTimes->nodeTime, createTimes->mySetTime, createTimes->listSetTime, createTimes->setSetTime, createTimes->mapSetTime, createTimes->multimapSetTime},
		{"Мощность (мкс)", sizeTimes->nodeTime , sizeTimes->mySetTime, sizeTimes->listSetTime , sizeTimes->setSetTime, sizeTimes->mapSetTime, sizeTimes->multimapSetTime},
		{"Подмножество A-A (мкс)",underAATimes->nodeTime , underAATimes->mySetTime,underAATimes->listSetTime , underAATimes->setSetTime, underAATimes->mapSetTime, underAATimes->multimapSetTime},
		{"Подмножество B-A (мкс)", underABTimes->nodeTime , underABTimes->mySetTime,underABTimes->listSetTime , underABTimes->setSetTime, underABTimes->mapSetTime, underABTimes->multimapSetTime},
		{"Равенство A-A (мкс)",isEqualAATimes->nodeTime , isEqualAATimes->mySetTime,isEqualAATimes->listSetTime , isEqualAATimes->setSetTime, isEqualAATimes->mapSetTime, isEqualAATimes->multimapSetTime},
		{"Равенство B-A (мкс)", isEqualABTimes->nodeTime , isEqualABTimes->mySetTime,isEqualABTimes->listSetTime , isEqualABTimes->setSetTime, isEqualABTimes->mapSetTime, isEqualABTimes->multimapSetTime},
		{"Объединение (мкс)", combiningTimes->nodeTime , combiningTimes->mySetTime,combiningTimes->listSetTime , combiningTimes->setSetTime, combiningTimes->mapSetTime, combiningTimes->multimapSetTime},
		{"Пересечение (мкс)", intersectionTimes->nodeTime , intersectionTimes->mySetTime,intersectionTimes->listSetTime , intersectionTimes->setSetTime, intersectionTimes->mapSetTime, intersectionTimes->multimapSetTime},
		{"Разность A-B (мкс)", differenceTimes->nodeTime , differenceTimes->mySetTime,differenceTimes->listSetTime , differenceTimes->setSetTime, differenceTimes->mapSetTime, differenceTimes->multimapSetTime},
		{"Разность B-A (мкс)",difference2Times->nodeTime , difference2Times->mySetTime,difference2Times->listSetTime , difference2Times->setSetTime, difference2Times->mapSetTime, difference2Times->multimapSetTime},
		{"Сим-ная разность (мкс)", symDifferenceTimes->nodeTime , symDifferenceTimes->mySetTime,symDifferenceTimes->listSetTime , symDifferenceTimes->setSetTime, symDifferenceTimes->mapSetTime, symDifferenceTimes->multimapSetTime},
	};
	// Вывод заголовков
	std::cout << left << setw(25) << " ";
	for (const auto& header : headers) {
		std::cout << setw(20) << header;
	}
	std::cout << endl;

	// Вывод данных
	for (size_t i = 0; i < data.size(); ++i) {
		std::cout << left << setw(25) << data[i][0];
		for (size_t j = 1; j < data[i].size(); ++j) {
			std::cout << setw(20) << data[i][j];
		}
		std::cout << endl;
	}
}

void UI::run() {
	std::cout << "Курсовая работа по ПДСД \nВыполнил студент группы 22ВП1 Ушаков Михаил" << endl;
	enterPowerOfSets();
	showTable();
}

void UI::enterPowerOfSets() {
	string powerOfSetA, powerOfSetB;
	bool a_ok = false;
	bool b_ok = false;

	// Цикл для первого числа
	while (!a_ok) {
		std::cout << "Введите мощность первого множества: ";
		cin >> powerOfSetA;
		try {
			_powerOfSetA = std::stoi(powerOfSetA);
			if (_powerOfSetA <= 0) {
				std::cout << "Мощность множества не может быть <= 0" << endl;
			}
			else {
				a_ok = true; // Число корректно, выходим из цикла
			}
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Ошибка: строка не является числом!" << std::endl;
		}
	}

	// Цикл для второго числа
	while (!b_ok) {
		std::cout << endl << "Введите мощность второго множества: ";
		cin >> powerOfSetB;
		try {
			_powerOfSetB = std::stoi(powerOfSetB);
			if (_powerOfSetB <= 0) {
				std::cout << "Мощность множества не может быть <= 0" << endl;
			}
			else {
				b_ok = true; // Число корректно, выходим из цикла
			}
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Ошибка: строка не является числом!" << std::endl;
		}
	}
}

void UI::clearConsole() {
	system("cls");
}