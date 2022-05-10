#pragma once

#include "Libraries.h"

#include "ListOfBuyers.h"

#pragma region NaturalPerson
template<typename T>
NaturalPerson<T>::NaturalPerson() {				//���������� ����
	this->FIO				= { "None" };
	this->mobilePhoneNumber = { "None" };
	this->accountNumber		= { "None" };
}
template<typename T>
NaturalPerson<T>::NaturalPerson(
	string FIO,
	T mobilePhoneNumber,
	T accountNumber
) {
	this->FIO				= FIO;
	this->mobilePhoneNumber = mobilePhoneNumber;
	this->accountNumber		= accountNumber;
}
#pragma endregion

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region LegalPerson
template<typename T>
LegalPerson<T>::LegalPerson() {					//����������� ����
	this->companuName	= { "None" };
	this->customerINN	= { "None" };
	this->accountNumber = { "None" };
}
template<typename T>
LegalPerson<T>::LegalPerson(
	string companuName,
	T customerINN,
	T accountNumber
) {
	this->companuName	= companuName;
	this->customerINN	= customerINN;
	this->accountNumber = accountNumber;

}
#pragma endregion

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region DataProduct
template<typename T>
DataProduct<T>::DataProduct() {
	this->productName		= { "None" };
	this->typeOfProduct		= { "None" };
	this->paymentDay		= { "None" };
	this->vendorINN			= { "None" };
	this->companyAddress	= { "None" };
	this->numberOfProduct	= 0;
	this->sumOfProduct		= 0;
}
template<typename T>
DataProduct<T>::DataProduct(
	T productName,
	T typeOfProduct,
	T paymentDay,
	T vendorINN,
	string companyAddress,
	int numberOfProduct,
	int sumOfProduct
) {
	this->productName		= productName;
	this->typeOfProduct		= typeOfProduct;
	this->paymentDay		= paymentDay;
	this->vendorINN			= vendorINN;
	this->companyAddress	= companyAddress;
	this->numberOfProduct	= numberOfProduct;
	this->sumOfProduct		= sumOfProduct;
}
template<typename T>
string DataProduct<T>::getDataProduct() {
	return "�������� ��������: " + this->productName 
		+ " ��� ��������: " + this->typeOfProduct 
		+ " ���� ������: " + this->paymentDay
		+ " ��� ����������: " + this->vendorINN 
		+ " ����� ����������: " + this->companyAddress
		+ " ���-�� ��������: " + to_string(this->numberOfProduct)
		+ " ����� ��������: " + to_string(this->sumOfProduct);
}
#pragma endregion

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region ListItem
template<typename T>
ListItem<T>::ListItem() {
	this->DataProduct::DataProduct();
	this->LegalPerson::LegalPerson();
	this->NaturalPerson::NaturalPerson();
	this->legalPerson = false;
	this->next = NULL;
	this->prev = NULL;
}
template<typename T>
ListItem<T>::ListItem(
	ListItem* next,
	ListItem* prev,
	bool legalPerson,
	T productName,
	T typeOfProduct,
	T paymentDay,
	T vendorINN,
	string companyAddress,
	int numberOfProduct,
	int sumOfProduct,
	string FIO,
	T mobilePhoneNumber,
	T companuName,
	T customerINN,
	T accountNumber
) {
	this->DataProduct<string>::DataProduct(
		productName,
		typeOfProduct,
		paymentDay,
		vendorINN,
		companyAddress,
		numberOfProduct,
		sumOfProduct
	);
	if (legalPerson) {
		this->LegalPerson<string>::LegalPerson(			//�� ����
			companuName,
			customerINN,
			accountNumber
		);
	}
	else {
		this->NaturalPerson<string>::NaturalPerson(		//��� ����
			FIO,
			mobilePhoneNumber,
			accountNumber
		);
	}
	this->legalPerson = legalPerson;
	this->next = next;
	this->prev = prev;
}
template<typename T>
ostream& ListItem<T>::operator << (ostream& os) {
	string personType;
	string personData;
	if (this->legalPerson) { personType = { "����������� ����" }; personData = this->LegalPerson<string>::getDataPerson(); }
	else { personType = { "���������� ����" }; personData = this->NaturalPerson<string>::getDataPerson(); }

	os << personType << " "
		<< personData << " "
		<< this->getDataProduct() << endl;
	return  os;
}
/*istream& ListItem::operator >> (istream& os) {
	string personType;
	string personData;
	string space = " ";
	if (this->legalPerson) { personType = { "����������� ����" }; personData = this->LegalPerson::getDataPerson(); }
	else { personType = { "���������� ����" }; personData = this->NaturalPerson::getDataPerson(); }

	os >> personType >> space
		>> personData >> space
		>> this->getDataProduct();
	return os;
}*/
template<typename T>
Data<T>* Data<T>::add(T data) {
	return this->ListItem<T>::ListItem();
}
#pragma endregion

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region ListOfBuyers
void ListOfBuyers::operator[](const int index) {
	ListItem<string>* LItemp = this->head;
	for (int i = 0; i < index; i++)
		LItemp = LItemp->next;
	LItemp->operator<<(cout);
}
ListOfBuyers::operator int() const {
	ListItem<string>* LItemp = this->head;
	int counter = 0;
	if (LItemp == NULL) {
		cout << counter;
	} else {
		while (true) {
			counter++;
			if (LItemp->next = NULL) break;
			LItemp = LItemp->next;
		}
		cout << counter;
	}
	return counter;
}
void ListOfBuyers::addClients			() {
	system("cls");
	cout << "\n\n\t���������� �������\n";
	cout << "\n\t1 - ���������� ����\n\t2 - ����������� ����\n\t0 - �����\n\t";
	int inputNum;
	cin >> inputNum;
	system("cls");
	switch (inputNum) {
		case(0): return;
		case(1): {
			string newSurname			= { "None" };
			string newName				= { "None" };
			string newPatronymic		= { "None" };
			string newMobilePhoneNumber	= { "None" };
			string newAccountNumber		= { "None" };

			string newProductName		= { "None" };
			string newTypeOfProduct		= { "None" };
			string newPaymentDay		= { "None" };
			char TempNewNumberOfProduct[100];
			char TempNewSumOfProduct[1000];

			cout << "\n\t\t������� ������ �������\n";
			cout << "\n\t�������: "; 	cin.get();		getline(cin, newSurname);
			cout << "\n\t���: ";						getline(cin, newName);
			cout << "\n\t��������: ";					getline(cin, newPatronymic);
			string newFIO = newSurname + " " + newName + " " + newPatronymic;

			cout << "\n\t����� ��������: ";				getline(cin, newMobilePhoneNumber);
			cout << "\n\t����� �����: ";				getline(cin, newAccountNumber);

			cout << "\n\t\t������� ������ ��������\n";
			cout << "\n\t�������� ��������: ";			getline(cin, newProductName);
			cout << "\n\t��� ��������: ";				getline(cin, newTypeOfProduct);
			cout << "\n\t���� ������ (��.��.����): ";	getline(cin, newPaymentDay);
			cout << "\n\t���-�� ���������: ";			cin.getline(TempNewNumberOfProduct, 100);
			int newNumberOfProduct = isInteger_l(TempNewNumberOfProduct);
			cout << "\n\t����� �������: ";				cin.getline(TempNewSumOfProduct, 1000);
			int newSumOfProduct = isInteger_l(TempNewSumOfProduct);
			bool newLegalPerson = false;
			system("cls");

			if (person == NULL) {
				tail = new ListItem<string>(
					NULL,
					NULL,
					newLegalPerson,
					newProductName,
					newTypeOfProduct,
					newPaymentDay,
					VendorINN,
					CompanyAddress,
					newNumberOfProduct,
					newSumOfProduct,
					newFIO,
					newMobilePhoneNumber,
					"None",
					"None",
					newAccountNumber);
				person = tail;
				head = tail;
			}
			else if (tail != NULL) {
				person = tail;
				person->next = new ListItem<string>(
					NULL,
					person,
					newLegalPerson,
					newProductName,
					newTypeOfProduct,
					newPaymentDay,
					VendorINN,
					CompanyAddress,
					newNumberOfProduct,
					newSumOfProduct,
					newFIO,
					newMobilePhoneNumber,
					"None",
					"None",
					newAccountNumber);;
				//person->next->prev = person;
				person = person->next;
				tail = person;
			}

			cout << "\n\t\t�������� \n" 
				<< "\n\t���: " << newFIO
				<< "\n\t����� ��������: " << newMobilePhoneNumber
				<< "\n\t����� �����: " << newAccountNumber
				<< "\n\t�������� ��������: " << newTypeOfProduct
				<< "\n\t��� ��������: " << newTypeOfProduct
				<< "\n\t���� ������ (��.��.����): " << newPaymentDay
				<< "\n\t���-�� ���������: " << newNumberOfProduct
				<< "\n\t����� �������: " << newSumOfProduct;
			cout << "\n\n\t";
			system("pause");
			system("cls");
			return;
		}
		case(2): {
			string newCompanyName = { "None" };
			char TempNewCustomerINN[20];
			char TempNewAccountNumber[50];

			string newProductName = { "None" };
			string newTypeOfProduct = { "None" };
			string newPaymentDay = { "None" };
			char TempNewNumberOfProduct[100];
			char TempNewSumOfProduct[1000];

			cout << "\n\t\t������� ������ �������\n";
			cout << "\n\t�������� ��������: ";cin.get();getline(cin, newCompanyName);
			cout << "\n\t����� ���: ";					cin.getline(TempNewCustomerINN, 20);
			string newCustomerINN = { "None" };
			newCustomerINN = to_string(isInteger_l(TempNewCustomerINN));
			cout << "\n\t����� �����: ";				cin.getline(TempNewAccountNumber, 50);
			string newAccountNumber = { "None" };
			newAccountNumber = to_string(isInteger_l(TempNewAccountNumber));

			cout << "\n\t\t������� ������ ��������\n";
			cout << "\n\t�������� ��������: ";			getline(cin, newProductName);
			cout << "\n\t��� ��������: ";				getline(cin, newTypeOfProduct);
			cout << "\n\t���� ������ (��.��.����): ";	getline(cin, newPaymentDay);
			cout << "\n\t���-�� ���������: ";			cin.getline(TempNewNumberOfProduct, 100);
			int newNumberOfProduct = isInteger_l(TempNewNumberOfProduct);
			cout << "\n\t����� �������: ";				cin.getline(TempNewSumOfProduct, 1000);
			int newSumOfProduct = isInteger_l(TempNewSumOfProduct);
			bool newLegalPerson = true;
			system("cls");

			if (tail == NULL && head == NULL) {
				tail = new ListItem<string>(
					NULL,
					NULL,
					newLegalPerson,
					newProductName,
					newTypeOfProduct,
					newPaymentDay,
					VendorINN,
					CompanyAddress,
					newNumberOfProduct,
					newSumOfProduct,
					"None",
					"None",
					newCompanyName,
					newCustomerINN,
					newAccountNumber);
				person = tail;
				head = tail;

			}
			else if(tail != NULL) {
				person = tail;
				person->next = new ListItem<string>(
					NULL,
					person,
					newLegalPerson,
					newProductName,
					newTypeOfProduct,
					newPaymentDay,
					VendorINN,
					CompanyAddress,
					newNumberOfProduct,
					newSumOfProduct,
					"None",
					"None",
					newCompanyName,
					newCustomerINN,
					newAccountNumber);
				//person->next->prev = person;
				person = person->next;
				tail = person;
			}
			cout << "\n\t\t�������� \n" 
				<< "\n\t�������� ��������: " << newCompanyName
				<< "\n\t����� ���: " << newCustomerINN
				<< "\n\t����� �����: " << newAccountNumber
				<< "\n\t�������� ��������: " << newTypeOfProduct
				<< "\n\t��� ��������: " << newTypeOfProduct
				<< "\n\t���� ������ (��.��.����): " << newPaymentDay
				<< "\n\t���-�� ���������: " << newNumberOfProduct
				<< "\n\t����� �������: " << newSumOfProduct;
			cout << "\n\n\t";
			system("pause");
			system("cls");
			return;
		}
		default: {
			cout << "\n\t������ ����� ";
			system("pause");
			system("cls");
			return;
		}
	}
}
//�����
void ListOfBuyers::sortClients			() {
	if (tail == NULL || head == NULL) {
		cout << "\n\n\t��� ������ �������� ��� ����������\n";
		system("cls");
		system("cls");
		return;
	}
	if (person == head && person == tail) {
		cout << "\n\n\t��� ������ �������� ��� ����������\n";
		system("cls");
		system("cls");
		return;
	}
	person = head;
	int counter = 1;
	while (true){
		counter++;
		person = person->next;
		if (person == tail) break;
	}
	person = head;
	if (person == head && person->next == tail) {
		for (int i = 1; i < counter; i++) {
			person = head;
			for (int j = 0; j < counter - i; j++) {
				if (person->getSumOfProduct() > person->next->getNumberOfProduct()) {
					head = person->next;
					person->next->next = person;
					person->prev = person->next;
					person->next->prev = NULL;
					person->next = NULL;
				}
				person = person->next;
	}	}	}
	else if (person == head && person->next != tail) {
		for (int i = 1; i < counter; i++)
		{
			person = head;

			for (int j = 0; j < counter - i; j++)
			{
				if (person->getSumOfProduct() > person->next->getNumberOfProduct())
				{
					ListItem<string>* Temp1 = person;
					ListItem<string>* Temp2 = person->next;
					ListItem<string>* Temp3 = person->next->next;

					head = person->next;
					Temp3->prev = Temp1;
					Temp2->next = Temp1;
					Temp2->prev = NULL;
					Temp1->next = Temp3;
					Temp1->prev = Temp2;
				}
				person = person->next;
			}
		}
	} 
	else if (person != head && person->next == tail) {
		for (int i = 1; i < counter; i++)
		{
			person = head;

			for (int j = 0; j < counter - i; j++)
			{
				if (person->getSumOfProduct() > person->next->getNumberOfProduct())
				{
					ListItem<string>* Temp1 = person->prev;
					ListItem<string>* Temp2 = person;
					ListItem<string>* Temp3 = person->next;

					tail = person->next;
					Temp1->next = Temp3;
					Temp2->next = NULL;
					Temp2->prev = Temp3;
					Temp3->next = Temp2;
					Temp3->prev = Temp1;
				}
				person = person->next;
			}
		}
	} 
	else if (person != head && person->next != tail) {
		for (int i = 1; i < counter; i++)
		{
			person = head;

			for (int j = 0; j < counter - i; j++)
			{
				if (person->getSumOfProduct() > person->next->getNumberOfProduct())
				{
					ListItem<string>* Temp1 = person->prev;
					ListItem<string>* Temp2 = person;
					ListItem<string>* Temp3 = person->next;
					ListItem<string>* Temp4 = person->next->next;

					Temp1->next = Temp3;
					Temp2->next = Temp4;
					Temp2->prev = Temp3;
					Temp3->next = Temp2;
					Temp3->prev = Temp1;
					Temp4->prev = Temp2;
				}
				person = person->next;
			}
		}
	}
	cout << "\n\n\t���������� �� ����� ���������\n";
	system("pause");
	system("cls");
	return;
}
//�����
void ListOfBuyers::transform			() {
	cout << "\n\n\t\t����� ������ ��������\n"
		<< "\n\t\t������ ����������\n";
	if (person->legalPerson) {
		cout << "\n\t1. �������� �������� - " << person->LegalPerson<string>::getName()
			<< "\n\t2. ����� ���" << person->LegalPerson<string>::getInfoNum()
			<< "\n\t3. ����� ����� - " << person->LegalPerson<string>::getPayNum();
	} else {
		cout << "\n\t1. ��� - " << person->NaturalPerson<string>::getName()
			<< "\n\t2. ����� ��������" << person->NaturalPerson<string>::getInfoNum()
			<< "\n\t3. ����� ����� - " << person->NaturalPerson<string>::getPayNum();
	}
	cout << "\n\t\t������ ��������\n"
		<< "\n\t4. �������� �������� - " << person->getProductName()
		<< "\n\t5. ��� �������� - " << person->getTypeOfProduct()
		<< "\n\t6. ���� ������ (��.��.����) - " << person->getPaymentDay()
		<< "\n\t7. ���-�� ��������� - " << person->getNumberOfProduct()
		<< "\n\t8. ����� ������� - " << person->getSumOfProduct()
		<< "\n\t0. �����\n\n\t";
	char InIntt;
	cin >> InIntt;

	int InInt = isInteger(InIntt);

	switch (InInt) {
		case(0): return;
		case(1): {
			if (person->legalPerson) {
				cout << "\n\n\t������� �������� ��������: ";
				string companyName;
				cin.get(); getline(cin, companyName);
				person->LegalPerson<string>::setName(companyName);
			}
			else {
				cout << "\n\n\t������� ���: ";
				string name, surname, pathr;
				cin.get(); getline(cin, surname);
				getline(cin, name);
				getline(cin, pathr);
				string FIO = surname + " " + name + " " + pathr;
				person->NaturalPerson<string>::setName(FIO);
			}
			break;
		}
		case(2): {
			if (person->legalPerson) {
				cout << "\n\n\t������� ����� ���: ";
				char charInfoNum[100];
				cin.get(); cin.getline(charInfoNum, 100);
				person->LegalPerson<string>::setInfoNum(to_string(isInteger_l(charInfoNum)));
			}
			else {
				cout << "\n\n\t������� ����� ���������: ";
				char charMobNum[100];
				cin.get(); cin.getline(charMobNum, 100);
				person->LegalPerson<string>::setInfoNum(to_string(isInteger_l(charMobNum)));
			}
			break;
		}
		case(3): {
			cout << "\n\n\t������� ����� �����: ";
			char charCustomerINN[100];
			cin.get(); cin.getline(charCustomerINN, 100);
			if (person->legalPerson) person->LegalPerson<string>::setInfoNum(to_string(isInteger_l(charCustomerINN)));
			else person->LegalPerson<string>::setInfoNum(to_string(isInteger_l(charCustomerINN)));
			break;
		}
		case(4): {
			cout << "\n\n\t������� �������� ��������: ";
			cin.get();
			string productName;
			getline(cin, productName);
			person->setProductName(productName);
			break;
		}
		case(5): {cout << "\n\n\t������� ��� ��������: ";
			cin.get();
			string productType;
			getline(cin, productType);
			person->setTypeOfProduct(productType);
			break;
		}
		case(6): {
			cout << "\n\n\t������� ���� ������ (��.��.����): ";
			cin.get();
			string payDay;
			getline(cin, payDay);
			person->setPaymentDay(payDay);
			break;
		}
		case(7): {
			cout << "\n\n\t������� ���-�� ��������: ";
			cin.get();
			char charNumOfProduct[100];
			cin.getline(charNumOfProduct, 100);
			int numOfProduct = isInteger_l(charNumOfProduct);
			person->setNumberOfProduct(numOfProduct);
			break;
		}
		case(8): {
			cout << "\n\n\t������� ����� �������: ";
			cin.get();
			char charSummOfProduct[1000];
			cin.getline(charSummOfProduct, 1000);
			int summOfProduct = isInteger_l(charSummOfProduct);
			person->setNumberOfProduct(summOfProduct);
			break;
		}
		default: {
			cout << "\n\n\t������� �������� ��������\n";
			system("pause");
			system("cls");
			break;
		}
	}
	system("cls");
}
void ListOfBuyers::transformClients		() {
	if (tail == NULL && head == NULL) {
		cout << "\n\n\t��� ������ �������� ��� ���������\n";
		system("pause");
		system("cls");
		return;
	}
	cout << "\n\n\t1 - ���������� ����"
		<< "\n\t2 - ����������� ����"
		<< "\n\t0 - �����";
	char charInputNum;
	cin >> charInputNum;
	int inputNum = isInteger(charInputNum);
	person = head;
	string inputSurname, inputName, inputPathr, inputFIO, inputCompanuName;
	switch (inputNum) {
		case(0):  return;
		case(1): {
			cout << "\n\n\t������� �������, ��� � ��������. 0. �����\n\n\t";
			cin >> inputSurname >> inputName >> inputPathr;
			inputFIO = inputSurname + " " + inputName + " " + inputPathr;
			if (inputSurname == "0" || inputName == "0" || inputPathr == "0" || inputFIO == "0") return;
			system("cls");
			int searchID = -1;
			int couErr = 0;
			int id = 1;
			while (true) {
				if (inputFIO == person->NaturalPerson<string>::getName()) { searchID = id; couErr++; }
				if (person->next == NULL) break;
				person = person->next;
				id++;
			}
			if (couErr > 1) {
				cout << "\n\n\t������� ����� ������ �������, ������� ������ ������� �������\n";
				system("pause");
				system("cls");
				return;
			}
			if (searchID == -1) {
				cout << "\n\n\t������ �� ������";
				system("pause");
				system("cls");
				return;
			}
			if (searchID >= 0) {
				person = head;
				for (int i = 0; i < searchID - 1; i++) {
					person = person->next;
				}
				cout << "\n\n\t�������� ������ ������� "; 
				person->operator<<(cout) 
					<< "\n\n\t1. ��\t2. ���\n\n\t";
				cin >> charInputNum;
				inputNum = isInteger(charInputNum);
				system("cls");
				switch (inputNum) {
					case(1): {transform(); return; }
					case(2): return;
					default: {
						cout << "\n\n\t������� �������� ��������";
						system("pause");
						system("cls");
						return;
					}
				}
			}
		}
		case(2): {
			cout << "\n\n\t������� �������� ��������. 0. �����\n\n\t";
			getline(cin, inputCompanuName);
			if (inputCompanuName == "0") return;
			system("cls");
			int searchID = -1;
			int couErr = 0;
			int id = 1;
			while (true) {
				if (inputCompanuName == person->LegalPerson<string>::getName()) { searchID = id; couErr++; }
				if (person->next == NULL) break;
				person = person->next;
				id++;
			}
			if (couErr > 1) {
				cout << "\n\n\t������� ����� ������ �������, ������� ������ ������� �������\n";
				system("pause");
				system("cls");
				return;
			}
			if (searchID == -1) {
				cout << "\n\n\t������ �� ������";
				system("pause");
				system("cls");
				return;
			}
			if (searchID >= 0) {
				person = head;
				for (int i = 0; i < searchID - 1; i++) {
					person = person->next;
				}
				cout << "\n\n\t�������� ������ ������� "; person->operator<<(cout) << "\n\n\t1. ��\t2. ���\n\n\t";
				cin >> charInputNum;
				inputNum = isInteger(charInputNum);
				system("cls");
				switch (inputNum) {
					case(1): {transform(); return; }
					case(2): return;
					default: {
						cout << "\n\n\t������� �������� ��������";
						system("pause");
						system("cls");
						return;
					}
				}
			}
		}
		default: {
			cout << "\n\n\t������ �����\n";
			system("pause");
			system("cls");
			break;
		}
	}
	system("cls");
}
//�����
void ListOfBuyers::swapAndDelClients	() {
	if (person != head && person != tail) {
		person->prev->next = person->next;
		person->next->prev = person->prev;
		delete person;
	}
	else if (person == head && person != tail) {
		head = person->next;
		head->prev = NULL;
		delete person;
	}
	else if (person == tail && person != head) {
		tail = person->prev;
		tail->next = NULL;
		delete person;
	}
	else {
		head = NULL;
		tail = NULL;
		delete person;
	}
	return;
}
void ListOfBuyers::delClients			() {
	if (tail == NULL && head == NULL) {
		cout << "\n\n\t��� ������ �������� ��� ��������\n";
		system("pause");
		system("cls");
		return;
	}
	cout << "\n\n\t1 - ���������� ����"
		<< "\n\t2 - ����������� ����"
		<< "\n\t0 - �����";
	char charInputNum;
	cin >> charInputNum;
	int inputNum = isInteger(charInputNum);
	person = head;
	string inputSurname, inputName, inputPathr, inputFIO, inputCompanuName;
	switch (inputNum) {
		case(0): return;
		case(1): {
			cout << "\n\n\t������� �������, ��� � ��������. 0. �����\n\n\t";
			cin >> inputSurname >> inputName >> inputPathr;
			inputFIO = inputSurname + " " + inputName + " " + inputPathr;
			if (inputSurname == "0" || inputName == "0" || inputPathr == "0" || inputFIO == "0") return;
			system("cls");
			int searchID = -1;
			int couErr = 0;
			int id = 1;
			while (true) {
				if (inputFIO == person->NaturalPerson<string>::getName()) { searchID = id; couErr++; }
				if (person->next == NULL) break;
				person = person->next;
				id++;
			}
			if (couErr > 1) {
				cout << "\n\n\t������� ����� ������ �������, ������� ������ ������� �������\n";
				system("pause");
				system("cls");
				return;
			}
			if (searchID == -1) {
				cout << "\n\n\t������ �� ������";
				system("pause");
				system("cls");
				return;
			}
			if (searchID >= 0) {
				person = head;
				for (int i = 1; i < searchID; i++)
					person = person->next;
				cout << "\n\n\t������� ������ ������� ";
				person->operator<<(cout) 
					<< "\n\n\t1. ��\t2. ���\n\n\t";
				cin >> charInputNum;
				inputNum = isInteger(charInputNum);
				system("cls");
				switch (inputNum) {
					case(1): {swapAndDelClients(); return; }
					case(2): return;
					default: {
						cout << "\n\n\t������� �������� ��������";
						system("pause");
						system("cls");
						return;
					}
				}
			}
		}
		case(2): {
			cout << "\n\n\t������� �������� ��������. 0. �����\n\n\t";
			getline(cin, inputCompanuName);
			if (inputCompanuName == "0") return;
			system("cls");
			int searchID = -1;
			int couErr = 0;
			int id = 1;
			while (true) {
				if (inputCompanuName == person->LegalPerson<string>::getName()) { searchID = id; couErr++; }
				if (person->next == NULL) break;
				person = person->next;
				id++;
			}
			if (couErr > 1) {
				cout << "\n\n\t������� ����� ������ �������\n";
				system("pause");
				system("cls");
				return;
			}
			if (searchID == -1) {
				cout << "\n\n\t������ �� ������";
				system("pause");
				system("cls");
				return;
			}
			if (searchID >= 0) {
				person = head;
				for (int i = 1; i < searchID; i++)
					person = person->next;
				cout << "\n\n\t������� ������ ������� ";
				person->operator<<(cout) 
					<< "\n\n\t1. ��\t2. ���\n\n\t";
				cin >> charInputNum;
				inputNum = isInteger(charInputNum);
				system("cls");
				switch (inputNum) {
					case(1): {swapAndDelClients(); return; }
					case(2): return;
					default: {
						cout << "\n\n\t������� �������� ��������";
						system("pause");
						system("cls");
						return;
					}
				}
			}
		}
		default: {
			cout << "\n\n\t������� �������� ��������\n";
			system("pause");
			system("cls");
			return;
		}
	}
	person = head;
	system("cls");
	return;
}
//�����
void ListOfBuyers::showClients			() {
	if (tail == NULL && head == NULL) {
		cout << "\n\n\t��� ������ �������� ��� ��������\n";
		system("pause");
		system("cls");
		return;
	}
	person = head;
	cout << endl;
	while (true) {
		cout << "\n\t";
		person->operator<<(cout);
		if (person->next == NULL)break;
		person = person->next;
		//cout << endl;
	}
	cout << "\n\n\t";
	system("pause");
	system("cls");
	return;
}
//�����
void ListOfBuyers::searchClients		() {
	if (tail == NULL && head == NULL) {
		cout << "\n\n\t��� ������ �������� ��� ��������\n";
		system("pause");
		system("cls");
		return;
	}
	cout << "\n\n\t1 - ���������� ����"
		<< "\n\t2 - ����������� ����"
		<< "\n\t0 - �����";
	char charInputNum;
	cin >> charInputNum;
	int inputNum = isInteger(charInputNum);
	person = head;
	string inputSurname, inputName, inputPathr, inputFIO, inputCompanuName;
	switch (inputNum) {
		case(0): return;
		case(1): {
			cout << "\n\n\t������� �������, ��� � ��������. 0. �����\n\n\t";
			cin >> inputSurname >> inputName >> inputPathr;
			inputFIO = inputSurname + " " + inputName + " " + inputPathr;
			if (inputSurname == "0" || inputName == "0" || inputPathr == "0" || inputFIO == "0") return;
			system("cls");
			int searchID = -1;
			int couErr = 0;
			int id = 1;
			while (true) {
				if (inputFIO == person->NaturalPerson<string>::getName()) {
					searchID = id; 
					cout << "\n\t"; 
					person->operator<<(cout); 
					cout << endl;
				}
				if (person->next == NULL) break;
				person = person->next;
				id++;
			}
			if (searchID == -1) cout << "\n\n\t������ �� ������";
			cout << "\n\t";
			system("pause");
			system("cls");
			return;
		}
		case(2): {
			cout << "\n\n\t������� �������� ��������. 0. �����\n\n\t";
			getline(cin, inputCompanuName);
			if (inputCompanuName == "0") return;
			system("cls");
			int searchID = -1;
			int couErr = 0;
			int id = 1;
			while (true) {
				if (inputCompanuName == person->LegalPerson<string>::getName()) {
					searchID = id;
					cout << "\n\t";
					person->operator<<(cout);
					cout << endl;
				}
				if (person->next == NULL) break;
				person = person->next;
				id++;
			}
			if (searchID == -1) cout << "\n\n\t������ �� ������";
			system("pause");
			system("cls");
			return;
		}
		default: {
			cout << "\n\n\t������� �������� ��������\n";
			system("pause");
			system("cls");
			return;
		}
	}
	person = head;
	system("cls");
	return;
}
//�����
void ListOfBuyers::saveClients			() {
	if (tail == NULL && head == NULL) {
		cout << "\n\n\t��� ������ �������� ��� ����������...";
		system("pause");
		system("cls");
		return;
	}
	string defaultFileName = (INDIVID_OUTPUT_FILE_LOCATION);
	cout << "\n\n\t1. ��������� � ����� � ��������� " << INDIVID_OUTPUT_FILE_LOCATION
		<< " � �������� �����\n\t2. �������� �������� �����\n\t0. �����\n\n\t";
	char charInputNum;
	cin >> charInputNum;
	int inputNum = isInteger(charInputNum);
	system("cls");
	switch (inputNum) {
		case(0): return;
		case(1): {
			ofstream outClients(INDIVID_OUTPUT_FILE_LOCATION);
			person = head;
			while (true) {
				person->operator<<(outClients);
				if (person == tail) break;
				person = person->next;
			}
			cout << "\n\n\t���������� ����� " << INDIVID_OUTPUT_FILE_LOCATION << "...";
			char p = _getch();
			system("cls");
			break;
		}
		case(2): {
			cout << "\n\n\t������� ������� ��������� ����� (��� ����������, ��������� ������ �����): ";
			string newName;
			cin.get();
			getline(cin, newName);
			newName += ".txt";
			system("cls");
			ofstream outClients(newName);
			person = head;
			while (true) {
				person->operator<<(outClients);
				if (person == tail) break;
				person = person->next;
			}
			cout << "\n\n\t��������� � ����� " << newName << "...";
			char p = _getch();
			system("cls");
			break;
		}
		default: {
			cout << "\n\n\t������� �������� ��������\n";
			system("pause");
			system("cls");
			return;
		}
	}
}

