#ifndef BMAT_HPP
#define BMAT_HPP

#include <iostream>
#include <ostream>
#include "Mat.hpp"

class BMat
{
    const int nl_;
    const int nc_;

    public :
    BMat(const int nl, const int nc);
    const int get_nl() const {return nl_;} 
    const int get_nc() const {return nc_;}

    //définir l'opérateur d'égalité en taille
    const bool same_size(const BMat& m) const;

    //définir les opérateurs virtuels
    virtual double& operator()(int l, int c) const = 0;
    virtual double operator()(int l, int c) = 0;

    //operateur de transposé
    const Mat transp();
};



#endif