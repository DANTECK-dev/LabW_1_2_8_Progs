/*#pragma once

#include "Libraries.h"

class Person 
{

private:
	Person* next;
	Person* prev;

	void swapAndDelClients	(Person*& head, Person*& tail, Person*& clients);
	void transform			(Person*& head, Person*& tail, Person*& clients);
	void show				();

public:

	class Data {

	public:

		string	Surname;
		string	Name;
		string	Patronymic;
		string	Address;
		string	PhoneNum;
		string	PayDay;
		int 	Summ;
	
		Data()
		{
			Surname = { "None" };
			Name = { "None" };
			Patronymic = { "None" };
			Address = { "None" };
			PhoneNum = { "None" };
			PayDay = { "None" };
			Summ = 0;

		}		
		
		Data(const Data& other)
		{
			this->Surname		= other.Surname;
			this->Name			= other.Name;
			this->Patronymic	= other.Patronymic;
			this->Address		= other.Address;
			this->PhoneNum		= other.PhoneNum;
			this->PayDay		= other.PayDay;
			this->Summ			= other.Summ;
		}

		void SortData		(Person*& head, Person*& tail, Person*& clients);

	} DATA;

	Person() 
	{
		cout << "\n\tПустой конструктор\n\t";

		this->next				= NULL;
		this->prev				= NULL;

		this->DATA.Name			= { "None" };
		this->DATA.Surname		= { "None" };
		this->DATA.Patronymic	= { "None" };
		this->DATA.Address		= { "None" };
		this->DATA.PhoneNum		= { "None" };
		this->DATA.PayDay		= { "None" };
		this->DATA.Summ			= 0;
	}

	Person(string Surname, string Name, string Patronymic, string Address, string PhoneNum, string PayDay, int Summ)
	{
		this->next = this;
		this->prev = this;

		this->DATA.Name			= Name			;
		this->DATA.Surname		= Surname		;
		this->DATA.Patronymic	= Patronymic	;
		this->DATA.Address		= Address		;
		this->DATA.PhoneNum		= PhoneNum		;
		this->DATA.PayDay		= PayDay		;
		this->DATA.Summ			= Summ			;

		cout << "\n\tЗапись создана конструктором с параметром\n\t";

		cout << "\n\n\tФИО: " << this->DATA.Surname << " " << this->DATA.Name << " " << this->DATA.Patronymic
			 << " Адресс: " << this->DATA.Address
			 << "\n\tТелефоный номер: " << this->DATA.PhoneNum
			 << " День оплаты: " << this->DATA.PayDay
			 << " Сумма: " << this->DATA.Summ;

		char p = _getch();
		system("cls");
	}

	~Person()
	{
		if (this)
		{
			while (true)
			{
				if (this->prev)
				{
					this == this->prev;
				}
			}

			if (this->next)
			{
				this == this->next;
				delete this->prev;
			}

			else
			{
				delete this;
			}
		}
	}

	void addClients			(Person*& head, Person*& tail, Person*& clients);

	void sortClients		(Person*& head, Person*& tail, Person*& clients);

	void transformClients	(Person*& head, Person*& tail, Person*& clients);
		
	void delClients			(Person*& head, Person*& tail, Person*& clients);

	void showClients		(Person*& head, Person*& tail, Person*& clients);

	void searchClients		(Person*& head, Person*& tail, Person*& clients);

	void saveClients		(Person*& head, Person*& tail, Person*& clients);

	void downloadClients	(Person*& head, Person*& tail, Person*& clients);
};*/