// BinaryTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

class BinTree
{
public:
	int data;
	BinTree *leftChild;
	BinTree *rightChild;
	BinTree() { leftChild = NULL;rightChild = NULL; }
};

BinTree *CreateBinTree()
{
	
	int data;
	BinTree *T;
	cin >> data;
	if (data == -1)
		T = NULL;
	else
	{
		T = new BinTree();
		T->data = data;
		T->leftChild = CreateBinTree();
		T->rightChild = CreateBinTree();
	}
	return T;
}

void PreTravel(BinTree* tree)
{
	if (tree)
	{
		cout << tree->data << " ";
		PreTravel(tree->leftChild);
		PreTravel(tree->rightChild);
	}
}

void InTravel(BinTree* tree)
{
	if (tree)
	{
		InTravel(tree->leftChild);
		cout << tree->data << " ";
		InTravel(tree->rightChild);
	}
}

void PostTravel(BinTree* tree)
{
	if (tree)
	{
		PostTravel(tree->leftChild);
		PostTravel(tree->rightChild);
		cout << tree->data << " ";
	}
}


int main()
{
	BinTree *tree = NULL;

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

	system("pause");
	return 0;
}


