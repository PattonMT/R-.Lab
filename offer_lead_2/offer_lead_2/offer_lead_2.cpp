
#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int pow_test(int m, int n)
{
	int sum = 1;
	int temp = m;
	while (n)
	{
		if (n & 1 == 1)
			sum *= temp;

		n=n >> 1;
		temp *= temp;
	}
	return sum ;
}

double pow_try(double m, int n)
{
	if (n == 0)
		return 1.0;
	if (n == 1)
		return m;

	double base = pow_try(m,n>>1);
	base *= base;
	
	if (n & 1 == 1)
		base *= m;

	return base;	
}

void printTo_n(int n)
{
	if (n <= 0)
		return;
	// 初始化字符串
	char* number = new char[n + 1];
	memset(number, '9', n);
	number[n] = '\0';

	

}

struct ListNode
{
	int n_value;
	ListNode* n_next;
};

void swap1_0(vector<int> &a)
{
	//int tmp = a[0];
	int i = 0;
	int j = a.size() - 1;
	while (i <= j)
	{
		//cout << ((a[i] & 1) == 1) << ' ' << ((a[j] & 1) == 0) << '\n';
		while ((a[i] & 1) == 1) { i++; }
		while ((a[j] & 1) == 0) { j--; }

		if (i <= j)
		{
			swap(a[i], a[j]);
			cout << "i is " << a[i] << ' ' << "j is " << a[j] << "\n";
			i++;
			j--;
		}
	}	
}
int main()
{
	int sum;
	int arr[] = { 2,4,6,8,10,2,1,9,15,6 };
	vector<int> a(arr, arr + 9);
	//sum = pow_try(3, 3);
	swap1_0(a);
	for (int i = 0;i < a.size();i++)
	{
		cout << a[i] << ' ';
	}
	//cout <<"hugo"<<sum;
	system("pause");
}

