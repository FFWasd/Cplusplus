#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <limits>
#include <fstream>
#include <algorithm>
#include <random>
#include "h.h"
using namespace std;

wstring keyboard(int z){
    wcin.ignore((numeric_limits<streamsize>::max)(), '\n');
    wstring words;
    if (z == 1) {
        wcout << L"Введите строку состоящую из русских слов: ";
    }
    if (z == 2) {
        wcout << L"Введите строку содержащую минимум один символ '\\': ";
    }
    if (z == 5) {
        wcout << L"Введите строку состоящую из десятичного числа: ";
    }
    else {
        wcout << L"Введите строку: ";
    }
    getline(wcin, words);
    system("cls");
    return words;
}

wstring strfile(){
    wifstream f("words.txt");  
    wstring words;
    getline(f,words);
    f.close();
    return words;
}

wstring strrand(int z) {
    int nums;
    wstring words;
    vector a = {L"Арбуз",L"помидор",L"обезьяна",L"банан",L"машина",L"город",L"кровать",L"медведь",L"время",L"телефон",L"азбука",L"дом",L"магазин",L"газета", L"ухо",L"рыба",L"футбол"};
    srand(time(0));
    int colnum = rand() % 5 + 1;
    if (z == 2) {
        for (int i = 0; i < colnum; i++) {
            words += a[rand() % 17];
            words += L'\\';
        }
        words.pop_back();
    }
    else if(z==5){
        nums = rand() % 1000000 + 1;
        words = to_wstring(nums);
    }
    else {
        for (int i = 0; i < colnum; i++) {
            words += a[rand() % 17];
            words += L' ';
        }
        words.pop_back();
    }
    return words;
}

wstring shifr(wstring &text, wstring &gamma){
    wstring result=text;
    for (int i=0;i<text.length();i++){
        result[i]=text[i]^gamma[i];
    }
    return result;
}

wstring create_gamma(int length, int seed){
    wstring gamma(length,' ');
    mt19937 rng(seed);
    uniform_int_distribution<> distrib(127, 255);
    for (int i=0;i<length;i++){
        gamma[i]=static_cast<char>(distrib(rng));
    }
    return gamma;
}

void z1(wstring words){
    int count=0;
    int cmax=0;
    for (wchar_t c : words){
        if (isspace(static_cast<unsigned char>(c))){
            if (count>cmax){
                cmax=count;
            }
            count=0;
        }
        else{
            count++;
        }
    }
    if (count>cmax){
        cmax=count;
    }
    
    wcout << L"Введённая строка: "<< words << endl;
    wcout << L"Длинна самого длинного слова: "<<cmax << endl;
}

void z2(wstring words){
    wcout << L"Введённая строка: " << words << endl;
    replace(
        words.begin(),
        words.end(),
        '\\',
        '/');
    wcout << L"Обновленная строка: " << words << endl;
}

void z3(wstring words){
    int key=1234;
    wstring gamma=create_gamma(words.length(),key);
    wstring hidden=shifr(words,gamma);
    wstring gamma2=create_gamma(hidden.length(),key);
    wstring oldtext=shifr(hidden,gamma2);
    wcout << L"Изначальный текст: " << words << endl;
    wcout << L"Зашифрованный текст: " << hidden << endl;
    wcout << L"Расшифрованный текст: " << oldtext << endl;
}

void z4(wstring words){
    wchar_t chast=L' ';
    int count,cmax=0;
    for (int i=0; i<words.length();i++){
        count=0;
        for (int j=0; j<words.length();j++){
            if (words[i]==words[j] && !isspace(words[i])) {
                count++;
            }
        }
        if (count >= cmax){
            cmax=count;
            chast=words[i];
        }
    }
    wcout << L"Введённая строка: " << words << endl;
    wcout << L"Символ который встречается наибольшее количество раз '" << chast << L"' количество этих символов: " << cmax << endl;
}

