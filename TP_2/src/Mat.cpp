#include "Mat.hpp"
#include "BMat.hpp"
#include "Vect.hpp"
#include <algorithm>

Mat::Mat(int nl, int nc) : BMat(nl, nc)
{
    data_ = new double[nl * nc]{0.0}; 
}

Mat::Mat(const Mat& m) : BMat(m)
{
    int size = m.get_nl() * m.get_nc();
    data_ = new double[size];
    for(int i = 0; i < size; ++i)
        data_[i] = m.data_[i]; 
}

Mat::~Mat()
{
    delete[] data_;
}

Mat& Mat::operator=(const Mat& m)
{
    if(get_nl() * get_nc() != m.get_nl() * m.get_nc())
    {
        delete[] data_;
        data_ = new double[m.get_nl() * m.get_nc()];
    }
    std::copy(m.data_, m.data_ + get_nl() * get_nc(), data_);
    return *this;
}

double& Mat::operator()(int l, int c) 
{
    return data_[l * get_nc() + c];
}

double Mat::operator()(int l, int c) const
{
    return data_[l*get_nc() +c];
}

void Mat::print(std::ostream& os) const
{
    for (int i = 0; i < BMat::get_nl(); ++i) {
        for (int j = 0; j < BMat::get_nc(); ++j)
            os << (*this)(i,j) << " ";
        os << std::endl;
    }
}

Mat Mat::transp()
{
    Mat result(get_nc(),get_nl());
    for(int i=0;i<get_nl();i++)
    {
        for(int j=0;j<get_nc();j++)
        {
            result(i,j) = (*this)(j,i);
        }
    }
    return result;
}