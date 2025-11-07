#include "BMat.hpp"
#include "Mat.hpp"
#include <vector>
#include <ostream>

Mat::Mat(int nl, int nc) : BMat(nl, nc) 
{
    if(nl==0 || nc==0)
        throw std::invalid_argument("Argument with value 0 is illegal");
    data.resize(nl*nc);
}

Mat Mat::transp()
{
    Mat result(get_nl(), get_nc());
    for(size_t i=0; i<(*this).get_nc();i++)
        for(size_t j=0; j<(*this).get_nl(); j++)
            result(i,j) = (*this)(j,i) ;
    return result;
}

double& Mat::operator()(int l, int c)
{
    return data[l * get_nc() + c];
}

const double& Mat::operator()(int l, int c) const
{
    return data[l * get_nc() + c];
}

void Mat::print(std::ostream& os) const
{
    for(int i=0; i<(*this).get_nl(); i++)
    {
        for(int j=0; j<(*this).get_nc(); j++)
            os << (*this)(i,j) << " ";
        os << std::endl;
    }
        
}

Mat operator+(const Mat& m1, const Mat& m2)
{
    if(!m1.same_size(m2))
        throw std::invalid_argument("The matrices should have the same size");
    
    Mat result(m1.get_nl(), m1.get_nc());
    int size = m1.get_data_size();
    for(size_t i=0; i< size; i++)
        result.data[i] = m1.data[i] - m2.data[i];
    return result;
}
Mat operator-(const Mat& m1, const Mat& m2)
{
    if(!m1.same_size(m2))
        throw std::invalid_argument("The matrices should have the same size");
    
    Mat result(m1.get_nl(), m1.get_nc());
    int size = m1.get_data_size();
    for(size_t i=0; i< size; i++)
        result.data[i] = m1.data[i] - m2.data[i];
    return result;
}