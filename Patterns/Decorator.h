#pragma once
#include <string>
#include <iostream>

using namespace std;

class Pizza
{
	string name;
public:
	Pizza(string n):name(n){}

	string getName() { return name; }

	virtual int getPrice() = 0;

};

class Italian : public Pizza
{

public:
	Italian() :Pizza(" ����������� �����: "){}

	int getPrice() override { return 100; }

};

class American : public Pizza
{

public:
	American() :Pizza(" ������������ �����: ") {}

	int getPrice() override { return 300; }

};


class Decorator : public Pizza
{
protected:
	Pizza* pizza;
public:
	Decorator(string n, Pizza * p) : Pizza(n), pizza(p){}

	virtual ~Decorator() { if(pizza) delete pizza; }

};

class Tomato : public Decorator
{

public:
	Tomato(Pizza *p) :Decorator(p->getName() + "\n  + ��������", p) {}

	int getPrice() override { return  pizza->getPrice() + 20; }

};

class Cheese : public Decorator
{

public:
	Cheese(Pizza *p) :Decorator(p->getName() + "\n  + ���", p) {}

	int getPrice() override { return pizza->getPrice() + 30; }

};

//
//int mainDocorator()
//{
//	goToRush();
//
//	cout << "\n-------����� �1-------" << endl;
//
//	Pizza* pizza = new Italian();
//	pizza = new Tomato(pizza);
//	pizza = new Cheese(pizza);
//
//	cout << pizza->getName() << endl;
//	cout << "---------------------" << endl;
//	cout << " ����: " << pizza->getPrice() << endl;
//
//
//	cout << "\n-------���� �2-------" << endl;
//
//	Pizza* pizza2 = new American();
//	pizza2 = new Cheese(pizza);
//	pizza2 = new Cheese(pizza);
//
//	cout << pizza2->getName() << endl;
//	cout << "---------------------" << endl;
//	cout << " ����: " << pizza2->getPrice() << endl;
//
//	return 0;
//}