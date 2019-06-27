#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

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

int main()
{
	map<int, string> mapStudent;
	map<char, int> first;

	mapStudent.insert(pair<int, string>(1, "student_one"));

	mapStudent.insert(pair<int, string>(2, "student_two"));

	mapStudent.insert(pair<int, string>(3, "student_three"));

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	map<char, std::string> mymap;

	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	map<int, string>::iterator iter;

	//for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		//cout << iter->first << ' ' << iter->second << endl;
	//cout << first[1] << endl;

	system("pause");
	return 0;
}