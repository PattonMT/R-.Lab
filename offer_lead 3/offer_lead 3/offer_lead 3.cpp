#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>
#include <assert.h>
#include <queue>
using namespace std;

// 二叉树的镜像
//// 树的申明
struct BinaryTree
{
	int b_value;
	BinaryTree* b_left;
	BinaryTree* b_right;
};

//// 函数
void MirrorBinTree(BinaryTree* pNode)
{
	if (pNode == nullptr)
		return;
	if (pNode->b_left == nullptr&&pNode->b_right == nullptr)
		return;
	
	BinaryTree* pTemp = pNode->b_left;
	pNode->b_left = pNode->b_right;
	pNode->b_right = pTemp;

	if (pNode->b_left)
		MirrorBinTree(pNode->b_left);
	if (pNode->b_right)
		MirrorBinTree(pNode->b_right);
}

// 对称二叉树
//// 初次输入时两个root相同
bool isSym(BinaryTree* root1, BinaryTree* root2)
{
	if (root1 ==nullptr&& root2==nullptr)
		return true;
	if (root1 == nullptr|| root2 == nullptr)
		return false;

	if (root1->b_value != root2->b_value)
		return false;

	return isSym(root1->b_left, root2->b_right) && isSym(root1->b_right, root1->b_left);
}

bool isPopOrder(const vector<int> pPush, const vector<int> pPop)
{
	if (pPush.size() != pPop.size())
		return false;
	stack<int> stc;
	for (int i = 0, j = 0;i < pPush.size();i++)
	{
		stc.push(pPush[i]);
		while (j<pPop.size()&&stc.top()==pPop[j])
		{
			stc.pop();
			j++;
		}
	}
	return stc.empty();  // 通过判断栈是否为空，来判断是否是输出
}

void PrintZigZag(BinaryTree* pRoot)
{
	if (pRoot == nullptr)
		return;
	
	queue<BinaryTree*> q[2];
	q[0].push(pRoot);
	int order = 0; // 标志在奇数层还是偶数层

	while (!q[0].empty()||!q[2].empty())
	{
		BinaryTree* print_one = q[order].front();
		q[order].pop();

		cout << print_one->b_value << ' ';
		
		// level范围是{0，1，2....}
		// oorder标准{0，1，0，1....}
		// 偶数行为自右向左压；奇数行自左向右压
		if (order == 0)
		{
			if (print_one->b_right)
				q[0].push(print_one->b_right);

			if (print_one->b_left)
				q[0].push(print_one->b_left);
		}
		else
		{

			if (print_one->b_left)
				q[1].push(print_one->b_left);

			if (print_one->b_right)
				q[1].push(print_one->b_right);
		}
		
		if (q[order].empty())
		{
			cout << '\n';
			order = 1 - order;
		}
	}
}

bool sequenceofBST(int sequence[],int length)
{
	if (sequence==nullptr)
		return false;

	int root = sequence[length - 1];

	int i = 0;
	int j = 0;
	// 找左子树
	for (i = 0;i < length - 1;i++)
	{
		if (sequence[i] > root)
			break;
	}
	// 右子树都大于root
	for (j = i;j < length - 1;j--)
	{
		if (sequence[j] < root)
			return false;
	}

	// 判断左子树是否为BTS
	bool left = false;
	left = sequenceofBST(sequence, i);

	// 判断右子树是否为BFS
	bool right = false;
	right = sequenceofBST(sequence + i, length - 1 - i);

	return (right&&left);
}



void FindPath(BinaryTree* a, int Sum, vector<int> & path, int currentSum)
{
	currentSum += a->b_value;
	path.push_back(a->b_value);

	// 判断是否是叶节点，是否和相同
	bool ifLeaf = a->b_left == nullptr&&a->b_right == nullptr;
	if (currentSum == Sum && ifLeaf)
	{
		cout << "A path is found \n";
		vector<int>::iterator it = path.begin();
		for (;it != path.end();it++)
			cout << *it << ' ';
	}

	// 若不是叶节点，遍历子节点
	if (a->b_left != nullptr)
		FindPath(a, Sum, path, currentSum);
	if (a->b_right != nullptr)
		FindPath(a, Sum, path, currentSum);

	// 每次都肯定会返回父节点，则要弹出最后一位
	path.pop_back();
}

struct complexListNode
{
	int p_value;
	complexListNode* p_next;
	complexListNode* p_sibiling;
};

