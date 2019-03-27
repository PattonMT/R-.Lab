#include "Matrix4.h"
//Ĭ�Ϲ��캯��
Matrix_4x4::Matrix_4x4()
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            if (i==j)
                matrix[i][j]=1;
            else
                matrix[i][j]=0;
        }
    }
}
//���������ʼ��
Matrix_4x4::Matrix_4x4(const double (&mat)[4][4])
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            matrix[i][j]=mat[i][j];
        }
    }
}
//�������캯��
Matrix_4x4::Matrix_4x4(const Matrix_4x4 &mat)
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            matrix[i][j]=mat.get_data(i,j);
        }
    }
}

Matrix_4x4 operator+ (const Matrix_4x4 &m1, const Matrix_4x4 &m2)
{
    Matrix_4x4 m;

    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            m[i][j]=m1.get_data(i,j)+m2.get_data(i,j);
        }
    }

    return m;
};
//����
Matrix_4x4 operator- (const Matrix_4x4 &m1, const Matrix_4x4 &m2)
{
    Matrix_4x4 m;

    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            m[i][j]=m1.get_data(i,j)-m2.get_data(i,j);
        }
    }

    return m;

};

/*
//��ֵ
Matrix_4x4& Matrix_4x4::operator= (const Matrix_4x4 &m)
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            matrix[i][j]=m.get_data(i,j);
        }
    }

    return *this;

};*/

//�˷�
Matrix_4x4 operator* (const Matrix_4x4 &m1, const Matrix_4x4 &m2)
{
    Matrix_4x4 m;

    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            m[i][j]=0;

            for (int k=0;k<4;k++)
            {
                m[i][j]+=m1.get_data(i,k)*m2.get_data(k,j);
            }
        }
    }

    return m;
};

//�������
ostream& operator <<(ostream& out_put, const Matrix_4x4 &m)
{
    out_put<<endl;


    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            out_put<<m.get_data(i,j)<<" ";
        }

        out_put<<endl;

    }

    return out_put;

}
//��������
istream& operator >>(istream& in_put, Matrix_4x4 &m)
{

    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            in_put>>m[i][j];
        }
    }
    return in_put;
}


//����ת��
Matrix_4x4 Matrix_4x4::transpose()
{
    double tmp;

    for (int i=0;i<4;i++)
    {
        for (int j=0;j<i;j++)
        {
            tmp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=tmp;
        }
    }

    return *this;
}

//ĳһ�г�һ��ϵ��
Matrix_4x4 Matrix_4x4::scale_row(int r, double scalar)
{
  for (int i = 0; i <4; ++i)
  {
    matrix[r][i] *= scalar;
  }
  return *this;
}

//ĳһ�г�һϵ���ӵ���һ��
Matrix_4x4 Matrix_4x4::shear_row(int r1, int r2, double scalar)
{
  for (int i = 0; i < 4; ++i)
  {
    matrix[r1][i] += scalar * matrix[r2][i];
  }
  return *this;
}

//����ĳ����
Matrix_4x4 Matrix_4x4::swap_row(int r1, int r2)
{
  double tmp;
  for(int i=0;i<4;i++)
  {
      tmp = matrix[r1][i];
      matrix[r1][i] = matrix[r2][i];
      matrix[r2][i] = tmp;
  }
  return *this;
}

//����������ʽ
double Matrix_4x4::det()
{
    int i,j,sign=0;
    double sum=1;
    for (i = 0;i <4;i++)
	{
		int maxrow = i;
		double Max = matrix[i][i];
		//�ж�ÿ�е��������������ŵ����Խ�����
		for (j = i + 1;j < 4;j++)
		{
			if (fabs(Max) < fabs(matrix[j][i]))
			{
				Max = matrix[j][i];
				maxrow = j;
			}
		}
		//�жϾ����Ƿ�Ϊ������
		if (fabs(Max) < 0.000001)
		{
			sum=0;
			break;
			return sum;
		}

		//��t������iʱ���������е�����Ԫ��
		if (maxrow != i)
		{
			sign++;
			swap_row(i, maxrow);
		}
        //��ȥ���̣���Ϊ�����ǵ���ʽ
		for (j = i + 1;j < 4;j++)
		{
			double scale = matrix[j][i] / matrix[i][i];
			for (int k = i;k < 4 + 1;k++)
				matrix[j][k] = matrix[j][k] - matrix[i][k] * scale;
		}
	}
	for (i = 0;i < 4;i++)      //�󻯼������ʽ��ֵ
		sum *= matrix[i][i];

	if (sign % 2 != 0)
		sum*=-1;
	return sum;
}


//��������
Matrix_4x4 Matrix_4x4::inverse()
{
    Matrix_4x4 identity;//��ʼ��Ϊ��λ����
    int i,j,r;
	double scalar;
	double shear_needed;

	for (i = 0; i < 4; ++i)
	{
	    //�ж�matrix[i][i]�Ƿ�Ϊ0��ͨ���н���ʵ���䲻Ϊ0
		if (matrix[i][i] == 0.0)
		{
			/* �õ���0�Խ���. */
			for (r = i + 1; r < 4; ++r)
			{
				if (matrix[r][i] != 0.0)
				{
					break;
				}
			}
			if (r == 4)
            {
                return identity;
                break;
			}
			swap_row(i, r);
			identity.swap_row(i, r);
		}

		/* �����б�֤�ضԽ���λ��Ϊ1 */
		scalar = 1.0 / matrix[i][i];//���ñ���ϵ��
		scale_row(i, scalar);
		identity.scale_row(i, scalar);
		/* �����е�����Ԫ���� 0 */
		for ( j = 0; j < 4; ++j)
		{
			if (i == j)
			{
				continue;
			}
			shear_needed = -matrix[j][i];
			shear_row(j, i, shear_needed);
			identity.shear_row(j, i, shear_needed);
		}
	}

	return identity;
}
