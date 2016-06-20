#ifndef __CVECTOR_H__
#define __CVECTOR_H__
#include <iostream>

using namespace std;


template <int vecsize, typename DATATYPE>
class CVector
{
    public:
        CVector(DATATYPE *y = NULL)
        {
            size = vecsize;
            data = NULL;
            set_data(y);
        }

        CVector(const CVector &a)
        {
            size = vecsize;
            data = NULL;
            set_data(a.data);
        }

        void print();

        bool operator==(CVector  &a);
        bool operator!=(CVector  &a);
        CVector operator=(CVector  a);
        CVector operator+=(CVector  &a);
        CVector operator-=(CVector  &a);
        CVector operator*=(DATATYPE &a);
        CVector operator+(CVector  &a);
        CVector operator-(CVector  &a);
        CVector operator*(DATATYPE &a);
        DATATYPE operator*(CVector  &a);

        ~CVector()
        { }

    protected:
        void set_data(DATATYPE *y);

        bool raven(CVector  &a);
        CVector copy(CVector  &a);
        CVector prib(CVector  &a);
        CVector vich(CVector  &a);
        CVector umncoef(DATATYPE &a);
        CVector sum(CVector  &a);
        CVector raz(CVector  &a);
        CVector multV(DATATYPE &a);
        DATATYPE scalar(CVector  &a);

    private:
        DATATYPE *data;
        int size;
};

template <int vecsize, typename DATATYPE>
void CVector<vecsize, DATATYPE>::print()
{
    for(int i = 0; i < vecsize; i++)
    {
        cout << data[i] << " ";
    }
}

template <int vecsize, typename DATATYPE>
void CVector<vecsize, DATATYPE>::set_data(DATATYPE *y)
{
    delete[]data;
    data = new DATATYPE[vecsize];
    for(int i = 0; i < vecsize; i++)
    {
        data[i] = y[i];
    }
}

//Functions

template <int vecsize, typename DATATYPE>
bool CVector<vecsize, DATATYPE>::raven(CVector &a)
{
    if(size != a.size) { return false; }
    else
    {
        for(int i = 0; i < size; i++)
        {
            if(data[i] != a.data[i]) { return false; }
        }
    }
    return true;
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::copy(CVector &a)
{
    set_data(a.data);
    return *this;
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::prib(CVector &a)
{
    if(size == a.size)
    {
        for(int i = 0; i < size; i++)
        {
            data[i] = data[i] + a.data[i];
        }
        return *this;
    }
    cout << "Error: different dimension vectors" << endl;
    return *this;
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::vich(CVector &a)
{
    if(size == a.size)
    {
        for(int i = 0; i < size; i++)
        {
            data[i] = data[i] - a.data[i];
        }
        return *this;
    }
    cout << "Error: different dimension vectors" << endl;
    return *this;
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::umncoef(DATATYPE &a)
{
    for(int i = 0; i < size; i++)
    {
        data[i] = data[i] * a;
    }
    return *this;
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::sum(CVector &a)
{
    if(size = a.size)
    {
        CVector a3(new DATATYPE[size]);
        for(int i = 0; i < size; i++)
        {
            a3.data[i] = data[i] + a.data[i];
        }
        return a3;
    }
    cout << "Error: different dimension vectors" << endl;
    return CVector();
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::raz(CVector &a)
{
    if(size = a.size)
    {
        CVector a3(new DATATYPE[size]);
        for(int i = 0; i < size; i++)
        {
            a3.data[i] = data[i] - a.data[i];
        }
        return a3;
    }
    cout << "Error: different dimension vectors" << endl;
    return CVector();
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::multV(DATATYPE &a)
{
    CVector a3(new DATATYPE[size]);
    for(int i = 0; i < size; i++)
    {
        a3.data[i] = data[i] * a;
    }
    return a3;
}

template <int vecsize, typename DATATYPE>
DATATYPE CVector<vecsize, DATATYPE>::scalar(CVector &a)
{
    if(size == a.size)
    {
        double res = 0;
        for(int i = 0; i < size; i++)
        {
            res = res + data[i] * a.data[i];
        }
        return res;
    }
    cout << "Error: different dimension vectors" << endl;
}



//Operators

template <int vecsize, typename DATATYPE>
bool CVector<vecsize, DATATYPE>::operator == (CVector &a)
{
    return raven(a);
}

template <int vecsize, typename DATATYPE>
bool CVector<vecsize, DATATYPE>::operator != (CVector &a)
{
    return !raven(a);
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::operator = (CVector a)
{
    return copy(a);
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::operator += (CVector &a)
{
    return prib(a);
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::operator -= (CVector &a)
{
    return vich(a);
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::operator *= (DATATYPE  &a)
{
    return umncoef(a);
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::operator + (CVector &a)
{
    return sum(a);
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::operator - (CVector &a)
{
    return raz(a);
}

template <int vecsize, typename DATATYPE>
CVector<vecsize, DATATYPE> CVector<vecsize, DATATYPE>::operator * (DATATYPE  &a)
{
    return multV(a);
}

template <int vecsize, typename DATATYPE>
DATATYPE CVector<vecsize, DATATYPE>::operator * (CVector &a)
{
    return scalar(a);
}

#endif // __CVECTOR_H__
