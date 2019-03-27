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
    Matrix_4x4(); //Ĭ�Ϲ��캯������ʼ������Ϊ��λ��
    Matrix_4x4(const double (&mat)[4][4]); //��һ��4x4�Ķ�ά�����ʼ��
    Matrix_4x4(const Matrix_4x4 &mat); //��һ��Matrix_4x4�Ķ����ʼ��
    Matrix_4x4 scale_row(int r, double scalar); //����r�г���һ��ϵ��scalar
    Matrix_4x4 swap_row(int r1, int r2); //����r1�к�r2��
    Matrix_4x4 shear_row(int r1, int r2, double scalar); //��r2�е�scalar������r1��

    //�������������������������
    friend Matrix_4x4 operator+ (const Matrix_4x4 &m1, const Matrix_4x4 &m2);
    friend Matrix_4x4 operator- (const Matrix_4x4 &m1, const Matrix_4x4 &m2);
    friend Matrix_4x4 operator* (const Matrix_4x4 &m1, const Matrix_4x4 &m2);
    //Matrix_4x4& operator= (const Matrix_4x4 &m);

    double *const operator[] (const int i){return matrix[i];} //˫�±귽ʽ���ʾ���Ԫ��
    double get_data(int i,int j) const{return matrix[i][j];}  //��ȡ����Ԫ��
    //double const& operator() (int i,int j){return matrix[i][j];}

    friend ostream& operator <<(ostream& out_put, const Matrix_4x4 &m);  //������������
    friend istream& operator >>(istream& in_put, Matrix_4x4 &m);   //�������������

    Matrix_4x4 transpose(); //����ת�ã��ı䵱ǰ����ֵ��������ת�þ���
    Matrix_4x4 inverse();   //�������棬�ı䵱ǰ����ֵ�����������
    double det();
};


#endif // MATRIX_4_SS_H