void ListOfBuyers::downloadClients		() {
	cout << "\n\n\t1. ��������� �� ����� � ��������� " << INDIVID_INPUT_FILE_LOCATION
		<< " � �������� �����\n\t2. �������� �������� �����\n\t0. �����\n\n\t";
	char charInputNum;
	cin >> charInputNum;
	int inputNum = isInteger(charInputNum);
	system("cls");
	string newFIO = { "None" };
	string newCompanyName = { "None" };
	string newMobilePhoneNumber = { "None" };
	string newCustomerINN = { "None" };
	string newAccountNumber = { "None" };

	bool newLegalPerson = false;
	string newProductName = { "None" };
	string newTypeOfProduct = { "None" };
	string newPaymentDay = { "None" };
	int newNumberOfProduct = 0;
	int	newSumOfProduct = 0;
	switch (inputNum) {
		case(0): return;
		case(1): {
			ifstream inClients(INDIVID_INPUT_FILE_LOCATION);
			if (inClients.bad()) {
				cout << "\n\t������ �����-������ ��� ������";
				system("pause");
				system("cls");
				return;
			}
			if (inClients.eof()) {
				cout << "\n\t��������� ����� �����";
				system("pause");
				system("cls");
				return;
			}
			if (inClients.fail()) {
				cout << "\n\t�������� ������ ������";
				system("pause");
				system("cls");
				return;
			}
			int size = 0;
			inClients >> size;
			for (int i = 0; i < size; i++) {
				inClients.get();
				string typeOfPerson;
				getline(inClients, typeOfPerson);
				if (typeOfPerson == "���������� ����") {
					newLegalPerson = false;
					getline(inClients, newFIO);
					getline(inClients, newMobilePhoneNumber);
					getline(inClients, newAccountNumber);
					getline(inClients, newProductName);
					getline(inClients, newTypeOfProduct);
					getline(inClients, newPaymentDay);
					inClients >> newNumberOfProduct;
					inClients >> newSumOfProduct;
				}
				else if (typeOfPerson == "����������� ����") {
					newLegalPerson = true;
					getline(inClients, newCompanyName);
					getline(inClients, newCustomerINN);
					getline(inClients, newAccountNumber);
					getline(inClients, newProductName);
					getline(inClients, newTypeOfProduct);
					getline(inClients, newPaymentDay);
					inClients >> newNumberOfProduct;
					inClients >> newSumOfProduct;
				}
				if (head == NULL) {
					person = new ListItem<string>(
						NULL,
						NULL,
						newLegalPerson,
						newProductName,
						newTypeOfProduct,
						newPaymentDay,
						this->VendorINN,
						this->CompanyAddress,
						newNumberOfProduct,
						newSumOfProduct,
						newFIO,
						newMobilePhoneNumber,
						newCompanyName,
						newCustomerINN,
						newAccountNumber
					);
					head = person;
					tail = person;
				}
				else {
					person = tail;
					person->next = new ListItem<string>(
						NULL,
						NULL,
						newLegalPerson,
						newProductName,
						newTypeOfProduct,
						newPaymentDay,
						this->VendorINN,
						this->CompanyAddress,
						newNumberOfProduct,
						newSumOfProduct,
						newFIO,
						newMobilePhoneNumber,
						newCompanyName,
						newCustomerINN,
						newAccountNumber
					);
					person->next->prev = person;
					person = person->next;
					tail = person;
				}
				newLegalPerson = false;
				newFIO = newCompanyName = newMobilePhoneNumber
					= newCustomerINN = newAccountNumber = newProductName
					= newTypeOfProduct = newPaymentDay = { "None" };
				newNumberOfProduct = newSumOfProduct = 0;
			}
			cout << "\n\n\t���������� �� ����� " << INDIVID_INPUT_FILE_LOCATION << "...";
			char p = _getch();
			system("cls");
			break;
		}
		case(2): {
			cout << "\n\n\t������� ������� ��������� ����� (��� ����������, ��������� ������ �����): ";
			string newName;
			cin.get();
			getline(cin, newName);
			newName += ".txt";
			system("cls");
			ifstream inClients(newName);
			if (inClients.bad()) {
				cout << "\n\t������ �����-������ ��� ������";
				system("pause");
				system("cls");
				return;
			}
			if (inClients.eof()) {
				cout << "\n\t��������� ����� �����";
				system("pause");
				system("cls");
				return;
			}
			if (inClients.fail()) {
				cout << "\n\t�������� ������ ������";
				system("pause");
				system("cls");
				return;
			}
			int size = 0;
			inClients >> size;
			for (int i = 0; i < size; i++) {
				inClients.get();
				string typeOfPerson;
				getline(inClients, typeOfPerson);
				if (typeOfPerson == "���������� ����") {
					newLegalPerson = false;
					getline(inClients, newFIO);
					getline(inClients, newMobilePhoneNumber);
					getline(inClients, newAccountNumber);
					getline(inClients, newProductName);
					getline(inClients, newTypeOfProduct);
					getline(inClients, newPaymentDay);
					inClients >> newNumberOfProduct;
					inClients >> newSumOfProduct;
				}
				else if (typeOfPerson == "����������� ����") {
					newLegalPerson = true;
					getline(inClients, newCompanyName);
					getline(inClients, newCustomerINN);
					getline(inClients, newAccountNumber);
					getline(inClients, newProductName);
					getline(inClients, newTypeOfProduct);
					getline(inClients, newPaymentDay);
					inClients >> newNumberOfProduct;
					inClients >> newSumOfProduct;
				}
				if (head == NULL) {
					person = new ListItem<string>(
						NULL,
						NULL,
						newLegalPerson,
						newProductName,
						newTypeOfProduct,
						newPaymentDay,
						this->VendorINN,
						this->CompanyAddress,
						newNumberOfProduct,
						newSumOfProduct,
						newFIO,
						newMobilePhoneNumber,
						newCompanyName,
						newCustomerINN,
						newAccountNumber
					);
					head = person;
					tail = person;
				}
				else {
					person = tail;
					person->next = new ListItem<string>(
						NULL,
						NULL,
						newLegalPerson,
						newProductName,
						newTypeOfProduct,
						newPaymentDay,
						this->VendorINN,
						this->CompanyAddress,
						newNumberOfProduct,
						newSumOfProduct,
						newFIO,
						newMobilePhoneNumber,
						newCompanyName,
						newCustomerINN,
						newAccountNumber
					);
					person->next->prev = person;
					person = person->next;
					tail = person;
				}
				newLegalPerson = false;
				newFIO = newCompanyName = newMobilePhoneNumber
					= newCustomerINN = newAccountNumber = newProductName
					= newTypeOfProduct = newPaymentDay = { "None" };
				newNumberOfProduct = newSumOfProduct = 0;
			}
			cout << "\n\n\t���������� �� ����� " << newName << "...";
			char p = _getch();
			system("cls");
			break;
		}
		default: {
			cout << "\n\n\t������� �������� ��������";
			system("pause");
			system("cls");
			return;
		}
	}
}

#pragma endregion