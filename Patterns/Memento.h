#pragma once
#include <iostream>
#include <stack>

using namespace std;

class HeroMemento;


class Hero
{
	int bullet = 10;
	int hp = 100;

public:

	void shoot()
	{
		if (bullet > 0)
			cout << "ПИУ! -> \n Патронов: " << --bullet << endl;
		else
			cout << "Патронов больше нет \n";
	}

	HeroMemento* save();

	void restore(HeroMemento* memento);
};


class HeroMemento
{
	int bullet = 10;
	int hp = 100;
public:
	HeroMemento(int _bul, int _hp) : bullet(_bul), hp(_hp) {}
	int getBullet() { return bullet; }
	int getHp() { return hp; }


};

class GameHistory
{
public:
	stack<HeroMemento*> history;
	Hero* hero;

	void save()
	{
		history.push(hero->save());
	}
	
	void undo()
	{
		hero->restore(history.top());
	}

};

HeroMemento* Hero::save()
{
	cout << "Сохраненгие игры: патронов - " << bullet << " хп - " << hp << endl;
	return new HeroMemento(bullet, hp);
}

void Hero::restore(HeroMemento* memento)
{
	bullet = memento->getBullet();
	hp = memento->getHp();
	cout << "Востановдение, Патронов - " << bullet << " хп - " << hp << endl;
}


//int main()
//{
//	goToRush();
//
//	Hero* hero = new Hero;
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//
//	GameHistory* gh = new GameHistory;
//	gh->save();
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//	gh->undo();
//	hero->shoot();
//	hero->shoot();
//	hero->shoot();
//
//
//	return 0;
//}