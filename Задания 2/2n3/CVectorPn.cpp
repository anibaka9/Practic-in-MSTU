#include <stdio.h>
#include <iostream>
#include "math.h"
#include "CVectorvir.h"
#include "CVectorPn.h"

 
using namespace std;

double CVectorPn::scal(CVector &a)
{
	if(getsize() == a.getsize())
	{
		int n = getsize();

		double *x = new double[n];
		double *y = new double[n];
		double res = 0;
		getdata(x);
		a.getdata(y);
		if(getsize() == a.getsize()) 
		{
			for (int i = 0; i < getsize(); ++i)
				res -= x[i] * y[i];
			return res;
		}	
	}
	
	else cout << "Error: different dimension vectors" << endl;
}
