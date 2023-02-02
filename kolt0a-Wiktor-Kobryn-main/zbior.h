#pragma once
#include <iostream>
using namespace std;

class Zbior
{
	size_t m_liczbaElementow = 0;
	double* m_elementy = nullptr;
	double m_dolnaGranica = 0;
	double m_gornaGranica = 0;
	void alokuj(int);
	void zwolnij();
public:
	Zbior(size_t liczElem, double dGran, double gGran);
	~Zbior() { 	zwolnij(); }
	double obliczSredniaElem();

	//konstruktor kopiujacy
	Zbior(const Zbior& org);
	//przenoszacy operator
	Zbior& operator=(Zbior&& org);
	//operator==
	bool operator==(Zbior& zb);
	//operator!=
	bool operator!=(Zbior& zb);
	//konwersja formalna do int
	operator int();

	friend ostream& operator<<(ostream& str, Zbior const& zb);
};

//konwersja nieformalna z double
Zbior double2zbior(double gGranica);
