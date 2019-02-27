#ifndef MATRIX_4_H
#define MATRIX_4_H

#include <iostream>
#include "math.h"
using namespace std;

class Matrix_4x4
{
private:
    double matrix[4][4];
public:
    Matrix_4x4(); //默认构造函数，初始化矩阵为单位阵
    Matrix_4x4(const double (&mat)[4][4]); //用一个4x4的二维数组初始化
    Matrix_4x4(const Matrix_4x4 &mat); //用一个Matrix_4x4的对象初始化
    Matrix_4x4 scale_row(int r, double scalar); //矩阵r行乘以一个系数scalar
    Matrix_4x4 swap_row(int r1, int r2); //交换r1行和r2行
    Matrix_4x4 shear_row(int r1, int r2, double scalar); //将r2行的scalar倍加至r1行

    //重载算术运算符，返回运算结果
    friend Matrix_4x4 operator+ (const Matrix_4x4 &m1, const Matrix_4x4 &m2);
    friend Matrix_4x4 operator- (const Matrix_4x4 &m1, const Matrix_4x4 &m2);
    friend Matrix_4x4 operator* (const Matrix_4x4 &m1, const Matrix_4x4 &m2);
    //Matrix_4x4& operator= (const Matrix_4x4 &m);

    double *const operator[] (const int i){return matrix[i];} //双下标方式访问矩阵元素
    double get_data(int i,int j) const{return matrix[i][j];}  //获取矩阵元素
    //double const& operator() (int i,int j){return matrix[i][j];}

    friend ostream& operator <<(ostream& out_put, const Matrix_4x4 &m);  //重载输出运算符
    friend istream& operator >>(istream& in_put, Matrix_4x4 &m);   //重载输入运算符

    Matrix_4x4 transpose(); //矩阵转置，改变当前矩阵值，并返回转置矩阵
    Matrix_4x4 inverse();   //矩阵求逆，改变当前矩阵值，返回逆矩阵
    double det();
};


#endif // MATRIX_4_SS_H
