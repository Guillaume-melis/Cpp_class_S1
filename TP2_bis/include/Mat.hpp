#ifndef MAT_HPP
#define MAT_HPP

#include <vector>
#include <ostream>
#include "BMat.hpp"

class Mat : public BMat
{
    std::vector<double> data; //meilleure manière que vector<vector<double>>

    public : 
    Mat(int nl, int nc);

    double& operator()(int l, int c) override;

    void print(std::ostream& os) const override;

    Mat transp();

    const Mat& operator+(const Mat& m);
    const Mat& operator-(const Mat& m);
};

#endif