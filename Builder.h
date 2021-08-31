﻿#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class MCComponent
{
public:
	virtual string toString() = 0;
};

class Radio :public MCComponent
{
public:
	string toString() override { return "Radio"; }
};


class CD :public MCComponent
{
public:
	string toString() override { return "CD"; }
};

class BlueRay :public MCComponent
{
public:
	string toString() override { return "BlueRay"; }
};



class MusicCenter
{
	Radio radio;
	CD cd;
	BlueRay br;
public:

	vector<MCComponent*> parts;
	void print() const
	{
		cout << "Music Center:" << endl;
		for (auto &p : parts)
			cout << p->toString() << endl;

		cout << endl;
	}
};

class Builder
{
public:
	virtual ~Builder() {}
	virtual void createRadio() const = 0;
	virtual void createCD() const = 0;
	virtual void createBlueRay() const = 0;
};

class MusicCenterBuilder :public Builder
{
	MusicCenter * product;
public:
	MusicCenterBuilder()
	{
		Reset();
	}

	~MusicCenterBuilder()
	{
		delete product;
	}

	void Reset()
	{
		product = new MusicCenter;
	}

	MusicCenter* getResult()
	{
		MusicCenter* result = product;
		Reset();
		return result;
	}

	void createRadio() const override
	{
		product->parts.push_back(new Radio);
	}

	void createCD() const override
	{
		product->parts.push_back(new CD);
	}

	void createBlueRay() const override
	{						  
		product->parts.push_back(new BlueRay);
	}

};

class Director
{
	Builder* builder;

public:
	void setBuilder(Builder* b)
	{
		builder = b;
	}

	void BuilderMegaMC()
	{
		builder->createRadio();
		builder->createCD();
		builder->createBlueRay();
	}

};