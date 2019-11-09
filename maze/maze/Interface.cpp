#include "Interface.h"
#include "Algoritm.h"
using namespace std;

enum RestartApp { Restart = 2 };
enum Command_mode { Exit = 1, User, Unit_Test };
enum ExceptionType { InvalidArg, NegativArg, InvalidName, FileNotExist, Error };

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

void Run() {
	int correct_value = 0;
	bool is_result = true;
	while (is_result != false) {
		for (int i = 0; i < 1;) {
			try {
				cout << "Select first command:" << endl;
				cout << "1-Exit, 2-Console, 3-Unit Test" << endl;
				correct_value = (int)ValidateValue();
				switch (correct_value) {
				case User: {
					mazeBuild() ? i++ : i = 0;
					break;
				}
				case Unit_Test: {
					//UnitTest() ? i++ : i = 0;
					break;
				}
				case Exit: exit(1);
				default: throw Exception(NegativArg, (char*)"Negativ argument!"); cout << endl; break;
				}
			}
			catch (Exception e)
			{
				e.display();
			}
		}
		try {
			for (int i = 0; i < 1;) {
				cout << "Select third command:" << endl;
				cout << "1-Exit, 2-Restart" << endl;
				correct_value = (int)ValidateValue();
				switch (correct_value) {
				case Exit: exit(1); break;
				case Restart: i++; cout << endl; break;
				default: throw Exception(NegativArg, (char*)"Negativ argument!"); cout << endl; break;
				}
			}
		}
		catch (Exception e)
		{
			e.display();
		}
	}
}

