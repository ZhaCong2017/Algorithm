#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *num = new int[n];
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int sum = num[0];
	int tmpsum = 0;
	for (int i = 0; i < n; i++)
	{
		tmpsum += num[i];
		if (sum < tmpsum)
			sum = tmpsum;
		if (tmpsum < 0)
			tmpsum = 0;
	}
	cout << sum << endl;
	system("pause");
	return 0;
}
