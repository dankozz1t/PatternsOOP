#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class TextFile
{
protected:
	string name;
	string text;

public:
	TextFile(string n) :name(n) {}

	string setName(string nam) { name = nam; }
	string getName() { return name; }

	void work()
	{
		int menu = 0;
		while (menu != 3)
		{
			system("cls");
			cout << " 1 - ��������" << endl;
			cout << " 2 - ��������� �� ����� ������" << endl;
			cout << " 3 - �������" << endl;

			cout << "�������: "; cin >> menu;
			switch (menu)
			{
			case 1: write(); break;
			case 2: text += "\n"; break;
			}
		}
	}

	void write()
	{
		cout << text;
		cin.ignore();

		string buff;
		getline(cin, buff);

		text += buff;
	}

	void print()
	{
		cout << "\n--------------------------\n";
		cout << text;
		cout << "\n--------------------------\n";
	}
};

class Editor
{
public:
	virtual ~Editor() {}
	virtual void create() = 0;
	virtual void open() = 0;
	virtual void save() = 0;
	virtual void saveNewName() = 0;
	virtual void close() = 0;
	virtual void print() = 0;

};

class TextEditor :public Editor
{
	vector<TextFile*> files;
	int acviteFiles;
public:
	void create() override
	{
		cout << "\n������� ��� �����: ";
		string nameFile; cin >> nameFile;

		TextFile* fil = new TextFile(nameFile);
		files.push_back(fil);

		acviteFiles = files.size() - 1;
	}

	void open() override
	{
		cout << "������������ �����: ";
		for (auto& c : files)
			cout << c->getName() << ", ";
		
		cout << "\n\n������� ��� �����: ";
		string nameFile; cin >> nameFile;

		for (int i = 0; i < files.size(); i++)
		{
			if (files[i]->getName() == nameFile)
			{
				cout << " * �� ������� ����: " << files[i]->getName() << endl;
				acviteFiles = i;
				
				files[acviteFiles]->work();
			}
		}
	}

	void save() override
	{
		files[acviteFiles]->print();
		cout << " * ���������!!!! * " << endl;
	}

	void saveNewName() override
	{
		cout << " * �������� ��� ����� ������" << endl;
	}

	void close() override
	{
		cout << " * ������" << endl;
	}
	
	void print() override
	{
		files[acviteFiles]->print();
	}

};


class GraphicsEditor :public Editor
{
public:
	void create() override
	{
		cout << " * ������ ����������� ��������" << endl;
	}

	void open() override
	{
		cout << " * ����� ����������� ��������" << endl;
	}

	void save() override
	{
		cout << " * ��������" << endl;
	}

	void saveNewName() override
	{
		cout << " * �������� ��� ����� ������" << endl;
	}

	void close() override
	{
		cout << " * ������" << endl;
	}
	
	void print() override
	{
		cout << " * ���������" << endl;
	}
};

class Creator
{
public:
	virtual ~Creator() {}
	virtual Editor* createEditor() const = 0; //��������� �����
	Editor* create()
	{
		Editor* editor = this->createEditor();
		return editor;
	}
};

class TextEditorCreator : public Creator
{
public:
	Editor* createEditor() const override
	{
		cout << " * �� ������� ��������� ��������" << endl;
		return new TextEditor;
	}
};

class GraphicsEditorCreator : public Creator
{
public:
	Editor* createEditor() const override
	{
		cout << " * �� ������� ��������� ��������" << endl;
		return new GraphicsEditor;
	}
};

int mainUniversal_Editor()
{
	Creator* creator = new TextEditorCreator;
	Editor* editor;

	editor = creator->create();
	int menu = 0;
	do
	{
		system("cls");
		cout << " * 1 - ������� " << endl;
		cout << " * 2 - ������� " << endl;
		cout << "   3 - ��������� " << endl;
		cout << "   4 - ��������� ��� ����� ������ " << endl;
		cout << " * 5 - �������� " << endl;
		cout << "   6 - ������� " << endl;
		cout << " * 7 - ����� " << endl;

		cout << "�������: "; cin >> menu;
		//TODO: ������ ���� ��� ������������ (�������)

		switch (menu)
		{
		case 1: system("cls"); editor->create(); break;
		case 2: system("cls"); editor->open(); break;
		case 3:  break;
		case 4:  break;
		case 5: system("cls"); editor->print(); system("pause"); break;
		case 6:  break;
		}

	} while (menu != 7);

	return 0;
}