#ifndef __CVECTOR_H__
#define __CVECTOR_H__
 
class CVector
{
public:
	CVector(int n = 0, double *dt = 0)
	{
		size = 0;
		data = 0;
		setdata(n, dt);
	}

	CVector(const CVector &a)
	{
		size = 0;
		data = 0;
		setdata(a.size, a.data);
	}



	virtual ~CVector() {delete[]data; }

	void print();


	CVector&operator = (CVector a);
	CVector&operator+=(CVector &a);
	CVector&operator-=(CVector &a);
	CVector&operator*=(double a);
	CVector operator+(CVector &a);
	CVector operator-(CVector &a);
	CVector operator*(double a);
	double operator*(CVector &a);
	bool operator==(CVector &a);
	bool operator!=(CVector &a);

	void setdata(int n, double *a);
	void getdata(double *a);
	unsigned int getsize();

	void prib(CVector &a);
	void vich(CVector &a);
	CVector sum(CVector &a);
	CVector raz(CVector &a);
	void umncoef(double a);
	double scal(CVector &a);
	bool raven(CVector &a);
	bool neraven(CVector &a);
	void copy(CVector &a);


private:
	double *data;
	int size;
};

#endif