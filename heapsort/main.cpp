#include<iostream>
using namespace std;

/*用引用传参的方法定义一个swap函数*/
template <typename T>
void swap1(T &a,T &b)
{
    T tmp;
    tmp=a;
    a=b;
    b=tmp;
}

/*递归方式构建大根堆(lenth是a的长度，index是节点下标)*/
template <typename T>
void adjust(T *a,int lenth,int index)
{
    int left = 2*index + 1;     // index的左子节点
    int right = 2*index + 2;    // index的右子节点

    int maxIdx = index;
    if(left<lenth && a[left] > a[maxIdx])
        maxIdx = left;
    if(right<lenth && a[right] > a[maxIdx])
        maxIdx = right;    //两个if，判断左右子节点谁更大，交换flag

    if(maxIdx != index)
    {
        swap1(a[maxIdx],a[index]);         //较大值上浮
        adjust(a,lenth,maxIdx);            //递归新节点
    }
}

/*堆排序*/
template <typename T>
void heapSort(T *a,int n)
{
    // 构建大根堆（从最后一个非叶子节点向上）
    for(int i=n/2 - 1; i >= 0; i--)   // n/2-1就是最后那个非叶子节点位置
    {
        adjust(a,n,i);
    }

    // 调整大根堆
    for(int i = n-1; i >= 1; i--)
    {
        swap1(a[0],a[i]);         // 将当前最大的放置到数组末尾
        adjust(a,i,0);            // 将未完成排序的部分继续进行堆排序
    }
}

int main()
{
    int n=0;
    cout<<"排序数据个数：";
    cin>>n;
    double a[n] = {0};

    cout<<"输入排序数据：";
    for(int i=0;i<n;i++)
        cin>>a[i];

    heapSort(a,n);
    cout<<endl<<"排序结果：";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
