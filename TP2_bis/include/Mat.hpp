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

    double& operator()(int l, int c) override;
    const double& operator()(int l, int c) const override;

    void print(std::ostream& os) const override;

    Mat transp();

    friend Mat& operator+(const Mat& m1, const Mat& m2);
    friend Mat& operator-(const Mat& m1, const Mat& m2);

};

Mat& operator+(const Mat& m1, const Mat& m2)
{
    if(!m1.same_size(m2))
        throw std::invalid_argument("The matrices should have the same size");
    
    Mat result(m1.get_nl(), m1.get_nc());
    int size = m1.get_data_size();
    for(size_t i=0; i< size; i++)
        result.data[i] = m1.data[i] - m2.data[i];
    return result;
}
Mat& operator-(const Mat& m1, const Mat& m2)
{
    if(!m1.same_size(m2))
        throw std::invalid_argument("The matrices should have the same size");
    
    Mat result(m1.get_nl(), m1.get_nc());
    int size = m1.get_data_size();
    for(size_t i=0; i< size; i++)
        result.data[i] = m1.data[i] - m2.data[i];
    return result;
}


#endif