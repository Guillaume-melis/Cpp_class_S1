#include "BMat.hpp"
#include "MatTD.hpp"

MatTD::MatTD(int n) : BMat(n, n)
{
    diagl_.resize(n-1);
    diag_.resize(n);
    diagu_.resize(n-1);
}

double zero = 0.0;

double& MatTD::operator()(int l, int c) // return by value
{
    if(l==c)
        return diag_[l];
    
    if(l==c-1)
        return diagu_[l];
    
    if(l==c+1)
        return diagl_[c];
    if(l==get_nl() || c==get_nc())
        return zero;

    return zero;
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
        return zero;
    return zero;
}

void MatTD::print(std::ostream& os) const
{
    for(int i=0; i<(*this).diag_.size(); i++)
    {
        for(int j=0; j<(*this).diag_.size(); j++)
            os << (*this)(i,j) << " ";
        os << std::endl;
    }
}

MatTD MatTD::transp()
{
    MatTD result(get_size());
    result.diag_ = diag_;       // diagonale principale inchangée
    result.diagu_ = diagl_;     // les diagonales sup et inf sont inversées
    result.diagl_ = diagu_;
    return result;
}