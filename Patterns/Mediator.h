#pragma once
#include <iostream>
#include <string>


using namespace std;

class Colleague;

class Mediator
{
public:
	virtual void send(string message, Colleague* colleague) = 0;

};

class Colleague
{
protected:
	Mediator* mediator;
public:
	Colleague(Mediator* mediator) : mediator((mediator)) {}

	virtual void send(string message)
	{
		mediator->send(message, this);
	}

	virtual void notyfi(string msg) = 0;
};

class Seller : public Colleague
{
public:
	Seller(Mediator* med) : Colleague(med) {}

	void notyfi(string msg) override
	{
		cout << "Продавец: "<< msg << endl;
	}
};


class Programmer : public Colleague
{
public:
	Programmer(Mediator* med) : Colleague(med) {}

	void notyfi(string msg) override
	{
		cout << "Программист: " << msg << endl;
	}
};


class Tester : public Colleague
{
public:
	Tester(Mediator* med) : Colleague(med) {}

	void notyfi(string msg) override
	{
		cout << "Тестировщик: " << msg << endl;
	}
};


class Meneger : public Mediator
{
public:
	Colleague* seller;
	Colleague* programmer;
	Colleague* tester;

	void send(string message, Colleague* colleague) override
	{
		if (colleague == seller)
			programmer->notyfi(message);
		else if (colleague == programmer)
			tester->notyfi(message);
		else if (colleague == tester)
			seller->notyfi(message);
	}
};

//int main()
//{
//	goToRush();
//
//	Meneger* meneger = new Meneger;
//	Colleague* seller = new Seller(meneger);
//	Colleague* programmer = new Programmer(meneger);
//	Colleague* tester = new Tester(meneger);
//
//	meneger->seller = seller;
//	meneger->programmer = programmer;
//	meneger->tester = tester;
//
//	seller->send("Есть работенка... Напишите прогу! ");
//	programmer->send("Тьфу! ИЗИ! Код написан! Протестируйте!");
//	tester->send("блЯ буду! Оттестирован, продавайте!");
//	
//	return 0;
//}