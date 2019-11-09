#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <ctime>
#include <windows.h> 
#include <stdio.h>
#include "Algoritm.h"
#include "Interface.h"
using namespace std;
int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
	setlocale(0, "rus");
	srand(time(0));

	Run();

	system("pause");
	return 0;
}

