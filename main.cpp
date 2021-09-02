#include <iostream>
#include <Windows.h>
#include "Patterns/Builder.h"
#include "Patterns/FactoryMethod.h"
#include "Patterns/Singleton.h"
#include "Patterns/AbstractFactory.h"
#include "Task_DVD_Disk/Task_DVD_Disk.h"

using namespace std;

int mainDVD()
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

int mainAbstractFactory()
{
	setlocale(0, "");


	Car* car = new Car;
	CreatorCar* creator = new CreatorCar;
	creator->setFactory(new SportCarFactory);
	creator->create(car);
	car->print();

	Car* bmw = new Car;
	creator->setFactory(new BMWFactory);
	creator->create(bmw);
	bmw->print();


	return 0;
}

int mainSingleton()
{
	setlocale(0, "");

	Logger * logger = Logger::getInstance();
	logger->sendMessage("Error #45");
	logger->sendMessage("Error #404");


	return 0;
}

int mainFactoryMethod()
{
	setlocale(0, "");

	//Creator * creator = new TrackCreator;
	//Transport* truck = creator->create();
	//truck->delivery("Kyiv");

	//creator = new ShipCreator;
	//Transport *ship = creator->create();
	//ship->delivery("Odessa");



	Creator * creator;
	Transport* transport;

	cout << "0 - Truck, 1 - Ship \n";
	cout << "Введите тип транспорта: ";
	bool n;  cin >> n;

	if (n)
		creator = new TrackCreator;
	else
		creator = new ShipCreator;

	string address;
	cout << "Адресс: ";
	cin >> address;
	

	transport = creator->create();
	transport->delivery(address);

	return 0;
}

int mainBuilder()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");

	Director* director = new Director; //Создали директора

	MusicCenterBuilder* mcBuilder = new MusicCenterBuilder; //Создали билдер

	director->setBuilder(mcBuilder); //Дали директору билдер
	director->BuilderMegaMC(); //Дали директору задачу строить центрМЕга

	MusicCenter* mc = mcBuilder->getResult(); //Создали музкЦентр и забрали его у директора 
	mc->print();

	ManualMusicCenter* manualBuilder = new ManualMusicCenter; //Создали инструкию

	director->setBuilder(manualBuilder); //Отдали директору билдер инструкции
	director->BuilderMegaMC(); //Сказали создать инструкцию мега центра

	ManualMC* manual = manualBuilder->getResult();
	cout << manual->getText() << endl;

	//director->BuilderMiniMC();
	//MusicCenter* mc1 = mcBuilder->getResult();
	//mc1->print();

	return  0;
}

