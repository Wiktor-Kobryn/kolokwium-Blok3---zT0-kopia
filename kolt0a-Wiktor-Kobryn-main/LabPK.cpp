#include <iostream>
#include "zbior.h"

#define Blok3

#ifdef Blok3

void main(void)
{
	Zbior z1(10, 4, 8), z2(3, 5, 10);
	Zbior z3(z1);
	cout << "z1:\n" << z1 << "\nz2:\n" << z2 << "\nz3:\n" << z3 << "\n\nsrednia z1: "
		<< z1.obliczSredniaElem() << "\nsrednia z2: " << z2.obliczSredniaElem()
		<< "\n\nz1 == z2:\t" << (z1 == z2) << "\nz1 == z1:\t" << (z1 == z1) << "\nz1 != z1:\t" << (z1 != z1)
		<< "\nz2 != z1:\t" << (z2 != z1)
		<< "\n\nzbior from double:\n" << double2zbior(2.5) << "\n\nint from Zbior z2:\t" << static_cast<int>(z2)
		<< endl;
}

#endif

#ifdef Blok4

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA Z BLOKU 4

#endif


