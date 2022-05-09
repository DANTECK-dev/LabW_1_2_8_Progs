
#include "Libraries.h"

#include "IndividualTask.h"

#include "ListOfBuyers.h"

enum class individualTaskMenu
{
	Exit,
	Add,
	Sort,
	Transform,
	Del,
	Show,
	Search,
	Save,
	Load,
	URL
};

void individualTask() {
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	ListOfBuyers p;

	while (true) {
		cout << "\n\t   ___ ___     ______    __  ___     __    __";
		cout << "\n\t /' __` __`\\  /\\  ___\\  /\\ \\/ __`\\  /\\ \\  /  \\";
		cout << "\n\t /\\ \\/\\ \\/\\ \\ \\ \\  ___\\ \\ \\  /_ \\ \\ \\ \\ \\/ /\\ \\";
		cout << "\n\t \\ \\_\\ \\_\\ \\ \\ \\ \\_____\\ \\ \\_\\ \\ \\_\\ \\ \\__/\\ \\_\\";
		cout << "\n\t  \\/_/\\/_/\\/_/  \\/_____/  \\/_/  \\/_/  \\/__/ \\/_/\n";
		cout << "\n\t  ----== Введите номер нужного действия ==----  ";
		cout << "\n\t       ----== 1. Добавить  клиента ==----       ";
		cout << "\n\t   ----== 2. Сортировать всех клиентов ==----   ";
		cout << "\n\t    ----== 3. Изменить данные клиента ==----    ";
		cout << "\n\t    ----== 4. Удалить  данные клиента ==----    ";
		cout << "\n\t    ----== 5. Вывести список клиентов ==----    ";
		cout << "\n\t     ----== 6. Поиск клиента по базе ==----     ";

#if VER == 2

		cout << "\n\t  ----== 7. Сохранить все  данные в файл==----  ";
		cout << "\n\t   ----== 8. Загрузить данные из файла ==----   ";

#elif VER == 1

		cout << "\n\t----== 9. Купите премиум версию программы ==----";
		cout << "\n\t----== Чтобы загружать и  выгружать файлы ==----";

#endif
		cout << "\n\t             ----== 0. Выход ==----             \n\t";

		char inputNum;
		cin >> inputNum;
		system("cls");
		int N = isInteger(inputNum);
		switch ((individualTaskMenu)N) {
		case individualTaskMenu::Exit:		return;
		case individualTaskMenu::Add: {p.addClients(); break; }
		case individualTaskMenu::Sort: {p.sortClients(); break; }
		case individualTaskMenu::Transform: {p.transformClients(); break; }
		case individualTaskMenu::Del: {p.delClients(); break; }
		case individualTaskMenu::Show: {p.showClients(); break; }
		case individualTaskMenu::Search: {p.searchClients(); break; }
#if VER == 2
		case individualTaskMenu::Save: {p.saveClients(); break; }
		case individualTaskMenu::Load: {p.downloadClients(); break; }
#elif VER == 1
		case individualTaskMenu::URL: {system("start pay.html"); break; }
#endif
		default: {
			cout << "\n\tВведено неверное значение";
			system("pause");
			system("cls");
			break;
		}
		}
	}
}