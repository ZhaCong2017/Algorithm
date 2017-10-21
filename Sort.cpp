#include<iostream>
#include<ctime>
#include<random>
#include<fstream>
#include<algorithm>
using namespace std;

bool check(int *num, int n)
{
	for (int i = 1; i < n; i++)
	{
		if (num[i - 1] > num[i])
			return false;
	}
	return true;
}

bool check2(int *num1, int *num2, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (num1[i] != num2[i])
		{
			return false;
		}
	}
	return true;
}
void copy(int *num, int *num_copy, int n)
{
	for (int i = 0; i < n; i++)
		num_copy[i] = num[i];
}

void BubbleSort(int *num, int n)
{
	int tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (num[i] > num[j])
			{
				tmp = num[j];
				num[j] = num[i];
				num[i] = tmp;
			}
		}
	}
}

void QuickSort(int *num, int lo, int hi)
{
	if (lo < hi)
	{
		int i = lo;
		int j = hi;
		int key = num[lo];
		while (i < j)
		{
			while (i < j && num[j] >= key)
				j--;
			num[i] = num[j];
			while (i < j && num[i] <= key)
				i++;
			num[j] = num[i];
		}
		num[i] = key;
		QuickSort(num, lo, i - 1);
		QuickSort(num, i + 1, hi);
	}
}

void Merge(int *num, int lo, int mid, int hi)
{
	int  *left, *right;
	int n1 = mid - lo + 1;
	int n2 = hi - mid;
	left = new int[n1 + 1];
	right = new int[n2 + 1];
	for (int i = 0; i < n1; i++)
		left[i] = num[i + lo];
	for (int i = 0; i < n2; i++)
		right[i] = num[i + mid + 1];
	left[n1] = right[n2] = INT_MAX;
	for (int i = 0, j = 0, k = lo; k <= hi; k++)
	{
		if (left[i] < right[j])
		{
			num[k] = left[i];
			i++;
		}
		else
		{
			num[k] = right[j];
			j++;
		}
	}
	delete[]left;
	delete[]right;
}

void MergeSort(int *num, int lo, int hi)
{
	if (lo < hi)
	{
		int mid = (lo + hi) / 2;
		MergeSort(num, lo, mid);
		MergeSort(num, mid + 1, hi);
		Merge(num, lo, mid, hi);
	}

}

void InsertSort(int *num, int n)
{
	int tmp;
	for (int i = 1; i < n; i++)
	{
		tmp = num[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (num[j] > tmp && j == 0)
			{
				num[j + 1] = num[j];
				num[j] = tmp;
			}
			else if (num[j] > tmp)
				num[j + 1] = num[j];
			else
			{
				num[j + 1] = tmp;
				break;
			}
		}
	}
}

int Left(int i)
{
	return i * 2;
}
int Right(int i)
{
	return i * 2 + 1;
}

inline void MAX_HEAPIFY(int *num, int n, int place)
{
	place++;
	int left = Left(place);
	int right = Right(place);
	int largest;
	if (left <= n && num[left - 1] > num[place - 1])
		largest = left;
	else
		largest = place;
	if (right <= n && num[right - 1] > num[largest - 1])
		largest = right;
	if (largest != place)
	{
		int tmp = num[place - 1];
		num[place - 1] = num[largest - 1];
		num[largest - 1] = tmp;
		MAX_HEAPIFY(num, n, largest - 1);
	}
}

void BuildHeap(int *num, int n)
{
	for (int i = n / 2; i >= 0; i--)
		MAX_HEAPIFY(num, n, i);
}

void HeapSort(int*num, int n)
{
	BuildHeap(num, n);
	int length = n;
	for (int i = n - 1; i > 0; i--)
	{
		int tmp = num[0];
		num[0] = num[i];
		num[i] = tmp;
		length--;
		MAX_HEAPIFY(num, length, 0);		
	}
}

void BucketSort(int *num, int n)
{
	vector<int>bucket(40000, 0);
	for (int i = 0; i < n; i++)
	{
		bucket[num[i]]++;
	}
	for (int i = 0, j = 0; i < 40000; i++)
	{
		for (; bucket[i] > 0; bucket[i]--)
		{
			num[j] = i;
			j++;
		}
	}

}
int main()
{
	ofstream out("result.txt");
	srand(time(0));
	clock_t start, finish;
	int n = 10000;
	int *num = new int[n];
	int *num_sort1 = new int[n];
	int *num_sort2 = new int[n];
	//int *num_sort3 = new int[n];
	int *num_sort4 = new int[n];
	int *num_sort5 = new int[n];
	int *num_sort6 = new int[n];
	for (int i = 0; i < n; i++)
		num[i] = rand();
	copy(num, num_sort1, n);
	start = clock();
	BubbleSort( num_sort1, n);
	finish = clock();
	cout << check(num_sort1, n) << endl;
	cout << "BubbleSort:" << (double)(finish - start) / CLOCKS_PER_SEC << endl;

	copy(num, num_sort2, n);
	start = clock();
	InsertSort(num_sort2, n);
	finish = clock();
	cout << check(num_sort2, n) << endl;
	cout << "InsertSort:" << (double)(finish - start) / CLOCKS_PER_SEC << endl;

	copy(num, num_sort4, n);
	start = clock();
	QuickSort(num_sort4, 0, n - 1);
	finish = clock();
	cout << check(num_sort4, n) << endl;
	cout << "QuickSort:" << (double)(finish - start) / CLOCKS_PER_SEC << endl;

	copy(num, num_sort4, n);
	start = clock();
	MergeSort(num_sort4, 0, n - 1);
	finish = clock();
	cout << check(num_sort4, n) << endl;
	cout << "MergeSort:" << (double)(finish - start) / CLOCKS_PER_SEC << endl;

	copy(num, num_sort5, n);
	start = clock();
	HeapSort(num_sort5, n);
	finish = clock();
	cout << check(num_sort5, n) << endl;
	cout << "HeapSort" << (double)(finish - start) / CLOCKS_PER_SEC << endl;

	copy(num, num_sort6, n);
	start = clock();
	BucketSort(num_sort6, n);
	finish = clock();
	cout << check(num_sort6, n) << endl;
	cout << "BucketSort:" << (double)(finish - start) / CLOCKS_PER_SEC << endl;

	copy(num, num_sort6, n);
	start = clock();
	sort(num_sort6, num_sort6 + n);
	finish = clock();
	cout << check(num_sort6, n) << endl;
	cout << "Sort:" << (double)(finish - start) / CLOCKS_PER_SEC << endl;

	/*cout << check2(num_sort1, num_sort2, n) << endl;
	cout << check2(num_sort1, num_sort3, n) << endl;
	cout << check2(num_sort1, num_sort4, n) << endl;
	cout << check2(num_sort1, num_sort5, n) << endl;
	cout << check2(num_sort1, num_sort6, n) << endl;*/
	/*for (int i = 0; i < n; i++)
		out << num_sort1[i] << "   ";
	out << endl << endl << endl;
	
	for (int i = 0; i < n; i++)
		out << num_sort2[i] << "   ";
	out << endl;*/

	system("pause");
	return 0;


}
