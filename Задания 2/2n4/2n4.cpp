#include "CVector.h"
#define DATATYPE int
#define VECTSIZE 4

void input_data(DATATYPE *x);
 
int main(int argc, char* argv[])
{

	DATATYPE *x = new DATATYPE[VECTSIZE];
	cout << "Reference the coordinates of the vector I: ";
    input_data(x);
    CVector<VECTSIZE, DATATYPE> vector1(x);
    cout << "Reference the coordinates of the vector II: ";
    input_data(x);
    CVector<VECTSIZE, DATATYPE> vector2(x);
    for(int i = 0; i < VECTSIZE; i++)
    {
        x[i] = 0;
    }
    CVector<VECTSIZE, DATATYPE> vector3(x);


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

	int k = 1, n;
	DATATYPE a;

	while (k != 0)
	{
		cin >> k;

		switch (k)
		{
		case 1: cout << "Enter the coordinates of the vector I: ";
				input_data(x);
				vector1 = CVector<VECTSIZE, DATATYPE>(x);
				break;
		case 2: cout << "Enter the coordinates of the vector II: ";
				input_data(x);
				vector2 = CVector<VECTSIZE, DATATYPE>(x);
				break;
		case 3: vector1 += vector2;
				break;
		case 4: vector1 -= vector2;
				break;
		case 5: cout << "Enter the number:";
				cin >> a;
				vector1 *= a;
				break;
		case 6: if (vector1 == vector2) cout << "True" << endl;
				else
				cout << "False" << endl;
				break;
		case 7: if (vector1 != vector2) cout << "True" << endl;
				else
					cout << "False" << endl;
				break;
		case 8: vector2 = vector1;
				break;
		case 9: vector3 = vector1 + vector2;
				break;
		case 10: vector3 = vector1 - vector2;
				 break;
		case 11: cout << "Enter the number:";
				 cin >> a;
				 vector3 = vector1 * a;
				 break;
		case 12: a = vector1 * vector2;
				 cout << "Scalar multiplication: " << a << endl;
				 break;
		case 13: cout << "vector I: ";
				 vector1.print();
				 cout << endl << "vector II: ";
				 vector2.print();
				 cout << endl << "vector III: ";
				 vector3.print();
				 cout << endl;
				 break;
		}
	}

    return 0;
}


void input_data(DATATYPE *x)
{
    for (int i = 0; i < VECTSIZE; i++)
    {
        cin >> x[i];
    }
}
