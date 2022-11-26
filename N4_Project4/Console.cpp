
#include "Console.h"
using namespace std;
//Lay toa do X
int conSole::whereX() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		return csbi.dwCursorPosition.X;
	}
	return -1;
}
//Lay toa do Y
int conSole::whereY() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		return csbi.dwCursorPosition.Y;
	}
	return -1;
}
//Di chuyen den toa do x,y
void conSole::gotoXY(int x, int y) {
	HANDLE hCONsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hCONsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCONsoleOutput, Cursor_an_Pos);
}
//color font
void conSole::SET_COLOR(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}
//Tat hien thi nhay chuot
void conSole::ShowCur(bool Cur) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1,Cur };
	SetConsoleCursorInfo(handle, &cursor);
}
//Ham tra ve phim
int conSole::inputKey() {
	if (_kbhit()) {
		int key = _getch();
		if (key == 224) {
			key = _getch();
			return key + 1000;
		}
		return key;
	}
}
//kich thuoc cua chu
void conSole::Font(int size) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = size;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

//kich thuoc cua man hinh console
void conSole::SetWindowSize(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

//Viet ra man hinh Console
void conSole::Write_Console(int x, int y, int n, string kitu) {
	conSole::gotoXY(x, y);
	for (int i = 0; i < n; i++) {
		cout << kitu;
	}
}
//Nhap gioi han
string conSole::Charlimit() {
	string s = "";
	char kt;
	while (true) {
		while (kt = _getch()) {
			if (kt == 13 || kt == 27) {
				break;
			}
			if (kt == 8) {
				if (s != "") {
					cout << "\b \b";
					s.pop_back();
				}
			}
			else if (s.size() < 25) {
				cout << kt;
				s += kt;
			}
		}
		bool flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ') {
				flag = false;
			}
		}
		if (s != "" && !flag) {
			return s;
		}
	}
}

//Doi chuoi thanh so
long long conSole::ChangeString(string chuoi) {
	long long s = 0;
	for (int i = 0; i < chuoi.size(); i++) {
		if (chuoi[i] >= 48 && chuoi[i] <= 58) {
			s = s * 10 + int(chuoi[i] - '0');
		}
	}
	return s;
}