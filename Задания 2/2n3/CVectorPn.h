#ifndef __CVECTORPN_H__
#define __CVECTORPN_H__

#include "CVectorvir.h"
class CVectorPn : public CVector
{
	public:
		CVectorPn() : CVector() { }
		CVectorPn(int n, double *dt = 0) : CVector(n, dt) { }
		CVectorPn(const CVector &a) : CVector(a) { }
		double operator * (CVector &a);
		CVectorPn operator*(double a);
	protected:
		double scal(CVector &a);
};

#endif