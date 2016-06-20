#include <iostream>
#include "CArrayOut.h"
#include "COddOut.h"

using namespace std;

void COddOut::out() const
{
	for (int i = 0; i < size; i += 2)
	{
		cout << data[i];
		if((i != size) || (i != size - 1)) cout << " ";
	}

	cout << endl;
} 