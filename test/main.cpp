#include <iostream>
#include <stdlib.h>
using namespace std;
//extern int cnt;
void swap1(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void insert_i(int a[] , int  length)
{
   while (1)
   {
      int parent=(length-1)/2;
      if(a[parent]<a[length])
         {
            swap1(a[parent],a[length]);//值双向交换
            //cnt++;
            length=parent;
         }
      else
            break;
   }
}

void delete_max(int a[],int length)
{
    int tmp=a[0];
    int index=0;

    while(1)
    {
        int left=2*index+1;
        int right=2*index+2;
        if(left>=length)
        {
            break;
        }
        else
        {
            int large=a[left]>a[right]?left:right;
            //cnt++;
            a[index]=a[large];//值单向传递
            index=large;
        }
    }
    a[index]=a[length];
    insert_i(a,index);
    a[length]=tmp;
}

void HeapSort(int a[], int n)
{
    //利用插入建立大顶堆
    for (int i=0;i<n;i++)
    {
        insert_i(a,i);
    }
    for(int i=n-1;i>0;i--)
    {
        delete_max(a,i);
    }
}
/*void set_cnt()
{
    cnt=0;
}
void display_cnt()
{
    cout<<"Compare ="<<cnt<<endl;
    cout<<"==================="<<endl;
}*/
int main()
{   int n=0;

    cout<<"The number of the numbers: ";
    cin>>n;
    int*a=new int[n];
    cout<<"Input numbers: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    HeapSort(a,n);
    cout<<endl<<"Output the result: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    /*
    for(n=100;n<=4000;n+=100)
    {
        int *a=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=rand();
        }
        cout<<"n="<<n;
        set_cnt();
        HeapSort(a,n);
        display_cnt();

        delete[] a;//释放new申请的数组空间
    }*/
    return 0;
}

