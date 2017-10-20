#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

#define max 9191891
#define factor 29
#define ch 96

bool verify(string haystack, string needle, int x)
{
	int n = needle.length();
	for (int i = x; i < x + n - 1; i++)
	{
		if (haystack[i] != needle[i - x])
			return false;
	}
	return true;
}

int rollinghash(string haystack, string needle)
{
	int n = needle.length();
	int m = haystack.length();
	if (n == 0)
		return 0;
	if (m == 0 || m < n)
		return -1;
	long long multiple = long long(pow(factor, n - 1)) % max;
	long long hash = 0;
	long long hashhay = 0;
	for (int i = 0; i < n; i++)
	{
		hash = (hash * factor + needle[i] - ch) % max;
		hashhay = (hashhay * factor + haystack[i] - ch) % max;
	}
	if (hash == hashhay && verify(haystack, needle, 0))
		return 0;
	for (int i = 1; i <= haystack.length() - n; i++)
	{
		hashhay = (hashhay - (haystack[i - 1] - ch) * multiple % max);
		if (hashhay < 0)
			hashhay += max;
		hashhay = (hashhay * factor + haystack[i + n - 1] - ch) % max;
		if (hash == hashhay && verify(haystack, needle, i))
			return i;
	}
	return -1;
}

int main()
{
	string haystack = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	string needle = "aaaab";
	cout << rollinghash(haystack, needle) << endl;
	system("pause");
	return 0;
}
