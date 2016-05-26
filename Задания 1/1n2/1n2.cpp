#include <stdio.h>
#include <iostream>
#include "math.h"

using namespace std;

int main()
{
    double el, sr, mmin, mmax;
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
        sr += el;
        if (el < mmin) mmin = el;
        if (el > mmax) mmax = el;
        if (el != 0) cout << " min = " << mmin
                     << " sr = " << sr / n << " max = " << mmax << "\n";
    }
	return 0;
}

