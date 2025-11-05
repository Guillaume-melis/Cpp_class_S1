#ifndef MAT_S_HPP
#define MAT_S_HPP

#include "Mat.hpp"

class MatS : public Mat
{
    public : 
    MatS(int n); 
    const int get_size() const;
    const double trace() const;
    double det() const;
};

#endif