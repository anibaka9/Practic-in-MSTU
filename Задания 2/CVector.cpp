#include <stdio.h>
#include <iostream>
#include "math.h"
#include "CVector.h"

using namespace std;


void CVector::setdata(int n, double *a)
{
	CVector::size = n;
	delete[]CVector::data;
	CVector::data = new double[n];
	for (int i = 0; i < n; ++i)
		CVector::data[i] = a[i];
}

void CVector::getdata(double *a)
{
	for (int i = 0; i < CVector::size; ++i)
		a[i] = CVector::data[i];
}

unsigned int CVector::getsize() { return CVector::size; }

void CVector::print()
{
	for (int i = 0; i < CVector::size; ++i)
		cout << CVector::data[i] << " ";
	cout << "\n";
}

void CVector::copy(CVector &a)
{
	setdata(a.size, a.data);
}

void CVector::prib(CVector &a)
{
	if (CVector::size == a.size)
	{
		for (int i = 0; i < a.size; ++i)
			CVector::data[i] += (a.data)[i];
	}
	else cout << "Error: different dimension vectors" << endl;
}

void CVector::umncoef(double a)
{
	for (int i = 0; i < CVector::size; ++i)
		CVector::data[i] * a;
}

void CVector::vich(CVector &a) 
{
	CVector b;
	b.copy(a);
	b.umncoef(-1);
	prib(b);
}

CVector CVector::sum(CVector &a)
{
	CVector c;
	c.copy(*this);
	c.prib(a);
	return c;
}

CVector CVector::raz(CVector &a)
{
	CVector c;
	c.copy(*this);
	c.vich(a);
	return c;
}
double CVector::scal(CVector &a)
{
	double res = 0;
	if(CVector::size == a.size) 
	{
		for (int i = 0; i < CVector::size; ++i)
			res += CVector::data[i] * a.data[i];
		return res;
	}
	else cout << "Error: different dimension vectors" << endl;
}

CVector CVector::vecumn(CVector &a)
{
	if (CVector::size == a.size == 3)
	{
		CVector res;
		res.data[0] = CVector::data[1] * a.data[2] - CVector::data[2] * a.data[1];
		res.data[1] = CVector::data[2] * a.data[0] - CVector::data[0] * a.data[2];
		res.data[2] = CVector::data[0] * a.data[1] - CVector::data[1] * a.data[0];
		return res;
	}
}

bool CVector::raven(CVector &a)
{
	bool res = 1;
	if(CVector::size == a.size)
	{
		for (int i = 0; i < CVector::size; ++i)
		{
			if (res == 1 && CVector::data[i] != a.data[i]) res = 0;
		}
		return res;
	}
	else return 0;
}

bool CVector::neraven(CVector &a) { return !(raven(a)); }


//Operators

CVector&CVector::operator = (CVector a) 
{
	copy(a);
	return *this;
}


CVector&CVector::operator+=(CVector &a) 
{
	prib(a);
	return *this;
}
CVector&CVector::operator-=(CVector &a) 
{
	vich(a);
	return *this;
}
CVector&CVector::operator*=(double a) 
{
	umncoef(a);
	return *this;
}
CVector CVector::operator+(CVector &a)
{
	CVector res = CVector::sum(a);
	return res;
}
CVector CVector::operator-(CVector &a) 
{
	CVector res = *this;
	res -= a;
	return res;
}
CVector CVector::operator*(double a)
{
	CVector res = *this;
	res.umncoef(a);
	return res;
}
CVector CVector::operator*(CVector &a) { return CVector::vecumn(a); }

double CVector::operator&(CVector &a) { return CVector::scal(a); }

bool CVector::operator==(CVector &a) { return CVector::raven(a); }

bool CVector::operator!=(CVector &a) { return CVector::neraven(a); }
