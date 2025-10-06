#include <iostream>
#include <ostream>
#include <cmath>
#include "Vect.hpp"

Vect::Vect(int size) : size_(size)
{
    if(size==0)
        throw std::invalid_argument("Size cannot be 0");

       
};

Vect::Vect(const Vect& v)
{

};

double Vect::norm(double p=2.0) const
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

Vect& Vect::operator=(Vect& v)
{
    if(this != &v)
    {
        if(v.size_ > size_)
        {
            size_ = v.size_;
        }
        for(int i=0; i<size_; i++)
        {
            data_[i] = v.data_[i];
        }
    }
    
    return *this;
}



