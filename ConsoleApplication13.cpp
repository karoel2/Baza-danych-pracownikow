#include "stdafx.h"
#include "iostream"
#include "Header.h"
#include "fstream"
#include "string"
#include "cstdlib"
#include "algorithm"
using namespace std;
int liczba_pracownikow, nr_pracownika = 0;
Pracownik tab[49];
float suma;
char wybor;
fstream plik;
int znajdz() {
	int i;
	string a;
	cout << "podaj nazwisko: ";
	cin >> a;
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	for (i = 0; i < liczba_pracownikow; i++) {
		if (a == tab[i].nazwisko) {
			return i;
		}
	}
}
string sprawdz() {
	int i;
	string a, b;
	bool c=true;
	cout << "podaj nazwisko: ";
	cin >> a;
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	for (i = 0; i < liczba_pracownikow; i++) {
		if (a == tab[i].nazwisko) {
			cout << "Pracownik juz jest w bazie danych!\n";
				c = false;
		}
	}
	if (c == true) {
		return a;
	}
	else {
		return b;
	}
}
void nowa_pensja()
{
	cout << "NOWA PENSJA\n";
	tab[znajdz()].nowapensja();
}
void nowa_premia() {
	cout << "NOWA PREMIA\n";
	tab[znajdz()].nowapremia();
}
void dodaj_pracownika() {
	cout << "DODAJ PRACOWNIKA\n";
	tab[liczba_pracownikow].dodaj(liczba_pracownikow, sprawdz());
}
void wypisz() {
	int i;
	for (i = 0; i < liczba_pracownikow; i++) {
		tab[i].pokaz();
	}
}
void wyplata() {
	int i;
	suma = 0.0;
	cout << "WYPLATA DLA WSZYSTKICH PRACOWNIKOW\n";
	for (i = 0; i < liczba_pracownikow; i++) {
		suma += tab[i].wyplata_pracownika();
	}
	cout << "Wyplata dla wszystkich pracownikow wynosi: " << suma << " zl" << endl;
}
void wczytaj() {
	string linia;
	int nr_linii = 1;
	plik.open("baza_danych.txt", ios::in);
	if (plik.good() == false) {
		cout << "Nie udalo sie wczytac pliku: baza_danych.txt!\n";
	}
	while (getline(plik, linia)) {
		if (nr_linii == 1) {
			tab[nr_pracownika].nazwisko = linia;
		}
		else if (nr_linii == 2) {
			tab[nr_pracownika].pensja = atoi(linia.c_str());
		}
		else if (nr_linii == 3) {
			tab[nr_pracownika].premia = atoi(linia.c_str());
			liczba_pracownikow++;
		}
		nr_linii++;
		if (nr_linii == 4) {
			nr_pracownika++;
			nr_linii = 1;
		}
	}
	plik.close();
}
void zapisz() {
	int i;
	plik.open("baza_danych.txt", ios::out);
	for (i = 0; i < liczba_pracownikow; i++) {
		plik << tab[i].nazwisko << endl;
		plik << tab[i].pensja << endl;
		plik << tab[i].premia << endl;
	}
	plik.close();
	cout << "ZAPISANO!\n";
}
void kasuj() {
	ofstream ofs("baza_danych.txt", ios::out | ios::trunc);
	ofs.close();
	cout << "Baza danych zostala pomyslnie usunieta!\n";
	exit(0);
}
int main()
{
	wczytaj();
	do {
		cout << "Wybierz: \n";
		cout << "1. Nowy pracownik\n";
		cout << "2. Nowa pensja\n";
		cout << "3. Nowa premia\n";
		cout << "4. Wyplata dla wszystkich pracownikow\n";
		cout << "5. Wypisz wszystkich pracownikow\n";
		cout << "6. Usun baze danychi zakoncz\n";
		cout << "7. Zapisz i zakoncz\n";
		cin >> wybor;
		system("cls");
		switch (wybor) {
		case '1':
			dodaj_pracownika();
			break;
		case '2':
			nowa_pensja();
			break;
		case '3':
			nowa_premia();
			break;
		case '4':
			wyplata();
			break;
		case '5':
			wypisz();
			break;
		case '6':
			kasuj();
		}
	} while (wybor != '7');
	zapisz();
	return 0;
}

