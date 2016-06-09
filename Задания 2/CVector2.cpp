#include <stdio.h>
#include <iostream>
#include "math.h"
#include "CVector.h"
#include "CVector2.h"


using namespace std;

double CVector2::scal(CVector &a)
{
	double res = 0;
	if((CVector::getsize() == 2) && (a.getsize() == 2))
	{
		double *x = new double[CVector::getsize()];
		double *y = new double[a.getsize()];
		CVector::getdata(x);
		a.getdata(y);
		res = res + 2*x[0]*y[1] + 5*x[1]*y[0];
		delete[]x;
		delete[]y;
	}
	else if(CVector::getsize() == a.getsize()) res = CVector::scal(a);
	else cout << "Error: different dimension vectors" << endl;
	return res;
}

double CVector2::operator * (CVector &a)
{
	return scal(a);
}