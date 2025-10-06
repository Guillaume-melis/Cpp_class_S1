#ifndef VECT_HPP
#define VECT_HPP

#include <ostream>
#include <iostream>
#include <stdexcept>
#include <cmath>

class Vect
{
    int size_;
    double* data_;

    friend std::ostream& operator<<(std::ostream& os, const Vect&);

    public: 
    Vect(int size);
    Vect(const Vect& v);
    ~Vect() {std::cout << "dtor Vect"<< std::endl;};
 
    int get_size() const {return size_;}
    double norm(double p = 2.0) const;

    //Surcharge des opérateurs internes
    double & operator[](int i);
    Vect& operator=(Vect& v);

};

//Surcharge opérateurs externes
Vect operator+(const Vect& v1, const Vect& v2);
Vect operator-(const Vect& v1, const Vect& v2);
double operator*(Vect& v1, const Vect& v2);
Vect operator*(Vect& v1, const double d); 
Vect operator*(double d, const Vect& v1);    
Vect operator/(Vect& v1, const double d);

#endif