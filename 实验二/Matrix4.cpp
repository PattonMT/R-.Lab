#include "Matrix4.h"
//默认构造函数
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
//利用数组初始化
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
//拷贝构造函数
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
//减法
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
//赋值
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

//乘法
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

//输出重载
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
//输入重载
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


//矩阵转置
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

//某一行乘一个系数
Matrix_4x4 Matrix_4x4::scale_row(int r, double scalar)
{
  for (int i = 0; i <4; ++i)
  {
    matrix[r][i] *= scalar;
  }
  return *this;
}

//某一行乘一系数加到另一行
Matrix_4x4 Matrix_4x4::shear_row(int r1, int r2, double scalar)
{
  for (int i = 0; i < 4; ++i)
  {
    matrix[r1][i] += scalar * matrix[r2][i];
  }
  return *this;
}

//交换某两行
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

//求矩阵的行列式
double Matrix_4x4::det()
{
    int i,j,sign=0;
    double sum=1;
    for (i = 0;i <4;i++)
	{
		int maxrow = i;
		double Max = matrix[i][i];
		//判断每列的最大数，并将其放到主对角线上
		for (j = i + 1;j < 4;j++)
		{
			if (fabs(Max) < fabs(matrix[j][i]))
			{
				Max = matrix[j][i];
				maxrow = j;
			}
		}
		//判断矩阵是否为奇异阵
		if (fabs(Max) < 0.000001)
		{
			sum=0;
			break;
			return sum;
		}

		//当t不等于i时交换这两行的所有元素
		if (maxrow != i)
		{
			sign++;
			swap_row(i, maxrow);
		}
        //消去过程，化为上三角的形式
		for (j = i + 1;j < 4;j++)
		{
			double scale = matrix[j][i] / matrix[i][i];
			for (int k = i;k < 4 + 1;k++)
				matrix[j][k] = matrix[j][k] - matrix[i][k] * scale;
		}
	}
	for (i = 0;i < 4;i++)      //求化简后行列式的值
		sum *= matrix[i][i];

	if (sign % 2 != 0)
		sum*=-1;
	return sum;
}


//求矩阵的逆
Matrix_4x4 Matrix_4x4::inverse()
{
    Matrix_4x4 identity;//初始化为单位矩阵
    int i,j,r;
	double scalar;
	double shear_needed;

	for (i = 0; i < 4; ++i)
	{
	    //判断matrix[i][i]是否为0，通过行交换实现其不为0
		if (matrix[i][i] == 0.0)
		{
			/* 得到非0对角阵. */
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

		/* 缩放行保证沿对角线位置为1 */
		scalar = 1.0 / matrix[i][i];//设置比例系数
		scale_row(i, scalar);
		identity.scale_row(i, scalar);
		/* 此列中的其他元素清 0 */
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
