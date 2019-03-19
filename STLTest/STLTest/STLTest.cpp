// STLTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// transform algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus
#include "pch.h"
using namespace std;

int op_increase(int i) { return ++i; }

int main() {
	vector<int> foo;
	vector<int> bar;

	// set some values:
	for (int i = 1; i < 6; i++)
		foo.push_back(i * 10);                         // foo: 10 20 30 40 50

	bar.resize(foo.size());                         // allocate space

	transform(foo.begin(), foo.end(), bar.begin(), op_increase);
	// bar: 11 21 31 41 51

// std::plus adds together its two arguments:
    transform(foo.begin(), foo.end(), bar.begin(), foo.begin(), plus<int>());
	// foo: 21 41 61 81 101

	cout << "foo contains:";
	for (vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	return 0;
}