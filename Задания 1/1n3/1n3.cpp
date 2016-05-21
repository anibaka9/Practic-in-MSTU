#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include "math.h"
#include <cmath>

using namespace std;

void prvec(int n, double *a);

void summ(int n, double *a, double *b, double *c);

void raz(int n, double *a, double *b, double *c);

int scal(int n, double *a, double *b);

int main()
{
    int n;
    do
    {

	    cout << "input n\n";
	    cin >> n;
	    if (n != 0)
	    {
	    	double *a = new double[n], *b = new double[n], *c = new double[n];
		    cout << "inp a\n";
		    for (int i = 0; i < n; ++i)
		    {
		    	cin >> a[i];
		    }
		    cout << "inp b\n";
		    for (int i = 0; i < n; ++i)
		    {
		    	cin >> b[i];
		    }
		    summ(n, a, b, c);
		    cout << "a + b = ";
		    prvec(n, c);
		    raz(n, a, b, c);
		    cout << "a - b = ";
		    prvec(n, c);
		    cout << "(a, b) = " << scal(n, a, b) << "\n";
	    }
	}
	while(n != 0);
	return 0;
}

void prvec(int n, double*a)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

void summ(int n, double *a, double *b, double *c)
{
	for (int i = 0; i < n; ++i) c[i] = a[i] + b[i];
}

void raz(int n, double *a, double *b, double *c)
{
	for (int i = 0; i < n; ++i) c[i] = a[i] - b[i];
}

int scal(int n, double *a, double *b)
{
	int res = 0;
	for (int i = 0; i < n; ++i) res += a[i] * b[i];
	return res;
}