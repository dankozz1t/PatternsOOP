#pragma once
#include <iostream>

using namespace std;

class Strategy
{
public:
	virtual float move(int len) = 0;	
};

class OnFoot : public Strategy
{
	int speed = 3;

public:
	float move(int len) override
	{
		cout << "Хуярим пешком" << endl;
		return (float)len / speed;
	}
};

class OnBuss : public Strategy
{
	int speed = 40;
	float timeStopping = 1 / 60.;

public:
	float move(int len) override
	{
		cout << "Хуярим на маршрутке" << endl;
		return (float)len / speed + len *timeStopping;
	}
};


class OnCar : public Strategy
{
	int speed = 60;

public:
	float move(int len) override
	{
		cout << "Хуярим на машине" << endl;
		return (float)len / speed;
	}
};

class Navigator
{
	Strategy* strategy = nullptr;
public:
	void setStrategy(Strategy* s) { if(strategy) delete strategy;  strategy = s; }

	void getTime(int len)
	{
		cout << "Расчетное время пути: " << strategy->move(len) << endl << endl;
	}
};


//int main()
//{
//	goToRush();
//
//	Navigator* navi = new Navigator;
//	navi->setStrategy(new OnFoot);
//	navi->getTime(100);
//
//	navi->setStrategy(new OnBuss);
//	navi->getTime(100);
//
//	navi->setStrategy(new OnCar);
//	navi->getTime(100);
//
//	
//	return 0;
//}