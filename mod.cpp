#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include "h.h"
using namespace std;


fitnes mas[100];

bool check_year(int year) {
	if (!(year >= 2000 && year <= 2010))
		return false;
	return true;
}

bool check_month(int month) {
	if (!(month > 0 && month < 13))
		return false;
	return true;
}

bool check_duration(int duration) {
	if (!(duration > 0 && duration < 31))
		return false;
	return true;
}

bool check_id(int id) {
	if (!(id > 9 && id < 100))
		return false;
	return true;
}

void vvod_z1(int* m) {
	wcout << L"--> ";
	wcin >> m[0] >> m[1] >> m[2] >> m[3];
	while (true) {
		if (!check_year(m[0])) {
			wcout << L"Введён недопустимый год! \nВведите новый год: ";
			wcin >> m[0];
			continue;
		}
		if (!check_month(m[1])) {
			wcout << L"Введён недопустимый месяц! \nВведите новый месяц: ";
			wcin >> m[1];
			continue;
		}
		if (!check_duration(m[2])) {
			wcout << L"Введена недопустимая продолжительность занятий! \nВведите новую продолжительность занятий: ";
			wcin >> m[2];
			continue;
		} 
		if (!check_id(m[3])) {
			wcout << L"Введён недопустимый код клиента! \nВведите новый код клиента: ";
			wcin >> m[3];
			continue;
		}
		break;
	}
}



void z1() {
	int n, no, duration_max = 0;
	int m[4];
	wcout << L"Введите N: ";
	wcin >> n;
	system("cls");

	wcout << L"Вводите данные в формате <Год(2000-2010)> <Номер месяца(1-12)> <Продолжительность занятий (в часах 1-30)> <Код клиента(10-99)>: " << endl;
	for (int i = 0; i < n; i++) {
		vvod_z1(m);
		mas[i].year = m[0];
		mas[i].month = m[1];
		mas[i].duration = m[2];
		mas[i].id = m[3];
	}

	for (int i = 0; i < n; i++) {
		if (mas[i].duration > duration_max) {
			duration_max = mas[i].duration;
			no = i;
		}
	}
	system("cls");
	wcout << L"Максимальная продолжительность: " << mas[no].duration << L" Год: " << mas[no].year << L" Месяц: " << mas[no].month << endl;

	check_zadach();
}

childs mas2[100];

bool check_klass2(int n) {
	if (!(n >= 1 && n <= 10))
		return false;
	return true;
}

bool check_klass4(int n) {
	if (!(n >= 1 && n <= 100))
		return false;
	return true;
}

void vvod_z2(wstring& fam, wstring& nam, int &klass, int &other) {
	wcout << L"--> ";
	wcin >> fam >> nam >> klass >> other;
	while (true) {
		if (klass < 1 || klass > 4) {
			wcout << L"Введён недопустимый класс! \nВведите новый класс: ";
			wcin >> klass;
			continue;
		}
		if (klass == 2 || klass == 3) {
			if (!check_klass2(other)) {
				wcout << L"Введены неверные баллы контрольной по математике! \nВведите новые баллы контрольной по математике: ";
				wcin >> other;
				continue;
			}
		}
		if (klass == 4) {
			if (!check_klass4(other)) {
				wcout << L"Введены неверные баллы итоговой аттестации! \nВведите новые баллы итоговой аттестации: ";
				wcin >> other;
				continue;
			}
		}
		break;
	}

}

