#include <iostream>
#include "CArrayOut.h"
#include "COddOut.h"

using namespace std;

int main(int argc, char const *argv[])
{
	double a[3] = {1.0, 2.3, 3.23};
	double b[3] = {5, 1, 3.23};
	CArrayOut Ca(3, a);
	Ca.out();
	COddOut Cb(3, b);
	Cb.out();
	CArrayOut *x = &Cb;
	(*x).out();
	getchar();
	return 0;
} 