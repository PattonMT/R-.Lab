// offer_lead.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int find_dup(vector<int> &test) {
	int tmp = test[0];
	for (int i = 1;i < test.size(); i++) {
		tmp = tmp ^ test[i];
	}
	return tmp;
}

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

void QuickSort(vector<int> &a, int left, int right)
{
	int i = left;
	int j = right;
	int begin = a[i];

	while (i <= j)
	{
		while (a[i] < begin) i++;
		while (a[j] > begin) j--;
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

void insert_p(vector<int> &a, int p)
{
	while (p > 0)
	{
		int parent = (p - 1) / 2;
		if (a[parent] < a[p])
		{
			swap(a[parent], a[p]);
			p = parent;
		}
		else break;
	}
}

void delete_max(vector<int> &a, int length)
{
	int tmp = a[0];
	int index = 0;

	// 找出最大的
	// large指向已遍历的最大值
	// index指向当前空缺位置
	while (1)
	{
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		
		if (left >= length)
			break;
		else 
		{
			int large = a[left] > a[right] ? left : right;
			a[index] = a[large];
			index = large;
		}
	}
	a[index] = a[length];
	a[length] = tmp;

}

void HeapSort(vector<int> &a)
{
	for (int i = 0;i < a.size();i++)
		insert_p(a, i);
	for (int i = a.size() - 1;i > 0;i--)
		delete_max(a, i);
}

int MinInOrder(vector<int> &a, int left, int right)
{
	int result = a[left];
	for (int i = left + 1;i <= right;i++)
	{
		if (result > a[i])
			result = a[i];
	}
	return result;
}

int FindMin_Rotate(vector<int> &a)
{
	int left = 0;
	int right = a.size() - 1;
	int mid = 0;
	while (a[left] >= a[right])
	{
		if (right - left == 1)
		{
			mid = right;
			break;
		}

		mid = (left + right) / 2;
		// 若left、mid、right三个指针指的数都相同，则用顺序查找
		if (a[left] == a[right] && a[left] == a[mid])
			return MinInOrder(a, left, right);

		if (a[mid] >= a[left])
			left = mid;
		else if (a[mid] <= a[right])
			right = mid;
	}
	return a[mid];	
}

bool haspath(char* matrix, int rows, int cols,char* str)
{
	// 判断二维数组是否合法
	if (matrix == NULL || rows < 0 || cols < 0)
		return false;

	// 创建访问标志的数组,置为0/false
	bool* visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);

	int pathLength = 0;
	// 在二维数组内循环
	for (int row = 0;row < rows;row++)
	{
		for (int col = 0;col < cols;col++)
		{
			if (haspathcore)
				return true;
		}
	}

	delete[] visited;
	return false;
}

bool haspathcore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathLength, bool* visited)
{
	// 读取到str最后，则返回true
	if (str[pathLength] == '\0')
		return true;

	bool haspath = false;

	if (row >= 0 && row < rows && col >= 0 && col < cols
		&&matrix[row*cols + col] == str[pathLength] 
		&& !visited[row*cols + col])
	{
		pathLength++;
		visited[row*cols + col] = true;
		// 在其上下左右四个方向查找
		haspath = haspathcore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
			|| haspathcore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
			|| haspathcore(matrix, rows, cols, row + 1, col, str, pathLength, visited)
			|| haspathcore(matrix, rows, cols, row, col + 1, str, pathLength, visited);

		if (!haspath)
		{
			--pathLength;
			visited[row*cols + col] = false;
		}
	}
	return haspath;
}

int moving_count(int threshold, int rows, int cols)
{
	bool* visited = new bool[rows*cols];
	for (int i = 0;i < rows*cols;i++)
	{
		visited[i] = false;
	}

	int count = moving_count_core(threshold, rows, cols, 0, 0, visited);
	return count;
}

int moving_count_core(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int count = 0;
	if (check)
	{
		visited[row*cols + row] = true;
		count = 1 + moving_count_core(threshold, rows, cols, row, col - 1, visited)
			+ moving_count_core(threshold, rows, cols, row, col - 1, visited)
			+ moving_count_core(threshold, rows, cols, row - 1, col + 1, visited)
			+ moving_count_core(threshold, rows, cols, row + 1, col, visited);
	}
	return count;
}


int max_cut(int length)
{
	// 排除三个特殊示例
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	// 初始化新的数组
	int* arr = new int[length + 1];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;

	int max=0;
	for (int i = 4;i <=length;i++)
	{
		max = 0;
		for (int j = 0;j < i / 2;j++)
		{   
			// 寻找最大
			int count = arr[j] * arr[i - j];
			if (max < arr[i])
				max = arr[i];

			arr[i] = max;
		}
	}
	return arr[length];
}

int max1_cut(int length)
{
	// 排除三个特殊示例
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	// 能够减3的次数
	int count_3 = length / 3;

	// 余数为1时，则少减一次，4=2*2
	if (length % 3 == 1)
		count_3--;

	// 能够除以2的次数
	int count_2 = (length - count_3) / 2;

	int max = pow(3, count_3)*pow(2, count_2);
	return max;
}

int count_1(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = n & (n - 1);
	}
	return count;
}

int main()
{
	//int a[11] = { 2,5,8,8,66,33,2,12,0,56,20 };

	int a[5] = {1,1,1,0,1};
	vector<int> v (a, a + sizeof(a) / sizeof(int));
	//MergeSort(v, 0, v.size()-1);
	//QuickSort(v, 0, v.size() - 1);
	//HeapSort(v);
	int minimun_num = FindMin_Rotate(v);
	cout << minimun_num;
	//for (int i = 0;i < v.size();i++)
		//cout << v[i] << ' ';
	
	

	system("pause");
}

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *par;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
	int L_value;
	ListNode* L_next;
};

void addnownode(ListNode**pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->L_value = value;
	pNew->L_next = NULL;

	if (*pHead = NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->L_next != NULL)
			pNode = pNode->L_next;
		pNode->L_next = pNew;
	}
}

long long Fibonacci(unsigned n)
{
	int result[2] = { 0,1 };
	if (n < 2)
		return result[n];

	long long fibOne = 0;
	long long fibTwo = 1;
	long long fibN = 0;
	for (unsigned int i = 2;i <= n;i++)
	{
		fibN = fibOne + fibTwo;

		fibTwo = fibN;
		fibOne = fibTwo;
	}
	return fibN;
}



