#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
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

// LeetCode198打家劫舍
// 动态规划
int rob(vector<int> a,int length)
{
	// 前三个的返回值
	if (length == 0)
		return 0;
	if (length == 1)
		return a[0];
	if (length == 2)
		return(max(a[0], a[1]));

	// 返回值前几个值的初始化
	vector<int> score(length+1,0);
	score[0] = 0;
	score[1] = a[0];
	score[2] = max(a[0], a[1]);

	// 状态方程
	for (int i = 3;i <= length;i++)
		score[i] = max(score[i - 2], score[i - 3]) + a[i - 1];

	return score[length];
}

int main()
{
	//map<int, string> mapStudent;
	//map<char, int> first;

	//mapStudent.insert(pair<int, string>(1, "student_one"));

	//mapStudent.insert(pair<int, string>(2, "student_two"));

	//mapStudent.insert(pair<int, string>(3, "student_three"));

	//first['a'] = 10;
	//first['b'] = 30;
	//first['c'] = 50;
	//first['d'] = 70;

	//map<char, std::string> mymap;

	//mymap['a'] = "an element";
	//mymap['b'] = "another element";
	//mymap['c'] = mymap['b'];

	//std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	//std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	//std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	//std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	//std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	//map<int, string>::iterator iter;

	//for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		//cout << iter->first << ' ' << iter->second << endl;
	//cout << first[1] << endl;

	int myints[] = { 2,7,9,3,1 };
	vector<int> a(myints, myints + sizeof(myints) / sizeof(int));
	int robber = 0;
	robber = rob(a, a.size());
	cout << robber<<endl;
	//cout << a[0] << a[1] << a[2];
	system("pause");
	return 0;
}