#include "BMat.hpp"
#include "MatTD.hpp"

MatTD::MatTD(int n) : BMat(n, n)
{
    diagl_.resize(n-1);
    diag_.resize(n);
    diagu_.resize(n-1);
}

double& MatTD::operator()(int l, int c)
{
    if(l==c)
        return diag_[l];
    
    if(l==c-1)
        return diagu_[l];
    
    if(l==c+1)
        return diagl_[c];
    
    if(l==get_nl() || c==get_nc())
        throw std::out_of_range("Value is 0");
}

const double& MatTD::operator()(int l, int c) const
{
    if(l==c)
        return diag_[l];

    if(l==c-1)
        return diagu_[l];
    
    if(l==c+1)
        return diagl_[c];
    
    if(l==get_nl() || c==get_nc())
        throw std::out_of_range("Value is 0");
}

void MatTD::print(std::ostream& os) const
{
    for(int i=0; i<(*this).diag_.size(); i++)
        for(int j=0; j<(*this).diag_.size(); j++)
            os << (*this)(i,j) << " ";
        os << std::endl;
}

MatTD MatTD::transp()
{
    MatTD result((*this).get_size());
    for(int i=0; i<(*this).diag_.size(); i++)
        for(int j=0; j<(*this).diag_.size(); j++)
            (*this)(i,j) = result(j,i);
    return result;
}