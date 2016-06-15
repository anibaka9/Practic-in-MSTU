#ifndef __CVECTOR_H__
#define __CVECTOR_H__
#include <iostream>

using namespace std;

template <typename DATATYPE, int vecsize>
class CVector
{
public:

	CVector(DATATYPE *dt = 0)
	{
		size = vecsize;
		data = 0;
		setdata(dt);
	}

	CVector(const CVector &a)
	{
		size = vecsize;
		data = 0;
		setdata(a.data);
	}



	~CVector() {delete[]data; }

	void print();


	CVector&operator = (CVector a);
	CVector&operator+=(CVector &a);
	CVector&operator-=(CVector &a);
	CVector&operator*=(DATATYPE a);
	CVector operator+(CVector &a);
	CVector operator-(CVector &a);
	CVector operator&(CVector &a);
	CVector operator*(DATATYPE a);
	DATATYPE operator*(CVector &a);
	bool operator==(CVector &a);
	bool operator!=(CVector &a);

	

protected:

	void setdata(DATATYPE *a);

	void prib(CVector &a);
	void vich(CVector &a);
	CVector sum(CVector &a);
	CVector raz(CVector &a);
	void umncoef(DATATYPE a);
	CVector vecumn(CVector &a);
	DATATYPE scal(CVector &a);
	bool raven(CVector &a);
	bool neraven(CVector &a);
	void copy(CVector &a);


private:
	DATATYPE *data;
	int size;
};

template <typename DATATYPE, int vecvecsize>
void CVector<DATATYPE, vecsize>::setdata(DATATYPE *a)
{
	CVector::size = vecsize;
	delete[]CVector::data;
	CVector::data = new DATATYPE[vecsize];
	for (int i = 0; i < n; ++i)
		CVector::data[i] = a[i];
}

template <typename DATATYPE, int vecsize>
void CVector<DATATYPE, vecsize>::print()
{
	for (int i = 0; i < CVector::size; ++i)
		cout << CVector::data[i] << " ";
	cout << "\n";
}

template <typename DATATYPE, int vecsize>
void CVector<DATATYPE, vecsize>::copy(CVector &a)
{
	setdata(a.data);
}

template <typename DATATYPE, int vecsize>
void CVector<DATATYPE, vecsize>::prib(CVector &a)
{
	for (int i = 0; i < CVector::size; ++i)
		CVector::data[i] += (a.data)[i];
}

template <typename DATATYPE, int vecsize>
void CVector<DATATYPE, vecsize>::umncoef(DATATYPE a)
{
	for (int i = 0; i < CVector::size; ++i)
		CVector::data[i] * a;
}

template <typename DATATYPE, int vecsize>
void CVector<DATATYPE, vecsize>::vich(CVector &a) 
{
	CVector b;
	b.copy(a);
	b.umncoef(-1);
	prib(b);
}

template <typename DATATYPE, int vecsize>
CVector<DATATYPE, vecsize> CVector<DATATYPE, vecsize>::sum(CVector &a)
{
	CVector c;
	c.copy(*this);
	c.prib(a);
	return c;
}

template <typename DATATYPE, int vecsize>
CVector<DATATYPE, vecsize> CVector<DATATYPE, vecsize>::raz(CVector &a)
{
	CVector c;
	c.copy(*this);
	c.vich(a);
	return c;
}

template <typename DATATYPE, int vecsize>
DATATYPE CVector<DATATYPE, vecsize>::scal(CVector &a)
{
	DATATYPE res = 0;

	for (int i = 0; i < CVector::size; ++i)
		res += CVector::data[i] * a.data[i];
	return res;
}

template <typename DATATYPE, int vecsize>
CVector<DATATYPE, vecsize> CVector<DATATYPE, vecsize>::vecumn(CVector &a)
{
	if (CVector::size == 3)
	{
		CVector res;
		res.data[0] = CVector::data[1] * a.data[2] - CVector::data[2] * a.data[1];
		res.data[1] = CVector::data[2] * a.data[0] - CVector::data[0] * a.data[2];
		res.data[2] = CVector::data[0] * a.data[1] - CVector::data[1] * a.data[0];
		return res;
	}
}


template <typename DATATYPE, int vecsize>
bool CVector<DATATYPE, vecsize>::raven(CVector &a)
{
	bool res = 1;
	for (int i = 0; i < CVector::size; ++i)
	{
		if (res == 1 && CVector::data[i] != a.data[i]) res = 0;
	}
	return res;

}

template <typename DATATYPE, int vecsize>
bool CVector<DATATYPE, vecsize>::neraven(CVector &a) { return !(raven(a)); }


//Operators
template <typename DATATYPE, int vecsize>
CVector<DATATYPE, vecsize>&CVector<DATATYPE, vecsize>::operator = (CVector a) 
{
	copy(a);
	return *this;
}

template <typename DATATYPE, int vecsize>
CVector<DATATYPE, vecsize>&CVector<DATATYPE, vecsize>::operator+=(CVector &a) 
{
	prib(a);
	return *this;
}

template <typename DATATYPE, int vecsize>
CVector<DATATYPE, vecsize>&CVector<DATATYPE, vecsize>::operator-=(CVector &a) 
{
	vich(a);
	return *this;
}

template <typename DATATYPE, int vecsize>
CVector<DATATYPE, vecsize>&CVector<DATATYPE, vecsize>::operator*=(DATATYPE a) 
{
	umncoef(a);
	return *this;
}

template <typename DATATYPE, int vecsize>
CVector<DATATYPE, vecsize> CVector<DATATYPE, vecsize>::operator+(CVector &a)
{
	CVector res = CVector::sum(a);
	return res;
}

template <typename DATATYPE, int vecsize>
CVector<DATATYPE, vecsize> CVector<DATATYPE, vecsize>::operator-(CVector &a) 
{
	CVector res = *this;
	res -= a;
	return res;
}

template <typename DATATYPE, int vecsize>
CVector<DATATYPE, vecsize> CVector<DATATYPE, vecsize>::operator*(DATATYPE a)
{
	CVector res = *this;
	res.umncoef(a);
	return res;
}

template <typename DATATYPE, int vecsize>
CVector<DATATYPE, vecsize> CVector<DATATYPE, vecsize>::operator&(CVector &a) { return CVector::vecumn(a); }

template <typename DATATYPE, int vecsize>
DATATYPE CVector<DATATYPE, vecsize>::operator*(CVector &a) { return CVector::scal(a); }

template <typename DATATYPE, int vecsize>
bool CVector<DATATYPE, vecsize>::operator==(CVector &a) { return CVector::raven(a); }

template <typename DATATYPE, int vecsize>
bool CVector<DATATYPE, vecsize>::operator!=(CVector &a) { return CVector::neraven(a); }

#endif