#include "BMat.hpp"
#include "MatTD.hpp"
#include <algorithm>

MatTD::MatTD(int n) : BMat(n, n)
{
    diagl_ = new double[n-1];
    diag_ = new double[n];
    diagu_ = new double[n-1];

}

MatTD::MatTD(const MatTD& m) : BMat(m.get_nl(), m.get_nc())
{
    diagl_ = new double[m.get_nl()-1];
    diagu_ = new double[m.get_nl()-1];
    diag_ = new double[m.get_nl()];
}

MatTD::~MatTD()
{
    delete[] diag_; 
    delete[] diagl_; 
    delete[] diagu_;
}


MatTD& MatTD::operator=(const MatTD& m)
{
    if(get_nc() != m.get_nc())
    {
        delete[] diag_;
        delete[] diagl_; 
        delete[] diagu_;
        diag_ = new double[m.get_nl()] ;
        diagl_ = new double[m.get_nl()-1];
        diagu_ = new double[m.get_nl()-1];
    }
    std::copy(m.diag_, m.diag_ + get_nl() * get_nc(), diag_);
    std::copy(m.diagl_, m.diagl_ + get_nl() * get_nc(), diagl_);
    std::copy(m.diagu_, m.diagu_ + get_nl() * get_nc(), diagu_);
    return *this;
}

double MatTD::operator()(int l, int c) const
{
    if(l==c)
        return diag_[l];
    
    if(l == c-1)
        return diagu_[l];
    
    if(l== c+1)
        return diagl_[l];
    
    else 
        return 0.0;
}

double& MatTD::operator()(int l, int c) 
{
    if(l==c)
        return diag_[l];
    
    if(l == c-1)
        return diagu_[l];
    
    if(l== c+1)
        return diagl_[l];
    
    else 
        throw std::out_of_range("Element en dehors de la bande tri-diagonale");
}

void MatTD::print(std::ostream& os) const {
    for (int i = 0; i < get_nl(); ++i) {
        for (int j = 0; j < get_nc(); ++j) {
            if (i == j)
                os << diag_[i] << " ";
            else if (i == j - 1)
                os << diagu_[i] << " ";
            else if (i == j + 1)
                os << diagl_[i] << " ";
            else
                os << 0.0 << " ";
        }
        os << std::endl;
    }
}

