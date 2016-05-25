#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include "math.h"
#include <cmath>
#include "1n5_vecfunc.h"

using namespace std;

int main()
{
    int n;
    do
    {
        cout << "input n\n";
        cin >> n;
        if (n != 0)
        {
            double a[3], b[3], c[3];
            cout << "inp a\n";
            for (int i = 0; i < n; ++i)
                cin >> a[i];
            cout << "inp b\n";
            for (int i = 0; i < n; ++i)
                cin >> b[i];
            if(n == 2)
            {
                a[2] = 0;
                b[2] = 0;
            }
            vecpr(a, b, c);
            cout << "a X b = ";
            prvec(n, c);
            cout << "Area = " << area(a, b) << "\n";
        }
    }
    while(n != 0);
    return 0;
}