void z2() {
	int n,check;
	wcout << L"Введите число N: ";
	wcin >> n;
	system("cls");
	wcout << L"Введите данные об ученике начальных классов (Фамилия, имя, класс, скорость чтения для 1-х классов, баллы по математике для 2-х и 3-х классов(от 1 до 10), баллы итоговой аттестации для 4-х классов(от 1 до 100): " << endl;
	wstring nam, fam;
	int klass, other;
	for (int i = 0; i < n; i++) {
		vvod_z2(fam,nam,klass,other);
		mas2[i].family = fam;
		mas2[i].name = nam;
		mas2[i].klass = klass;
		if (klass == 4)
			mas2[i].other.klass_4 = other;
		if (klass == 2 || klass == 3)
			mas2[i].other.klass_2_3 = other;
		if (klass == 1)
			mas2[i].other.klass_1 = other;
	}

	wofstream f;
	f.open("output.txt", ios::out);
	f << left << setw(25) << L"Фамилия " << setw(25) << L" Имя" << setw(25) << L" Класс" << setw(25) << L" Скорость чтения(1 класс), Баллы(2-4 класс)" << endl;
	for (int i = 0; i < n; i++) {
		if (mas2[i].klass == 1)
			f << left << setw(25) << mas2[i].family << L" " << setw(25) << mas2[i].name << L" " << setw(25) << mas2[i].klass << L" " << setw(25) << mas2[i].other.klass_1 << endl;
		if (mas2[i].klass == 2 || mas2[i].klass == 3)
			f << setw(25) << mas2[i].family << L" " << setw(25) << mas2[i].name << L" " << setw(25) << mas2[i].klass << L" " << setw(25) << mas2[i].other.klass_2_3 << endl;
		if (mas2[i].klass == 4)
			f << setw(25) << mas2[i].family << L" " << setw(25) << mas2[i].name << L" " << setw(25) << mas2[i].klass << L" " << setw(25) << mas2[i].other.klass_4 << endl;
	}
	f.close();
	system("cls");
	wcout <<left << setw(25) << L"Фамилия "<< setw(25) << L" Имя" << setw(25) << L" Класс" << setw(25) << L" Скорость чтений(1 класс), Баллы(2-4 класс)" << endl;
	for (int i = 0; i < n; i++) {
		if (mas2[i].klass == 1)
			wcout << left << setw(25) << mas2[i].family << L" " << setw(25) << mas2[i].name << L" " << setw(25) << mas2[i].klass << L" " << setw(25) << mas2[i].other.klass_1 << endl;
		if (mas2[i].klass == 2 || mas2[i].klass == 3)
			wcout << setw(25) << mas2[i].family << L" " << setw(25) << mas2[i].name << L" " << setw(25)<< mas2[i].klass << L" " << setw(25) << mas2[i].other.klass_2_3 << endl;
		if (mas2[i].klass == 4)
			wcout << setw(25) << mas2[i].family << L" " << setw(25)<< mas2[i].name << L" " << setw(25) << mas2[i].klass << L" " << setw(25) << mas2[i].other.klass_4 << endl;
	}
	check_zadach();
}

students mas3[100];

void vvod_z3(wstring &name, int &age, float &bal) {
	wcout << L"--> ";
	wcin >> name >> age >> bal;
}

void registr(wstring &word) {
	for (int i = 0;i<word.length();i++) {
		word[i] = towlower(word[i]);
	}
}

void student_search(int n) {
	bool flag = true;
	wstring name, name2;
	wcout << L"Введите имя студента: ";
	wcin >> name;
	registr(name);
	system("cls");
	for (int i = 0; i < n && flag; i++) {
		name2 = mas3[i].name;
		registr(name2);
		if (name2 == name) {
			wcout << left << setw(20) << L"Имя" << left << setw(20) << L"Возраст" << left << setw(20) << L"Средний балл" << endl;
			wcout << left << setw(20) << mas3[i].name << left << setw(20) << mas3[i].age << left << setw(20) << mas3[i].avbal << endl;
			flag = false;
		}
	}
	if (flag) {
		wcout << L"Такого студента нет! " << endl;
		student_search(n);
	}
}

void student_change(int n) {
	bool flag = true;
	wstring name, name2,new_name;
	int age,change;
	float bal;
	wcout << L"Введите имя студента, данные которого необходимо изменить: ";
	wcin >> name;
	registr(name);
	system("cls");
	for (int i = 0; i < n && flag; i++) {
		name2 = mas3[i].name;
		registr(name2);
		if (name2 == name) {
			wcout << left << setw(20) << L"Имя" << left << setw(20) << L"Возраст" << left << setw(20) << L"Средний балл " << endl;
			wcout << left << setw(20) << mas3[i].name << left << setw(20) << mas3[i].age << left << setw(20) << mas3[i].avbal << endl << endl;
			wcout << L"Выберите что необходимо изменить: \n1. Имя \n2. Возраст \n3. Средний балл \n4. Всю информацию \n--> ";
			wcin >> change;
			system("cls");
			switch (change) {
			case 1:
				wcout << L"Введите имя: ";
				wcin >> mas3[i].name;
				break;
			case 2:
				wcout << L"Введите возраст: ";
				wcin >> mas3[i].age;
				break;
			case 3:
				wcout << L"Введите средний балл: ";
				wcin >> mas3[i].avbal;
				break;
			case 4:
				wcout << L"Введите имя студента, возраст, средний балл: ";
				wcin >> mas3[i].name >> mas3[i].age >> mas3[i].avbal;
				break;
			}
			wcout << L"Данные изменены!" << endl;
			flag = false;
		}
	}
	if (flag) {
		wcout << L"Такого студента нет! " << endl;
		student_change(n);
	}
}

void student_add(int &n) {
	wcout << L"Введите имя студента, возраст, средний балл: " << endl;
	wcout << L"--> ";
	wcin >> mas3[n].name >> mas3[n].age >> mas3[n].avbal;
	wcout << L"Данные студента добавлены! " << endl;
	wcout << endl;
	n++;
}

