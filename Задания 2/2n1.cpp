#include <stdio.h>
#include <iostream>
#include "math.h"

#include "CVector.h"

int main(int argc, char const *argv[])
{
	double b[3] = {1, 2, 3};
	CVector a = CVector(3, b);
	a.print();
	double d[3] = {1, 0, 0};
	CVector c = CVector(3, d);
	a = c;
	a.print();
	getchar();
	return 0;
}