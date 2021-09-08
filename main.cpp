#include <iostream>
#include <Windows.h>

#include "Task_DVD_Disk/Task_DVD_Disk.h"

#include "Patterns/Builder.h"
#include "Patterns/FactoryMethod.h"
#include "Patterns/Singleton.h"
#include "Patterns/AbstractFactory.h"
#include "Patterns/Prototype.h"
#include "Patterns/Adapter.h"
#include "Patterns/Bridge.h"
#include "Patterns/Decorator.h"
#include "Patterns/Composite.h"
#include "Patterns/Facade.h"

using namespace std;

void goToRush()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
}

int main()
{
	goToRush();

	Programmer_ *pr = new Programmer_();
	TextEditor* te = new TextEditor;
	Compillee* com = new Compillee;
	Debuger * deb = new Debuger;
	Facade* fa =new Facade(te, com, deb);
	pr->createApp(fa);

	return 0;
}

int mainComposite()
{
	goToRush();

	Componentt* fs = new Directory("^FileSystem");
	Componentt* discC = new Directory("disk C");
	Componentt* folder1 = new Directory("$ Folder 1");
	Componentt* folder2 = new Directory("$ Folder 2");
	Componentt* folder3 = new Directory("$ Folder 3");
	Componentt* folder4 = new Directory("$ Folder 4");
	Componentt* file1 = new File("* File 1");
	Componentt* file2 = new File("* File 2");
	Componentt* file3 = new File("* File 3");

	fs->addComponent(discC);
	discC->addComponent(folder1);
	discC->addComponent(folder2);
	discC->addComponent(folder3);
	discC->addComponent(file1);
	folder1->addComponent(folder4);
	folder4->addComponent(file3);

	fs->print();





	return 0;
}


int mainDocorator()
{
	goToRush();

	cout << "\n-------Пицца №1-------" << endl;

	Pizza * pizza = new Italian();
	pizza = new Tomato(pizza);
	pizza = new Cheese(pizza);

	cout << pizza->getName() << endl;
	cout << "---------------------" << endl;
	cout << " Цена: " << pizza->getPrice() << endl;


	cout << "\n-------Пица №2-------" << endl;

	Pizza * pizza2 = new American();
	pizza2 = new Cheese(pizza);
	pizza2 = new Cheese(pizza);

	cout << pizza2->getName() << endl;
	cout << "---------------------" << endl;
	cout << " Цена: " << pizza2->getPrice() << endl;

	return 0;
}

int mainBridge()
{
	goToRush();

	Programmer * freelancer = new Freelance(new CPPLanguage());
	freelancer->work();
	freelancer->getMoney();

	cout << " ------------------- " << endl;

	freelancer->setLanguage(new CSharpLanguage());
	freelancer->work();
	freelancer->getMoney();

	cout << " ------------------- " << endl;


	Programmer * office = new Office(new CPPLanguage());
	office->work();
	office->getMoney();

	cout << " ------------------- " << endl;

	office->setLanguage(new CSharpLanguage());
	office->work();
	office->getMoney();

	return 0;
}

int mainAdapter()
{
	goToRush();

	Adapter::Driver * driver = new Adapter::Driver();
	Adapter::Car * car = new Adapter::Car;
	driver->travel(car);

	Adapter::Camel * camel = new Adapter::Camel();
	Adapter::Adapter* adapter = new Adapter::Adapter(camel);

	driver->travel(adapter);

	return 0;
}

void method(Prototype * figure)
{
	Prototype * figureCopy = figure->clone();
	figure->print();

}

int mainPrototype()
{
	goToRush();

	Prototype * f = new _Rectangle(12, 5);
	method(f);

	f->print();

	return 0;
}


int mainDVD()
{
	goToRush();

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
	goToRush();


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
	goToRush();

	Logger * logger = Logger::getInstance();
	logger->sendMessage("Error #45");
	logger->sendMessage("Error #404");


	return 0;
}

int mainFactoryMethod()
{
	goToRush();

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
	goToRush();

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

