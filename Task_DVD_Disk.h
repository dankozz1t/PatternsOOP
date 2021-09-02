#pragma once
#include <string>
#include <iostream>
using namespace std;


class Disk
{
public:
	string data;
	unsigned dataSize;
	unsigned diskSize;
	bool readable;

	//bool recoverData(string& rec)
	//{
	//}

public:
	Disk()
	{
		data = "";
		dataSize = 0;
		diskSize = 0;
		readable = true;
	}
	Disk(string& di) { data = di; }
	~Disk() {}

	bool empty()
	{
		return data.empty();
	}

	bool isOpen()
	{
		return readable;
	}

	string& getData()
	{
		return data;
	}

	void setData(string& d)
	{
		data = d;
	}

	unsigned getDiskSize()
	{
		return diskSize;
	}

	unsigned getHash()
	{
		hash<string> h;
		int t = h(data);
		return t;
	}

	void clearData()
	{
		if (!empty()) data.erase();
	}

};


class DVD_Drive
{
public:
	Disk* disk = nullptr;

	void open(Disk* dis)
	{

		int t = rand() % 4;
		if (t) dis->readable = true;
		else cout << "0 \n";
		disk = dis;
	}

	void read(Disk* di)
	{
		if (di->isOpen())
		{
			cout << "DATA: " << di->getData() << endl;
			cout << "DATA_SIZE: " << di->dataSize << " мб" <<endl;
			cout << "DISK_SIZE: "<< di->getDiskSize() << " мб" << endl;
			cout << "HASH: "<< di->getHash() << endl;
		}
		else
			cout << "НЕ могу открыть\n";
	}

	void write(Disk* di, string& data, unsigned& size)
	{
		if (di->isOpen())
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
				cout << "Пустой диск\n";
		}
		else
			cout << "НЕ могу открыть\n";
	}

};
