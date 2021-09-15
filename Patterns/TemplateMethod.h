#pragma once
#include <iostream>
#include <string>

using namespace std;

class HouseBuilder
{
protected:
	virtual void buildWall() = 0;
	virtual void buildDoor() = 0;
	virtual void buildWindows(int w) = 0;
	virtual void buildRoof() = 0;
	virtual void buildPool() = 0;
public:
	void buildHouse(int wind)
	{
		buildWall();
		buildDoor();
		buildWindows(wind);
		buildRoof();
		buildPool();
	}

	virtual string getResult() = 0;
};

class StandartHouse :public HouseBuilder
{
	string house = "*-Стандартный дом: \n";
public:
	void buildDoor() override
	{
		house += "  +Деревянная дверь \n";
	}
	void buildWindows(int wind) override
	{
		string d = to_string(wind);
		house += "  +Деревянные окна " + d + "\n";
	}
	void buildRoof() override
	{
		house += "  +Черепичная крыша \n";
	}
	void buildWall() override
	{
		house += "  +Каменные стены \n";
	}
	void buildPool() override {};

	string getResult() override { return house; }
};

class EliteHouse :public HouseBuilder
{
	string house = "*-Элитный дом: \n";
public:
	void buildDoor() override
	{
		house += "  +Золотая дверь \n";
	}
	void buildWindows(int wind) override
	{
		string d = to_string(wind);
		house += "  +Позалоченые окна " + d + "\n";
	}
	void buildRoof() override
	{
		house += "  +Крыша из стали\n";
	}
	void buildWall() override
	{
		house += "  +Нано-стены \n";
	}
	void buildPool() override
	{
		house += "  +Бассейн с подогревом \n";
	};

	string getResult() override { return house; }
};

//int main()
//{
//	goToRush();
//
//	HouseBuilder* house1 = new StandartHouse;
//	house1->buildHouse(10);
//	cout << house1->getResult();
//
//	cout << endl << endl;
//	HouseBuilder* house2 = new EliteHouse;
//	house2->buildHouse(20);
//	cout << house2->getResult();
//	
//	return 0;
//}