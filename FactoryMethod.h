#pragma once
#include <string>
#include <iostream>

using namespace std;

class Transport
{

public:
	virtual ~Transport() {}
	virtual void delivery(string adress) const = 0;
	virtual string name() const = 0;

};

class Creator
{
public:
	virtual ~Creator() {}
	virtual Transport* createTransport() const = 0; //Фабричный метод
	Transport* create()
	{
		Transport* transport = this->createTransport();
		cout << transport->name();
		return transport;
	}
};

class Truck :public Transport
{
	void delivery(string address) const override
	{
		cout << " груз доставлен по адрессу: " << address << endl;
	}

	string name() const override
	{
		return "Задействован грузовик :";
	}
};

class TrackCreator : public Creator
{
public:
	Transport* createTransport() const override
	{
		return new Truck;
	}
};

class Ship :public Transport
{
	void delivery(string address) const override
	{
		cout << " груз доставлен морем по адрессу: " << address << endl;
	}

	string name() const override
	{
		return "Задействован аараход :";
	}
};

class ShipCreator : public Creator
{
public:
	Transport* createTransport() const override
	{
		return new Ship;
	}
};





