#ifndef __CVECTORPN_H__
#define __CVECTORPN_H__

#include "CVector.h"
class CVectorPn : private CVector
{
	public:
		CVectorPn() : CVector() { }
		CVectorPn(int n, double *dt = 0) : CVector(n, dt) { }
		CVectorPn(const CVector &a) : CVector(a) { }
		double operator * (CVector &a);
	protected:
		double scal(CVector &a);
};

#endif