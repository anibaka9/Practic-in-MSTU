#ifndef __CVECTOR_H__
#define __CVECTOR_H__

class CVector
{
public:
	CVector()
	{
		size = 0;
		data = new double[0];
	}

	CVector(int n,double *dt)
	{
		setsize(n);
		setdata(dt);
	}

	CVector(const CVector &a)
	{
		size = a.size;
		for (int i = 0	; i < size; ++i)
			data[i] = a.data[i];
	}

	void print(CVector &a);

	~CVector() { }

	void setsize(int n);
	void setdata(double *a);
	
	void prib(CVector &a);
	void vich(CVector &a);
	CVector sum(CVector &a, CVector &b);
	CVector raz(CVector &a, CVector &b);
	CVector umncoef(double a);
	CVector vecumn(CVector &a, CVector &b);
	double scal(CVector &a, CVector &b);
	bool raven(CVector &a, CVector &b);
	bool neraven(CVector &a, CVector &b);
	void copy(CVector &a);

	void operator+=(CVector &a);
	void operator-=(CVector &a);
	void operator*=(double a);
	CVector operator+(CVector &a);
	CVector operator-(CVector &a);
	CVector operator*(double a);
	CVector operator*(CVector &a);
	double operator&(CVector &a);
	bool operator==(CVector &a);
	bool operator!=(CVector &a);
	CVector operator=(CVector &a);

private:
	double *data;
	unsigned int size;
};

#endif