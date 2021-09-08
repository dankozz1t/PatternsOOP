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


//
//int mainComposite()
//{
//	goToRush();
//
//	Componentt* fs = new Directory("^FileSystem");
//	Componentt* discC = new Directory("disk C");
//	Componentt* folder1 = new Directory("$ Folder 1");
//	Componentt* folder2 = new Directory("$ Folder 2");
//	Componentt* folder3 = new Directory("$ Folder 3");
//	Componentt* folder4 = new Directory("$ Folder 4");
//	Componentt* file1 = new File("* File 1");
//	Componentt* file2 = new File("* File 2");
//	Componentt* file3 = new File("* File 3");
//
//	fs->addComponent(discC);
//	discC->addComponent(folder1);
//	discC->addComponent(folder2);
//	discC->addComponent(folder3);
//	discC->addComponent(file1);
//	folder1->addComponent(folder4);
//	folder4->addComponent(file3);
//
//	fs->print();
//
//
//
//
//
//	return 0;
//}