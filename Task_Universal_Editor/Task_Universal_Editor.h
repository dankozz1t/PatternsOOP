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
			cout << " 1 - печатать" << endl;
			cout << " 2 - перевести на другу строку" << endl;
			cout << " 3 - закрыть" << endl;

			cout << "Введите: "; cin >> menu;
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
		cout << "\nВведите имя файла: ";
		string nameFile; cin >> nameFile;

		TextFile* fil = new TextFile(nameFile);
		files.push_back(fil);

		acviteFiles = files.size() - 1;
	}

	void open() override
	{
		cout << "Существующие файлы: ";
		for (auto& c : files)
			cout << c->getName() << ", ";
		
		cout << "\n\nВведите имя файла: ";
		string nameFile; cin >> nameFile;

		for (int i = 0; i < files.size(); i++)
		{
			if (files[i]->getName() == nameFile)
			{
				cout << " * Вы открыли файл: " << files[i]->getName() << endl;
				acviteFiles = i;
				
				files[acviteFiles]->work();
			}
		}
	}

	void save() override
	{
		files[acviteFiles]->print();
		cout << " * СОХРАНЕНО!!!! * " << endl;
	}

	void saveNewName() override
	{
		cout << " * Сохранил под новым именем" << endl;
	}

	void close() override
	{
		cout << " * Закрыл" << endl;
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
		cout << " * Создал графический редактор" << endl;
	}

	void open() override
	{
		cout << " * Отрыл графический редактор" << endl;
	}

	void save() override
	{
		cout << " * Сохранил" << endl;
	}

	void saveNewName() override
	{
		cout << " * Сохранил под новым именем" << endl;
	}

	void close() override
	{
		cout << " * Закрыл" << endl;
	}
	
	void print() override
	{
		cout << " * Посмотрел" << endl;
	}
};

class Creator
{
public:
	virtual ~Creator() {}
	virtual Editor* createEditor() const = 0;
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
		cout << " * Вы создали текстовый редактор" << endl;
		return new TextEditor;
	}
};

class GraphicsEditorCreator : public Creator
{
public:
	Editor* createEditor() const override
	{
		cout << " * Вы создали текстовый редактор" << endl;
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
		cout << " * 1 - Создать " << endl;
		cout << " * 2 - Открыть " << endl;
		cout << "   3 - Сохранить " << endl;
		cout << "   4 - Сохранить под новым именем " << endl;
		cout << " * 5 - Показать " << endl;
		cout << "   6 - Закрыть " << endl;
		cout << " * 7 - Выход " << endl;

		cout << "Введите: "; cin >> menu;
		//TODO: другое меню для Графического (Палитра)

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