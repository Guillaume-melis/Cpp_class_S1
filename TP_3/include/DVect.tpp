#include "DVect.hpp"

template <size_t N>
DVect<N>& DVect<N>::operator=(const DVect<N>& v)
{
    N = v.get_size();
    for(int i=0;i<v.get_size();i++)
    {
        (*this)[i] = v[i];
    }
    return *this;
}

template <size_t N>
double DVect<N>::norm(double p) const
{
    double sum=0.0;
    for(int i=0;i<get_size();i++)
    {
        sum += pow(fabs((*this)[i]),p);
    }
    return pow(sum,1/p);
}

template <size_t N>
DVect<N> operator+(const DVect<N>& v1, const DVect<N>& v2)
{
    if(v1.get_size() != v2.get_size())
        throw std::invalid_argument("Size of the vectors must be the same");

    DVect<v1.get_size()> result;
    for(int i=0;i<result.get_size();i++)
    {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

template <size_t N>
DVect<N> operator-(const DVect<N>& v1, const DVect<N>& v2)
{
    if(v1.get_size() != v2.get_size())
        throw std::invalid_argument("Size of the vectors must be the same");

    DVect<v1.get_size()> result;
    for(int i=0;i<result.get_size();i++)
    {
        result[i] = v1[i] - v2[i];
    }
    return result;
}

template <size_t N>
DVect<N> operator*(const DVect<N>& v1, const DVect<N>& v2)
{
    if(v1.get_size() != v2.get_size())
        throw std::invalid_argument("Size of the vectors must be the same");

    DVect<v1.get_size()> result;
    for(int i=0;i<result.get_size();i++)
    {
        result[i] = v1[i] * v2[i];
    }
    return result;
}

template <size_t N>
DVect<N> operator*(const double d, const DVect<N>& v)
{
    DVect<v.get_size()> result;
    for(int i=0;i<result.get_size();i++)
    {
        result[i] = d * v[i];
    }
    return result;
}

template <size_t N>
DVect<N> operator*(const DVect<N>& v,const double d)
{
    DVect<v.get_size()> result;
    for(int i=0;i<result.get_size();i++)
    {
        result[i] = d * v[i];
    }
    return result;
}

template <size_t N>
DVect<N> operator/(const DVect<N>& v,const double d)
{
    DVect<v.get_size()> result;
    for(int i=0;i<result.get_size();i++)
    {
        result[i] = v[i]/d;
    }
    return result;
}