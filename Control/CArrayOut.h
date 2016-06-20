#ifndef __CARRAYOUT_H__
#define __CARRAYOUT_H__

class CArrayOut
{
public:
	CArrayOut(int n = 0, double *b = 0)
	{
		size = n;
		data = new double[n];
		for (int i = 0; i < size; ++i)
			data[i] = b[i];
	};
	~CArrayOut() {delete[] data; }; 
	void out() const;
protected:
	int size;
	double *data;
};

#endif 