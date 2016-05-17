#include <stdio.h>
#include <iostream>
#include "math.h"
#include <cmath>

using namespace std;

int main()
{
    double el, sum, sr, mmin, mmax;
    int n = 1;
    cout << "inp els\n";
    cin >> el;
    sr = mmin = mmax = el;
    cout << " min = " << mmin
         << " sr = " << sr << " max = " << mmax << "\n"; 
    while (el != 0)
    {
        cin >> el;
        n++;
        sr = (sr * (n - 1) + el) / n;
        if (el < mmin) mmin = el;
        if (el > mmax) mmax = el;
        if (el != 0) cout << " min = " << mmin
                     << " sr = " << sr << " max = " << mmax << "\n";
    }
	return 0;
}

