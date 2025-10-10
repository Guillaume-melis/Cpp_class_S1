#ifndef MATTD_HPP
#define MATTD_HPP

#include "BMat.hpp"
class MatTD : public BMat 
{
    double* diagl_;
    double* diag_;
    double* diagu_;

    public :
    MatTD(int n);
    ~MatTD();
    MatTD(const MatTD& m);

    //surcharge de l'opérateur d'égalité
    MatTD& operator=(const MatTD& m);

    //définition des méthodes virtuelles
    double& operator()(int l, int c) override;
    double operator()(int l, int c)const override;

    void print(std::ostream& os) const override;

    //Mat MatTD::transp() const override;

};


#endif