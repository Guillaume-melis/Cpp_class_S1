#ifndef MATTD_HPP
#define MATTD_HPP

#include "BMat.hpp"

class MatTD : public BMat
{
    std::vector<double> diagl_;
    std::vector<double> diag_;
    std::vector<double> diagu_;

    public :
    MatTD(int n);

    int get_size() {return diag_.size();}
    double& operator()(int l, int c) override;
    const double& operator()(int l, int c) const override;

    void print(std::ostream& os) const override;

    MatTD transp();
}; 

#endif