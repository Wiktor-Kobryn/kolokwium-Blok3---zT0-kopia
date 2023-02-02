#include "zbior.h"
#include <new>
#include <random>

void Zbior::alokuj(int n)
{
	if (n > 0)
	{
		m_elementy = new(std::nothrow) double[n];
		m_liczbaElementow = n;
	}
}

void Zbior::zwolnij()
{
	if (m_elementy != nullptr)
	{
		delete[] m_elementy;
		m_elementy = nullptr;
	}
}

Zbior::Zbior(size_t liczElem, double dGran, double gGran)
	:m_dolnaGranica(dGran), m_gornaGranica(gGran)
{
	alokuj(liczElem);
	std::uniform_real_distribution<double> zakres(m_dolnaGranica, m_gornaGranica);
	std::random_device generator;
	for (int elem = 0; elem < liczElem; elem++)
		m_elementy[elem] = zakres(generator);
}

Zbior::Zbior(const Zbior& org)
	:m_dolnaGranica(org.m_dolnaGranica), m_gornaGranica(org.m_gornaGranica),
	m_liczbaElementow(org.m_liczbaElementow)
{
	if (org.m_elementy != nullptr)
	{
		alokuj(m_liczbaElementow);
		for (int i = 0; i < m_liczbaElementow; i++)
		{
			this->m_elementy[i] = org.m_elementy[i];
		}
	}
}

Zbior& Zbior::operator=(Zbior&& org)
{
	if (this != &org)
	{
		if (this->m_elementy != nullptr)
			zwolnij();
		this->m_elementy = org.m_elementy;
		this->m_dolnaGranica = org.m_dolnaGranica;
		this->m_gornaGranica = org.m_gornaGranica;
		this->m_liczbaElementow = org.m_liczbaElementow;

		org.m_elementy = nullptr;
	}
	return *this;
}

ostream& operator<<(ostream& str, Zbior const& zb)
{
	for (int i = 0; i < zb.m_liczbaElementow - 1; i++)
		str << zb.m_elementy[i] << ", ";
	str << zb.m_elementy[zb.m_liczbaElementow - 1];
	return str;
}

double Zbior::obliczSredniaElem()
{
	double sumaElem = 0;
	for (int i = 0; i < m_liczbaElementow; i++)
		sumaElem += m_elementy[i];
	return sumaElem / m_liczbaElementow;
}

bool Zbior::operator==(Zbior& zb)
{
	double tolerancja = 0.000001;
	if (this != &zb)
	{
		if ((obliczSredniaElem() < (zb.obliczSredniaElem() - tolerancja)) || (obliczSredniaElem() > (zb.obliczSredniaElem() + tolerancja)))
			return false;
	}
	return true;
}

bool Zbior::operator!=(Zbior& zb)
{
	return !(*this == zb);
}

Zbior::operator int()
{
	return m_liczbaElementow;
}

Zbior double2zbior(double gGranica)
{
	return { 10, 0.0, gGranica };
}