// sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//快排
void QuickSort(vector<int> &a,int left,int right)
{
	int i = left;
	int j = right;
	int pivot = a[i];
	while (i <= j)
	{
		while (a[i] < pivot) { i++;}
		while (a[j] > pivot) { j--;}
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < right) QuickSort(a, i, right);
	if (j > left) QuickSort(a, left, j);
}

//堆排
//建立最大堆
void insert_i(vector<int> &a, int length)
{
	while (length > 0)
	{
		int parent = (length - 1) / 2;
		if (a[parent] < a[length])
		{
			swap(a[parent], a[length]);
			length = parent;
		}
		else break;
	}
}

//将最大值删除并放在尾部
void delete_max(vector<int> &a, int length)
{
	int tmp = a[0];
	int ind = 0;
	while (1)
	{
		int left = 2 * ind + 1;
		int right = 2 * ind + 2;
		if(left>=length)
		{
			break;
		}
		else
		{
			int large = a[left] > a[right] ? left : right;
			a[ind] = a[large];
			ind = large;
		}
	}
	a[ind] = a[length];
	a[length] = tmp;
}
void HeapSort(vector<int> &a, int n)
{
	for (int i = 0;i < n;i++)
	{
		insert_i(a, i);
	}
	for (int i = n - 1;i > 0;i--)
	{
		delete_max(a, i);
	}
}

//归并排序
const int maxn = 500000, INF = 0x3f3f3f3f;
int L[maxn / 2 + 2], R[maxn / 2 + 2];
void merge(vector<int> &a, int n, int left, int mid, int right)
{
	int n1 = mid - left, n2 = right - mid;
	for (int i = 0;i < n1;i++)
		L[i] = a[left + i];
	for (int i = 0;i < n2;i++)
		R[i] = a[mid + i];
	L[n1] = R[n2] = INF;
	int i = 0, j = 0;
	for (int k = left;k < right;k++)
	{
		if (L[i] <= R[j])
			a[k] = L[i++];
		else
			a[k] = R[j++];
	}
}
void MergeSort(vector<int> &a, int n, int left, int right)
{
	if (left + 1 < right)
	{
		int mid = (left + right) / 2;
		MergeSort(a, n, left, mid);
		MergeSort(a, n, mid, right);
		merge(a, n, left, mid, right);
	}
}
int main()
{
	int arr[] = { 5,16,7,26,9,4 };
	vector<int> a(arr, arr + 6);

	//QuickSort(a, 0, 5);

	//HeapSort(a, 6);

	MergeSort(a,6,0,6);

	for (int i = 0;i < 6;i++)
		cout << a[i] << " ";

	system("pause");
	return 0;
}



