#pragma once
#include "Hanghoa.h"
#include "Donhang.h"
#include "Dangnhap.h"
#include "Queue.h"
#include "Console.h"
#include <fstream>
using namespace std;
using namespace conSole;
//Cac chuc nang chinh

//Thoat man hinh
void OutESC();

//Hien thi menu
int Menu(string* arr);

//Nhap hang hoa tu file
void InputFile(cGoods* hh, int& n, Queue<cOrder>& dh, cLogin* dn, int& z);

//Hien thi thong tin hang hoa
void Show_Content(int y, string* a, int* vt, cGoods* hh, int& n);

//Tim kiem thong tin hang hoa
void Search_Goods(cGoods* hh, int& n, int* vt, string* a);

//Dat Hang
void Order_Goods(cGoods* hh, int& n, Queue<cOrder>& dh);

//Quan li
void Manager_Goods(cGoods* hh, int& n, Queue<cOrder>& dh, cLogin* dn, int& z);

//Su lua chon
int Option(string* option, int n, int x, int y, bool clear);

//Thoat man hinh
void OutESC() {
	while (true) {
		if (inputKey() == 27) {
			system("cls");
			break;
		}
	}
}
//Hien thi menu
int Menu(string* arr) {
	SET_COLOR(50);
	Write_Console(25, 3, 58, " ");
	Write_Console(25, 7, 58, " ");
	Write_Console(25, 19, 58, " ");
	for (int i = 4; i < 19; i++) {
		Write_Console(25, i, 1, " ");
		Write_Console(82, i, 1, " ");
	}
	SET_COLOR(78);
	Write_Console(38, 5, 1, "NHOM 4 - PROJECT 4 - PRODUCT MANAGER ");
	SET_COLOR(3);
	int xx = 30, yy = 9;
	for (int i = 0; i < 5; i++) {
		Write_Console(xx, yy, 1, arr[i]);
		yy += 2;
	}
	int x = 30, y = 9;
	int yc = y;
	while (true) {
		SET_COLOR(15);
		yy = 9;
		for (int i = 0; i < 5; i++) {
			if (yy == y) {
				Write_Console(xx, yy, 1, arr[i]);
			}
			yy += 2;
		}
		int check = inputKey();
		if (check == 1072) {
			y -= 2;
			if (y < 9) {
				y = 17;
			}
		}
		else if (check == 1080) {
			y += 2;
			if (y > 17) {
				y = 9;
			}
		}
		else if (check == 13) {
			return y;
		}
		if (y != yc) {
			SET_COLOR(3);
			yy = 9;
			for (int i = 0; i < 5; i++) {
				if (yy == yc) {
					Write_Console(xx, yy, 1, arr[i]);
				}
				yy += 2;
			}
			Write_Console(x - 2, yc - 1, 50, " ");
			Write_Console(x - 2, yc, 1, " ");
			Write_Console(x + 47, yc, 1, " ");
			Write_Console(x - 2, yc + 1, 50, " ");
		}
		Write_Console(x - 2, y - 1, 50, " ");
		Write_Console(x - 2, y, 1, " ");
		Write_Console(x + 47, y, 1, " ");
		Write_Console(x - 2, y + 1, 50, " ");
		yc = y;
	}
}

//Nhap du lieu tu file
void InputFile(cGoods* hh, int& n, Queue<cOrder>& dh, cLogin* dn, int& z) {
	ifstream is;
	is.open("HangHoa.txt");
	if (!is) {
		Write_Console(25, 5, 1, "Khong the mo file HangHoa.txt");
	}
	else {
		while (!is.eof()) {
			is >> hh[n];
			n++;
		}
	}
	is.close();
	ifstream iss;
	iss.open("DonHang.txt");
	if (!iss) {
		Write_Console(25, 5, 1, "Khong the mo file DonHang.txt");
	}
	else {
		cOrder nhap;
		while (!iss.eof()) {
			iss >> nhap;
			if (nhap.GetAmount() == 0) {
				break;
			}
			dh.enQueue(nhap);
		}
	}
	iss.close();
	ifstream isss;
	isss.open("Admin.txt");
	if (!isss) {
		Write_Console(25, 5, 1, "Khong the mo file Admin.txt");
	}
	else {
		while (!isss.eof()) {
			isss >> dn[z];
			z++;
		}
	}

	isss.close();
}

