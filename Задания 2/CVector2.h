#ifndef __CVECTOR2_H__
#define __CVECTOR2_H__

#include "CVector.h"
class CVector2: private CVector
{
	public:
		CVector2() : CVector() { }
		CVector2(int n, double *dt = 0) : CVector(n, dt) { }
		CVector2(const CVector &a) : CVector(a) { }

		double operator * (CVector &a);
	protected:
		double scal(CVector &a);

};

#endif