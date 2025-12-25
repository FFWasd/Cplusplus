#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "h.h"
using namespace std;

int main(){
    locale::global(locale(""));
    int original_mode_out = _setmode(_fileno(stdout), _O_U16TEXT);
    int original_mode_in = _setmode(_fileno(stdin), _O_U16TEXT);
    setlocale(LC_ALL, "Russian");
    int z,vvod;
    wstring words;
    wcout << L"Задания: \n1. String46 (самое длинное слово) \n2. Str18 (заменить \\ на /) \n3. Str23 (Наложение гаммы) \n4. Str44 (Частый символ) \n5. Str31 (перевод в 18-ю систему счисления) \n6. 3 (Азбука морзе) \n7. Five6 (ДЗ девятиклассника, Заполнить файл FN1.txt) \nВыберите задание: ";
    wcin >> z;
    system("cls");
    if (z != 7) {
        wcout << L"Ввод строки: \n1. С клавиатуры \n2. Из файла (words.txt) \n3. Рандом \nВыберите способ: ";
        wcin >> vvod;
        system("cls");
        switch(vvod){
            case 1:
                words=keyboard(z);
                break;
            case 2:
                words=strfile();
                break;
            case 3:
                words = strrand(z);
                break;
            default:
                cout << "Такого способа нет!" << endl;
                return 0;
        }
    }
    system("cls");
    switch(z){
        case 1:
            if (z1_check(words)) {
                z1(words);
            }
            else {
                wcout << L"Строка должна содержать только русские слова!" << endl;
                return 0;
            }
            break;
        case 2:
            if (z2_check(words)) {
                z2(words);
            }
            else {
                wcout << L"Строка должна содержать минимум 1 символ \\ !";
                return 0;
            }
            break;
        case 3:
            z3(words);
            break;
        case 4:
            z4(words);
            break;
        case 5:
            if (!checknum(words)){
                wcout << L"Необходимо ввести число в 10-ричной системе счисления!" << endl;
                return 0;
            }
            else{
                z5(words);
            }
            break;
        case 6:
            z6(words);
            break;
        case 7:       
            z7();
            break;
        default:
            wcout << L"Такого задания нет!" << endl;
            return 0;
    }
}