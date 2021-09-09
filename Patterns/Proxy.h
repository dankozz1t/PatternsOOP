#pragma once
#include <string>
#include <iostream>
#include <map>

using namespace std;


class IPage
{
public:
	virtual string getPage(int key) = 0;
};

class DataBase:public IPage
{
	map<int, string> base;
public:
	DataBase()
	{
		base[1] = "Page 1";
		base[2] = "Page 2";
		base[3] = "Page 3";
		base[4] = "Page 4";
		base[5] = "Page 5";
	}

	string getPage(int key) override
	{
		if (base.count(key))
			return base[key];
		return "No page";
	}
};


class DataBaseProxy : public IPage
{
	map<int, string> cash;
	DataBase* base;

public:
	string getPage(int key) override
	{
		if (cash.count(key))
			return cash[key];
		else
		{
			base = new DataBase;
			string data = base->getPage(key);
			cash[key] = data;
			delete base;
			return data;
		}
	}
	
};


//int mainProxy()
//{
//	goToRush();
//
//	DataBaseProxy * proxy = new DataBaseProxy();
//	while (true)
//	{
//		int page;  cin >> page;
//
//		cout << proxy->getPage(page);
//
//	}
//
//	return 0;
//}
