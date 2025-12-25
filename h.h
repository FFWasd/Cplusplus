#include <iostream>
#include <string>
using namespace std;
#pragma once

struct fitnes {
	int year;
	int month;
	int duration;
	int id;
};

union dop_info {
	short int klass_1;
	float klass_4;
	short int klass_2_3;

};

struct childs {
	wstring family;
	wstring name;
	int klass;
	dop_info other;
};

struct students {
	wstring name;
	int age;
	float avbal;
};

void z1();
void z2();
void z3();
void vvod_z1(int* m);
void vvod_z2(wstring &fam, wstring &name, int& klass, int& other);
void vvod_z3(wstring& name, int& age, float& bal);
void registr(wstring& word);
void student_change(int n);
void student_add(int& n);
void count_bal(int n);
void check_menu(int n);
void av_bal(int n);
void check_zadach();
void age_search(int n);
void menu(int n);
void student_search(int n);
bool check_klass2(int n);
bool check_klass4(int n);
bool check_year(int year);
bool check_month(int month);
bool check_duration(int duration);
bool check_id(int id);
void zadaniya();