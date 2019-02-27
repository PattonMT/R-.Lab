#include<iostream>
#include"Matrix4.h"

using namespace std;

int main()
{
    //double m[4][4]={{1,0,0,0},{1,2,0,0},{2,1,3,0},{1,2,1,4}};
    double m[4][4]={{0,2,0,1},{3,3,2,1},{3,2,4,0},{2,2,1,1}};
    //double m[4][4]={{1,1,2,2},{2,2,3,3},{2,1,3,4},{5,3,1,2}};
    Matrix_4x4 a;
    cout<<"a : "<<a<<endl;

    Matrix_4x4 b(m);
    cout<<"b(m) : "<<b<<endl;

    Matrix_4x4 c(b);
    cout<<"c(b) : "<<c<<endl;

    Matrix_4x4 d;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
            d[i][j]=-i*4-j;
    }
    cout<<"d : "<<d<<endl;


    d=a+c;
    cout<<"d=a+c : "<<d<<endl;

    d=d-a;
    cout<<"d=d-a : "<<d<<endl;

    d=c.transpose();
    cout<<"d=c.transpose() : "<<d<<endl<<"c : "<<c.transpose()<<endl;

    d=c.inverse();
    cout<<"c.inverse "<<d<<endl;

    d=b*d;
    cout<<"d=c*c.inverse "<<d<<endl;

    double determinant=b.det();
    cout<<endl<<"b.det()= "<<determinant<<endl;

    return 0;
}

