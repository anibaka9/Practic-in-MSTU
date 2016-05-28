#include <stdio.h>
#include <iostream>
#include "math.h"

using namespace std;

#include "CVector.h"

void CVector::setsize(int n)
{
	CVector::size = new double[n];
}

void CVector::setdata(double *a)
{
	for (int i = 0; i < CVector::size; ++i)
		CVector::data[i] = a[i];
}

void CVector::print(CVector &a)

void CVector::copy(CVector &a)
{
	*this.setsize(a.size);
	*this.setdata(a.data);
}

void CVector::prib(CVector &a)
{
	if (CVector::size == a.size)
	{
		for (int i = 0; i < a.size; ++i)
			CVector::data[i] += a.data[i];
	}
}

void CVector::umncoef(double a)
{
	for (int i = 0; i < *CVector::size; ++i)
		CVector::data[i] * a;
}

void CVector::vich(CVector &a) {return CVector.umncoef(-1); }

CVector CVector::sum(CVector &a, CVector &b)
{
	CVector c;
	c.copy(a);
	return c.prib(b);
}

CVector CVector::raz(CVector &a, CVector &b) return sum(a, b.umncoef(-1));

double CVector::scal(CVector &a, CVector &b)
{
	double res = 0;
	if(a.size == b.size) 
	for (int i = 0; i < count; ++i)
		res += a.data[i] * b.data[i];
	return res;
}

CVector CVector::vecumn(CVector &a, CVector &b)
{
	if (a.size == b.size == 3)
	{
		CVector res;
		res.data[0] = a.data[1] * b.data[2] - a.data[2] * b.data[1];
		res.data[1] = a.data[2] * b.data[0] - a.data[0] * b.data[2];
		res.data[2] = a.data[0] * b.data[1] - a.data[1] * b.data[0];
		return res;
	}
}

bool CVector::raven(CVector &a, CVector &b)
{
	bool res = 1;
	if(a.size == b.size)
	{
		for (int i = 0; i < a.size; ++i)
		{
			if (res == 1 && a.data[i] != b.data[i]) res = 0;
		}
		return res;
	}
	else return 0;
}

bool CVector::neraven(CVector &a, CVector &b) return !(raven(a, b));


void operator+=(CVector &a) *this.prib(a);
void operator-=(CVector &a) *this.vich(a);
void operator*=(double a) *this.umncoef(a);
CVector operator+(CVector &a) return sum(*this, a);
CVector operator-(CVector &a) return raz(*this, b);
CVector operator*(double a)
{
	CVector res;
	res.copy(*this);
	return res.umncoef(a);
}
CVector operator*(CVector &a) return vecumn(*this, a);
double operator&(CVector &a) return scal(*this, a);
bool operator==(CVector &a) return raven(*this, a);
bool operator!=(CVector &a) return neraven(*this, a);
void operator=(CVector &a) this.copy(a);