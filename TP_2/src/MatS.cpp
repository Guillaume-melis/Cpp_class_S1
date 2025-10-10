#include "MatS.hpp"
#include <algorithm>


MatS::MatS(int n) : Mat(n, n) { }

const int MatS::get_size() const
{
    return Mat::get_nc() * Mat::get_nl();
}

const double MatS::trace() const
{
    double trace = 0.0;
    for(int i=0; i < Mat::get_nc(); i++)
    {
        trace += (*this)(i,i);
    }
    return trace;
}

double MatS::det() const
{
    Mat L(Mat::get_nc(),Mat::get_nl());
    Mat U(Mat::get_nc(), Mat::get_nl());


    for(int i=0;i<Mat::get_nc();i++)
    {
        for(int k=i;k<Mat::get_nc();k++)
        {
            double sum = 0.0;

            for(int j=0;j<i;j++)
            {
                sum += L(i,j) * U(j,k);
            }
            U(i,k) = (*this)(i,k) - sum;
        }
        for(int k=i;k<Mat::get_nc();k++)
        {
            if(i==k)
            {
                L(i,i) = 1;
            }
            else
            {
                double sum = 0.0;
                for(int j=0; j<i; j++)
                {
                    sum += L(k,j) * U(j,i);
                }
                L(k,i) = ((*this)(k,i) - sum) / U(i,i);
            }
        }
    }
    double det = 1.0;
    for(int i=0;i < Mat::get_nc();i++)
        det*= U(i,i);
    
    return det;
}