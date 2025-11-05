#ifndef B_MAT_HPP
#define B_MAT_HPP

#include <iostream>
#include <ostream>
#include <vector>

class BMat
{
    int nl_;
    int nc_;

    friend std::ostream& operator<<(std::ostream& os, const BMat&);

    public : 
    BMat(int nl, int nc);
    const int get_nl() const {return nl_;}
    const int get_nc() const {return nc_;}

    virtual double& operator()(int l, int c) = 0;
    virtual const double& operator()(int l, int c) const = 0;

    const bool same_size(const BMat& m) const;

    virtual void print(std::ostream& os) const = 0;
};

#endif