#ifndef MAT_HPP
#define MAT_HPP

#include "BMat.hpp"
#include <iostream>
#include <ostream>
#include <algorithm>

class Mat : public BMat
{
    double* data_;

    public :
    Mat(int nl, int nc); //ctor
    ~Mat(); //dtor
    Mat(const Mat& m); //c-c

    //surcharge des opérateurs
    Mat& operator=(const Mat& m);

    //définition des methodes virtuelles 
    double& operator()(int l, int c) override;
    double operator()(int l, int c) const override;

    void print(std::ostream& os) const override;
};

#endif