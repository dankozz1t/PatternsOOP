#include <iostream>
#include <Windows.h>

#include "Patterns/TemplateMethod.h"

using namespace std;

void goToRush()
{
	SetConsoleTitleA("DesignPatterns");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
}

int main()
{
	goToRush();

	
	return 0;
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

//int main()
//{	
//	mainUniversal_Editor();
//	
//	return 0;
//}























