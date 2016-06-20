#include <iostream>
#include "hider.h"
#include "CArrayOut.h"

using namespace std;

void CArrayOut::out() const{
	for (int i = 0; i < size; ++i)
	{
		cout << data[i];
		if(i != size - 1) cout << " ";
	}
	cout << endl;
}
