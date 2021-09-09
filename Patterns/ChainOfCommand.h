#pragma once
#include <string>
#include <iostream>

using namespace std;

class Handler
{
	Handler* nextHandler;
public:
	virtual void sendPayment(int sum) = 0;

};

class Client
{
	Handler * handler;
public:
	Client(Handler* h) :handler(h) {}

	void sendPayment(int sum)
	{
		if (handler)
			handler->sendPayment(sum);
	}
};

class Economict : public Handler
{
	Handler* nextHandler;
public:
	Economict(Handler* h) :nextHandler(h) {}

	virtual	void sendPayment(int sum) override
	{
		if (sum < 1000)
			cout << "Платеж проведен успешно. (с) Економист." << endl;
		else
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
		}
	}

};

class Buhfalter : public Handler
{
	Handler* nextHandler;
public:
	Buhfalter(Handler* h) :nextHandler(h) {}

	virtual	void sendPayment(int sum) override
	{
		if (sum < 5000)
			cout << "Платеж проведен успешно. (с) Бугалтер." << endl;
		else
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
		}
	}

};

class Director : public Handler
{
	Handler* nextHandler;
public:
	Director(Handler* h) :nextHandler(h) {}

	virtual void sendPayment(int sum) override
	{
		if (sum < 10000)
			cout << "Платеж проведен успешно. (с) Директор." << endl;
		else
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
			else
				cout << "Нужен совет директоров! КОНЕЦ!" << endl;
		}
	}

};