//Hien thi thong tin hang hoa
void Show_Content(int y, string* a, int* vt, cGoods* hh, int& n) {
	SET_COLOR(31);
	Write_Console(43, 3, 1, " THONG TIN HANG HOA ");
	Write_Console(7, 6, 5, " ");
	Write_Console(13, 6, 7, " ");
	Write_Console(21, 6, 17, " ");
	Write_Console(39, 6, 13, " ");
	Write_Console(53, 6, 9, " ");
	Write_Console(63, 6, 9, " ");
	Write_Console(73, 6, 19, " ");
	Write_Console(93, 6, 10, " ");
	vt[1] += 1; vt[2] += 1; vt[3] += 2; vt[4] += 2; vt[5] += 2; vt[6] += 2;
	for (int i = 0; i < 8; i++) {
		Write_Console(vt[i], 6, 1, a[i]);
	}
	SET_COLOR(15);
	for (int i = 5; i <= y + 4; i++) {
		if (i % 2 != 0) {
			Write_Console(6, i, 98, "-");
		}
		else {
			Write_Console(6, i, 1, "|");
			Write_Console(12, i, 1, "|");
			Write_Console(20, i, 1, "|");
			Write_Console(38, i, 1, "|");
			Write_Console(52, i, 1, "|");
			Write_Console(62, i, 1, "|");
			Write_Console(72, i, 1, "|");
			Write_Console(92, i, 1, "|");
			Write_Console(103, i, 1, "|");
		}
	}
	if (y % 2 == 0) {
		Write_Console(6, y + 5, 98, "-");
	}
	//In thong tin hang hoa
	int x = 8;
	int stt = 1;
	for (int i = 0; i < n; i++) {
		gotoXY(9, x);
		cout << stt;
		hh[i].cGoods::Expost(x);
		x += 2;
		stt += 1;
	}
	SET_COLOR(5);
	Write_Console(43, x + 2, 1, "NHAN PHIM \"ESC\" DE THOAT");
	SET_COLOR(15);
}
//Tim kiem thong tin hang hoa
void Search_Goods(cGoods* hh, int& n, int* vt, string* a) {
	string Name_Goods;
	SET_COLOR(31);
	Write_Console(5, 1, 30, " ");
	Write_Console(5, 3, 30, " ");
	Write_Console(5, 2, 2, " ");
	Write_Console(33, 2, 2, " ");
	Write_Console(5, 1, 1, "  NHAP TEN SAN PHAM BAN CAN TIM:  ");
	SET_COLOR(63);
	Write_Console(7, 2, 26, " ");
	gotoXY(7, 2);
	conSole::ShowCur(true);
	Name_Goods =Charlimit();
	conSole::ShowCur(false);
	SET_COLOR(15);
	cGoods chh[100];
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (Name_Goods == hh[i].GetName()) {
			chh[m++] = hh[i];
		}
	}
	if (m != 0) {
		Show_Content(m * 2 + 2, a, vt, chh, m);
	}
	else {
		SET_COLOR(4);
		Write_Console(39, 12, 1, "KHONG TIM THAY TEN SAN PHAM");
		SET_COLOR(5);
		Write_Console(40, 14, 1, "NHAN PHIM \"ESC\" DE THOAT");
	}
}
//Dat Hang
void Order_Goods(cGoods* hh, int& n, Queue<cOrder>& dh) {
	cOrder dhm;
	bool Try = false;
	while (true) {
		dhm.Input_Order();
		SET_COLOR(15);
		string option[] = { "XAC NHAN DAT HANG","NHAP LAI DON HANG","QUAY LAI" };
		int vt = Option(option, 3, 2, 7, false);
		if (vt == 0) {
			for (int i = 0; i < n; i++) {
				if (hh[i].GetCode() == dhm.GetCode() && hh[i].GetAmount() >= dhm.GetAmount()&&dhm.GetAmount()>0) {
					Try = true;
				}
			}
			system("cls");
			SET_COLOR(15);
			if (Try) {
				Write_Console(38, 10, 1, "Don hang dang cho xu li...");
				Sleep(1000);
				break;
			}
			else {
				Write_Console(42, 10, 1, "Dat hang khong thanh cong");
				SET_COLOR(4);
				Write_Console(42, 16, 1, "NHAN \"ENTER\" DE TIEP TUC");
				Write_Console(42, 18, 1, "NHAN PHIM \"ESC\" DE THOAT");
				SET_COLOR(3);
				char a = _getch();
				if (a == 27) {
					break;
				}
			}
		}
		else if (vt == 2) {
			break;
		}
		SET_COLOR(15);
		system("cls");
	}
	dhm.SetNumber(dh.GetSize() + 1);
	dhm.SetTotal(hh, n);
	if (Try) {
		dh.enQueue(dhm);
		ofstream os("DonHang.txt");
		dh.display(os);
	}
	SET_COLOR(15);
	ShowCur(false);
}

