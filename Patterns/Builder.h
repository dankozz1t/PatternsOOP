#pragma once
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

	void BuilderMiniMC()
	{
		builder->createRadio();
		builder->createCD();
	}

};

class ManualMC
{
	string text = "Manual for Music Center\n";
public:
	void addText(string text)
	{
		this->text += text;
	}

	string getText() { return  text; }
};

class ManualMusicCenter : public Builder
{
	ManualMC* product;
public:

	ManualMusicCenter()
	{
		Reset();
	}

	~ManualMusicCenter()
	{
		delete product;
	}

	void Reset()
	{
		product = new ManualMC;
	}

	ManualMC* getResult()
	{
		ManualMC* result = product;
		Reset();
		return result;
	}

	void createRadio() const override
	{
		product->addText("Dlya zapyska radio najmite 1\n");
	}

	void createCD() const override
	{
		product->addText("Dlya zapyska CD najmite 2\n");
	}

	void createBlueRay() const override
	{
		product->addText("Dlya zapyska BlueRay najmite 3\n");
	}
};


//int mainBuilder()
//{
//	//goToRush();
//
//	//Director* director = new Director; //Создали директора
//
//	//MusicCenterBuilder* mcBuilder = new MusicCenterBuilder; //Создали билдер
//
//	//director->setBuilder(mcBuilder); //Дали директору билдер
//	//director->BuilderMegaMC(); //Дали директору задачу строить центрМЕга
//
//	//MusicCenter* mc = mcBuilder->getResult(); //Создали музкЦентр и забрали его у директора 
//	//mc->print();
//
//	//ManualMusicCenter* manualBuilder = new ManualMusicCenter; //Создали инструкию
//
//	//director->setBuilder(manualBuilder); //Отдали директору билдер инструкции
//	//director->BuilderMegaMC(); //Сказали создать инструкцию мега центра
//
//	//ManualMC* manual = manualBuilder->getResult();
//	//cout << manual->getText() << endl;
//
//	////director->BuilderMiniMC();
//	////MusicCenter* mc1 = mcBuilder->getResult();
//	////mc1->print();
//
//	return  0;
//}