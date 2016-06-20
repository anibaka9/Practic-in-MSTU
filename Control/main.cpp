#include <iostream>
#include "CArrayOut.h"
#include "COddOut.h"

using namespace std;

int main(int argc, char const *argv[])
{
	double a[3];
	a[0] = 1; a[1] = 2; a[3] = 3.5;
	CArrayOut Ca(3, a);
	return 0;
} 