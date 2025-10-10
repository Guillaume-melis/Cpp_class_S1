#ifndef MATS_HPP
#define MATS_HPP

#include "Mat.hpp"

class MatS : public Mat
{
    public : 
    MatS(int n);
    const int get_size() const;
    const double trace() const;
    const double det() const;
};

#endif