void count_bal(int n) {
	int count = 0;
	float bal;
	wcout << L"Введите балл: ";
	wcin >> bal;
	for (int i = 0; i < n; i++) {
		if (mas3[i].avbal == bal)
			count++;
	}
	wcout << L"Количество студентов с баллом " << bal << L": " << count << endl;
}

void av_bal(int n) {
	wcout << L"Вводите имена студентов для подсчёта их среднего балла, для завершения введите 0: " << endl;
	wstring name,name2;
	int count = 0;
	float sum_bal=0,result=0;
	while (name != to_wstring(0)) {
		bool flag = true;
		wcout << L"--> ";
		wcin >> name;
		registr(name);
		for (int i = 0; i < n && flag; i++) {
			name2 = mas3[i].name;
			registr(name2);
			if (name2 == name) {
				sum_bal += mas3[i].avbal;
				flag = false;
				count++;
			}
		}
		if (flag) {
			wcout << L"Такого студента нет! " << endl;
		}
	}
	result = sum_bal / count;
	wcout << L"Средний балл выбранных студентов: " << result << endl;
}

void age_search(int n) {
	int age;
	wcout << L"Введите возраст для поиска студентов: ";
	wcin >> age;
	system("cls");
	wcout << left << setw(20) << L"Имя" << left << setw(20) << L"Возраст" << left << setw(20) << L"Средний балл " << endl;
	for (int i = 0; i < n; i++) {
		if (age==mas3[i].age)
			wcout << left << setw(20) << mas3[i].name << left << setw(20) << mas3[i].age << left << setw(20) << mas3[i].avbal << endl;
	}
}

void check_menu(int n) {
	wstring check;
	wcout << L"Введите 0 чтобы вернуться в меню: ";
	wcin >> check;
	if (check == to_wstring(0))
		menu(n);
	else {
		wcout << L"Неверный ввод!" << endl;
		check_menu(n);
	}
}

void check_zadach() {
	wstring check;
	wcout << L"Введите 0 чтобы вернуться к задачам: ";
	wcin >> check;
	if (check == to_wstring(0)) {
		system("cls");
		zadaniya();
	}
	else {
		wcout << L"Неверный ввод! "<< endl;
		check_zadach();
	}
}

void menu(int n) {
	int a, check;
	system("cls");
	wcout << L"Выберите действие: \n1. Вывести информацию о всех студентах \n2. Вывести информацию об одном студенте \n3. Добавить студента \n4. Изменить информацию о студенте \n5. Подсчёт количества студентов с определённым баллом \n6. Вычисление общего среднего балла для определённых студентов \n7. Поиск студентов по возрасту \n0. Обратно к задачам" << endl;
	wcout << L"--> ";
	wcin >> a;
	system("cls");
	switch (a) {
	case 1:
		wcout << left << setw(20) << L"Имя" << left << setw(20) << L"Возраст" << left << setw(20) << L"Средний балл " << endl;
		for (int i = 0; i < n; i++) {
			wcout << left << setw(20) << mas3[i].name << left << setw(20) << mas3[i].age << left << setw(20) << mas3[i].avbal << endl;
		}
		check_menu(n);
		break;
	case 2:
		student_search(n);
		check_menu(n);
		break;
	case 3:
		student_add(n);
		check_menu(n);
		break;
	case 4:
		student_change(n);
		check_menu(n);
		break;
	case 5:
		count_bal(n);
		check_menu(n);
		break;
	case 6:
		av_bal(n);
		check_menu(n);
		break;
	case 7:
		age_search(n);
		check_menu(n);
		break;
	case 0:
		system("cls");
		zadaniya();
		break;
	default:
		wcout << L"Такого действия нет! ";
		menu(n);
		break;
	}
}

void z3() {
	wstring name;
	int age,n,a;
	float bal;
	wcout << L"Введите количество студентов: ";
	wcin >> n;
	system("cls");
	wcout << L"Введите имя студента, возраст, средний балл: " << endl;
	for (int i = 0; i < n; i++) {
		vvod_z3(name, age, bal);
		mas3[i].name = name;
		mas3[i].age = age;
		mas3[i].avbal = bal;
	}
	menu(n);
}

void zadaniya() {
	int z;
	wcout << L"Выберите задачу: \n1. Фитнес-центр \n2. Ученики младших классов \n3. Студенты \n0. Выход \n--> ";
	wcin >> z;
	system("cls");
	switch (z) {
		case 1:
			z1();
			break;
		case 2:
			z2();
			break;
		case 3:
			z3();
			break;
		case 0:
			wcout << L"Программа завершена!" << endl;
			exit(0);
			break;
		default:
			wcout << L"Такой задачи нет!" << endl;
			zadaniya();
			break;
	}
}