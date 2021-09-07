#pragma once
#include <iostream>

using namespace std;

class Prototype
{
public:
	virtual Prototype* clone() = 0;
	virtual void print() const = 0;
};

class _Rectangle: public Prototype
{
	int width, height;

public:
	_Rectangle(int w, int h) : width(w), height(h) {}

	void print() const override
	{
		cout << "W = " << width << "\nH = " << height << endl;
	}

	Prototype* clone() override
	{
		return new _Rectangle(width, height);
	}
};

class _Circle : public  Prototype
{
	int radius;
public:
	_Circle(int r) : radius(r) {}

	void print() const override
	{
		cout << "R = " << radius << endl;
	}

	Prototype* clone() override
	{
		return new _Circle(radius);
	}


};
