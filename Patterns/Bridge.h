#pragma once
#include <iostream>

using namespace std;

class Language
{
public:
	virtual void build() = 0;
	virtual void execute() = 0;

};

class CPPLanguage: public Language
{
	void build() override
	{
		cout << " � ������� ����������� C++" << endl;
	}

	void execute() override
	{
		cout << " ��������� ***.��� ����" << endl;
	}

};

class CSharpLanguage : public Language
{
	void build() override
	{
		cout << " � ������� ����������� C#" << endl;
	}

	void execute() override
	{
		cout << " ��������� .NET" << endl;
	}

};

class Programmer
{
	Language* lang;
public:
	Programmer(Language * l):lang(l){}

	void setLanguage(Language* l) { lang = l; }

	void work()
	{
		lang->build();
		lang->execute();
	}

	virtual void getMoney() = 0;

};

class Freelance : public Programmer
{
public:
	Freelance(Language* l):Programmer(l){}

	void getMoney() override
	{
		cout << " �������� ������ �� ����� $$$ " << endl;
	}
};

class Office :public Programmer
{
public:
	Office(Language* l) :Programmer(l) {}

	void getMoney() override
	{
		cout << " �������� �������� ��������� $$$ " << endl;
	}
};


//int mainBridge()
//{
//	goToRush();
//
//	Programmer* freelancer = new Freelance(new CPPLanguage());
//	freelancer->work();
//	freelancer->getMoney();
//
//	cout << " ------------------- " << endl;
//
//	freelancer->setLanguage(new CSharpLanguage());
//	freelancer->work();
//	freelancer->getMoney();
//
//	cout << " ------------------- " << endl;
//
//
//	Programmer* office = new Office(new CPPLanguage());
//	office->work();
//	office->getMoney();
//
//	cout << " ------------------- " << endl;
//
//	office->setLanguage(new CSharpLanguage());
//	office->work();
//	office->getMoney();
//
//	return 0;
//}