bool checknum(wstring words){
    for (char c : words) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

void z5(wstring words){
    long long int num=stoi(words),x;
    wstring res=L"";
    while (num>0){
        x=num%18;
        if (x>=0 && x<=9){
            res=wchar_t('0'+x)+res;
        }
        else if (x>=10 && x<=17){
            res=wchar_t('A'+(x-10))+res;
        }
        num/=18;
    }
    wcout << L"Число " << words << L" в 18-й системе счисления: " << res << endl;
}

void z6(wstring words){
    wstring morse=L"";
    bool flag = true, flag2 = true;
    while (flag){
        for (wchar_t x : words){
            x = towupper(x);
            switch(x){
                case L'А':
                case 'A':
                    morse+=L"·− ";
                    break;
                case L'Б':
                case 'B':
                    morse+=L"−··· ";
                    break;
                case L'Ц':
                case 'C':        
                    morse+=L"−·−· ";
                    break;
                case L'В':
                case 'W':
                    morse+=L"·−− ";
                    break;
                case L'Г':
                case 'G':
                    morse+=L"−−· ";
                    break;
                case L'Д':
                case 'D':
                    morse+=L"−·· ";
                    break;
                case L'Е':
                case 'E':
                    morse+=L"· ";
                    break;
                case L'Ж':
                case 'V':
                    morse+=L"···− ";
                    break;
                case L'З':
                case 'Z':
                    morse+=L"−−·· ";
                    break;
                case L'И':
                case 'I':
                    morse+=L"·· ";
                    break;
                case L'Й':
                case 'J':
                    morse+=L"·−−− ";
                    break;
                case L'К':
                case 'K':
                    morse+=L"−·− ";
                    break;
                case L'Л':
                case 'L':
                    morse+=L"·−·· ";
                    break;
                case L'М':
                case 'M':
                    morse+=L"−− ";
                    break;
                case L'Н':
                case 'N':
                    morse+=L"−· ";
                    break;
                case L'О':
                case 'O':
                    morse+=L"−−− ";
                    break;
                case L'П':
                case 'P':
                    morse+=L"·−−· ";
                    break;
                case L'Р':
                case 'R':
                    morse+=L"·−· ";
                    break;
                case L'С':
                case 'S':
                    morse+=L"··· ";
                    break;
                case L'Т':
                case 'T':
                    morse+=L"− ";
                    break;
                case L'У':
                case 'U':
                    morse+=L"··− ";
                    break;
                case L'Ф':
                case 'F':
                    morse+=L"··−· ";
                    break;
                case L'Х':
                case 'H':
                    morse+=L"···· ";
                    break;
                case L'Ч':
                case L'Ö':
                    morse+=L"−−−· ";
                    break;
                case L'Ш':
                    morse += L"−−−− ";
                    break;
                case L'Щ':
                case 'Q':
                    morse+=L"−−·− ";
                    break;
                case L'Ъ':
                case L'Ñ':
                    morse+=L"−−·−− ";
                    break;
                case L'Ы':
                case 'Y':
                    morse+=L"−·−− ";
                    break;
                case L'Ь':
                case 'X':
                    morse+=L"−··− ";
                    break;
                case L'Э':
                case L'É':
                    morse+=L"··−·· ";
                    break;
                case L'Ю':
                case L'Ü':
                    morse+=L"··−− ";
                    break;
                case L'Я':
                case L'Ä':
                    morse+=L"·−·− ";
                    break;
                default:
                    if (isspace(x))
                        morse += L'\\';
                    else {
                        wcout << L"В строке есть недопустимые символы!" << endl;
                        flag = false;
                        flag2 = false;
                    }
                    break;
            }
        }
        flag=false;
    }
    if (flag2) {
        wcout << L"Введённая строка: " << words << endl;
        wcout << L"Зашифрованная строка: " << morse << endl;
    }
}

long long ten(wstring n) {
    long long result = 0;
    int osn = 1;
    for (int i = n.length() - 1; i >= 0; i--) {
        if (n[i] >= '0' && n[i] <= '9') {
            result += (n[i] - '0') * osn;
        }
        if (n[i] >= 'A' && n[i] <= 'F') {
            result += (n[i] - 'A' + 10) * osn;
        }
        osn *= 16;
    }
    return result;
}

wstring sixtoten(wstring num1, wstring num2, wchar_t t) {
    wstring result=L"";
    long long n1,n2,res,x;
    n1 = ten(num1);
    n2 = ten(num2);
    if (t == '+') {
        res = n1 + n2;
    }
    else if (t == '*') {
        res = n1 * n2;
    }
    while (res > 0) {
        x = res % 16;
        if (x >= 0 && x <= 9) {
            result = wchar_t('0' + x) + result;
        }
        else if (x >= 10 && x <= 15) {
            result = wchar_t('A' + (x - 10)) + result;
        }
        res /= 16;
    }
    return result;
}

bool issix(wstring n) {
    for (char c : n) {
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
            return false;
        }
    }
    return true;
}

void z7() {
    wifstream f1("FN1.txt");
    wofstream f2("FN2.txt");
    wstring n1, n2, res1, res2, a;
    wchar_t q, t;
    while (getline(f1,a)) {
        if (issix(n1) && issix(n2)){
            wstringstream ss(a);
            if (ss >> n1 >> t >> n2 >> q >> res1) {
                res2 = sixtoten(n1, n2, t);
                if (res1 != res2) {
                    f2 << n1 << t << n2 << q << res1 << '!' << endl;
                }
                else {
                    f2 << n1 << t << n2 << q << res1 << endl;
                }
            }
            else {
                f2 << L"Недопустимая строка!" << endl;
            }
        }
        else {
            f2 << L"Недопустимая строка!" << endl;
        }
    }
    wcout << L"Проверьте файл FN2.txt!" << endl;
}

bool z1_check(wstring words) {
    for (wchar_t x : words) {
        if (!(x >= L'\u0400' && x <= L'\u04FF' || isspace(x))){
            return false;
        }
    }
    return true;
}

bool z2_check(wstring words) {
    for (wchar_t x : words) {
        if (x == L'\\')
            return true;
    }
    return false;
}