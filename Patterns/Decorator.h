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
	Italian() :Pizza(" Итальянская пицца: "){}

	int getPrice() override { return 100; }

};

class American : public Pizza
{

public:
	American() :Pizza(" Американская пицца: ") {}

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
	Tomato(Pizza *p) :Decorator(p->getName() + "\n  + помидоры", p) {}

	int getPrice() override { return  pizza->getPrice() + 20; }

};

class Cheese : public Decorator
{

public:
	Cheese(Pizza *p) :Decorator(p->getName() + "\n  + сыр", p) {}

	int getPrice() override { return pizza->getPrice() + 30; }

};