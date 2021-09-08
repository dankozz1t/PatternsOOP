#pragma once
#include <string>
#include <iostream>
#include <list>

using namespace std;

class Componentt
{
protected:
	string name;
public:
	Componentt(string n) :name(n){}

	virtual void addComponent(Componentt* c) {}
	virtual void print()
	{
		cout << name << endl;
	}
};

class Directory : public Componentt
{
	list<Componentt*>  componentts;

public:
	Directory(string n) :Componentt(n){}
	void addComponent(Componentt* c) override { componentts.push_back(c); }

	void print() override
	{
		cout << "Directory: " << name << endl;
		for (auto &c : componentts)
			c->print();
	}
};


class File : public Componentt
{
public:
	File(string n) : Componentt(n){}

};


