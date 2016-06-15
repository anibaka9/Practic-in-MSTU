#include <stdio.h>
#include <iostream>
#include "math.h"

#include "CVector.h"
#include "CVector2.h"



using namespace std;

int main(int argc, char const *argv[])
{
	cout << "1: reference dimensions and the coordinates of the vector I" << endl <<
	"2: reference dimensions and the coordinates of the vector II" << endl <<
	"3: adding (v1 += v2)" << endl <<
	"4: subtracting (v1 -= v2)" << endl <<
	"5: multiplication (v1 *= a)" << endl <<
	"6: comparing (v1 == v2)" << endl <<
	"7: comparing (v1 != v2)" << endl <<
	"8: equating (v2 = v1)" << endl <<
	"9: vector addition (v3 = v1 + v2)" << endl <<
	"10: vector difference (v3 = v1 - v2)" << endl <<
	"11: vector by multiplying the number (v3 = v1 * a)" << endl <<
	"12: scalar multiplication (a = v1 * v2)" << endl <<
	"13: coordinate conclusion" << endl <<
	"0: exit" << endl;
	getchar();
	CVector2 *v1 = new CVector2(), *v2 = new CVector2(), *v3 = new CVector2();
	CVector *Cv1, *Cv2;
	int k = 1;
	double *x;
	double a;
	int n;
	

	while (k != 0)
	{
		cin >> k;

		switch (k)
		{
		case 1: cout << "Enter the dimension of the vector I:";
			cin >> n;
			cout << "Enter the coordinates of the vector I: ";
			delete[]x;
			x = new double[n];
			for (int i = 0; i < n; i++)
			{
				cin >> x[i];
			}
			*v1 = CVector2(n, x);
			break;
		case 2: cout << "Enter the dimension of the vector II: ";
			cin >> n;
			cout << "Enter the coordinates of the vector II: ";
			delete[]x;
			x = new double[n];
			for (int i = 0; i < n; i++)
			{
				cin >> x[i];
			}
			*v2 = CVector2(n, x);
			break;
		case 3: *v1 += *v2;
			break;
		case 4: *v1 -= *v2;
			break;
		case 5: cout << "Enter the number:";
			cin >> a;
			*v1 *= a;
			break;
		case 6: if (v1 == v2) cout << "True" << endl;
				else
					cout << "False" << endl;
			break;
		case 7: if (v1 != v2) cout << "True" << endl;
				else
					cout << "False" << endl;
			break;
		case 8: *v2 = *v1;
			break;
		case 9: *v3 = *v1 + *v2;
			break;
		case 10: *v3 = *v1 - *v2;
			break;
		case 11: cout << "Enter the number:";
			cin >> a;
			*v3 = (*v1) * a;
			break;
		case 12:
			a = *v1 * *v2;
			cout << "scalar multiplication for CVector2: " << a << endl;
			Cv1 = v1;
			Cv2 = v2;
			a = *Cv1 * *Cv2;
			cout << "scalar multiplication for CVector: " << a << endl;
			break;
		case 13: cout << "vector I: ";
			v1->print();
			cout << endl << "vector II:  ";
			v2->print();
			cout << endl << "vector III: ";
			v3->print();
			cout << endl;
			break;
		}
	}
	return 0;
}