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
        for(size_t j; j<(*this).get_nl(); j++)
            (*this)(i,j) = result(j,i);
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
        for(int j=0; j<(*this).get_nc(); j++)
            os << (*this)(i,j) << " ";
        os << std::endl;
}