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

template <typename T>
void insert_i(T a[], int length)
{
    while (length>0)
    {
        int parent=(length-1)/2;

        if (a[parent]<a[length])
        {
            swap1(a[parent],a[length]);
            length=parent;
        }
        else
            break;
    }
}

template <typename T>
void delete_max(T a[], int length)
{
    T tmp=a[0];
    int ind=0;

    while(1)
    {
        int left = 2*ind + 1;
        int right = 2*ind + 2;

        if(left>=length)
        {
            break;
        }
        else
        {
            int large=a[left]>a[right] ? left : right;
            a[ind]=a[large];
            ind=large;
        }
    }

    a[ind]=a[length];
    a[length]=tmp;
}


/*堆排序*/
template <typename T>
void heapSort(T a[],int n)
{
    // 构建大根堆（从最后一个非叶子节点向上）
    for (int i=0;i<n;i++)
    {
        insert_i(a,i);
    }

    cout<<"0 : ";
    for(int k=0;k<n;k++)
        cout<<a[k]<<" ";
    cout<<endl;

    for (int i=n-1;i>0;i--)
    {
        delete_max(a,i);

        cout<<n-i<<" : ";
        for (int k=0;k<n;k++)
            cout<<a[k]<<" ";
        cout<<endl;
    }
}

int main()
{
    int n=0;

    cout<<"排序数据个数：";
    cin>>n;
    double *a=new double[n];

    cout<<"输入排序数据：";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    heapSort(a,n);

    cout<<endl<<"排序结果：";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
