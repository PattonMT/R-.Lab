// HuaWei_char_identify.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <cstdio>
#include <iostream>
//#include <cstring>
//#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

//const int MAXN = 150;
//char s[MAXN];
string s;
char opset[6] = { '!','&','|','(',')','#' };
char prio[6][6] =
{
	'>', '>', '>', '<', '>', '>',
	'<', '>', '>', '<', '>', '>',
	'<', '<', '>', '<', '>', '>',
	'<', '<', '<', '<', '=', '>',
	'>', '>', '>', '<', '>', '>',
	'<', '<', '<', '<', '>', '=',
};

// 找到对应运算符在 opset 数组的下标
int findindex(char op)
{
	for (int i = 0; i < 6; i++)
	{
		if (opset[i] == op)
			return i;
	}
}

// 比较两个字符大小
char compare(char a, char b)
{
	int x = findindex(a);
	int y = findindex(b);
	return prio[x][y];
}

// 计算与或值
int calc(int x, int y, char op)
{
	if (op == '|')
		return x | y;
	if (op == '&')
		return x & y;
	return 0;
}

int main()
{
	while (getline(cin,s))
	{
		int lens = s.length();
		s.push_back('#');   // s 数组尾部存为'#'
		//s[lens + 1] = '\0';
		int t, x, y;
		char op;
		int i = 0;
		stack<int>P;  // 用于存储运算数，整数元素
		stack<char>Q;  // 用于存储运算符号，字符元素

		Q.push('#');  // 把栈底存为 '#'

		while (s[i] != '#' || Q.top() != '#')
		{
			// 当s数组读到末尾，且Q已经读到栈底，说明全部运算结束
			if (s[i] == '1' || s[i] == '0')
			{
				if (s[i] == '1')
					t = 1;
				else
					t = 0;
				P.push(t);
				i++;
			}
			else
			{
				switch (compare(Q.top(), s[i]))
				{
				case '<':  // 栈顶元素优先级低，则当前元素入栈
					Q.push(s[i]);
					i++;
					break;
				case '=': // 左右括号匹配，脱括号并接收下一字符
					Q.pop();
					i++;
					break;
				case '>':  // 退栈并将运算结果入栈
					if (Q.top() == '!')
					{   // 栈顶元素为 ！，单目操作符
						x = P.top();
						P.pop();
						P.push(!x);
						Q.pop();
					}
					else
					{   // 栈顶元素不是 ！
						x = P.top();
						P.pop();
						y = P.top();
						P.pop();
						op = Q.top();
						Q.pop();    //计算结果并入栈
						P.push(calc(x, y, op));
					}
					break;
				}
			}
		}

		int ans = P.top();
		cout << ans << endl;
		system("pause");
	}
	return 0;
}