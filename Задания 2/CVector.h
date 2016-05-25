#ifndef __CVECTOR_H__
#define __CVECTOR_H__

class CVector
{
public:
	CVector();
	~CVector();
private:
	std::vector<double> v;
	int n;
};

#endif