#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include "math.h"
//#include <cmath>

using namespace std;

double scal(int n, double *a, double *b);
double modul(int n, double *a);
double angle(int n, double *a, double *b);

int main()
{
    int n;
    do
    {

        cout << "input n\n";
        cin >> n;
        if (n < 0) continue;
        if (n != 0)
        {
            double *a = new double[n], *b = new double[n];
            cout << "inp a\n";
            for (int i = 0; i < n; ++i) cin >> a[i];
            cout << "inp b\n";
            for (int i = 0; i < n; ++i) cin >> b[i];
            cout << "Lenght a = " << modul(n, a) << "\n";
            cout << "Lenght b = " << modul(n, b) << "\n";
            cout << "The angle between a and b = " << angle(n, a, b) << "\n";
        }
    }
    while(n != 0);
    return 0;
}


double scal(int n, double *a, double *b)
{
    double res = 0;
    for (int i = 0; i < n; ++i) res += a[i] * b[i];
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