// 复制链表，插空连接
void CloneNodes(complexListNode* pHead)
{
	complexListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		complexListNode* pCloned = new complexListNode();
		pCloned->p_value = pNode->p_value;
		pCloned->p_next = pNode->p_next;
		pCloned->p_sibiling = nullptr;

		pNode->p_next = pCloned;

		pNode = pCloned->p_next;
	}
}

// 设置p_sibiling
void connectSibilingNodes(complexListNode* pHead)
{
	complexListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		complexListNode* pCloned = pNode->p_next;
		if (pNode->p_sibiling != nullptr)
			pCloned->p_sibiling = pNode->p_sibiling->p_next;

		pNode = pCloned->p_next;
	}
}

// 把长链表分成两个链表，奇数偶数
complexListNode* ReconectedNodes(complexListNode* pHead)
{
	complexListNode* pNode = pHead;
	complexListNode* pClondeHead = nullptr;
	complexListNode* pClonedNode = nullptr;

	// 构建克隆链表的链表头
	if (pNode!=nullptr)
	{
		pClondeHead = pClonedNode = pNode->p_next;
		pNode->p_next = pClonedNode->p_next;
		pNode = pNode->p_next;
	}

	// 循环分开两个链表
	while (pNode!=nullptr)
	{
		pClonedNode->p_next = pNode->p_next;
		pClonedNode = pClonedNode->p_next;
		pNode->p_next = pClonedNode->p_next;
		pNode = pNode->p_next;
	}
	return pClonedNode;
}

void insert_p(vector<int> &a, int p)
{
	while (p > 0)
	{
		int parent = (p - 1) / 2;
		if(a[parent] > a[p])
		//if (a[parent] < a[p])
		{
			swap(a[parent], a[p]);
			p = parent;
		}
		else break;
	}
}

void delete_min(vector<int> &a, int length)
{
	int tmp = a[0];
	int index = 0;

	// 找出最大的
	// large指向已遍历的最大值
	// index指向当前空缺位置
	while (1)
	{
		int left = 2 * index + 1;
		int right = 2 * index + 2;

		if (left >= length)
			break;
		else
		{
			int small = a[left] > a[right] ? right : left;
			a[index] = a[small];
			index = small;
		}
	}
	a[index] = a[length];
	a[length] = tmp;

}

void HeapSort(vector<int> &a)
{
	for (int i = 0;i < a.size();i++)
		insert_p(a, i);
	for (int i = a.size() - 1;i > a.size() - 4;i--)
		delete_min(a, i);
}

// 将二叉搜索树转化为排序双向链表
BinaryTree* Convert(BinaryTree* pOrigin)
{
	BinaryTree*pLastNode = nullptr;
	ConvertNode(pOrigin, &pLastNode);
}

void ConvertNode(BinaryTree* pNode, BinaryTree**pLastNode)
{
	if (pNode == nullptr)
		return;

	BinaryTree* pCurrent = pNode;

	if (pCurrent->b_left != nullptr)
		ConvertNode(pCurrent->b_left, pLastNode);
	// 将当前值左（前）指向lastnode
	// lastnode 的右（后）指向当前值
	pCurrent->b_left = *pLastNode;
	if (pLastNode != nullptr)
		(*pLastNode)->b_right = pCurrent;
	// 将last指向当前值
	*pLastNode = pCurrent;

	if (pCurrent->b_right != nullptr)
		ConvertNode(pCurrent->b_right, pLastNode);
}

void Permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
		cout << pStr << endl;
	else
	{
		for (char* pCh = pBegin;*pCh != '\0';pCh++)
		{
			// 列出所有可能的头部
			// 通过将第一个与后面的顺次交换
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			// 定好第一个数，在递归进行下一个数的确定
			Permutation(pStr, pBegin + 1);

			// 恢复成初始的字符状态
			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

		}
	}
}

// 序列化二叉树
void Series(BinaryTree* pRoot, ostream & stream)
{
	if (pRoot == nullptr)
	{
		stream << "$,";
		return;
	}
	stream << pRoot->b_value << ',';
	Series(pRoot->b_left, stream);
	Series(pRoot->b_right, stream);
}


int main()
{
	int myints[] = {7,15,9,2,16,45,6,7,32 };
	vector<int> v(myints, myints + 9);
	HeapSort(v);
	for (int i = v.size()-1;i > v.size() - 4;i--)
		cout << v[i] << " ";
	cout << endl;
	
	// cout << "Hello World!\n"; 
	system("pause");
}

