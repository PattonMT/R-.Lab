// BinaryTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
//创建节点类，包含数值和左右孩子
class BinTree
{
public:
	int data;
	BinTree *leftChild;
	BinTree *rightChild;
	BinTree() { leftChild = NULL; rightChild = NULL; }
};
//通过递归构建二叉树
BinTree *CreateBinTree()
{
	
	int data;
	BinTree *T;
	cin >> data;
	if (data == -1)
		T = NULL;
	else
	{
		T = new BinTree();//初始化
		T->data = data;
		T->leftChild = CreateBinTree();
		T->rightChild = CreateBinTree();
	}
	return T;
}
//前序遍历
void PreTravel(BinTree* tree)
{
	if (tree)
	{
		cout << tree->data << " ";
		PreTravel(tree->leftChild);
		PreTravel(tree->rightChild);
	}
}
//中序遍历
void InTravel(BinTree* tree)
{
	if (tree)
	{
		InTravel(tree->leftChild);
		cout << tree->data << " ";
		InTravel(tree->rightChild);
	}
}

//后序遍历
void PostTravel(BinTree* tree)
{
	if (tree)
	{
		PostTravel(tree->leftChild);
		PostTravel(tree->rightChild);
		cout << tree->data << " ";
	}
}

void LevelTravel(BinTree* tree)
{
	queue<BinTree*> q;
	q.push(tree);
	
	while (!q.empty())
	{
		//cout << q.size() <<"& "<<endl;
		BinTree *temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if (temp->leftChild) q.push(temp->leftChild);
		if (temp->rightChild) q.push(temp->rightChild);
	}
}

void InsertTree(BinTree* &tree, int data)
{
	if (tree == NULL)
	{
		tree = new BinTree();
		tree->data = data;
	}
	else if(tree->data>data)
	{
		InsertTree(tree->leftChild, data);
	}
	else if (tree->data < data)
	{
		InsertTree(tree->rightChild, data);
	}
}

void RemoveTree(BinTree* &tree, int data)
{
	if (tree - NULL) return;
	if (tree->data > data) { RemoveTree(tree->leftChild, data); }
	else if (tree->data < data) { RemoveTree(tree->rightChild, data);}
	else
	{
		//BinTree *node = tree;
		tree = (tree->leftChild) ? tree->leftChild : tree->rightChild;
	}
}

int main()
{
	BinTree *tree = NULL;
/*
	cout << "Please input a tree with PreOrder,use -1 as NULL" << endl;
	tree = CreateBinTree();
	
	cout << "PreOrder Traversal" << endl;
	PreTravel(tree);
	cout << " " << endl;

	cout << "InOrder Traversal" << endl;
	InTravel(tree);
	cout << " " << endl;

	cout << "PostOrder Traversal" << endl;
	PostTravel(tree);
	cout << " " << endl;

	cout << "LevelOrder Traversal" << endl;
	LevelTravel(tree);
	cout << " " << endl;
*/
	int a;
	for (int i=0;i < 6;i++)
	{
		cout << "Input a node" << endl;
		cin >> a;
		InsertTree(tree, a);
	}

	cout << "LevelOrder Traversal" << endl;
	LevelTravel(tree);
	cout << " " << endl;

	system("pause");
	return 0;
}


