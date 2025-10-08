#ifndef MAT_HPP
#define MAT_HPP

#include "BMat.hpp"
#include <iostream>
#include <ostream>

class Mat : public BMat
{
    double* data_;

    public :
    Mat(int nl, int nc); //ctor
    ~Mat(); //dtor
    Mat(const Mat& m); //c-c

    //surcharge des opérateurs



};

#endif