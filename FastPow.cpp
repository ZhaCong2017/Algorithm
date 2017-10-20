#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

double fastpow(double a, int n)
{
	bool minus = false;
	if (n < 0)
	{
		n = -n;
		minus = true;
	}
	double result = 1;
	while (n)
	{
		if (n & 1)
			result = result * a;
		a = a * a;
		n >>= 1;
	}
	if (minus)
		return 1 / result;
	else
		return result;
}

int main()
{
	double a = 2.5;
	int b = 2;
	cout << fastpow(a, b) << endl;
	cout << pow(a, b) << endl;
	system("pause");
	return 0;
}
