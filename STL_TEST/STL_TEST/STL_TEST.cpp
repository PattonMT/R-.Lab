// STL_TEST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cstdio>      /* printf, scanf, NULL */
#include <cstdlib>     /* malloc, free, rand */
#include <deque>
using namespace std;
int a[2000][2000];

class Node
{
public: 
	int val;
	Node *left;
	Node *right;
	Node() { left = NULL;right = NULL; }
};

void Quicksort(vector<int> &a, int left, int right)
{
	int i = left;
	int j = right;
	int begin = a[left];

	while (i <= j)
	{
		while (a[i] < a[left]) i++;
		while (a[j] > a[right]) j--;
		if (i < j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	
	if (i < right) Quicksort(a, i, right);
	if (j > left) Quicksort(a, left, j);
}

Node *createTree()
{
	int data;
	Node *T;
	cin >> data;
	if (data == -1)
		T = NULL;
	else
	{
		T = new Node();
		T->val= data;
		T->left = createTree();
		T->right = createTree();
	}
	return T;
}

void PreTree(Node* tree,vector<int> result)
{
	if (tree)
	{
		result.push_back(tree->val);
		PreTree(tree->left,result);
		PreTree(tree->right,result);
	}
}

void LevelTree(Node* tree, vector<int> result)
{
	queue<Node*> q;
	Node* temp;
	q.push(tree);

	while (!q.empty())
	{
		temp = q.front();
		result.push_back(temp->val);
		q.pop();
		if (tree->left) q.push(tree->left);
		if (tree->right) q.push(tree->right);
	}
}

int main()
{
	vector<int>::iterator it;
	vector<vector<int> > matrix(3, vector<int>(3,0));
	/*int M = 3;
	int N = 3;
	int **matrix = new int*[M];
	int *buffer = new int[M*N];
	for (int i = 0;i < M;i++)
		matrix[i] = buffer + i * N;*/

	int array[] = { 10,21,6,15,98,13,7};
	vector<int> aj(array,array+sizeof(array)/sizeof(int));
	
	char s[10] = "abcdefg";
	cout << (void*)&matrix[0][0] << " " << (void*)&matrix[0][1] << " " << (void*)&matrix[0][2] << endl;
	cout << (void*)&matrix[1][0] << " " << (void*)&matrix[1][1] << " " << (void*)&matrix[1][2] << endl;
	cout << (void*)&matrix[2][0] << " " << (void*)&matrix[2][1] << " " << (void*)&matrix[2][2] << endl;
	//Quicksort(aj,0, sizeof(array) / sizeof(int)-1);
	
	/*for (it = aj.begin();it != aj.end();it++)
		cout << *it << " ";
	cout <<endl;*/

//测试next_permutation
	/*int myints[] = {1,2,3,4};
	sort(myints, myints + 4);
	cout << "the 3! possible permutation with 3 elements\n";
	do {
		cout << myints[0] << " " << myints[1]<<" " << myints[2] <<" "<< myints[3]<<'\n';
	} while (next_permutation(myints, myints + 4));
	cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] <<" "<< myints[3] << '\n';*/

//* malloc example: random string generator*/
		/*int i, n;
		char * buffer;

		printf("How long do you want the string? ");
		cin>>i;

		buffer = (char*)malloc(i + 1);
		if (buffer == NULL) exit(1);

		for (n = 0; n < i; n++)
			buffer[n] = rand() % 26 + 'a';
		buffer[i] = '\0';

		cout << "Random string:" << buffer;
		free(buffer);*/

	
	system("pause");
	return 0;
}

