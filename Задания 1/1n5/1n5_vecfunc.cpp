#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include "math.h"
//#include <cmath>
#include "1n5_vecfunc.h"

using namespace std;

double scal(int n, double *a, double *b)
{
    double res = 0;
    for (int i = 0; i < n; ++i)
        res += a[i] * b[i];
    return res;
}

double modul(int n, double *a) 
{
    return sqrt(scal(n, a, a));
}

double angle(int n, double *a, double *b) 
{
    return acos(scal(n, a, b) / (modul(n, a) * modul(n, b)));
}

void vecpr(double *a, double *b, double *c)
{
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}

double area(double *a, double *b)
{
    double c[3];
    vecpr(a, b, c);
    return modul(3, c);
}

void prvec(int n, double*a)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}