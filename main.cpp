#include <iostream>
#include <Windows.h>

#include "Patterns/Mediator.h"

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
//	mainUniversal_Editor();
//	
//	return 0;
//}























