#include "tvect.hpp"

template <typename T>
TVect<T>::TVect(size_t size) : size_(size), data_(new T[size_])
{
    
}

template <typename T>
TVect<T>::TVect(const TVect& v) : size_(v.size_)
{
    data_ = new T[size_];
    for(int i=0; i<size_;i++)
    {
        data_[i] = v.data_[i];
    }
}

template <typename T>
TVect<T>::~TVect()
{
    delete[] data_;
}

template <typename T>
T& TVect<T>::operator[](int i)
{
    if(i<0 || i>= size_)
        throw std::invalid_argument("Try accessing a member out of range");
    return data_[i];
}

template <typename T>
const T& TVect<T>::operator[](int i) const
{
    if(i<0 || i>= size_)
        throw std::invalid_argument("Try accessing a member out of range");
    return data_[i];
}

template <typename T>
TVect<T>& TVect<T>::operator=(const TVect& v)
{
    size_ = v.size_;
    delete data_;
    data_ = new T[v.size_];
    for(int i=0;i < size_;i++)
    {
        data_[i] = v[i];
    }
    return *this;
}


template <typename T>
double TVect<T>::norm(double p) const
{
    double sum=0.0;
    for(int i=0;i<size_;i++)
    {
        sum += pow(fabs(data_[i]),p);
    }
    return pow(sum,1/p);
}

template <typename T>
TVect<T> operator+(const TVect<T>& v1, const TVect<T>& v2)
{
    if(v1.size_ != v2.size_)
        throw std::invalid_argument("The size of the vectors should be the same");
    TVect<T> resultat(v1.size_);
    for(int i=0; i< v1.size_; i++)
    {
        resultat[i] = v1[i] + v2[i];
    }
    return resultat;
}

template <typename T>
TVect<T> operator-(const TVect<T>& v1, const TVect<T>& v2)
{
    if(v1.size_ != v2.size_)
        throw std::invalid_argument("The size of teh vectors should be the same");

    TVect<T> resultat(v1.size_);
    for(int i=0; i<v1.size_;i++)
    {
        resultat[i] = v1[i] - v2[i];
    }
    return resultat;
}

template <typename T>
TVect<T> operator*(const TVect<T>& v1, const TVect<T>& v2)
{
    if(v1.size_ != v2.size_)
        throw std::invalid_argument("The size of the vectors should be the same");

    TVect<T> resultat(v1.size_);
    for(int i=0; i<v1.size_;i++)
    {
        resultat[i] = v1[i] * v2[i];
    }    
    return resultat;
}


template <typename T>
TVect<T> operator*(const double d, const TVect<T>& v)
{
    TVect<T> resultat(v.size_);
    for(int i=0;i<v.size_;i++)
    {
        resultat[i] = d*v[i];
    }
    return resultat;
}

template <typename T>
TVect<T> operator*(const TVect<T>& v, const double d)
{
    TVect<T> resultat(v.size_);
    for(int i=0;i<v.size_;i++)
    {
        resultat[i] = d*v[i];
    }
    return resultat;
}

template <typename T>
TVect<T> operator/(const TVect<T>& v, const double d)
{
    TVect<T> resultat(v.size_);
    for(int i=0;i<v.size_;i++)
    {
        resultat[i] = v[i]/d;
    }
    return resultat;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const TVect<T>& v)
{
    os << "(" ;
    for(int i=0; i<v.get_size(); i++)
    {   
        if(i<v.get_size()-1)
            os << v[i] << ",";
        else 
            os << v[i];
    }
    os << ")" ;
    return os;
}


