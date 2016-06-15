#include "CVectorshab.h"
#define DATATYPE double
#define VECTSIZE 3

void input_data(DATATYPE *x);

int main(int argc, char* argv[])
{
	DATATYPE *x = new DATATYPE[VECTSIZE];

	CVector<DATATYPE, VECTSIZE> v1(x);
	CVector<DATATYPE, VECTSIZE> v2(x);
	CVector<DATATYPE, VECTSIZE> v3(x);

	int k = 1, n;
	DATATYPE a;

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
			v1 = CVector<DATATYPE, VECTSIZE>(n, x);
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
			v2 = CVector<DATATYPE, VECTSIZE>(n, x);
			break;
		case 3: v1 += v2;
			break;
		case 4: v1 -= v2;
			break;
		case 5: cout << "Enter the number:";
			cin >> a;
			v1 *= a;
			break;
		case 6: if (v1 == v2) cout << "True" << endl;
				else
					cout << "False" << endl;
			break;
		case 7: if (v1 != v2) cout << "True" << endl;
				else
					cout << "False" << endl;
			break;
		case 8: v2 = v1;
			break;
		case 9: v3 = v1 + v2;
			break;
		case 10: v3 = v1 - v2;
			break;
		case 11: cout << "Enter the number:";
			cin >> a;
			v3 = v1 * a;
			break;
		case 12: a = v1 * v2;
			cout << "Scalar product:" << a << endl;
			break;
		case 13: cout << "vector I: ";
			v1.print();
			cout << endl << "vector II:  ";
			v2.print();
			cout << endl << "vector III: ";
			v3.print();
			cout << endl;
			break;
		}
	}

}

void input_data(DATATYPE *x)
{
	for (int i = 0; i < VECTSIZE; i++)
	{
		cin >> x[i];
	}
}