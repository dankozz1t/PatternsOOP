#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

class Disk
{
public:
	string data;
	unsigned dataSize;
	unsigned diskSize;
	bool readable = false;

	Disk() {}
	~Disk() {}

	bool empty() { return data.empty(); }
	bool isOpen() { return readable; }

	string& getData() { return data; }
	void setData(string& d) { data = d; }

	unsigned getDataSize() { return dataSize; }
	unsigned getDiskSize() { return diskSize; }

	unsigned getHash()
	{
		hash<string> _hash;
		return int(_hash(data));
	}

};


class DVD_Drive
{
public:
	Disk* disk = nullptr;

	void insert(Disk* dis)
	{
		int t = rand() % 4;
		if (t)
		{
			cout << "Диск успешно вставлен" << endl;
			dis->readable = true;
		}
		else
		{
			cout << " EROR_*@&^$(+_-+( НеYyда4ная попыTка, п0пробYYйте снова.. \n";
			dis->readable = false;
		}
		disk = dis;
	}

	void erase(Disk* dis)
	{
		if (dis->readable)
		{
			cout << "Диск успешно извлечен" << endl;
			dis->readable = false;
		}
		else
			cout << "Не могу найти диск" << endl;

		disk = dis;
	}

	void read(Disk* di)
	{
		if (di->isOpen())
		{
			if (!di->empty())
			{
				cout << "Данные диска: " << di->getData() << endl;
				cout << "Размер данных диска: " << di->getDataSize() << " мб" << endl;
				cout << "Свободного места осталось: " << di->getDiskSize() << " мб" << endl;
				cout << "Хэш: " << di->getHash() << endl;
			}
			else
				cout << "Пустой диск\n";
		}
		else
			cout << "Не могу найти диск\n";
	}

	void write(Disk* di, string& data, unsigned& size)
	{
		if (di->empty())
		{
			if (size <= di->diskSize)
			{
				di->data = data;
				di->dataSize = size;
				di->diskSize -= size;
			}
			else cout << "Недостаточно памяти\n";

		}
		else
			cout << "Диск НЕ пустой\n";

	}

	void clear(Disk* di)
	{
		if (!di->empty())
		{
			di->data.erase();
			di->diskSize += di->dataSize;
			di->dataSize = 0;
			cout << " Диск успешно очищен " << endl;
		}
		else
			cout << " Диск ПУСТОЙ " << endl;

	}


};

int mainTaskDISK()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");

	DVD_Drive* drive = new DVD_Drive;
	Disk* disk = new Disk;
	disk->diskSize = 1024;

	int menu = 0;
	do
	{
		cout << "\nРАЗМЕР ДИСКА: " << disk->diskSize << " мб\n" << endl;
		cout << "1 - Вставить диск" << endl;
		cout << "2 - Записать данные" << endl;
		cout << "3 - Считать данные" << endl;
		cout << "4 - Извлечь диск" << endl;
		cout << "5 - Очистить диск" << endl;
		cout << "6 - Выход" << endl;

		cout << "Введите: "; cin >> menu;
		cout << endl;
		
		system("cls");
		
		switch (menu)
		{
		case 1: drive->insert(disk); break;
		case 2:
		{
			if (disk->isOpen())
			{
				cout << "ЗАПИСЬ Дата: ";
				string tempData;  cin >> tempData;
				cout << "ЗАПИСЬ размер (мб): ";
				unsigned tempSize; cin >> tempSize;
				cin.ignore();

				drive->write(disk, tempData, tempSize);
			}
			else
				cout << "Не могу найти диск\n";
			break;
		}
		case 3:	drive->read(disk); break;
		case 4:	drive->erase(disk); break;
		case 5: drive->clear(disk); break;
		}

		system("pause");
		
	} while (menu != 6);

	return 0;
}
