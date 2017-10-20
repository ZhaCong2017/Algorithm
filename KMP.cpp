#include<iostream>
#include<string>
using namespace std;

int *getnext(string needle)
{
	int *next = new int[needle.length()];
	next[0] = -1;
	for (int j = 1, k = -1; j < needle.length(); j++)
	{
		while (k > -1 && needle[j] != needle[k + 1])
			k = next[k];
		if (needle[j] == needle[k + 1])
			k++;
		next[j] = k;
	}
	return next;
}

int KMP(string haystack, string needle)
{
	int *next = getnext(needle);
	for (int i = 0, k = -1; i < haystack.length(); i++)
	{
		while (k > -1 && haystack[i] != needle[k + 1])
			k = next[k];
		if (haystack[i] == needle[k + 1])
			k++;
		if (k == needle.length() - 1)
			return i - needle.length() + 1;
	}
	return -1;
}

int main()
{
	string haystack = "ababcaababcaabc";
	string needle = "ababcaabc";
	cout << KMP(haystack, needle) << endl;
	system("pause");
	return 0;
}
