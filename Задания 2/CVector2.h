#ifndef __CVECTOR2_H__
#define __CVECTOR2_H__

#include "CVector.h"
class CVector2: public CVector
{
	public:
		CVector2(int n = 0, double *dt = 0) : CVector(n, dt) { }
		CVector2(const CVector &a) : CVector(a) { }
		double operator * (CVector &a);
		protected:
		double scal(CVector &a);

};

#endif