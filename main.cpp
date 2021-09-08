#include <iostream>
#include <Windows.h>

#include "Task_Universal_Editor/Task_Universal_Editor.h"

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
	
	mainUniversal_Editor();
	
	return 0;
}























