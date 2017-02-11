#pragma once
#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;
class Pracownik {
	int pensja;
	int premia;
public:
	string nazwisko;
	void pokaz();
	void dodaj(int &a, string);
	void nowapensja();
	void nowapremia();
	float wyplata_pracownika();
private:
	void walidacja(int &a, string);
	friend void zapisz();
	friend void wczytaj();
};