void setsize()


void CVector::operator(CVector &a)
{
	if (CVector.size == a.size)
	{
		for (int i = 0; i < CVector.size; ++i)
			CVector.data[i] += a.data[i];
	}
}

CVector CVector::operator*(int a, CVector &b)
{
	
	for (int i = 0; i < b.size; ++i)
	{
		
	}
}