#include "SecondGeneralTask.h"
#include "ClassesForSecondGeneralTask.h"

#include "Libraries.h"


void inputGeneral(string &name, string &companyName, int &price, int &weight) {
	cout << "\n\n\tНазвание: ";
	cin >> name;
	cout << "\n\tНазвание компании: ";
	cin >> companyName;
	cout << "\n\tЦена: ";
	cin >> price;
	cout << "\n\tВес: ";
	cin >> weight;
}

void newProduct(Product*& Current, Product*& Head, string name, string companyName, 
	int price, int weight, bool open, int expirationDateInCloseState,
	int expirationDateInOpenState, int expirationDate, string typeOfComponent, string productType) {
	if (Current == NULL) {
		Current = new Product(name, companyName, price, weight, open, expirationDateInCloseState,
			expirationDateInOpenState, expirationDate, typeOfComponent, productType);
		Head = Current;
	}
	else if (Current->next == NULL) {
		Current->next = new Product(name, companyName, price, weight, open, expirationDateInCloseState,
			expirationDateInOpenState, expirationDate, typeOfComponent, productType);
		Current = Current->next;
	}
}
void secondGeneralTask()
{
	int counter = 0;
	const int size = 10;
	Product* products = NULL;
	Product* head = NULL;
	/*Product* products = static_cast<Product*>(operator new[](size * sizeof(Product)));
	//Product** products = new Product*[size];
	for (int i = 0; i < size; i++)
		new (products + i) Product();
		//products[i] = new Product();*/
	while (true) {
		system("cls");
		string	productType					= { "None" };
		string	typeOfComponent				= { "None" };
		string	companyName					= { "None" };
		string	name						= { "None" };
		int		expirationDateInCloseState	= 0;
		int		expirationDateInOpenState	= 0;
		int		expirationDate				= 0;
		int		price						= 0;
		int		weight						= 0;
		bool	open						= false;
		cout << "\n\t1 - Добавить новый продукт"
			<< "\n\t2 - Вывести все продукты"
			<< "\n\t0 - Выход\n\t";
		int inputNum;
		cin >> inputNum;
		system("cls");
		switch (inputNum) {
			case (0): return;
			case (1): {
				cout << "\n\tДобавить Товар"
					<< "\n\t1 - Продукт питания"
					<< "\n\t2 - Электронный товар"
					<< "\n\t0 - Выход\n\t";
				cin >> inputNum;
				system("cls");
				switch (inputNum) {
					case (0): return;
					case (1): {
						cout << "\n\tДобавить продукт питания"
							<< "\n\t1 - Консервированный продукт"
							<< "\n\t2 - Свежий продукт"
							<< "\n\t0 - Выход\n\t";
						cin >> inputNum;
						system("cls");
						switch (inputNum) {
							case (0): return;
							case (1): {
								cout << "\n\tДобавить консервированный продукт";
								inputGeneral(name, companyName, price, weight);
								cout << "\n\tОткрыта ли консервы: \n\t1 - Открыта\n\t2 - Закрыта\n\t0 - Выход\n\t";
								cin >> inputNum;
								switch (inputNum) {
									case(0): return;
									case(1): {
										open = true;
										cout << "\n\tСрок годности(открытой консервы): ";
										cin >> expirationDateInOpenState;
										break;
									}
									case(2): {
										open = false;
										cout << "\n\tСрок годности(закрытой консервы): ";
										cin >> expirationDateInCloseState;
										break;
									}
									default: {
										cout << "\n\tОшибка ввода \n\n\t";
										system("pause");
										continue;
									}
								}
								newProduct(products, head, name, companyName, price, weight,
									open, expirationDateInCloseState, expirationDateInOpenState,
									expirationDate, typeOfComponent, productType);
								counter++;
								break;
							}
							case (2): {
								cout << "\n\tДобавить свежий продукт";
								inputGeneral(name, companyName, price, weight);
								cout << "\n\tСрок годности: ";
								cin >> expirationDate;
								newProduct(products, head, name, companyName, price, weight,
									open, expirationDateInCloseState,expirationDateInOpenState, 
									expirationDate, typeOfComponent, productType);
								counter++;
								break;
							}
							default: {
								cout << "\n\tОшибка ввода \n\n\t";
								system("pause");
								continue;
							}
						}
						break;
					}
					case (2): {
						cout << "\n\tДобавить электронный продукт";
						inputGeneral(name, companyName, price, weight);
						cout << "\n\tТип продукта: ";
						cin >> productType;
						cout << "\n\tТип комплетующего: ";
						cin >> typeOfComponent;
						newProduct(products, head, name, companyName, price, weight,
							open, expirationDateInCloseState, expirationDateInOpenState,
							expirationDate, typeOfComponent, productType);
						counter++;
						break;
					}
					default: {
						cout << "\n\tОшибка ввода \n\n\t";
						system("pause");
						continue;
					}
				}
				break; 
			}
			case (2): {
				products = head;
				if (head == NULL) {
					cout << "\n\tEmpty\n\t";
					system("pause");
					break;
				}
				int days = 0;
				while (true) {
					string temp = *products;
					cout << "\n\t" << temp;
					days += products->getExpirationDate();
					if (products->next == NULL)break;
					products = products->next;
				}
				cout << "\n\tОбщая сумма сроков годности: " << days << "\n\n\t";
				system("pause");
				continue;
			}
			default: {
				cout << "\n\tОшибка ввода \n\n\t";
				system("pause");
				continue;
			}
		}
	}
	return;
}