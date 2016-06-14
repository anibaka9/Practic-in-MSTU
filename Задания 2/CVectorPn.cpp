#include <stdio.h>
#include <iostream>
#include "math.h"
#include "CVectorvir.h"
#include "CVectorPn.h"


using namespace std;

double CVectorPn::scal(CVector &a)
{
	if(CVector::getsize() == a.getsize())
	{
		int n = CVector::getsize();

		double *x = new double[n];
		double *y = new double[n];
		double res = 0;
		CVector::getdata(x);
		a.getdata(y);
		if(CVector::getsize() == a.getsize()) 
		{
			for (int i = 0; i < CVector::getsize(); ++i)
				res -= x[i] * y[i];
			return res;
		}	
	}
	
	else cout << "Error: different dimension vectors" << endl;
}

double CVectorPn::operator * (CVector &a)
{
	return scal(a);
}