//Quan li
void Manager_Goods(cGoods* hh, int& n, Queue<cOrder>& dh, cLogin* dn, int& z) {
	int run = 1;
	while (run <= 3) {
		system("cls");
		SET_COLOR(31);
		Write_Console(43, 5, 1, " SYSTEM LOGIN ");
		Write_Console(35, 8, 12, " ");
		Write_Console(35, 10, 12, " ");
		Write_Console(38, 8, 1, " User ");
		Write_Console(37, 10, 1, "Password");
		SET_COLOR(15);
		Write_Console(39, 4, 28, "*");
		Write_Console(39, 6, 28, "*");
		Write_Console(39, 5, 1, "*");
		Write_Console(66, 5, 1, "*");
		for (int i = 7; i <= 11; i++) {
			if (i % 2 != 0) {
				Write_Console(34, i, 38, "-");
			}
			else {
				Write_Console(34, i, 1, "|");
				Write_Console(47, i, 1, "|");
				Write_Console(71, i, 1, "|");
			}
		}
		ShowCur(true);
		cLogin login;
		string tk = "", mk = "";
		char kt;
		gotoXY(49, 8);
		while (kt = _getch()) {
			if (kt == 13 || kt == 27) {
				break;
			}
			if (kt == 8) {
				if (tk != "") {
					cout << "\b \b";
					tk.pop_back();
				}
			}
			else if(tk.size()<20) {
				cout << kt;
				tk += kt;
			}
		}
		gotoXY(49, 10);
		while (kt = _getch()) {
			if (kt == 13 || kt == 27) {
				break;
			}
			if (kt == 8) {
				if (mk != "") {
					cout << "\b \b";
					mk.pop_back();
				}
			}
			else if(mk.size()<20) {
				cout << "*";
				mk += kt;
			}
		}
		ShowCur(false);
		login.SetUser(tk);
		login.SetPassword(mk);
		for (int i = 0; i < z; i++) {
			if (dn[i] == login) {
				run = 10;
			}
		}
		SET_COLOR(3);
		if (run == 10) {
			Write_Console(43, 13, 1, "LOGIN SUCCESSFULLY");
			Sleep(800);
		}
		else if (run == 3) {
			Write_Console(35, 13, 1, "DANG NHAP SAI 3 LAN VUI LONG QUAY LAI SAU");
			Sleep(800);

		}
		else {
			Write_Console(35, 13, 1, "LOGIN FAILED, PLEASE TRY AGAIN");
			SET_COLOR(4);
			Write_Console(42, 16, 1, "NHAN \"ENTER\" DE TIEP TUC");
			Write_Console(42, 18, 1, "NHAN PHIM \"ESC\" DE THOAT");
			SET_COLOR(3);
			char a = _getch();
			if (a == 27) {
				break;
			}
		}
		run++;
	}

	//Cac Chuc Nang Quan Li
	if (run == 11) {
		string option[] = { "XU LI DON HANG","QUAN LI HANG HOA","QUAY LAI" };
		while (true) {
			int vt = Option(option, 3, 2, 0, true);
			if (vt == 0) {
				system("cls");
				if (dh.GetSize() != 0) {
					dh.peek().Expost();
					string optionss[] = { "XAC NHAN DON HANG","HUY DON HANG","QUAY LAI" };
					while (true) {
						int vtss = Option(optionss, 3, 2, 9, false);
						if (vtss == 0) {
							for (int i = 0; i < n; i++) {
								if (dh.peek().GetCode() == hh[i].GetCode()) {
									hh[i].SetAmout(hh[i].GetAmount() - dh.peek().GetAmount());
								}
							}
							dh.deQueue();
							ofstream os("DonHang.txt");
							if (dh.GetSize() != 0) {
								dh.display(os);
							}
							else {
								os << "";
							}
							system("cls");
							SET_COLOR(3);
							Write_Console(42, 13, 1, " XAC NHAN DON HANG THANH CONG ");
							SET_COLOR(15);
							char breaks=_getch();
							break;
						}
						else if (vtss == 1) {
							dh.deQueue();
							ofstream os("DonHang.txt");
							if (dh.GetSize() != 0) {
								dh.display(os);
							}
							else {
								os << "";
							}
							system("cls");
							SET_COLOR(3);
							Write_Console(42, 13, 1, " HUY DON HANG THANH CONG ");
							SET_COLOR(15);
							char breaks=_getch();
							break;
						}
						else if (vtss == 2) {
							break;
						}
						else {
							;
						}
					}
					ofstream os("HangHoa.txt");
					for (int i = 0; i < n; i++) {
						os << hh[i];
						if (i != n - 1) {
							os << "\n";
						}
					}
				}
				else {
					system("cls");
					SET_COLOR(3);
					Write_Console(42, 13, 1, " HIEN TAI CHUA CO DON HANG ");
					SET_COLOR(15);
					_getch();
				}

			}
			else if (vt == 1) {
				string options[] = { "THEM HANG HOA","XOA HANG HOA","CAP NHAT LAI SO LUONG","QUAY LAI" };
				while (true) {
					int vts = Option(options, 4, 2, 0, true);
					if (vts == 0) {
						cGoods hhm;
						system("cls");
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

						ShowCur(true);
						Write_Console(45, 2, 1, " THEM HANG HOA MOI ");
						Write_Console(25, 5, 1, "Nhap ma san pham");
						Write_Console(25, 7, 1, "Nhap ten san pham");
						Write_Console(25, 9, 1, "Nhap noi san xuat");
						Write_Console(25, 11, 1, "Nhap mau san pham");
						Write_Console(25, 13, 1, "Nhap gia ban");
						Write_Console(25, 15, 1, "Ngay nhap kho");
						Write_Console(25, 17, 1, "Nhap so luong");
						SET_COLOR(15);
						hhm.Input();
						ShowCur(false);
						bool kt = true;
						for (int i = 0; i < n; i++) {
							if (hh[i].GetCode() == hhm.GetCode() || hhm.GetCode().length() != 4) {
								kt = false;
								break;
							}
						}
						system("cls");
						SET_COLOR(4);
						if (kt) {
							Write_Console(45, 8, 1, "THEM HANG HOA THANH CONG");
							hh[n] = hhm;
							n++;
						}
						else {
							Write_Console(45, 8, 1, "THEM HANG HOA KHONG THANH CONG");
							Write_Console(40, 10, 1, "Ma hang hoa khong duoc trung va co 4 ki tu");
						}
					}
					else if (vts == 1) {
						system("cls");
						string Code_Goods;
						SET_COLOR(31);
						Write_Console(5, 1, 30, " ");
						Write_Console(5, 3, 30, " ");
						Write_Console(5, 2, 2, " ");
						Write_Console(33, 2, 2, " ");
						Write_Console(5, 1, 1, "  NHAP MA HANG BAN CAN XOA:  ");
						SET_COLOR(63);
						Write_Console(7, 2, 26, " ");
						gotoXY(7, 2);
						conSole::ShowCur(true);
						getline(cin, Code_Goods);
						conSole::ShowCur(false);
						SET_COLOR(15);
						bool kt = true;
						for (int i = 0; i < n; i++) {
							if (Code_Goods == hh[i].GetCode()) {
								kt = false;
								for (int j = i; j < n - 1; j++) {
									hh[j] = hh[j + 1];
								}
								n--;
							}
						}
						if (!kt) {
							SET_COLOR(4);
							Write_Console(42, 12, 1, "XOA HANG HOA THANH CONG");
							SET_COLOR(5);
							Write_Console(40, 14, 1, "NHAN PHIM \"ESC\" DE THOAT");
						}
						else {
							SET_COLOR(4);
							Write_Console(42, 12, 1, "KHONG TIM THAY HANG HOA");
							SET_COLOR(5);
							Write_Console(40, 14, 1, "NHAN PHIM \"ESC\" DE THOAT");
						}
					}
					else if (vts == 2) {
						system("cls");
						string Code_Goods;
						SET_COLOR(31);
						Write_Console(5, 1, 30, " ");
						Write_Console(5, 3, 30, " ");
						Write_Console(5, 2, 2, " ");
						Write_Console(33, 2, 2, " ");
						Write_Console(5, 1, 1, "  NHAP MA HANG HANG HOA:  ");
						SET_COLOR(63);
						Write_Console(7, 2, 26, " ");
						gotoXY(7, 2);
						conSole::ShowCur(true);
						getline(cin, Code_Goods);
						SET_COLOR(15);
						bool kt = true;
						for (int i = 0; i < n; i++) {
							if (Code_Goods == hh[i].GetCode()) {
								kt = false;
								int x;
								Write_Console(5, 4, 1, "  CAP NHAT SO LUONG:  ");
								gotoXY(26, 4);
								cin >> x;
								hh[i].SetAmout(x);
							}
						}
						conSole::ShowCur(false);
						if (!kt) {
							SET_COLOR(4);
							Write_Console(40, 12, 1, "CAP NHAT SO LUONG THANH CONG");
							SET_COLOR(5);
							Write_Console(40, 14, 1, "NHAN PHIM \"ESC\" DE THOAT");
						}
						else {
							SET_COLOR(4);
							Write_Console(42, 12, 1, "KHONG TIM THAY MA HANG");
							SET_COLOR(5);
							Write_Console(40, 14, 1, "NHAN PHIM \"ESC\" DE THOAT");
						}
					}
					else if (vts == 3) {
						break;
					}
					else {

					}
					ofstream os("HangHoa.txt");
					for (int i = 0; i < n; i++) {
						os << hh[i];
						if (i != n - 1) {
							os << "\n";
						}
					}
					char breaks=_getch();
				}
			}
			else if (vt == 2) {
				break;
			}
			else {

			}
		}
	}
}

