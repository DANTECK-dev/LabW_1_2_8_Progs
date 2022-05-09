#pragma once
#include "Libraries.h"

class General {
protected:
	string	name;
	string	companyName;
	int		price;
	int		weight;
public:
	General();
	General(string name, string companyName, int price, int weight);
	string getGeneral();
	/*void setName(string name);
	void setCompanyName(string companyName);
	void setPrice(int price);
	void setWeight(int weight);*/
};


class CannedProduct : General{
protected:
	int expirationDateInOpenState;
	int expirationDateInCloseState;
	bool open;
public:
	CannedProduct();
	CannedProduct(string name, string companyName, int price, int weight,
		int expirationDateInOpenState, int expirationDateInCloseState, bool open);
	string getCannedProduct();
	/*void setExpirationDateInOpenState(int expirationDateInOpenState);
	void setExpirationDateInCloseState(int expirationDateInCloseState);
	void setOpen(bool open);
	void setCannedProduct(string name,
		string companyName,
		int price,
		int weight);*/
};


class FreshProduct : General {
protected:
	int expirationDate;
public:
	FreshProduct();
	FreshProduct(string name, string companyName, int price, int weight, int expirationDate);
	string getFreshProduct();
	/*void setExpirationDate(int expirationDate);
	void setFreshProduct(string name,
		string companyName,
		int price,
		int weight);*/
};


class FoodProduct : CannedProduct , FreshProduct{
public:
	FoodProduct();
	FoodProduct(string name, string companyName, int price, int weight,
		int expirationDateInOpenState, int expirationDateInCloseState, bool open, int expirationDate);
	virtual int getExpirationDate();
	string getFoodProduct();
	/*void setFoodProduct(string name,
		string companyName,
		int price,
		int weight,
		int expirationDateInOpenState,
		int expirationDateInCloseState, 
		bool open,
		int expirationDate);*/
};


class Accessories : General {
protected:
	string typeOfComponent;	// of which it is a part
public:
	Accessories();
	Accessories(string name, string companyName, int price, int weight, string typeOfComponent);
	string getAccessories();
	/*void setTypeOfComponent(string typeOfComponent);
	void setAccessories(string name,
		string companyName,
		int price,
		int weight);*/
};


class ElectronicGoods : Accessories{
protected:
	string productType;
public:
	ElectronicGoods();
	ElectronicGoods(string name, string companyName, int price,
		int weight, string typeOfComponent, string productType);
	string getElectronicGoods();
	/*void setProductType(string productType);
	void setElectronicGoods(
		string name,
		string companyName,
		int price,
		int weight,
		string typeOfComponent);*/
};


class Product : public FoodProduct, public ElectronicGoods{
public:
	//Абстрактный класс
	Product* next = NULL;
	Product* prev = NULL;
	Product();
	int getExpirationDate() {return FoodProduct::getExpirationDate();}
	Product(string name, string companyName, int price, int weight, bool open, int expirationDateInCloseState,
		int expirationDateInOpenState, int expirationDate, string typeOfComponent, string productType);
	operator string () const;
	/*void newProduct(string name, string companyName, int price, int weight, bool open, int expirationDateInCloseState,
		int expirationDateInOpenState, int expirationDate, string typeOfComponent, string productType);
	void setProduct (
		string name,
		string companyName,
		int price,
		int weight,
		bool open,
		int expirationDateInCloseState,
		int expirationDateInOpenState,
		int expirationDate,
		string typeOfComponent,
		string productType
	);*/
};