#pragma once
#include <iostream>
#include <string>

using namespace std;

class Water;

class IWaterState
{
public:
	virtual void heat(Water* water) = 0;
	virtual void frost(Water* water) = 0;
};

class Water
{
	IWaterState* state = nullptr;
public:
	void setState(IWaterState* state)
	{
		delete this->state;
		this->state = state;
	}

	void heat()
	{
		state->heat(this);
	}

	void frost()
	{
		state->frost(this);
	}
};

class SolidWaterState : public IWaterState
{
public:
	void heat(Water* water) override;

	void frost(Water* water) override
	{
		cout << "Продолжаем замораживать лёд" << endl;
	}
};

class LiquideWaterState : public IWaterState
{
public:
	void heat(Water* water) override;

	void frost(Water* water) override
	{
		cout << "Вода превращается в лёд" << endl;
		water->setState(new SolidWaterState);
	}
};

class GasWaterState : public IWaterState
{
	void heat(Water* water) override
	{
		cout << "Продолжаем нагревать лёд" << endl;
	}

	void frost(Water* water) override
	{
		cout << "Пар превращается в воду" << endl;
		water->setState(new LiquideWaterState);
	}
};

inline void SolidWaterState::heat(Water* water)
{
	cout << "Лёд превращается в воду" << endl;
	water->setState(new LiquideWaterState);
}

inline void LiquideWaterState::heat(Water* water)
{
	cout << "Вода превращается в пар" << endl;
	water->setState(new GasWaterState);
}

//int main()
//{
//	goToRush();
//
//	Water* water = new Water;
//	water->setState(new SolidWaterState);
//	water->heat();
//	water->heat();
//	water->heat();
//	water->frost();
//	water->frost();
//	water->frost();
//	water->frost();
//	
//	return 0;
//}