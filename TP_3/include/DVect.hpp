#ifndef DVECT_HPP
#define DVECT_HPP

#include <stdexcept>
#include <ostream>
#include <iostream>

template <size_t N>
class DVect : std::array<double, std::size_t N>
{
    public : 
    DVect() {};

    size_t get_size() const {return N;}

    DVect& operator=(const DVect& v);

    double norm(double p = 2.0) const;
};

//surcgarge des opérateurs externes
template <size_t N>
DVect<N> operator+(const DVect<N>& v1, const DVect<N>& v2);
template <size_t N>
DVect<N> operator-(const DVect<N>& v1, const DVect<N>& v2);
template <size_t N>
DVect<N> operator*(const DVect<N>& v1, const DVect<N>& v2);
template <size_t N>
DVect<N> operator*(const double d, const DVect<N>& v2);
template <size_t N> 
DVect<N> operator*(const DVect<N>& v, const double d);
template <size_t N>
DVect<N> operator/(const DVect<N>& v, const double d);

#include "DVect.tpp"


#endif