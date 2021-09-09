#include <iostream>
#include <Windows.h>

#include "Patterns/ChainOfCommand.h"
#include "Task_Universal_Editor/Task_Universal_Editor.h"

using namespace std;

void goToRush()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
}


//int main()
//{
//	goToRush();
//
//	Client* client = new Client(new Economict(new Buhfalter(new Director(nullptr))));
//	client->sendPayment(300);
//	client->sendPayment(1500);
//	client->sendPayment(6000);
//	client->sendPayment(10000);
//
//	return 0;
//}



int main()
{	
	mainUniversal_Editor();
	
	return 0;
}























