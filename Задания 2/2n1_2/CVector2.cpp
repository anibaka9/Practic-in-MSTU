#include <stdio.h>
#include <iostream>
#include "math.h"
#include "CVector.h"
#include "CVector2.h"


using namespace std;

double CVector2::scal(CVector &a)
{
	double res = 0;
	if((getsize() == 2) && (a.getsize() == 2))
	{
		double *x = new double[getsize()];
		double *y = new double[a.getsize()];
		getdata(x);
		a.getdata(y);
		res = res + 2*x[0]*y[1] + 5*x[1]*y[0];
		delete[]x;
		delete[]y;
	}
	else if(getsize() == a.getsize()) res = scal(a);
	else cout << "Error: different dimension vectors" << endl;
	return res;
}

double CVector2::operator * (CVector &a)
{
	return scal(a);
}

CVector2 CVector2::operator*(double a)
{
	CVector2 res = *this;
	res.umncoef(a);
	return res;
}