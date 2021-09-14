#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Subscriber;

class Publisher
{
protected:
	string name;

	vector<Subscriber*> subscribers;
public:
	Publisher(string n) :name(n) {}
	
	void addSubscriber(Subscriber* sub) 
	{
		subscribers.push_back(sub);
	}

	void removeSubscriber(Subscriber* sub) 
	{
		auto it = find(subscribers.begin(), subscribers.end(), sub);
		if (it != subscribers.end())
			subscribers.erase(it);
	}

	string getName() { return name; }

	virtual float getPrice() { return 0; }
	virtual string getMessage() { return ""; }
	
	virtual void change() = 0;
	void notify();
};


class Automobile : public Publisher
{
	float price;
public:
	Automobile(string n, float p) :Publisher(n), price(p) {}

	float getPrice() override { return price; }
	
	void change() override
	{
		float p;
		cout << "Новая цена: "; cin >> p;
		if (p != price)
		{
			price = p;
			notify();
		}
	}
};


class Subscriber
{
public:
	virtual void update(Publisher* product) = 0;
};

class Buyer : public Subscriber
{
	Publisher* product;
	string name;
public:
	Buyer(string n) : name(n) {}

	void setProduct(Publisher* product) { this->product = product; }

	void update(Publisher* product) override
	{
		cout << name << ", изменилась цена продукта: " <<
			product->getName() << "! Купите прямо сейчас ВСЕГО за: " << product->getPrice() <<"$" << endl << endl;
	}
};

class Nickname : public Subscriber
{
	Publisher* product;
	string name;
public:
	Nickname(string n) : name(n) {}

	void setProduct(Publisher* product) { this->product = product; }

	void update(Publisher* product) override
	{
		cout << " Сообщение для " << name << ", " <<
			product->getMessage() << endl << endl;
	}
};

void Publisher::notify()
{
	for (auto s : subscribers)
		s->update(this);
}


class Chat : public Publisher
{
	string messages = "";
public:
	Chat(string n) : Publisher(n) {}

	void change()
	{
		string st;
		cout << "Новое сообщение: ";
		getline(cin, st);
		messages += st;
		notify();
	}
	
	string getMessage() override { return  messages; }
};

//int main()
//{
//	goToRush();
//
//	//Publisher* product = new Automobile("Mercedes CuberFUCK", 12000);
//	//Publisher* product2 = new Automobile("Audi DeadIncide", 100);
//	//Subscriber* buyer = new Buyer("Илон Муск");
//	//Subscriber* buyer2 = new Buyer("Марк Сукенберг");
//
//	//product->addSubscriber(buyer);
//	//product->change();
//
//	//product2->addSubscriber(buyer);
//	//product2->addSubscriber(buyer2);
//	//product2->change();
//
//
//	//Subscriber* nick1 = new Nickname("Nick1");
//	//Subscriber* nick2 = new Nickname("Nick2");
//	//Subscriber* nick3 = new Nickname("Nick3");
//
//	//Publisher* chat = new Chat("Телеграмм");
//	//chat->addSubscriber(nick1);
//	//chat->addSubscriber(nick2);
//	//chat->addSubscriber(nick3);
//
//	//chat->change();
//	//chat->change();
//	//chat->removeSubscriber(nick2);
//	//chat->change();
//	
//	return 0;
//}