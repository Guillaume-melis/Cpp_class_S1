#include <iostream>
#include <ostream>
#include <cmath>
#include <algorithm>
#include "Vect.hpp"

Vect::Vect(int size) : Mat(size, 1), size_(size)
{
    if(size==0)
        throw std::invalid_argument("Size cannot be 0");

    data_ = new double[size_];
       
}

Vect::Vect(const Vect& v) : Mat(v.size_, 1), size_(v.size_) 
{
    data_ = new double [size_];
    for(int i=0; i<size_;i++)
    {
        data_[i] = v.data_[i];
    }
}

Vect::~Vect()
{
    delete[] data_;
}

double Vect::norm(double p) const
{
    double vector_norm=0.0; 

    for(int i=0; i< size_; i++)
    {
        vector_norm+= pow(fabs(data_[i]),p);
    }

    return pow(vector_norm,1/p);
}

double& Vect::operator[](int i)
{
    if(i<0 || i>= size_)
        throw std::invalid_argument("Try accessing a member out of range");
    return data_[i];
}

double Vect::operator[](int i) const
{
    if(i<0 || i>= size_)
        throw std::invalid_argument("Try accessing a member out of range");

    return data_[i];
}

Vect& Vect::operator=(const Vect& v) //Actually it's not the best way to do as we have to free the memory allocation. It's better to use the swap
{
    if(this != &v)
    {
        if(v.size_ != size_)
        {
            size_ = v.size_;
            delete[] data_;
            data_ = new double[size_];
        }
        for(int i=0; i<size_; i++)
        {
            data_[i] = v.data_[i];
        }
    }
    
    return *this;
}


//Surcharge des opérateurs externes
Vect operator+(Vect& v1,Vect& v2)
{
    if(v1.get_size() == v2.get_size())
    {
        int common_size=v1.get_size();
        Vect result(common_size);
        for(int i=0; i<common_size; i++)
        {
            result[i] = v1[i] + v2[i];
        }
        return result;
    }
    else
    {
        throw std::invalid_argument("Vector must have the same size");
        Vect result(0);
        return result;
    }
}

Vect operator-(Vect& v1, Vect& v2)
{
    if(v1.get_size() == v2.get_size())
    {
        int size = v1.get_size();
        Vect result(size);
        for(int i=0; i<size; i++)
        {
            result[i] = v1[i] - v2[i];
        }
        return result;
    }else
    {
        throw std::invalid_argument("The vector must have the same size");
        Vect result(0);
        return result;
    }
}

double operator*(Vect& v1, Vect& v2)
{
    if(v1.get_size() == v2.get_size())
    {
        double result=0.0;
        for(int i=0; i< v1.get_size(); i++)
        {
            result += v1[i] * v2[i];
        }
        return result;
    }
    else 
        throw std::invalid_argument("Vector doesn't have the same size brozer");
}

Vect operator*(Vect& v, const double d)
{
    const int size = v.get_size();
    Vect result(size);
    for(int i=0; i<size;i++)
    {
        result[i] = d*v[i];
    }
    return result;
}

Vect operator*(double d, Vect& v1)
{
    const int size = v1.get_size();
    Vect result(size);
    for(int i=0; i<size; i++)
    {
        result[i] = d*v1[i];
    }
    return result;
}

Vect operator/(Vect& v, const double d)
{
    const int size = v.get_size();
    Vect result(size);
    for(int i=0; i<size; i++)
    {
        result[i] = v[i]/d;
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Vect& v)
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