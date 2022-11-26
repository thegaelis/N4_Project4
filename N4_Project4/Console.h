#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <cwchar>
#include <iostream>
#include <string>
#include "Hanghoa.h"
using namespace std;
namespace conSole {
	//vi tri x
	int whereX();
	//vi tri y
	int whereY();
	//vi tri xy
	void gotoXY(int x, int y);
	//mau
	void SET_COLOR(int color);
	//tro
	void ShowCur(bool Cur);
	//lay key
	int inputKey();
	//size
	void Font(int size);
	//cai dat man hinh
	void SetWindowSize(int width, int height);
	//Viet ra man hinh Console
	void Write_Console(int x, int y, int n, string kitu);
	//Nhap gioi han
	string Charlimit();
	//Doi chuoi thanh so
	long long ChangeString(string chuoi);
}
#endif // CONSOLE_H