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

/*�ݹ鷽ʽ���������(lenth��a�ĳ��ȣ�index�ǽڵ��±�)*/
template <typename T>
void adjust(T *a,int lenth,int index)
{
    int left = 2*index + 1;     // index�����ӽڵ�
    int right = 2*index + 2;    // index�����ӽڵ�

    int maxIdx = index;
    if(left<lenth && a[left] > a[maxIdx])
        maxIdx = left;
    if(right<lenth && a[right] > a[maxIdx])
        maxIdx = right;    //����if���ж������ӽڵ�˭���󣬽���flag

    if(maxIdx != index)
    {
        swap1(a[maxIdx],a[index]);         //�ϴ�ֵ�ϸ�
        adjust(a,lenth,maxIdx);            //�ݹ��½ڵ�
    }
}

/*������*/
template <typename T>
void heapSort(T *a,int n)
{
    // ��������ѣ������һ����Ҷ�ӽڵ����ϣ�
    for(int i=n/2 - 1; i >= 0; i--)   // n/2-1��������Ǹ���Ҷ�ӽڵ�λ��
    {
        adjust(a,n,i);
    }

    // ���������
    for(int i = n-1; i >= 1; i--)
    {
        swap1(a[0],a[i]);         // ����ǰ���ķ��õ�����ĩβ
        adjust(a,i,0);            // ��δ�������Ĳ��ּ������ж�����
    }
}

int main()
{
    int n=0;
    cout<<"�������ݸ�����";
    cin>>n;
    double a[n] = {0};

    cout<<"�����������ݣ�";
    for(int i=0;i<n;i++)
        cin>>a[i];

    heapSort(a,n);
    cout<<endl<<"��������";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
