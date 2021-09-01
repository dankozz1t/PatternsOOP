#pragma once
#include <string>
#include <iostream>

using namespace std;


class Component
{
public:
	virtual string toString() const = 0;
};

class Engine :public Component
{
public:
	string toString() const override
	{
		return "Engine";
	}

};

class Transmissin :public Component
{
public:
	string toString() const override
	{
		return "Transmissin";
	}

};

class BodyType :public Component
{
public:
	string toString() const override
	{
		return "BodyType";
	}

};

class DiselEngine : public Engine
{
	string toString() const override
	{
		return "Disel Engine";
	}
};

class GasEngine : public  Engine
{
	string toString() const override
	{
		return "Gas Engine";
	}
};

class ElectroEngine : public Engine
{
	string toString() const override
	{
		return "ElectroEngine";
	}

};

class MechanicTransmission : public Transmissin
{
	string toString() const override
	{
		return "MechanicTransmission";
	}

};

class AutomaticTransmission : public Transmissin
{
	string toString() const override
	{
		return "AutomaticTransmission ";
	}

};

class VariatorTransmission : public Transmissin
{
	string toString() const override
	{
		return "Variator Engine";
	}

};

class SedanBodyType : public BodyType
{
	string toString() const override
	{
		return "SedanBodyType";
	}

};

class SportBodyType : public BodyType
{
	string toString() const override
	{
		return "SportBodyType";
	}

};

class UniversalBodyType : public BodyType
{
	string toString() const override
	{
		return "UniversalBodyType";
	}

};

class Car
{
	Engine* engine;
	Transmissin* transmissin;
	BodyType* bodytype;
	string name;
public:
	Car();
	virtual ~Car()
	{
		if (engine) delete engine;
		if (transmissin) delete transmissin;
		if (bodytype) delete bodytype;
	}

	void setEngine(Engine* eng) { engine = eng; };
	void setTransmissin(Transmissin* tra) { transmissin = tra; };
	void setBodytype(BodyType* bt) { bodytype = bt; };

	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Engine: " << engine->toString() << endl;
		cout << "Transmissin: " << transmissin->toString() << endl;
		cout << "BodyType: " << bodytype->toString() << endl;
	}


};
