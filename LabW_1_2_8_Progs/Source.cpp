
#include "Libraries.h"

#include "FirstGeneralTask.h"
#include "SecondGeneralTask.h"
#include "IndividualTask.h"

using namespace std;

enum class MAIN_MENU 
{
	Exit,
	FirstGeneralTask,
	SecondGeneralTask,
	IndividualTask
};

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));
	int q=0;

	while (true) 
	{
		if (q > 0) cin.ignore(32767, '\n');
		q++;
		cout << "\n\t\tОбщие задания\n\t1. Задание 1\t2. Задание 2\n\n\t3. Индивидуальное задание 7 вариант\n\n\tДополнительное задание отсутствует\n\n\t0. Выход\n\n\t";
		char inputNum;
		cin >> inputNum;

		int L;
		try
		{
			L = isInteger(inputNum);
		}
		catch (const exception& err)
		{
			cout << "\n\t" << err.what() << " ... ";
			char p = _getch();
			system("cls");
			continue;
		}

		system("cls");
		switch ((MAIN_MENU)L) 
		{
			case MAIN_MENU::Exit: 
				return 0;

			case MAIN_MENU::FirstGeneralTask: 
			{
				try
				{
					firstGeneralTask();
				}
				catch (const exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
					//break;
				}	
				break;
			}

			case MAIN_MENU::SecondGeneralTask: 
			{
				try 
				{
					secondGeneralTask();
				}
				catch (const exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
					//break;
				}
				break;
			}

			case MAIN_MENU::IndividualTask: 
			{
				try 
				{
					individualTask();
				}
				catch (const exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
					//break;
				}
				break;
			}

			default: {cout << "\n\tВведено неверное значение, нажмите любую клавишу для продолжения... "; char p = _getch(); system("cls"); break; }
		}
		system("cls");
	}
}