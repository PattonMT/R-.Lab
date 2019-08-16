// temple.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int decrease_num = 0;
	int over_all = 0;
	int temp;
	int result;

	vector<vector<int> > a(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
			decrease_num = decrease_num + a[i][j] - 1;
			over_all += a[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			temp = min(a[i][j],a[i][j - 1]);
			decrease_num += temp;
		}
	}


	for (int j = 0; j < M; j++)
	{
		for (int i = 1; i < N; i++)
		{
			temp = min(a[i][j] , a[i - 1][j]);
			decrease_num += temp;
		}
	}

	result = over_all * 6 - decrease_num * 2;
	cout << result;

	system("pause");
	return 0;
}

