#pragma once
#include <string>
#include <iostream>
#include <map>

using namespace std;



class HouseFlyweight
{
protected:
	string name = "No name";
	int floor;

public:
	virtual void build(int x, int y) = 0;
	virtual string getName() { return name; }
};


class PanelHouse :public HouseFlyweight
{

public:
	PanelHouse() { floor = 9, name = "Panel"; }

	void build(int x, int y) override
	{
		cout << "Построен панельный дом из " << floor << " этажей" << endl;
		cout << "КОРДИНАТЫ: X: " << x << ", Y: " << y << endl << endl;
	}
};

class BricklHouse :public HouseFlyweight
{

public:
	BricklHouse() { floor = 16, name = "Brick"; }

	void build(int x, int y) override
	{
		cout << "Построен кирпичный дом из " << floor << " этажей" << endl;
		cout << "КОРДИНАТЫ: X: " << x << ", Y: " << y << endl << endl;
	}
};

class HouseFactory
{
	map<string, HouseFlyweight*> pool;

public:

	HouseFactory()
	{
		pool["Panel"] = new PanelHouse();
		pool["Brick"] = new BricklHouse();
	}
	HouseFlyweight* getHouse(string key)
	{
		if (pool.count(key))
			return pool[key];
		return nullptr;
	}
};

class House
{
protected:
	int x;
	int y;
	HouseFlyweight * house;
public:
	House(int x_, int y_, HouseFlyweight* h) : x(x_), y(y_), house(h)
	{
		if (house)
			house->build(x, y);
		else
		{
			x = 0;
			y = 0;

			cout << "Дом не построен" << endl;
		}
	}

	void print()
	{
		if (house)
			cout << "House - " << house->getName() << endl;
		else
			cout << "КОРДЫ: X: " << x << ", Y: " << y << endl << endl;
			cout << "Дом не построен" << endl;
	}
};



//int main()
//{
//	goToRush();
//
//	HouseFactory* factory = new HouseFactory();
//
//	vector<House*> houses;
//	for (int i = 0; i < 5; i++)
//	{
//		if (i > 1 && i < 4)
//			houses.push_back(new House(rand() % 100, rand() % 100,
//				factory->getHouse("Brick")));
//		else
//			houses.push_back(new House(rand() % 100, rand() % 100,
//				factory->getHouse("Panel")));
//	}
//	for (auto &h : houses)
//		h->print();
//
//
//	return 0;
//}