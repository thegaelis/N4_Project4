#pragma once
#ifndef Donhang
#define Donhang

#include <iostream>
#include <string>
#include "Console.h"
//#include "Common_Funtcion.h"
using namespace std;
class cOrder {
	int Number;
	string Code;
	int Amount;
	double Total;
	string Name;
	string Address;
	string Phone;
	string Day;
public:
	cOrder();
	cOrder(const cOrder& copy);
	~cOrder();
	void Input_Order();
	friend istream& operator >> (istream& is, cOrder& p);
	friend ostream& operator << (ostream& os, cOrder p);
	void Expost();
	void SetTotal(cGoods hh[], int n);
	void SetNumber(int i);
	string GetCode();
	int GetAmount();
};
#endif // !ORDER_H
