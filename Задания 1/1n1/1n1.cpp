#include <stdio.h>
#include <iostream>
#include "math.h"

using namespace std;

int resh(double a, double b, double c, double &x1, double &x2);

int main(int argc, char const *argv[])
{
	double a, b, c;
	int flag;
	double x1, x2;
	do
	{
		cout << "inp a, b, c ";
		cin >> a >> b >> c;
		if(a == 0) continue;
		flag = resh(a, b, c, x1, x2);
		if(flag > 0)
			cout << "x1 = " << x1 << ", x2 = " << x2 << "\n";
		else
			cout << "no resh\n";
	}
	while(a != 0);
	return 0;
}


int resh(double a, double b, double c, double &x1, double &x2)
{
	double dis = b * b - 4 * a * c;
	if(dis >= 0)
	{
		x1 = (-b + sqrt(dis)) / (2 * a);
		x2 = (-b - sqrt(dis)) / (2 * a);
		if(dis > 0) return 2;
		return 1;
	}
	return 0;
	
	
}

