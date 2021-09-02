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
			cout << "���� ������� ��������" << endl;
			dis->readable = true;
		}
		else
		{
			cout << " EROR_*@&^$(+_-+( ��Yy��4��� ����T��, �0����YY��� �����.. \n";
			dis->readable = false;
		}
		disk = dis;
	}

	void erase(Disk* dis)
	{
		if (dis->readable)
		{
			cout << "���� ������� ��������" << endl;
			dis->readable = false;
		}
		else
			cout << "�� ���� ����� ����" << endl;

		disk = dis;
	}

	void read(Disk* di)
	{
		if (di->isOpen())
		{
			if (!di->empty())
			{
				cout << "������ �����: " << di->getData() << endl;
				cout << "������ ������ �����: " << di->getDataSize() << " ��" << endl;
				cout << "���������� ����� ��������: " << di->getDiskSize() << " ��" << endl;
				cout << "���: " << di->getHash() << endl;
			}
			else
				cout << "������ ����\n";
		}
		else
			cout << "�� ���� ����� ����\n";
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
			else cout << "������������ ������\n";

		}
		else
			cout << "���� �� ������\n";

	}

	void clear(Disk* di)
	{
		if (!di->empty())
		{
			di->data.erase();
			di->diskSize += di->dataSize;
			di->dataSize = 0;
			cout << " ���� ������� ������ " << endl;
		}
		else
			cout << " ���� ������ " << endl;

	}


};

int main()
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
		cout << "\n������ �����: " << disk->diskSize << " ��\n" << endl;
		cout << "1 - �������� ����" << endl;
		cout << "2 - �������� ������" << endl;
		cout << "3 - ������� ������" << endl;
		cout << "4 - ������� ����" << endl;
		cout << "5 - �������� ����" << endl;
		cout << "6 - �����" << endl;

		cout << "�������: "; cin >> menu;
		cout << endl;
		
		system("cls");
		
		switch (menu)
		{
		case 1: drive->insert(disk); break;
		case 2:
		{
			if (disk->isOpen())
			{
				cout << "������ ����: ";
				string tempData;  cin >> tempData;
				cout << "������ ������ (��): ";
				unsigned tempSize; cin >> tempSize;
				cin.ignore();

				drive->write(disk, tempData, tempSize);
			}
			else
				cout << "�� ���� ����� ����\n";
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
