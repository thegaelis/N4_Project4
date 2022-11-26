#pragma once
#ifndef Hanghoa
#define Hanghoa

#include <iostream>
#include <string>
#include "Console.h"
using namespace std;
class cGoods {
	string Code;
	string Name;
	string Place;
	string Color;
	double Price;
	string Day;
	int Amount;
public:
	cGoods();
	cGoods(const cGoods& copy);
	~cGoods();
	friend istream& operator >> (istream& is, cGoods& p);
	friend ostream& operator<< (ostream& os, cGoods p);
	void Input();
	void Expost(int y);
	string GetName();
	string GetCode();
	double GetPrice();
	int GetAmount();
	void SetAmout(int x);
};
#endif
