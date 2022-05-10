
#include "Libraries.h"

#include "AdditionalTask.h"

class Date {
protected:
	int sizeDate;
};
class IConversion
{
public:
	virtual void copy() = 0;
	virtual operator int() = 0;
	virtual operator string() = 0;
};
class IList {
	virtual void push(int a) = 0;
	virtual void pop() = 0;
	virtual void clear() = 0;
};
class DynamicMassive : public IConversion, public Date, public IList {
private:
	int sizeMas;
	int* Mas;
	int count = 0;
public:
	DynamicMassive(int sizeMas)
	{
		this->sizeMas = sizeMas;
		this->Mas = new int[sizeMas];
		for (int i = 0; i < sizeMas; i++)
		{
			Mas[i] = 0;
		}
	}
	void copy() override {}
	operator int() override
	{
		return sizeDate;
	}
	operator string() override {
		string temp;
		for (int i = 0; i < sizeMas; i++)
		{
			temp += to_string(Mas[i]) + " ";
		}
		return temp;
	}
	void push(int a) override
	{
		for (int i = 0; i < sizeMas; i++)
		{
			if (Mas[i] == 0)
			{
				Mas[i] = a;
				count++;
				break;
			}
		}
		sizeDate += 1;
	}
	void pop() override
	{
		int rando;
		rando = 1 + rand() % (count - 1);
		cout << rando;
		cout << " Random: " << Mas[rando] << endl;
	}
	void clear() override
	{
		sizeDate = 0;
		delete Mas;
	}
	void show()
	{
		for (int i = 0; i < sizeMas; i++)
		{
			cout << "Show: " << Mas[i] << endl;
		}
		cout << "SizeDate: " << sizeDate << endl;
	}
};
class DataQueue : public IList, public IConversion, public Date {
private:
	class Node {
	public:
		int date;
		Node* next;
		Node(int date, Node* next = NULL)
		{
			this->next = next;
			this->date = date;
		}
	};

	Node* head;
	int sizeList;
public:
	DataQueue() {}
	void copy() override {}
	operator int() override { return sizeDate; }
	operator string() override {
		Node* ptr = head;
		string temp;
		while (ptr != NULL)
		{
			temp += to_string(ptr->date) + " ";
			ptr = ptr->next;
		}
		return temp;
	}
	void push(int a) override {
		if (head == NULL)
		{
			head = new Node(a);
		}
		else
		{
			Node* ptr = head;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = new Node(a);
		}
		sizeDate++;
	}
	void pop()override
	{
		Node* temp = head;
		cout <<"Delete: " << head->date << endl;
		head = head->next;
		delete temp;
	}
	void clear() override
	{
		//Node* ptr = head;
		Node* temp = head;
		while (head != NULL) {
			cout << "Delete: " << head->date << endl;
			head = head->next;
		}
		delete temp;
	}
	void show() {
		Node* ptr = head;
		while (ptr != NULL)
		{
			cout << "Element: " << ptr->date << endl;
			ptr = ptr->next;
		}
	}
};

void additionalTask() {
	srand(time(NULL));
	int size = 4;
	//int mas[3] = { 1,2,3 };
	//int mas1[3] = { 3,2,1 };
	DynamicMassive a = DynamicMassive(size);
	a = DynamicMassive(size);
	cout << "Добавление(Push): " << endl;
	a.push(2);
	a.push(3);
	a.push(9);
	a.push(6);
	a.show();
	cout << "Удаение(POP): " << endl;
	a.pop();
	a.pop();
	a.pop();
	cout << "Очистка(Clear): " << endl;
	a.clear();
	a.show();
	cout << endl;

	DataQueue a1 = DataQueue();
	a1.push(5);
	a1.push(6);
	a1.push(7);
	a1.show();
	cout << "Удаение(POP): " << endl;
	a1.pop();
	a1.show();
	cout << "метод Operator INT: " << endl;
	cout << "INT: " << a1.operator int() << endl;
	cout << "метод Operator STRING: " << endl;
	cout << "STRING: " << a1.operator string() << endl;
	a1.clear();
	a1.show();
	system("pause");
	system("cls");
	return;
}