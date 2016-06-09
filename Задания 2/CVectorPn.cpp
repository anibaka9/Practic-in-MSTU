#include <stdio.h>
#include <iostream>
#include "math.h"
#include "CVector.h"
#include "CVectorPn.h"


using namespace std;

double CVectorPn::scal(CVector &a)
{
	double res = 0;
	if(CVector::getsize() == a.getsize()) res = CVector::scal(a);
	else cout << "Error: different dimension vectors" << endl;
	return res;
}

double CVectorPn::operator * (CVector &a)
{
	return scal(a);
}