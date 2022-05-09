
#include "FirstGeneralTask.h"

#include "ThisIs.h"

#include "Libraries.h"

using namespace std;
template<typename T>
class SetMassive {
public:

	SetMassive() {
		this->pHead = nullptr;
		this->SIZE = 0;
	}
	~SetMassive() {
		clearAll();
	}
	int getSize() {
		return SIZE;
	}
	void pushBack(const T data) {
		if (SetMassive::chekValue(data))
			return;
		if (this->pHead == nullptr) {
			this->pHead = new Mass(data);
		}
		else {
			Mass* pTemp = this->pHead;
			while (pTemp->pNext != nullptr) {
				pTemp = pTemp->pNext;
			}
			pTemp->pNext = new Mass(data);
		}
		this->SIZE++;
	}
	void showAll() {
		Mass* pTemp = this->pHead;
		while (pTemp != nullptr) {
			cout << pTemp->data << " ";
			pTemp = pTemp->pNext;
		}
	}
	void deleteMass(const int index) {
		int counter = 0;
		Mass* pTemp = this->pHead;

		if (counter == index) {
			this->pHead = this->pHead->pNext;
			delete pTemp;
		}

		else {

			for (; counter < index - 1; counter++) {
				pTemp = pTemp->pNext;
			}

			Mass* pTempForDelete = pTemp->pNext;
			pTemp->pNext = pTempForDelete->pNext;
			delete pTempForDelete;
		}

		this->SIZE--;
	}
	void clearAll() {
		for (int i = 0; i < getSize(); i++) {
			deleteMass(i);
		}

		this->SIZE = 0;
	}
	bool chekValue(const T value) {
		Mass* pTemp = this->pHead;
		while (pTemp != nullptr) {
			if (pTemp->data == value) {
				return true;
			}
			pTemp = pTemp->pNext;
		}
		return false;
	}
	void operator+(const T data) {
		SetMassive::pushBack(data);
	}
	void operator+(const SetMassive& other) {
		Mass* pTemp = other.pHead;
		while (pTemp != nullptr) {
			SetMassive::pushBack(pTemp->data);
			pTemp = pTemp->pNext;
		}
	}
	void operator-(const T data) {
		if (SetMassive::chekValue(data)) {
			deleteMass(getIndexOfValue(data));
		}
		else {
			cout << "none";
		}
	}
	void operator-(const SetMassive& other) {
		Mass* pTemp = other.pHead;
		while (pTemp != nullptr) {
			if (SetMassive::chekValue(pTemp->data)) {
				cout << pTemp->data << " ";
			}
			pTemp = pTemp->pNext;
		}
		cout << "\n\t";
	}
	int& operator[](const int index) {
		Mass* pTemp = this->pHead;

		if (index == 0) {
			return pTemp->data;
		}

		else {
			int counter = 0;
			while (counter != index) {
				pTemp = pTemp->pNext;
				counter++;
			}
			return pTemp->data;
		}
	}
	int getIndexOfValue(const T value) {
		int counter = 0;
		Mass* pTemp = this->pHead;
		while (pTemp->data != value) {
			pTemp = pTemp->pNext;
			counter++;
		}
		return counter;
	}

private:
	class Mass {
	public:
		T data;
		Mass* pNext;
		Mass(T data = 0, Mass* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int SIZE;
	Mass* pHead;
};

void firstGeneralTask() {
	cout << "\n\t";
	SetMassive<int> it;
	it.pushBack(343333);
	it.pushBack(5676);
	it.pushBack(2343222);
	SetMassive<int> it2;
	it2.pushBack(343333);
	it2.pushBack(56);
	it2.pushBack(2343222);
	SetMassive<string> it3;
	it3.pushBack("fdggg");
	it3.pushBack("cxvb");
	it3.pushBack("gddfff");
	it3.pushBack("mvbr");
	SetMassive<string> it4;
	it4.pushBack("fdggg");
	it4.pushBack("cxv");
	it4.pushBack("gddfff");
	it4.pushBack("mvr");
	it - it2;
	cout << "\n\t";
	it3 - it4;
	cout << "\n\t";
	it.showAll();
	cout << "\n\t";
	it2.showAll();
	cout << "\n\t";
	it3.showAll();
	cout << "\n\t";
	it4.showAll();
	cout << "\n\t";
	system("pause");
	return;
}