#ifndef __CVECTOR_H__
#define __CVECTOR_H__

class CVector
{
public:
	CVector(int size, std::string &s): n(size);
	~CVector();
	void operator+=(CVector &a);
	void operator-=(CVector &a, CVector &b);
	CVector operator-(CVector &a, CVector &b);
	CVector operator*(int a, CVector &b);
	CVector operator*(CVector &a, CVector &b);
	bool operator==(CVector &a, CVector &b);
	bool operator!=(CVector &a, CVector &b);
private:
	double *data;
	int size;
	void setsize(int size);
};

#endif