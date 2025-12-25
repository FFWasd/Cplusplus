#include <iostream>
#include <string>
using namespace std;
#pragma once
struct fitnes {
	int year;
	int month;
	int id;
	int duration;
};
struct pupils {
	wstring name;
	int bal;
};

void create_mas_rand(int* m, int n);
void create_mas_keyboard(int* m, int n);
void print_mas(int* m, int n);
void sort_vibor(int* m, int n);
void z1();
void z2();
void z3();
void menu();
void check_menu();
int vvod_id();
void vvod_z2(int* m);
bool check_year(int year);
bool check_month(int month);
bool check_duration(int duration);
bool check_id(int id);
void find_years(int n, int k, int* years, int& j);
void sort_year(int* years, int& j);
void min_duration(int* years, int n, int* months, int& p);
