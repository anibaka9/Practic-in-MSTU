// 1n4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "math.h"
#include <cmath>

using namespace std;

void scal(double *a, double *b, double *c)
{
    for (int i = 0; i < sizeof(a); i++) c[i] = a[i] * b[i];
}

void vsum(double *a, double *b, double *c)
{
    for (int i = 0; i < sizeof(a); i++) c[i] = a[i] + b[i];
}

void vras(double *a, double *b, double *c)
{
    for (int i = 0; i < sizeof(a); i++) c[i] = a[i] - b[i];
}

void vras(double *a)
{
    for (int i = 0; i < sizeof(a); i++) cout << a[i] << " ";
    cout << "\n";
}

int _tmain(int argc, _TCHAR* argv[])
{
    int ras;
    cin >> ras;
    double *a = new double[ras], *b = new double[ras];
    for (int i = 0; i < ras; i++) cin >> a[i];
    for (int i = 0; i < ras; i++) cin >> b[i];
	return 0;
}

