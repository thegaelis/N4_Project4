#include "Donhang.h"
using namespace conSole;
cOrder::cOrder() {
	this->Number = 0;
	this->Code = "";
	this->Amount = 0;
	this->Total = 0;
	this->Name = "";
	this->Address = "";
	this->Phone = "";
	this->Day = "";
}
cOrder::cOrder(const cOrder& copy) {
	this->Number = copy.Number;
	this->Code = copy.Code;
	this->Amount = copy.Amount;
	this->Total = copy.Total;
	this->Name = copy.Name;
	this->Address = copy.Address;
	this->Phone = copy.Phone;
	this->Day = copy.Day;
}
cOrder::~cOrder() {}

void cOrder::Input_Order() {
	for (int i = 4; i <= 16; i += 2) {
		Write_Console(23, i, 60, "-");
	}
	for (int i = 5; i <= 15; i += 2) {
		Write_Console(23, i, 1, "|");
		Write_Console(48, i, 1, "|");
		Write_Console(82, i, 1, "|");
	}
	SET_COLOR(31);
	for (int i = 5; i <= 15; i += 2) {
		Write_Console(24, i, 24, " ");
	}
	ShowCur(true);
	Write_Console(40, 2, 1, " NHAP THONG TIN CHO DON HANG ");
	gotoXY(25, 5); cout << "Nhap ma san pham";
	gotoXY(25, 7); cout << "Nhap so luong";
	gotoXY(25, 9); cout << "Nhap ho va ten";
	gotoXY(25, 11); cout << "Nhap dia chi nhan hang";
	gotoXY(25, 13); cout << "Nhap so dien thoai";
	gotoXY(25, 15); cout << "Nhap ngay mua hang";
	SET_COLOR(15);
	gotoXY(50, 5);  Code = Charlimit();
	gotoXY(50, 7); Amount=ChangeString(Charlimit());
	gotoXY(50, 9); Name = Charlimit();
	gotoXY(50, 11); Address = Charlimit();
	gotoXY(50, 13); Phone = Charlimit();
	gotoXY(50, 15); Day = Charlimit();
	ShowCur(false);
}
void cOrder::Expost() {
	for (int i = 4; i <= 18; i += 2) {
		Write_Console(23, i, 60, "-");
	}
	for (int i = 5; i <= 17; i += 2) {
		Write_Console(23, i, 1, "|");
		Write_Console(48, i, 1, "|");
		Write_Console(82, i, 1, "|");
	}
	SET_COLOR(31);
	for (int i = 5; i <= 17; i += 2) {
		Write_Console(24, i, 24, " ");
	}
	Write_Console(40, 2, 1, " DON HANG DANG CHO XU LI ");
	gotoXY(25, 5); cout << "Ma san pham";
	gotoXY(25, 7); cout << "So luong";
	gotoXY(25, 9); cout << "Ho va ten";
	gotoXY(25, 11); cout << "Dia chi nhan hang";
	gotoXY(25, 13); cout << "So dien thoai";
	gotoXY(25, 15); cout << "Ngay mua hang";
	gotoXY(25, 17); cout << "Tong tien";
	gotoXY(25, 3); cout << "STT: " << Number;
	SET_COLOR(15);
	gotoXY(50, 5);  cout << Code;
	gotoXY(50, 7); cout << Amount;
	gotoXY(50, 9); cout << Name;
	gotoXY(50, 11); cout << Address;
	gotoXY(50, 13); cout << Phone;
	gotoXY(50, 15); cout << Day;
	gotoXY(50, 17); cout << Total;
}
istream& operator >> (istream& is, cOrder& p) {
	is >> p.Number;
	is.ignore();
	getline(is, p.Code);
	is >> p.Amount;
	is >> p.Total;
	is.ignore();
	getline(is, p.Name);
	getline(is, p.Address);
	getline(is, p.Phone);
	getline(is, p.Day);
	return is;
}
ostream& operator << (ostream& os, cOrder p) {
	os << p.Number << "\n";
	os << p.Code << "\n";
	os << p.Amount << "\n";
	os << p.Total << "\n";
	os << p.Name << "\n";
	os << p.Address << "\n";
	os << p.Phone << "\n";
	os << p.Day;
	return os;
}
void cOrder::SetTotal(cGoods hh[], int n) {
	for (int i = 0; i < n; i++) {
		if (hh[i].GetCode() == Code) {
			Total = Amount * hh[i].GetPrice();
		}
	}
}
void cOrder::SetNumber(int i) {
	Number = i;
}
string cOrder::GetCode() {
	return Code;
}
int cOrder::GetAmount() {
	return Amount;
}
