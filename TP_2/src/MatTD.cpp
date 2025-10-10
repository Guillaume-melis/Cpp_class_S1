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
    delete[] diag_, diagl_, diagu_;
}


MatTD& MatTD::operator=(const MatTD& m)
{
    if(get_nc() != m.get_nc())
    {
        delete diag_, diagl_, diagu_;
        diag_, diagl_, diagu_ = new double[m.get_nl()], new double[m.get_nl()-1], new double[m.get_nl()-1];
    }
    std::copy(m.diag_, m.diag_ + get_nl() * get_nc(), diag_);
    std::copy(m.diagl_, m.diagl_ + get_nl() * get_nc(), diagl_);
    std::copy(m.diagu_, m.diagu_ + get_nl() * get_nc(), diagu_);
    return *this;
}

double& MatTD::operator()(int l, int c) const
{
    double& result = *0.0;
    if(l == get_nl() || c == get_nc())
        return 0;
}