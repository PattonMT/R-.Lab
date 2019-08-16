
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		// 输入
		string a, b, result;
		char temp;
		if (s.size() == 0)
			break;
		unsigned int f = s.find('@');
		a = s.substr(0, f);
		b = s.substr(f + 1);
		//cout << a << "@@" << b << endl;
		if (b.size() == 0)
			cout << a << "@" << endl;
		else
		{
			while (!b.empty())
			{
				// 找第一个逗号
				unsigned int pointa = a.find(',');
				unsigned int pointb = b.find(',');
				if (pointb == -1) // 若b是最后一段
				{
					unsigned int endhead = a.find(b[0]);
					result += a.substr(0, endhead);
					a.erase(0, endhead);
					pointa = a.find(',');
					if (pointa == -1)
					{
						char firsttemp = b[0];
						b.erase(0, b.find(':') + 1);
						a.erase(0, a.find(':') + 1);

						int x = atoi(a.substr(0).c_str()) - atoi(b.substr(0).c_str());
						temp = x + 48;
						result = result + firsttemp + ':' + temp;
					}
					else
					{
						string ahead = a.substr(0, pointa);
						ahead.erase(0, ahead.find(':') + 1);
						b.erase(0, b.find(':') + 1);
						int x = atoi(ahead.substr(0).c_str()) - atoi(b.substr(0).c_str());
						temp = x + 48;
						result = result + a[0] + ':' + temp + ',';
						a.erase(0, pointa + 1);
						result += a;
					}
					b.clear();
				}
				else
				{
					string ahead = a.substr(0, pointa);
					string bhead = b.substr(0, pointa);
					//cout << ahead << " and " << bhead << endl;
					if (ahead[0] == bhead[0])
					{
						ahead.erase(0, ahead.find(':') + 1);
						bhead.erase(0, bhead.find(':') + 1);
						int x = atoi(ahead.substr(0).c_str()) - atoi(bhead.substr(0).c_str());
						temp = x + 48;
						//cout << temp << endl;
						result = result + b[0] + ':' + temp + ',';
						a.erase(0, pointa + 1);
						b.erase(0, pointb + 1);
					}
					else
					{
						result += a.substr(0, pointa + 1);
						a.erase(0, pointa + 1);
					}
				}
			}
			cout << result << endl;
		}
	}
	system("pause");
	return 0;
}

