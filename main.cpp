#include <iostream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "h.h"

using namespace std;

int main() {
	locale::global(locale(""));
	int original_mode_out = _setmode(_fileno(stdout), _O_U16TEXT);
	int original_mode_in = _setmode(_fileno(stdin), _O_U16TEXT);
	setlocale(LC_ALL, "RU");

	menu();
}
