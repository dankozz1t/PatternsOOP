#pragma once
#include <iostream>

using namespace std;

namespace Adapter
{
	class Transport
	{

	public:
		virtual void drive() const = 0;

	};

	class Animal
	{

	public:
		virtual void move() const = 0;

	};

	class Car : public Transport
	{
	public:
		void drive() const override
		{
			cout << " Машина едет по дороге " << endl;
		}

	};

	class Camel : public Animal
	{
	public:
		void move() const override
		{
			cout << " Верблюд идет по пустыне " << endl;
		}

	};

	class Driver
	{
	public:
		void travel(Transport * transport)
		{
			transport->drive();
		}
	};


	class Adapter : public Transport  //CamelToTransport
	{
		Camel * camel;

	public:
		Adapter(Camel * c) : camel(c){}

		void drive() const override
		{
			camel->move();
		}
	};

}