//Ham lua chon
int Option(string* option, int n, int x, int y, bool clear) {
	int vt = 0;
	if (clear) {
		system("cls");
	}
	if (option[0] == "XU LI DON HANG") {
		SET_COLOR(31);
		Write_Console(30, 3, 47, " ");
		Write_Console(30, 7, 47, " ");
		Write_Console(30, 19, 47, " ");
		for (int i = 4; i < 19; i++) {
			Write_Console(30, i, 1, " ");
			Write_Console(76, i, 1, " ");
		}
		SET_COLOR(78);
		Write_Console(42, 5, 1, " CAC CHUC NANG QUAN LI ");
		SET_COLOR(3);
	}
	if (option[0] == "THEM HANG HOA") {
		SET_COLOR(31);
		Write_Console(30, 3, 47, " ");
		Write_Console(30, 7, 47, " ");
		Write_Console(30, 21, 47, " ");
		for (int i = 4; i < 21; i++) {
			Write_Console(30, i, 1, " ");
			Write_Console(76, i, 1, " ");
		}
		SET_COLOR(78);
		Write_Console(44, 5, 1, " QUAN LI HANG HOA ");
		SET_COLOR(3);
	}
	while (true) {
		for (int i = 0; i < n; i++) {
			if (vt != i) {
				SET_COLOR(3);
				Write_Console(45, x * i + 11 + y, 1, option[i]);
			}
			else {
				SET_COLOR(15);
				Write_Console(45, x * i + 11 + y, 1, option[i]);
			}
		}
		int check = inputKey();
		if (check == 1072) {
			vt--;
			if (vt < 0) {
				vt = n - 1;
			}
		}
		else if (check == 1080) {
			vt++;
			if (vt > n - 1) {
				vt = 0;
			}
		}
		else if (check == 13) {
			SET_COLOR(15);
			return vt;
		}
	}
}