#pragma once
#include <string>
#include <iostream>

using namespace std;

class TextEditor
{
public:
	void creareCode() { cout << "Написание кода" << endl; }
	void save() { cout << "Сохранение кода " << endl; }

};

class Compillee
{
public:
	void Compille() { cout << " Компиляция кода" << endl; }
};

class Debuger
{
public:
	void execute() { cout << "Выполнение кода " << endl; }
	void finish() { cout << "Завершение работы " << endl; }
};

class Facade
{
	TextEditor* tex;
	Compillee* com;
	Debuger* deb;

public:
	Facade(TextEditor* t, Compillee* c, Debuger* d) :tex(t), com(c), deb(d) {}

	void F5()
	{
		tex->creareCode();
		tex->save();
		com->Compille();
		deb->execute();
		deb->finish();
	}

};

class Programmer_
{
public:
	void createApp(Facade* vs)
	{
		vs->F5();
	}
};
