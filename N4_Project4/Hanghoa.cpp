
#include "Hanghoa.h"
using namespace conSole;
cGoods::cGoods() {
	this->Code = "";
	this->Name = "";
	this->Place = "";
	this->Color = "";
	this->Price = 0;
	this->Day = "";
	this->Amount = 0;
}
cGoods::cGoods(const cGoods& copy) {
	this->Code = copy.Code;
	this->Name = copy.Name;
	this->Place = copy.Place;
	this->Color = copy.Color;
	this->Price = copy.Price;
	this->Day = copy.Day;
	this->Amount = copy.Amount;
}
cGoods::~cGoods() {}
string cGoods::GetName() {
	return Name;
}
string cGoods::GetCode() {
	return Code;
}
double cGoods::GetPrice() {
	return Price;
}
int cGoods::GetAmount() {
	return Amount;
}
void cGoods::SetAmout(int x) {
	Amount = x;
}
istream& operator >> (istream& is, cGoods& p) {
	gotoXY(50, 5);
	getline(is, p.Code);
	gotoXY(50, 7);
	getline(is, p.Name);
	gotoXY(50, 9);
	getline(is, p.Place);
	gotoXY(50, 11);
	getline(is, p.Color);
	gotoXY(50, 13);
	is >> p.Price;
	is.ignore();
	gotoXY(50, 15);
	getline(is, p.Day);
	gotoXY(50, 17);
	is >> p.Amount;
	is.ignore();
	return is;
}
ostream& operator<< (ostream& os, cGoods p) {
	os << p.Code << "\n";
	os << p.Name << "\n";
	os << p.Place << "\n";
	os << p.Color << "\n";
	os << p.Price << "\n";
	os << p.Day << "\n";
	os << p.Amount;
	return os;
}
void cGoods::Input() {
	gotoXY(50, 5);
	Code = Charlimit();
	gotoXY(50, 7);
	Name = Charlimit();
	gotoXY(50, 9);
	Place = Charlimit();
	gotoXY(50, 11);
	Color = Charlimit();
	gotoXY(50, 13);
	Price=ChangeString(Charlimit());
	gotoXY(50, 15);
	Day = Charlimit();
	gotoXY(50, 17);
	Amount= ChangeString(Charlimit());
}
void cGoods::Expost(int y) {
	gotoXY(14, y);
	cout << Code;
	gotoXY(22, y);
	cout << Name;
	gotoXY(40, y);
	cout << Place;
	gotoXY(54, y);
	cout << Color;
	gotoXY(64, y);
	cout << Price;
	gotoXY(74, y);
	cout << Day;
	gotoXY(94, y);
	cout << Amount;
}