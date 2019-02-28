// linear.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
	int val;
	Node *left, *right;
	Node() { left = NULL; right = NULL; } //初始化
};

Node* build(Node* root, int val)
{
	if (root == NULL)
	{
		root = new Node();
		root->val = val;
		return root;
	}
	if (val < root->val) root->left = build(root->left, val);
	else if (val > root->val) root->right = build(root->right, val);
	return root;
}

void levelOrder(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node *temp = q.front();


		q.pop();
		cout << temp->val << " ";
		if (temp->left) q.push(temp->left);
		if (temp->right) q.push(temp->right);
	}
}

void preOrder(Node* root)
{
	if (root)
	{
		cout << root->val << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node* root)
{
	if (root)
	{
		inOrder(root->left);
		cout << root->val << " ";
		inOrder(root->right);
	}
}

void postOrder(Node* root)
{
	if (root)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->val << " ";
	}
}

int main()
{
	Node *root = NULL;
	int t[] = { 5,4,6,3,7 };
	for (int i = 0; i < 5; i++) root = build(root, t[i]);
	levelOrder(root);
	cout << ";" << endl;

	preOrder(root);
	cout << ";" << endl;

	inOrder(root);
	cout << ";" << endl;

	postOrder(root);

	system("Pause");
	return 0;
}