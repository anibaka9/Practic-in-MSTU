#include <stdio.h>
#include <iostream>
#include "math.h"

#include "CVector.h"

int main(int argc, char const *argv[])
{
	CVector a;
	double b[3] = {1, 2, 3};
	a.setsize(3);
	a.setdata(b);
	CVector::print(a);
	getchar();
	return 0;
}