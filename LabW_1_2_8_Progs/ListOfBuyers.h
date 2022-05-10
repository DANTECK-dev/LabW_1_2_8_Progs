#pragma once

#include "Libraries.h"

template<typename T>
class Data {
protected:
	static Data* add(T data);
};

template<typename T>
class DataPerson {
protected:
	virtual void setName	(T) = 0;
	virtual void setInfoNum	(T) = 0;
	virtual void setPayNum	(T) = 0;
	virtual void setDataPerson(T, T, T) = 0;

	virtual T getName		() = 0;
	virtual T getInfoNum	() = 0;
	virtual T getPayNum	() = 0;
	virtual T getDataPerson() = 0;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
class NaturalPerson : public DataPerson<T> {
protected:
	string FIO;
	T mobilePhoneNumber;
	T accountNumber;
public:
	NaturalPerson();
	NaturalPerson(
		string FIO,
		T mobilePhoneNumber, 
		T accountNumber
	);
	void setName(string FIO)					override { this->FIO				= FIO; }
	void setInfoNum(T mobilePhoneNumber)		override { this->mobilePhoneNumber	= mobilePhoneNumber; }
	void setPayNum(T accountNumber)				override { this->accountNumber		= accountNumber; }
	void setDataPerson(string FIO, T mobilePhoneNumber, T accountNumber) override {
		this->FIO = FIO;
		this->mobilePhoneNumber = mobilePhoneNumber;
		this->accountNumber = accountNumber;
	}

	string getName()	override { return FIO; }
	T getInfoNum()		override { return mobilePhoneNumber; }
	T getPayNum()		override { return accountNumber; }
	T getDataPerson()	override { return "ФИО: " + FIO + " Моб. телефон: " + mobilePhoneNumber + " Номер счёта: " + accountNumber; }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
class LegalPerson : public DataPerson<T> {
protected:
	string companuName;
	T customerINN;
	T accountNumber;
public:
	LegalPerson();
	LegalPerson(
		string companuName,
		T customerINN,
		T accountNumber
	);
	void setName(string companuName)	override { this->companuName	= companuName; };
	void setInfoNum(T customerINN)		override { this->customerINN	= customerINN; };
	void setPayNum(T accountNumber)		override { this->accountNumber	= accountNumber; };
	void setDataPerson(T companuName, T customerINN, T accountNumber) override {
		this->companuName = companuName;
		this->customerINN = customerINN;
		this->accountNumber = accountNumber;
	}
	string getName()		override { return companuName; };
	T getInfoNum()			override { return customerINN; };
	T getPayNum()			override { return accountNumber; };
	string getDataPerson()	override { return "Название компании: "
		+ companuName + " ИНН компании: " 
		+ customerINN + " Номер счёта: " + accountNumber; }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
class DataProduct {
protected:
	string productName;
	T typeOfProduct;
	T paymentDay;
	T vendorINN;
	string companyAddress;
	int numberOfProduct;
	int sumOfProduct;
public:
	DataProduct();
	DataProduct(
		T productName,
		T typeOfProduct,
		T paymentDay,
		T vendorINN,
		string companyAddress,
		int numberOfProduct,
		int sumOfProduct
	);
	void setProductName		(T productName)			{ this->productName		= productName;		};
	void setTypeOfProduct	(T typeOfProduct)		{ this->typeOfProduct	= typeOfProduct;	};
	void setPaymentDay		(T paymentDay)			{ this->paymentDay		= paymentDay;		};
	void setVendorINN		(T vendorINN)			{ this->vendorINN		= vendorINN;		};
	void setCompanyAddress	(string companyAddress)		{ this->companyAddress	= companyAddress;	};
	void setNumberOfProduct	(int numberOfProduct)	{ this->numberOfProduct	= numberOfProduct;	};
	void setSumOfProduct	(int sumOfProduct)		{ this->sumOfProduct	= sumOfProduct;		};

	T  getProductName()			{ return this->productName;		};
	T  getTypeOfProduct()		{ return this->typeOfProduct;	};
	T  getPaymentDay()			{ return this->paymentDay;		};
	T  getVendorINN()			{ return this->vendorINN;		};
	string  getCompanyAddress()		{ return this->companyAddress;	};
	int		getNumberOfProduct(){ return this->numberOfProduct;	};
	int		getSumOfProduct()	{ return this->sumOfProduct;	};
	string	getDataProduct();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
class ListItem : public LegalPerson<T>, public NaturalPerson<T>, public DataProduct<T>, public Data<T> {
public:
	ListItem<T>* next;
	ListItem<T>* prev;
	bool legalPerson;
	ListItem();
	ListItem(
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
	);
	friend Data<T>* Data<T>::add(T data);
	ostream& operator << (ostream& os);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ListOfBuyers {
private:
	ListItem<string>* person		= NULL;
	ListItem<string>* head			= NULL;
	ListItem<string>* tail			= NULL;
	string VendorINN		= { "758313399357" };
	string CompanyAddress	= { "622966, Калининградская область, город Кашира, пл. Балканская, 27" };
	void swapAndDelClients();
	void transform();
public:
	void operator[]			(const int index);
	operator int () const;
	string getVendorINN()								{ return this->VendorINN;					}
	string getCompanyAddress()							{ return this->CompanyAddress;				}
	void setVendorINN(string newVendorINN)				{ this->VendorINN = newVendorINN;			}
	void setCompanyAddress(string newCompanyAddress)	{ this->CompanyAddress = newCompanyAddress;	}
	void addClients			();
	void sortClients		();
	void transformClients	();
	void delClients			();
	void showClients		();
	void searchClients		();
	void saveClients		();
	void downloadClients	();
};