#include "Algoritm.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <ctime>
#include <windows.h> 
#include <stdio.h>

#define MAX_LENGTH 255
using namespace std;

enum Command_mode { Exit = 1, inFile, User, Unit_Test };
enum Dialog { Yes = 1, No, SaveData, SaveResult };
enum ExceptionType { InvalidArg, NegativArg, InvalidName, FileNotExist, Error };
enum NumTest { Test1, Test2, Test3, Test4, Test5 };

// Исключения;
class Exception
{
	int num;
	char *str;
public:
	Exception(int num, char *str) {
		this->num = num;
		this->str = str;
	}
	// Вывод исключения;
	void display() {
		cout << "Exception - #" << num << ", "
			<< str << endl;
	}
};

int mazeBuild() {
	string b[1000], t = "p";
	int a = 1, c[1000], c1 = 2, n, k = 0, height = 0, width = 0;
	try {
		while (height % 2 == 0 || width % 2 == 0 || height < 5 || width < 5 || (height + 2)*(width + 2) >= 1000 || width>70) {
			cout << "Введите нечетную высоту (рекомендуется > 20)" << endl;
			height = ValidateValue();
			cout << "Введите нечетную ширину (рекомендуется > 20)" << endl;
			width = ValidateValue();
			if (height < 5) cout << "Маленькая высота!" << endl;
			if (width < 5) cout << "Маленькая ширина!" << endl;
			if ((height + 2)*(width + 2) >= 1000) cout << "Слишком большой лабиринт" << endl;
			if (width > 70)cout << "Слишком большая ширина" << endl;
			if (width % 2 == 0 || height % 2 == 0)cout << "Числа должны быть нечетными!" << endl;
		}
		height += 2;
		width += 2;
		for (int x = 0; x < height*width; x++) {
			b[x] = " ";
			if (x < width)b[x] = "+"; // верхняя граница лабиринта
			if (x > height*width - width - 1)b[x] = "+"; //нижняя граница лабиринта
			if (x % width == 0)b[x] = "+"; //левая боковая граница
			if (x % width == width - 1)b[x] = "+"; //правая боковая граница
		}
		while (a % 2 == 1)
			a = rand() % (width - 4) + width * height - width + 2;
		b[a] = ".";
		b[a - width] = ".";
		a = 1;
		while (a % 2 == 1)
			a = rand() % (width - 4) + 2;
		b[a] = ".";
		b[a + width] = ".";
		a += width * 2;
		cout << 1;
		while (c1 > 1) {
			int a1 = a;
			if (k < 15) {
				c[c1] = a;
				c1++;
			}
			b[a] = ".";
			k = 0;
			while (a1 == a && k < 15) {
				n = rand() % 4 + 1;
				if (n == 1 && b[a + 2] == " ")a++;
				if (n == 2 && b[a + width * 2] == " ")a += width;
				if (n == 3 && b[a - width * 2] == " ")a -= width;
				if (n == 4 && b[a - 2] == " ")a--;
				k++;
			}
			if (k == 15) {
				c[c1 - 1] = 0;
				c1 -= 2;
				a = c[c1];
				c1++;
			}
			if (a > 0)
				b[a] = ".";
			if (a < 0)
				c1 = 0;
			if (k < 15) {
				if (n == 1)a++;
				if (n == 2)a += width;
				if (n == 3)a -= width;
				if (n == 4)a--;
				b[a] = ".";
			}
		}
		b[width * 2] = "+";
		for (int x = 0; x < width*height; x++) {
			if (b[x] == "+")b[x] = "";
			if (b[x] == " ")b[x] = "|"; //Все стенки внутри лабиринта (подходят символы # , / , |, +)
			if (x > width * 2 || x < width)
				if (b[x] == ".")b[x] = " ";
		}
		system("CLS");
		for (int x = 0; x < width*height; x++) {
			cout << b[x];
			if (x % width == width - 1)
				cout << endl;
		}
		return 1;
	}
	catch (Exception e) {
		e.display();
		return 0; 

	}

}

// Функция корректного ввода;
double ValidateValue() {
	double tmp;
	bool isInputSuccessful = true;
	do {
		try {
			cin >> tmp;
			isInputSuccessful = true;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				isInputSuccessful = false;
				throw Exception(InvalidArg, (char*)"Invalid argument! Repeat:");
			}
			else {
				cin.ignore(INT_MAX, '\n');
				return tmp;
			}
		}
		catch (Exception e) {
			e.display();
		}
	} while (!isInputSuccessful);
}

////Прохождение //void mazeSolve()
	//int a1, a2, m[1000], j, h = 0;
	//c1 = 0;
	//cout << "Хотите следить за прохождением лабиринта? yes/no ";
	//while (h == 0) {
	//	cin >> t;
	//	if (t == "yes") {
	//		h = 1;
	//		j = 0;
	//	}
	//	if (t == "no") {
	//		h = 1;
	//		j = 1;
	//	}
	//}
	//k = j;
	//for (int x = 0; x < width; x++) {
	//	for (int y = 0; y < width*height; y++)
	//		b[y] = b[y + 1];
	//}
	//for (int x = 0; x < width; x++)
	//	if (b[x] == ".")
	//		a = x;
	//for (int x = width * (height - 3) - 1; x < width*(height - 2); x++)
	//	if (b[x] == " ")
	//		a1 = x;
	//for (int x = 0; x < 1000; x++)
	//	c[x] = 0;
	//b[a] = ".";
	//while (a != a1) {
	//	if (k == 0) {
	//		system("CLS");
	//		for (int x = 0; x < width*height; x++) {
	//			cout << b[x];
	//			if (x % width == width - 1)
	//				cout << endl;
	//		}
	//		Sleep(150);
	//	}
	//	n = 0;
	//	a2 = a;
	//	while (a2 == a) {
	//		n++;
	//		k = j;
	//		if (n == 1 && b[a - width] == " "&&a - width > 0 && m[a - width] != 666)a -= width;
	//		if (n == 2 && b[a - 1] == " "&&m[a - 1] != 666)a--;
	//		if (n == 3 && b[a + 1] == " "&&m[a + 1] != 666)a++;
	//		if (n == 4 && b[a + width] == " "&&m[a + width] != 666)a += width;
	//		if (n == 5) {
	//			k = 1;
	//			n = 0;
	//			c1--;
	//			b[a] = " ";
	//			m[a] = 666;
	//			c1--;
	//			a = c[c1];
	//			c1++;
	//		}
	//	}
	//	b[a] = ".";
	//	c[c1] = a;
	//	c1++;

	//}
	//system("CLS");
	//for (int x = 0; x < width*height; x++) {
	//	if (b[x] == ".")
	//		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
	//	cout << b[x];
	//	if (x % width == width - 1)
	//		cout << endl;
	//	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
	//}
