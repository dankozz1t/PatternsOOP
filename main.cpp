#include <iostream>
#include <Windows.h>
#include "Builder.h"
#include "FactoryMethod.h"
#include "Singleton.h"
#include "AbstractFactory.h"
#include "Task_DVD_Disk.h"

using namespace std;

int main()
{
	SetConsoleCP(1251); //у
	SetConsoleOutputCP(1251);
	setlocale(0, "");

	DVD_Drive* drive = new DVD_Drive;
	Disk* disk = new Disk;
	disk->diskSize = 1024;

	cout << "РАЗМЕР ДИСКА: " << disk->diskSize << " мб" << endl;

	cout << "\nзаписываю...\n\n";

	string temp;
	cout << "ЗАПИСЬ Дата: ";
	cin >> temp;

	unsigned size;
	cout << "ЗАПИСЬ размер (мб): ";
	cin >> size;
	cin.ignore();

	drive->open(disk);


	
	drive->write(disk, temp,size);
	cout << "\n...записал\n";


	cout << "\nсчитываю..\n\n";
	drive->read(disk);
	cout << "\n...считал\n";
	
	return 0;
}

int mainAbstractFactory()
{
	setlocale(0, "");


	//Car* car = new Car;
	//CreatorCar* creator = new CreatorCar;
	//creator->setFactory(new SportCarFactory);
	//creator->create(car);
	//car->print();

	//Car* bmw = new Car;
	//creator->setFactory(new BMWFactory);
	//creator->create(bmw);
	//bmw->print();


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

