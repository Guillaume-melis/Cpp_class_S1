#ifndef TVECT_HPP
#define TVECT_HPP

#include <cstddef>   // pour size_t
#include <stdexcept> // pour std::out_of_range
#include <iostream>  // pour operator<< (optionnel)
#include <ostream>
#include <cmath>
#include <algorithm>

template <typename T>
class TVect
{
    size_t size_;
    T* data_;

    friend std::ostream& operator<<(std::ostream& os, const TVect&);

    public :
    TVect(size_t size) ;
    ~TVect();
    TVect(const TVect& v);

    size_t get_size() const {return size_;}

    //surcharge des opérateurs internes
    T& operator[](int i);
    const T& operator[](int i) const;

    TVect& operator=(const TVect& v);

    double norm(double p = 2.0) const;

};

//surcgarge des opérateurs externes
template <typename T>
TVect<T> operator+(const TVect<T>& v1, const TVect<T>& v2);
template <typename T>
TVect<T> operator-(const TVect<T>& v1, const TVect<T>& v2);
template <typename T>
TVect<T> operator*(const TVect<T>& v1, const TVect<T>& v2);
template <typename T>
TVect<T> operator*(const double d, const TVect<T>& v2);
template <typename T> 
TVect<T> operator*(const TVect<T>& v, const double d);
template <typename T>
TVect<T> operator/(const TVect<T>& v, const double d);

#include "tvect.tpp"

#endif