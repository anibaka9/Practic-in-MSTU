#ifndef __CARRAYOUT_H__
#define __CARRAYOUT_H__

class CArrayOut
{
public:
	CArrayOut(int n, double *b){
		size = n;
		for (int i = 0; i < size; ++i)
		{
			data[i] = b[i];
		}
	};
	~CArrayOut() {delete[] data; }; 
	void out() const;
private:
	int size;
	double *data;
};

#endif 