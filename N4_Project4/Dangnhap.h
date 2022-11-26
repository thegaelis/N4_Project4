#pragma once
#ifndef Dangnhap
#define Dangnhap

#include <iostream>
#include "Console.h"
using namespace std;
using namespace conSole;
class cLogin {
	string User;
	string Password;
public:
	cLogin();
	cLogin(const cLogin& copy);
	~cLogin();
	friend istream& operator >> (istream& is, cLogin& login);
	bool operator ==(cLogin p);
	void SetUser(string user);
	void SetPassword(string password);
	string GetUser();
	string GetPassword();
};

#endif
