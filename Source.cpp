#include "stdafx.h"
#include "Header.h"
#include "iostream"
#include "string"
using namespace std;
void Pracownik::dodaj(int &a, string b) {
	bool c, d;
	int e=0, f=0;
	if (b != "") {
		nazwisko = b;
		do {
			c = true;
			string g = "podaj pensje: ";
			walidacja(e,g);
			if (e <= 0) {
				cout << "Wartosc musi byc wieksza od 0\n";
				c = false;
			}
		} while (c == false);
		pensja = e;
		do {
			d = true;
			string g = "podaj premie: ";
			walidacja(f,g);
			if (f <= 0 || f >= 100) {
				cout << "Wartosc musi byc wieksza od 0 i mniejsza od 100\n";
				d = false;
			}
		} while (d == false);
		premia = f;
		a++;
		cout << "DODAJ PRACOWNIKA: wykonano\n";
	}
}
void Pracownik::nowapensja() {
	int a=0;
	bool b;
	do {
		b = true;
		string g = "podaj nowa pensje: ";
		walidacja(a, g);
		if (a <= 0) {
			cout << "Wartosc musi byc wieksza od 0\n";
			b = false;
		}
	} while (b == false);
	pensja = a;
	cout << "NOWA PENSJA: wykonano\n";
}
void Pracownik::nowapremia() {
	int a=0;
	bool b;
	do {
		b = true;
		string g = "podaj premie: ";
		walidacja(a, g);
		if (a <= 0 || a >= 100) {
			cout << "Wartosc musi byc wieksza od 0 i mniejsza od 100\n";
			b = false;
		}
	} while (b == false);
	premia = a;
	cout << "NOWA PREMIA: wykonano\n";
}
float Pracownik::wyplata_pracownika() {
	return pensja + pensja*(premia*0.01);
}
void Pracownik::pokaz() {
	cout << nazwisko << endl;
	cout << pensja << " zl" << endl;
	cout << premia << " %" << endl;
}
void Pracownik::walidacja(int &a, string b) {
	do {
		cout << b;
		if (cin >> a) {
			break;
		}
		else {
			cout << "Podaj liczbe!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (1);
}
