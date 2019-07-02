#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct BinTreeNode
{
	int b_value;
	BinTreeNode* b_left;
	BinTreeNode* b_right;
};

int morthanHalf(vector<int> a, int length)
{
	int result = a[0];
	int time = 1;
	for (int i = 1;i < length;i++)
	{
		if (time == 0)
		{
			result = a[i];
			time = 1;
		}
		else if (result == a[i])
			time++;
		else
			time--;
	}
	return result;
}

int MaxSum(vector<int> num, int length)
{
	int pre = num[0];
	int cur = 0;
	int max = pre;
	for (int i = 1;i < length;i++)
	{
		if (pre > 0)
			cur = pre + num[i];
		else
			cur = num[i];

		if (cur > max)
			max = cur;

		pre = cur;
	}
	return max;
}

template<typename T> class DynamicArray
{
public:
	// 将树插入--类似于堆的建立
	// 规则：总数偶数时插入min
	void Insert(T num)
	{
		if ((min.size() + max.size()) & 1 == 0)//若为偶数
		{
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());

			num = max[0];

			pop_heap(max.begin(), max.end(), less<T>());
			max.pop_back();

			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<T>());
		}
		else
		{
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<T>());

			num = min[0];

			pop_heap(min.begin(), min.end(), greater<T>());
			min.pop_back();

			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());
		}
	}

	T getMedian()
	{
		int size = max.size() + min.size();
		T median = 0;
		if (size & 1 == 0)
			median = min[0];
		else
			median = (min[0] + max[0]) / 2;

		return median;
	}

private:
	vector<T> min;
	vector<T> max;
};

int numof1between1andn(int n)
{
	if (n < 1)
		return 0;

	int num = 0;
	int base = 1;
	int round = n;
	while (round != 0)
	{
		int left = round % 10;
		round = round / 10;

		num += round * base;
		if (left == 1)
			num += (n%base) + 1;
		else if (left > 1)
			num += base;
	}
	return num;
}

char FirstNotRepeating(char* pString)
{
	if (pString == nullptr)
		return '\0';

	const int tablesize = 256;
	unsigned int hashtable[tablesize];
	for (unsigned int i = 0;i < tablesize;i++)
		hashtable[i] = 0;

	char* pHshaKey = pString;
	while (*(pHshaKey) != '\0')
		hashtable[*(pHshaKey++)]++;

	pHshaKey = pString;
	while (*pHshaKey != '\0')
	{
		if (hashtable[*pHshaKey] == 1)
			return *pHshaKey;

		pHshaKey++;
	}
}
// 二叉树的深度
int depth(BinTreeNode* root)
{
	if (root == nullptr)
		return 0;

	int Rleft = depth(root->b_left);
	int Rright = depth(root->b_right);

	return max(Rleft+1, Rright+1);
}

int main()
{
	int myints[] = { 1,-2,3,10,-4,7,2,-5 };
	vector<int> v(myints, myints + 8);
	int a=MaxSum(v, 8);
	cout << a <<endl;
	system("pause");
	return 0;
}
