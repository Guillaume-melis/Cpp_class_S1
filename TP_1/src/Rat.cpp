#include <iostream>
#include <ostream>
#include "Rat.hpp"


Rat::Rat(int num, int den) : num_(num), den_(den) 
{
    //gestion d'erreur
    if(den_==0)
        throw std::invalid_argument("Invalid argument, division by 0");
    
    if(den_ < 0)
    {
        num_ = -num_;
        den_ = -den_;
    }

    reduce();
    
};


void Rat::reduce()
{
    int g = std::gcd(num_,den_);
    num_ /= g;
    den_ /= g;
}

//gestion opéateurs internes
Rat& Rat::operator+=(const Rat r)
{
    num_ = num_ * r.den_ + r.num_ * den_;
    den_ = den_ * r.den_;
    reduce();
    return *this;
}

Rat& Rat::operator-=(const Rat r)
{
    num_ = num_ * r.den_ - r.num_ * den_;
    den_ = den_ * r.den_;
    reduce();
    return *this;
}

Rat& Rat::operator*=(const Rat r)
{
    num_ = num_ * r.num_;
    den_ = den_ * r.den_;
    reduce();
    return *this;
}

Rat& Rat::operator/=(const Rat r)
{
    num_ = num_ * r.den_;
    den_ = den_ * r.num_;
    reduce(); 
    return *this;
}

//gestion opérateurs externes
Rat operator+(Rat r1, const Rat& r2)
{
    r1+=r2;
    return r1;
}

Rat operator-(Rat r1, const Rat& r2)
{
    r1 -= r2;
    return r1;
}

Rat operator*(Rat r1, const Rat& r2)
{
    r1 *= r2;
    return r1;
}

Rat operator/(Rat r1, const Rat& r2)
{
    r1 /= r2;
    return r1;
}

bool operator==(const Rat& r1, const Rat& r2)
{
    if (r1.num_ == r2.num_ && r1.den_ == r2.den_)
        return true ;
    return false;
}

bool operator!=(const Rat& r1, const Rat& r2)
{
    if(r1 == r2)
        return false;
    return true;
}

bool operator<(const Rat& r1, const Rat& r2)
{
    if(r1 != r2 && r1.den_ > r2.den_)
        return true;
    return false;
}

bool operator<=(const Rat& r1, const Rat& r2)
{
    if(r1 < r2 || r1 == r2)
        return true;
    return false;
}

bool operator>(const Rat& r1, const Rat& r2)
{
    if(r1!=r2 && r1.get_den() < r2.get_den())
        return true;
    return false;
}

bool operator>=(const Rat& r1, const Rat& r2)
{
    return !(r1 < r2);
}

//opérateur d'affichage 
std::ostream& operator<<(std::ostream& os,const Rat& r)
{
    if(r.get_den() == 1)
        os << r.get_num() << std::endl;
    else
    {
        os << r.get_num() << "/" << r.get_den() << std::endl;
    }
    return os;
}