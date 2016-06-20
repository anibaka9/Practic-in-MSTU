#include <iostream>
#include "CArrayOut.h"
#include "COddOut.h"

using namespace std;

void COddOut::out() const
{
	for (int i = 0; i < size; ++i)
		if (data[i] % 2 = 1) cout << data[i];
	cout << endl;
} 