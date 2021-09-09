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

	void setName(string nam) { name = nam; }
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

			cout << "Введите меню: "; cin >> menu;
			switch (menu)
			{
			case 1: write(); break;
			case 2: text += "\n"; break;
			default: break;
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
	virtual void deleteFile() = 0;

	virtual void getMenu(Editor*) = 0;

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
		cout << " *-- " << files[acviteFiles]->getName() << " --*" << endl;
		files[acviteFiles]->print();
		cout << " * СОХРАНЕНО!!!! * " << endl;
	}

	void saveNewName() override
	{
		cout << " *-- " << files[acviteFiles]->getName() << " --*" << endl;
		
		cout << "Введите новое имя: "; string newName; cin >> newName;
		
		files[acviteFiles]->setName(newName);
		cout << " * Фаил сохранен под новым именем: * " << files[acviteFiles]->getName() << endl;
	}

	void close() override
	{
		if (acviteFiles == 0) //Если Активный файл(окно) закрыть, откроется предыдущий
			cout << " * Нет активных окон или же оно одно." << endl;
		else
		{
			cout << "Активный файл " << files[acviteFiles]->getName() << " закрыт." << endl;
			acviteFiles--;
			cout << "Теперь Активный файл " << files[acviteFiles]->getName() << endl;
		}
	}

	void print() override
	{
		cout << " *-- " << files[acviteFiles]->getName() << " --*" << endl;
		files[acviteFiles]->print();
	}

	void deleteFile() override
	{
		cout << "Активный файл " << files[acviteFiles]->getName() << " удален." << endl;
		files.erase(files.begin() + acviteFiles);
		cout << "Теперь Активный файл " << files[acviteFiles]->getName() << endl;
	}


	void getMenu(Editor* editor) override
	{
		int menu = 0;
		do
		{
			system("cls");
			cout << " *-- ТЕКТОВЫЙ РЕДАКТОР -- *" << endl;
			cout << " * 1 - Создать " << endl;
			cout << " * 2 - Открыть " << endl;
			cout << " * 3 - Сохранить " << endl;
			cout << " * 4 - Сохранить под новым именем " << endl;
			cout << " * 5 - Показать " << endl;
			cout << " * 6 - Закрыть " << endl;
			cout << " * 7 - Удалить " << endl;
			cout << " * 8 - Выход " << endl;

			cout << "Введите: "; cin >> menu;

			switch (menu)
			{
			case 1: system("cls"); editor->create(); break;
			case 2: system("cls"); editor->open(); break;
			case 3: system("cls"); editor->save(); system("pause"); break;
			case 4: system("cls"); editor->saveNewName(); system("pause"); break;
			case 5: system("cls"); editor->print(); system("pause"); break;
			case 6: system("cls"); editor->close(); system("pause"); break;
			case 7: system("cls"); editor->deleteFile(); system("pause");  break;
			}

		} while (menu != 8);
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
		cout << " * Посмотрел/Печать" << endl;
	}

	void deleteFile() override
	{
		cout << " * Удалил" << endl;

	}

	void palette()
	{
		cout << " * Использую палитру!" << endl;
	}

	void getMenu(Editor* editor) override
	{
		int menu = 0;
		do
		{
			system("cls");
			cout << " *-- ГРАФИЧЕСКИЙ РЕДАКТОР -- *" << endl;
			cout << " * 1 - Создать " << endl;
			cout << " * 2 - Открыть " << endl;
			cout << " * 3 - Сохранить " << endl;
			cout << " * 4 - Сохранить под новым именем " << endl;
			cout << " * 5 - Показать/Печать " << endl;
			cout << " * 6 - Закрыть " << endl;
			cout << " * 7 - Удалить " << endl;
			cout << " * 8 - ПАЛИТРА " << endl;			
			cout << " * 9 - Выход " << endl;

			cout << "Введите: "; cin >> menu;

			switch (menu)
			{
			case 1: system("cls"); editor->create(); system("pause"); break;
			case 2: system("cls"); editor->open(); system("pause"); break;
			case 3: system("cls"); editor->save(); system("pause"); break;
			case 4: system("cls"); editor->saveNewName(); system("pause"); break;
			case 5: system("cls"); editor->print(); system("pause"); break;
			case 6: system("cls"); editor->close(); system("pause"); break;
			case 7: system("cls"); editor->deleteFile(); system("pause");  break;
			case 8: system("cls"); GraphicsEditor::palette(); system("pause");  break; //TODO: ?????
			}

		} while (menu != 9);
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
		return new TextEditor;
	}
};

class GraphicsEditorCreator : public Creator
{
public:
	Editor* createEditor() const override
	{
		return new GraphicsEditor;
	}
};

int mainUniversal_Editor()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	SetConsoleTitleA("Universal Editor");
	
	Creator* creator = nullptr;
	Editor* editor = nullptr;

	int menu = 0;
	while (menu != 3)
	{
		system("cls");
		cout << "ВЫ ОТКРЫЛИ РЕДАКТОР. КАКОЙ РЕДАКТОР ВАС ИНТЕРЕСУЕТ?" << endl;
		cout << " 1 - Открыть Текстовый редактор." << endl;
		cout << " 2 - Открыть Графический редактор." << endl;
		cout << " 3 - Выход." << endl;

		cout << "Введите: ";  cin >> menu;

		switch (menu)
		{
		case 1: creator = new TextEditorCreator; break;
		case 2:	creator = new GraphicsEditorCreator; break;
		case 3: return 0;
		}

		editor = creator->create();
		editor->getMenu(editor);
	}

	return 0;

}