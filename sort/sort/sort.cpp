// sort.cpp : 包含快排，归并排序，堆排序

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 快排
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

// 堆排
//// 建立最大堆
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

//// 将最大值删除并放在尾部
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

// 归并排序
void Merge(vector<int> &a, int l, int m, int r)
{
	// 获取左右部分数组的大小（实际还是原数组）
	int l_c = m - l + 1;
	int r_c = r - m;
	
	// 将数组值赋给临时数组（两个数组）
	int i, j, k;
	vector<int> L(l_c + 1);
	vector<int> R(r_c + 1);
	for (i = 0;i < l_c;i++)
		L[i] = a[l + i];
	for (j = 0;j < r_c;j++)
		R[j] = a[m + 1 + j];

	// 每个数组的最后一个数赋值11111111,任意数与之比较都小
	L[l_c] = 11111111;
	R[r_c] = 11111111;

	//
	for (i = 0, j = 0, k = l;k <= r;k++)
	{
		if (L[i] < R[j])
			a[k] = L[i++];
		else
			a[k] = R[j++];
	}
}

void MergeSort(vector<int> &a, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		Merge(a, l, m, r);
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



