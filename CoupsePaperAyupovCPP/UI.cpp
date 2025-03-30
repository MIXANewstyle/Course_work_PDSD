#include "UI.h"

void UI::showTable() {
	// Заголовки столбцов
	vector<string> headers = { "Односвязный список", "Класс 'Список'", "List", "Set", "Map", "Multimap" };
	vector<vector<string>> data = {
		{"Создание множества", "0", "0", "0", "0", "0", "0"},
		{"Мощность", "0", "0", "0", "0", "0", "0"},
		{"Подмножество A-A", "0", "0", "0", "0", "0", "0"},
		{"Подмножество B-A", "0", "0", "0", "0", "0", "0"},
		{"Равенство A-A", "0", "0", "0", "0", "0", "0"},
		{"Равенство B-A", "0", "0", "0", "0", "0", "0"},
		{"Объединение", "0", "0", "0", "0", "0", "0"},
		{"Пересечение", "0", "0", "0", "0", "0", "0"},
		{"Разность A-B", "0", "0", "0", "0", "0", "0"},
		{"Симметричная разность", "0", "0", "0", "0", "0", "0"}
	};
	// Вывод заголовков
	cout << left << setw(25) << " ";
	for (const auto& header : headers) {
		cout << setw(20) << header;
	}
	cout << endl;

	// Вывод данных
	for (size_t i = 0; i < data.size(); ++i) {
		cout << left << setw(25) << data[i][0];
		for (size_t j = 1; j < data[i].size(); ++j) {
			cout << setw(20) << data[i][j];
		}
		cout << endl;
	}
}

void UI::showMenu() {
	cout << endl << "МЕНЮ" << endl <<
		"1) Ввести мощность множеств" << endl <<
		"2) Создать множества" << endl <<
		"3) Вычислить время вполнения операций" << endl <<
		"Любой символ) Выход" << endl << 
		"Введите номер пункта: " <<
		endl;
}

void UI::run() {
	cout << "Курсовая работа по ПДСД \nВыполнил студент группы 23ВП1 Аюпов Марат " << endl;
	while (!_programEnd){
		showMenu();
		int number;
		cin >> number;
		if (number == 1) {
			try {
				enterPowerOfSets();
				clearConsole();
			}
			catch (exception ex) {
				clearConsole();
				cerr << "Исключение: " << ex.what() << endl;
			}
		}
		else if (number == 2) {
			clearConsole();
			createSets();
		}
		else if (number == 3) {
			clearConsole();
			showTable();
			cout << "\n1) Продолжить \nЛюбой символ) Выход" << endl;
			int number2;
			cin >> number2;
			if (number2 == 1) {
				continue;
			}
			else{
				return;
			}
		}
		else {
			return;
		}
	}
}

void UI::enterPowerOfSets() {
	cout << "Введите мощность множества на основе односвязного списка: ";
	cin >> _powerOfNode;
	cout << "Введите мощность множества на основе класса 'Список': ";
	cin >> _powerOfMySet;
	cout << "Введите мощность множества на основе List: ";
	cin >> _powerOfList;
	cout << "Введите мощность множества на основе Set: ";
	cin >> _powerOfSet;
	cout << "Введите мощность множества на основе Map: ";
	cin >> _powerOfMap;
	cout << "Введите мощность множества на основе Multimap: ";
	cin >> _powerOfMultimap;
	if (_powerOfNode <= 0 || _powerOfMySet <= 0 || _powerOfList <= 0 || _powerOfSet <= 0 || _powerOfMap <= 0 || _powerOfMultimap <= 0) {
		_powerOfNode = _powerOfMySet = _powerOfList = _powerOfSet = _powerOfMap = _powerOfMultimap = 0;
		throw invalid_argument("Значение не может быть отрицательным!");
	}
}

void UI::createSets() {
	if (_powerOfNode <= 0 || _powerOfMySet <= 0 || _powerOfList <= 0 || _powerOfSet <= 0 || _powerOfMap <= 0 || _powerOfMultimap <= 0) {
		clearConsole();
		cout << "Сначала введите мощность множеств!" << endl;
	}
	else {
		clearConsole();
		ListSet* listSet = new ListSet(_powerOfList, 0, 99);
		cout << listSet->PrintSet("|") << endl;
		cout << "Множества созданы!" << endl;
	}
}

void UI::clearConsole() {
	system("cls");
}