#include<iostream>
using namespace std;

/*�����ô��εķ�������һ��swap����*/
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


/*������*/
template <typename T>
void heapSort(T a[],int n)
{
    // ��������ѣ������һ����Ҷ�ӽڵ����ϣ�
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

    cout<<"�������ݸ�����";
    cin>>n;
    double *a=new double[n];

    cout<<"�����������ݣ�";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    heapSort(a,n);

    cout<<endl<<"��������";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
