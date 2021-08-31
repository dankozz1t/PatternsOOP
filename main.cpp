#include <iostream>

#include "Builder.h"

using namespace std;

int main()
{

	Director* director = new Director;
	MusicCenterBuilder* mcBuilder = new MusicCenterBuilder;
	director->setBuilder(mcBuilder);
	director->BuilderMegaMC();

	MusicCenter* mc = mcBuilder->getResult();
	mc->print();

}

