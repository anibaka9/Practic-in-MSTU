#include <stdio.h>
#include <iostream>
#include "math.h"
#include "CVector.h"

using namespace std;
 

void CVector::setdata(int n, double *a)
{
	size = n;
	delete[]data;
	data = new double[n];
	for (int i = 0; i < n; ++i)
		data[i] = a[i];
}

void CVector::getdata(double *a)
{
	for (int i = 0; i < size; ++i)
		a[i] = data[i];
}

unsigned int CVector::getsize() { return CVector::size; }

void CVector::print()
{
	for (int i = 0; i < size; ++i)
		cout << data[i] << " ";
	cout << "\n";
}

void CVector::copy(CVector &a)
{
	setdata(a.size, a.data);
}

void CVector::prib(CVector &a)
{
	if (size == a.size)
	{
		for (int i = 0; i < a.size; ++i)
			data[i] += (a.data)[i];
	}
	else cout << "Error: different dimension vectors" << endl;
}

void CVector::umncoef(double a)
{
	for (int i = 0; i < size; ++i)
		data[i] = data[i] * a;
}

void CVector::vich(CVector &a) 
{
	CVector b(a);
	b.umncoef(-1);
	prib(b);
}

CVector CVector::sum(CVector &a)
{
	CVector c(*this);
	c.prib(a);
	return c;
}

CVector CVector::raz(CVector &a)
{
	CVector c(*this);
	c.vich(a);
	return c;
}
double CVector::scal(CVector &a)
{
	double res = 0;
	if(size == a.size) 
	{
		for (int i = 0; i < size; ++i)
			res += data[i] * a.data[i];
		return res;
	}
	else cout << "Error: different dimension vectors" << endl;
}


bool CVector::raven(CVector &a)
{
	bool res = 1;
	if(size == a.size)
	{
		for (int i = 0; i < size; ++i)
		{
			if (res == 1 && data[i] != a.data[i]) res = 0;
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
	return CVector::sum(a);
}
CVector CVector::operator-(CVector &a) 
{
	return raz(a);
}
CVector CVector::operator*(double a)
{
	CVector res = *this;
	res.umncoef(a);
	return res;
}

double CVector::operator*(CVector &a) { return CVector::scal(a); }

bool CVector::operator==(CVector &a) { return CVector::raven(a); }

bool CVector::operator!=(CVector &a) { return CVector::neraven(a); }
