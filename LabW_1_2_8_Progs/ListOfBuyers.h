#pragma once

#include "Libraries.h"

class DataPerson {
protected:
	virtual void setName	(string) = 0;
	virtual void setInfoNum	(string) = 0;
	virtual void setPayNum	(string) = 0;
	virtual void setDataPerson(string, string, string) = 0;

	virtual string getName		() = 0;
	virtual string getInfoNum	() = 0;
	virtual string getPayNum	() = 0;
	virtual string getDataPerson() = 0;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class NaturalPerson : public DataPerson {
protected:
	string FIO;
	string mobilePhoneNumber;
	string accountNumber;
public:
	NaturalPerson();
	NaturalPerson(
		string FIO,
		string mobilePhoneNumber, 
		string accountNumber
	);
	void setName(string FIO)					override { this->FIO				= FIO; }
	void setInfoNum(string mobilePhoneNumber)	override { this->mobilePhoneNumber	= mobilePhoneNumber; }
	void setPayNum(string accountNumber)		override { this->accountNumber		= accountNumber; }
	void setDataPerson(string FIO, string mobilePhoneNumber, string accountNumber) override {
		this->FIO = FIO;
		this->mobilePhoneNumber = mobilePhoneNumber;
		this->accountNumber = accountNumber;
	}

	string getName()		override { return FIO; }
	string getInfoNum()		override { return mobilePhoneNumber; }
	string getPayNum()		override { return accountNumber; }
	string getDataPerson()	override { return "ФИО: " + FIO + " Моб. телефон: " + mobilePhoneNumber + " Номер счёта: " + accountNumber; }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class LegalPerson : public DataPerson {
protected:
	string companuName;
	string customerINN;
	string accountNumber;
public:
	LegalPerson();
	LegalPerson(
		string companuName,
		string customerINN,
		string accountNumber
	);
	void setName(string companuName)		override { this->companuName	= companuName; };
	void setInfoNum(string customerINN)		override { this->customerINN	= customerINN; };
	void setPayNum(string accountNumber)	override { this->accountNumber	= accountNumber; };
	void setDataPerson(string companuName, string customerINN, string accountNumber) override {
		this->companuName = companuName;
		this->customerINN = customerINN;
		this->accountNumber = accountNumber;
	}
	string getName()		override { return companuName; };
	string getInfoNum()		override { return customerINN; };
	string getPayNum()		override { return accountNumber; };
	string getDataPerson()	override { return "Название компании: " 
		+ companuName + " ИНН компании: " 
		+ customerINN + " Номер счёта: " + accountNumber; }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class DataProduct {
protected:
	string productName;
	string typeOfProduct;
	string paymentDay;
	string vendorINN;
	string companyAddress;
	int numberOfProduct;
	int sumOfProduct;
public:
	DataProduct();
	DataProduct(
		string productName,
		string typeOfProduct,
		string paymentDay,
		string vendorINN,
		string companyAddress,
		int numberOfProduct,
		int sumOfProduct
	);
	void setProductName		(string productName)	{ this->productName		= productName;		};
	void setTypeOfProduct	(string typeOfProduct)	{ this->typeOfProduct	= typeOfProduct;	};
	void setPaymentDay		(string paymentDay)		{ this->paymentDay		= paymentDay;		};
	void setVendorINN		(string vendorINN)		{ this->vendorINN		= vendorINN;		};
	void setCompanyAddress	(string companyAddress)	{ this->companyAddress	= companyAddress;	};
	void setNumberOfProduct	(int numberOfProduct)	{ this->numberOfProduct	= numberOfProduct;	};
	void setSumOfProduct	(int sumOfProduct)		{ this->sumOfProduct	= sumOfProduct;		};

	string  getProductName()	{ return this->productName;		};
	string  getTypeOfProduct()	{ return this->typeOfProduct;	};
	string  getPaymentDay()		{ return this->paymentDay;		};
	string  getVendorINN()		{ return this->vendorINN;		};
	string  getCompanyAddress()	{ return this->companyAddress;	};
	int		getNumberOfProduct(){ return this->numberOfProduct;	};
	int		getSumOfProduct()	{ return this->sumOfProduct;	};
	string	getDataProduct();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ListItem : public LegalPerson, public NaturalPerson, public DataProduct {
public:
	ListItem* next;
	ListItem* prev;
	bool legalPerson;
	ListItem();
	ListItem(
		ListItem* next,
		ListItem* prev,
		bool legalPerson,
		string productName,
		string typeOfProduct,
		string paymentDay,
		string vendorINN,
		string companyAddress,
		int numberOfProduct,
		int sumOfProduct,
		string FIO,
		string mobilePhoneNumber,
		string companuName,
		string customerINN,
		string accountNumber
	);
	void nextItem();
	void prevItem();
	ostream& operator << (ostream& os);
	istream& operator >> (ostream& os);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ListOfBuyers {
private:
	ListItem* person		= NULL;
	ListItem* head			= NULL;
	ListItem* tail			= NULL;
	string VendorINN		= { "758313399357" };
	string CompanyAddress	= { "622966, Калининградская область, город Кашира, пл. Балканская, 27" };
	void swapAndDelClients();
	void transform();
	void show();
public:
	void operator[]			(const int index);
	operator int () const;
	void addClients			(/*ListItem*& head, ListItem*& tail, ListItem*& clients*/);
	void sortClients		(/*ListItem*& head, ListItem*& tail, ListItem*& clients*/);
	void transformClients	(/*ListItem*& head, ListItem*& tail, ListItem*& clients*/);
	void delClients			(/*ListItem*& head, ListItem*& tail, ListItem*& clients*/);
	void showClients		(/*ListItem*& head, ListItem*& tail, ListItem*& clients*/);
	void searchClients		(/*ListItem*& head, ListItem*& tail, ListItem*& clients*/);
	void saveClients		(/*ListItem*& head, ListItem*& tail, ListItem*& clients*/);
	void downloadClients	(/*ListItem*& head, ListItem*& tail, ListItem*& clients*/);
};