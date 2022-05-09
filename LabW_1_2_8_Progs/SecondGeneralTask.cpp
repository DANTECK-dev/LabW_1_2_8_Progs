#include "SecondGeneralTask.h"
#include "ClassesForSecondGeneralTask.h"

#include "Libraries.h"

//При создании ключа, не нумеруются строки
class KeyGen {
public:
	virtual string get() = 0;
	static KeyGen* random(int n);
	static KeyGen* order(string str);
};
class Rand : public KeyGen{
public:
	Rand() {}
	Rand(int n) {
		this->n = n;
		size += 1;
	}
	string get() override {
		string str;
		srand(time(NULL));
		for (int i = 0; i < n; i++){
			str += to_string(0 + rand() % 9);
		}
		return str;
	}
	friend KeyGen* KeyGen::random(int n);
	int GetN() {
		return n;
	}
protected:
	int n, size;
};
class Order : KeyGen, Rand {
public:
	Order() {}
	Order(string str) {
		this->str = str;
	}
	string get() override {
		str += to_string(size);
		return str;	
	}
	friend KeyGen* KeyGen::order(string str);
private:
	string str;
};
KeyGen* KeyGen::random(int n){
	return static_cast<KeyGen*>(new Rand(n));
}
KeyGen* KeyGen::order(string str) {
	return static_cast<KeyGen*>(new Order(str));
}

void secondGeneralTask() {
	KeyGen* a;
	a = KeyGen::order("str");
	cout << a->get() << " : ";
	a = KeyGen::random(4);
	cout << a->get() << endl;
	cout << "*******************************" << endl;
	a = KeyGen::order("Key");
	cout << a->get() << " : ";
	a = KeyGen::random(5);
	cout << a->get() << endl;
	system("pause");
	system("cls");
	return;
}