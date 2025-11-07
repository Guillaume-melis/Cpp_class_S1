#ifndef MAT_HPP
#define MAT_HPP

#include <vector>
#include <ostream>
#include "BMat.hpp"
#include "Mat.hpp"

class Mat : public BMat
{
    std::vector<double> data; //meilleure manière que vector<vector<double>>

    public : 
    Mat(int nl, int nc);
    int get_data_size() const {return data.size();}
    std::vector<double> get_data() {return data;}

    double& operator()(int l, int c) override;
    const double& operator()(int l, int c) const override;

    void print(std::ostream& os) const override;

    Mat transp();

    friend Mat operator+(const Mat& m1, const Mat& m2);
    friend Mat operator-(const Mat& m1, const Mat& m2);

};


#endif