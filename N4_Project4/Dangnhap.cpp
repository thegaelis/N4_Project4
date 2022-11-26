#include "Dangnhap.h"

cLogin::cLogin() {
	User = "";
	Password = "";
}
cLogin::cLogin(const cLogin& copy) {
	User = copy.User;
	Password = copy.Password;
}
cLogin::~cLogin() {}
void cLogin::SetUser(string user) {
	User = user;
}
void cLogin::SetPassword(string password) {
	Password = password;
}
string cLogin::GetUser() {
	return User;
}
string cLogin::GetPassword() {
	return Password;
}
istream& operator >> (istream& is, cLogin& login) {
	getline(is, login.User);
	getline(is, login.Password);
	return is;
}
bool cLogin::operator == (cLogin p) {
	if (User == p.User && Password == p.Password) {
		return true;
	}
	return false;
}