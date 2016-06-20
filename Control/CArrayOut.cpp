#include <iostream>
#include "CArrayOut.h"

using namespace std;

void CArrayOut::out() const{
	for (int i = 0; i < size; ++i)
	{
		cout << data[i];
	}
	cout << endl;
}
