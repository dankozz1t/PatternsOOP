#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;


class TV
{
	
public:
	void on()
	{
		cout << "TV on" << endl;
	}

	void off()
	{
		cout << "TV off" << endl;
	}
};


class ICommand
{
public:
	virtual void execute() = 0;
};

class TVOnCommand : public ICommand
{
	TV* tv;
public:
	TVOnCommand(TV* tv) :tv(tv){}

	void execute() override
	{
		tv->on();
	}
};


class TVOffCommand : public ICommand
{
	TV* tv;
public:
	TVOffCommand(TV* tv) :tv(tv) {}

	void execute() override
	{
		tv->off();
	}
};

class Pult
{
	vector<ICommand*> command;
public:
	Pult(int size) { command.resize(size); }

	void setCommand(int num, ICommand* com)
	{
		command[num] = com;
	}

	void pressButton(int num)
	{
		command[num]->execute();
	}
};


class Multivarka
{
public:
	void start(int time)
	{
		cout << "Готовим еду" << endl;
		for(int i =0; i < time; i++)
		{
			cout << ".";
			Sleep(1000);
		}
		cout << endl;
		cout << " Готово!" << endl;
	}
};

class MultivarkaStartCommand : public ICommand
{
	Multivarka* multi;
	int time;
public:
	MultivarkaStartCommand(Multivarka* multi, int time) : multi(multi), time(time) {}

	void execute() override
	{
		multi->start(time);
	}
};



//int main()
//{
//	goToRush();
//
//	TV* tv = new TV;
//	Pult* pult = new Pult(3);
//
//	pult->setCommand(0, new TVOnCommand(tv));
//	pult->setCommand(1, new TVOffCommand(tv));
//
//	pult->pressButton(0);
//	pult->pressButton(1);
//	
//
//	Multivarka* multi = new Multivarka;
//	pult->setCommand(2, new MultivarkaStartCommand(multi, 10));
//
//	pult->pressButton(2);
//	return 0;
//}