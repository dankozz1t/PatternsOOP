#include <iostream>
#include <Windows.h>
#include "Builder.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	srand(time(0));
	
	Director* director = new Director;
	MusicCenterBuilder* mcBuilder = new MusicCenterBuilder;
	director->setBuilder(mcBuilder);
	director->BuilderMegaMC();

	MusicCenter* mc = mcBuilder->getResult();
	mc->print();

}

