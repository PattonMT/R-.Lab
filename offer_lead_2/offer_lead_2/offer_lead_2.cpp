
#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int pow_test(int m, int n)
{
	int sum = 1;
	int temp = m;
	while (n)
	{
		if (n & 1 == 1)
			sum *= temp;

		n=n >> 1;
		temp *= temp;
	}
	return sum ;
}

double pow_try(double m, int n)
{
	if (n == 0)
		return 1.0;
	if (n == 1)
		return m;

	double base = pow_try(m,n>>1);
	base *= base;
	
	if (n & 1 == 1)
		base *= m;

	return base;	
}


struct ListNode
{
	int n_value;
	ListNode* n_next;
};

struct BinaryTree
{
	int p_value;
	BinaryTree* p_left;
	BinaryTree* p_right;
};

void deleteDuplication(ListNode** pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pPre = nullptr;
	ListNode* pCur = *pHead;

	while (pCur != nullptr)
	{
		ListNode* pNex = pCur->n_next;
		bool needDelete = false;
		if (pNex != nullptr&&pCur->n_value == pNex->n_value)
			needDelete = true;

		if (!needDelete)
		{
			pPre = pCur;
			pCur = pNex;
		}
		else
		{
			int value = pCur->n_value;
			ListNode* pTobeDel = pCur;
			while (pTobeDel != nullptr&&pTobeDel->n_value == value)
			{
				pNex = pTobeDel->n_next;

				delete pTobeDel;
				pTobeDel = nullptr;

				pTobeDel = pNex;
			}

			// 若指针头就是重复，且被删除，后面无后续数字，则
			if (pPre == nullptr)
				*pHead = pNex;
			else
				pPre->n_next = pNex;
			pCur = pNex;
		}
		
	}
}

bool a_include_b(BinaryTree* father, BinaryTree* son)
{
	if (son == nullptr)
		return true;
	if (father == nullptr)
		return false;
	if (father->p_value != son->p_value)
		return false;

	return a_include_b(father->p_left, son->p_left) && a_include_b(father->p_right, son->p_right);
}

bool SonTree(BinaryTree* father, BinaryTree* son)
{
	bool result = false;
	if (father != nullptr &&son != nullptr)
	{
		if (father->p_value == son->p_value)
			result = a_include_b(father, son);

		if (!result)
			result = SonTree(father->p_left, son);

		if(!result)
			result = SonTree(father->p_right, son);
	}
	return result;
}



// 奇数在前，偶数在后
void swap1_0(vector<int> &a)
{
	//int tmp = a[0];
	int i = 0;
	int j = a.size() - 1;
	while (i <= j)
	{
		//cout << ((a[i] & 1) == 1) << ' ' << ((a[j] & 1) == 0) << '\n';
		while ((a[i] & 1) == 1) { i++; }
		while ((a[j] & 1) == 0) { j--; }

		if (i <= j)
		{
			swap(a[i], a[j]);
			cout << "i is " << a[i] << ' ' << "j is " << a[j] << "\n";
			i++;
			j--;
		}
	}	
}

ListNode* FindKthNode(ListNode*pListHead, int k)
{
	if (pListHead == NULL || k == 0)
		return NULL;
	
	ListNode* ANode = pListHead;
	ListNode* BNode = ANode;

	for (int i = 0;i < k - 1;i++)
		ANode = ANode->n_next;

	while (ANode->n_next)
	{
		ANode = ANode->n_next;
		BNode = BNode->n_next;
	}
	return BNode;
}

ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pre;
	ListNode* curr;
	ListNode* follow;

	pre = pHead;
	curr = pHead->n_next;
	follow = curr->n_next;

	pHead->n_next = NULL;
	while (follow!=NULL)
	{
		curr->n_next = pre;
		pre = curr;
		curr = follow;
		follow = follow->n_next;
	}
	curr->n_next = pre;
}

ListNode*Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;

	ListNode* MergedHead = NULL;
	if (pHead1->n_next < pHead2->n_next)
	{
		MergedHead = pHead1;
		MergedHead->n_next = Merge(pHead1->n_next,pHead2);
	}
	else
	{
		MergedHead = pHead2;
		MergedHead->n_next = Merge(pHead1,pHead2->n_next);
	}
	return MergedHead;
}

int main()
{
	int sum;
	int arr[] = { 2,4,6,8,10,2,1,9,15,6 };
	vector<int> a(arr, arr + 9);
	//sum = pow_try(3, 3);
	swap1_0(a);
	for (int i = 0;i < a.size();i++)
	{
		cout << a[i] << ' ';
	}
	//cout <<"hugo"<<sum;
	system("pause");
}

