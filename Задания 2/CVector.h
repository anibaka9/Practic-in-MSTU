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

	CVector(int n, double *dt)
	{
		setdata(n, dt);
	}

	CVector(const CVector &a)
	{
		setdata(a.size, a.data);
	}



	~CVector() {delete[]data; }

	void print();


	CVector&operator = (CVector &a);
	CVector&operator+=(CVector &a);
	CVector&operator-=(CVector &a);
	CVector&operator*=(double a);
	CVector operator+(CVector &a);
	CVector operator-(CVector &a);
	CVector operator*(double a);
	CVector operator*(CVector &a);
	double operator&(CVector &a);
	bool operator==(CVector &a);
	bool operator!=(CVector &a);


protected:
	void setdata(unsigned int n, double *a);
	void getdata(double *a);
	unsigned int getsize();
	
	void prib(CVector &a);
	void vich(CVector &a);
	CVector sum(CVector &a);
	CVector raz(CVector &a);
	void umncoef(double a);
	CVector vecumn(CVector &a);
	double scal(CVector &a);
	bool raven(CVector &a);
	bool neraven(CVector &a);
	void copy(CVector &a);


private:
	double *data;
	unsigned int size;
};

#endif