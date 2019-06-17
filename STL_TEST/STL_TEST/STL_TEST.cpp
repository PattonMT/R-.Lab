// STL_TEST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
//#include <bits.h>
using namespace std;

void QuickSort(vector<int> &a,int left,int right)
{
	int i = left;
	int j = right;
	int first = a[i];
	while (i <= j)
	{
		while (a[i] < first) { i++;}
		while (a[j] > first) { j--;}

		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (j > left) QuickSort(a, left, j);
	if (i < right) QuickSort(a, i, right);
}

y_clipped = tf.clip_by_value(y_, 1e-10, 0.9999999)
cross_entropy = -tf.reduce_mean(tf.reduce_sum(y * tf.log(y_clipped) + (1 - y) * tf.log(1 - y_clipped), axis=1))

#define eps 1e-8
int main()
{


	int ans;
	ans = (int)pow(8, 1.0 / 3);
	cout << ans << " ";
	ans = (int)pow(8, 1.0 / 3 + eps);
	cout << ans <<endl;
	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
