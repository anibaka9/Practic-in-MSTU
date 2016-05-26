void CVector::setsize(int n)
{
	size = new double[n]
}

void CVector::setdata(double *a)
{
	for (int i = 0; i < CVector::size; ++i)
		CVector::data[i] = a[i];
}

void prib(CVector &a)
{
	if (CVector::size == a.size)
	{
		for (int i = 0; i < a.size; ++i)
			CVector::data[i] += a.data[i]
	}
}

void 