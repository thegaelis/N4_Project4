#pragma once
#include "Functions.h"

//Menu
string arr[] = { "HIEN THI THONG TIN HANG HOA","TIM KIEM THONG TIN HANG HOA" ,"DAT HANG","QUAN LY","THOAT" };
//Hien thi Hang hoa
string a[] = { "STT","MA","TEN SAN PHAM","XUAT XU","MAU","GIA","NGAY NHAP KHO","SO LUONG" };
//Hang hoa
cGoods hh[100];
//So luong hang hoa
int n = 0;
//Don hang
Queue<cOrder> dh;
//Dang nhap
cLogin dn[100];
//so luong tai khoan dang nhap
int z = 0;

//HAM CHAY CHUONG TRINH
void RUN() {
	conSole::SetWindowSize(1000, 600);
	conSole::ShowCur(false);
	conSole::Font(24);
	InputFile(hh, n, dh, dn, z);
	while (true) {
		int vt[] = { 8,14,22,40,54,64,74,94 };
		system("cls");
		int tt = Menu(arr);
		if (tt == 9) {
			system("cls");
			Show_Content(n * 2 + 2, a, vt, hh, n);
			OutESC();
		}
		else if (tt == 11) {
			system("cls");
			Search_Goods(hh, n, vt, a);
			OutESC();
		}
		else if (tt == 13) {
			system("cls");
			Order_Goods(hh, n, dh);
		}
		else if (tt == 15) {
			system("cls");
			Manager_Goods(hh, n, dh, dn, z);
		}
		else {
			system("cls");
			break;
		}
		system("cls");
	}
}