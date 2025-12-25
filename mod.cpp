#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <climits>
#include <iomanip>
#include "h.h"

using namespace std;

void menu() {
	int z;
	wcout << L"Выберите задание: \n1. Sort6 (Сортировка методом простого выбора) \n2. ExamTaskC14 (Фитнесс центр) \n3. Five11 (Сортировка учеников, заполнить файл pupils.txt) \n0. Выход" << endl;
	wcout << L"--> ";
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
		default:
			wcout << L"Такого задания нет!" << endl;
			menu();
			break;
	}
}

void check_menu() {
	wstring check;
	wcout << L"Введите 0 чтобы вернуться к задачам: ";
	wcin >> check;
	if (check == to_wstring(0)) {
		system("cls");
		menu();
	}
	else {
		wcout << L"Неверный ввод! " << endl;
		check_menu();
	}
}

void create_mas_rand(int* m, int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		m[i] = rand() % 100 + -30;
	}
}

void create_mas_keyboard(int* m,int n) {
	wcout << L"Вводите числа:" << endl;
	for (int i = 0; i < n; i++) {
		wcout << "--> ";
		wcin >> m[i];
	}
}

void print_mas(int* m, int n) {
	for (int i = 0; i < n; i++) {
		wcout << m[i] << " ";
	}
	wcout << endl;
}

void sort_vibor(int* m, int n) {
	ofstream f1("output.txt");
	int tmax, k;
	for (int i = n-1; i >0; i--) {
		tmax = m[i];
		k = i;
		for (int j = 0; j < i; j++) {
			if (m[j] > tmax) {
				tmax = m[j];
				k = j;
			}
		}
		if (k != i) {
			m[k] = m[i];
			m[i] = tmax;
		}
		for (int h = 0; h < i; h++) {
			f1 << m[h] << " ";
		}
		f1 << "|";
		for (int h = i; h < n; h++) {
			f1 << m[h] << " ";
		}
		f1 << endl;
	}
	f1.close();
}

void z1() {
	int mas[100],mas2[100];
	int n,c;
	wcout << L"Введите число N: ";
	wcin >> n;
	system("cls");
	wcout << L"Выберите способ создания массива: \n1. С клавиатуры \n2. Рандом \n--> ";
	wcin >> c;
	system("cls");
	switch (c) {
		case 1:
			create_mas_keyboard(mas, n);
			wcout << L"Начальный массив: ";
			print_mas(mas, n);
			sort_vibor(mas, n);
			wcout << endl << L"Отсортированный массив: ";
			print_mas(mas, n);
			wcout << endl << L"Протокол сортировки можно посмотреть в файле output.txt!" << endl;
			break;
		case 2:
			create_mas_rand(mas, n);
			wcout << L"Начальный массив: ";
			print_mas(mas, n);
			sort_vibor(mas, n);
			wcout << endl << L"Отсортированный массив: ";
			print_mas(mas, n);
			wcout << endl << L"Протокол сортировки можно посмотреть в файле output.txt!" << endl;
			break;
		default:
			wcout << L"Такого выбора нет!";
			break;
	}
	check_menu();
	
}

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

void vvod_z2(int* m) {
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
		if (!check_id(m[2])) {
			wcout << L"Введён недопустимый код клиента! \nВведите новый код клиента: ";
			wcin >> m[2];
			continue;
		}
		if (!check_duration(m[3])) {
			wcout << L"Введена недопустимая продолжительность занятий! \nВведите новую продолжительность занятий: ";
			wcin >> m[3];
			continue;
		}
		break;
	}
}

void find_years(int n, int k, int* years, int& j) {
	for (int i = 0; i < n; i++) {
		if (mas[i].id == k) {
			years[j] = i;
			j++;
		}
	}
}

void sort_year(int* years,int &j) {
	int t;
	for (int i = 0; i < j; i++) {
		for (int k = 0; k < j-i-1; k++) {
			if (mas[years[k]].year > mas[years[k+1]].year) {
				t = years[k];
				years[k] = years[k + 1];
				years[k + 1] = t;
			}
		}
	}
}

void min_duration(int* years, int j, int* months, int& p) {
	p = 0;
	if (j == 0) return;
	int i = 0;
	while (i < j) {
		int current_year = mas[years[i]].year;
		int min_idx = years[i];
		while (i < j && mas[years[i]].year == current_year) {
			int current_idx = years[i];
			if (mas[current_idx].duration < mas[min_idx].duration) {
				min_idx = current_idx;
			}
			else if (mas[current_idx].duration == mas[min_idx].duration) {
				if (mas[current_idx].month > mas[min_idx].month) {
					min_idx = current_idx;
				}
			}
			i++;
		}
		months[p] = min_idx;
		p++;
	}
}

int vvod_id() {
	int k;
	wcout << L"Введите код клиента: ";
	wcin >> k;
	if (check_id(k)) {
		return k;
	}
	else {
		wcout << L"Введён недопустимый код клиента! ";
		vvod_id();
	}
}

void z2() {
	int months[100];
	int years[100], p=0;
	int n, duration_max = 0,k,j=0;
	int m[4];
	k=vvod_id();
	wcout << L"Введите N: ";
	wcin >> n;
	system("cls");

	wcout << L"Вводите данные в формате <Год(2000-2010)> <Номер месяца(1-12)> <Код клиента(10-99)> <Продолжительность занятий (в часах 1-30)>: " << endl;
	for (int i = 0; i < n; i++) {
		vvod_z2(m);
		mas[i].year = m[0];
		mas[i].month = m[1];
		mas[i].id = m[2];
		mas[i].duration = m[3];
	}

	system("cls");

	find_years(n, k, years, j);
	sort_year(years, j);
	min_duration(years, j, months, p);
	if (p != 0) {
		for (int i = 0; i < p; i++) {
			wcout << mas[months[i]].year << setw(10) << mas[months[i]].month << setw(10) << mas[months[i]].duration << endl;
		}
	}
	else {
		wcout << L"Нет данных! " << endl;
	}
	wcout << endl;

	check_menu();
}



pupils pup[100];

void quick_sort(int L, int R) {
	int i = L, j = R, t;
	wstring w;
	wstring x;
	x = pup[(L + R) / 2].name;
	do
	{
		while (pup[i].name < x) i++;
		while (pup[j].name > x) j--;
		if (i <= j)
		{
			w = pup[i].name; pup[i].name = pup[j].name; pup[j].name = w;
			t = pup[i].bal; pup[i].bal = pup[j].bal; pup[j].bal = t;
			i++; j--;
		}
	} while (i <= j);
	if (L < j) quick_sort(L, j);
	if (i < R) quick_sort(i, R);
}

void z3() {
	wifstream f1("pupils.txt");
	wofstream f2("sort_pupils.txt");
	wstring name;
	int bal,n=0;
	while (f1 >> name >> bal) {
		pup[n].name = name;
		pup[n].bal = bal;
		n++;
	}

	quick_sort(0, n - 1);

	for (int i = 0; i < n; i++) {
		f2 << left << setw(15) <<pup[i].name << " " << right << setw(5) << pup[i].bal << endl;
	}
	f1.close();
	f2.close();
	wcout << L"Проверьте файл sort_pupil.txt" << endl;

	check_menu();
}