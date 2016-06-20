#ifndef __CODDOUT_H__
#define __CODDOUT_H__

#include "CArrayOut.h"

class COddOut: public CArrayOut
{
public:
	COddOut(int n, double *b) : Cvector(n, b) { };
	~COddOut() {delete[] data; };
	void out() const;
};

#endif 