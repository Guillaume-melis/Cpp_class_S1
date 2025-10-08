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
    return *this = Rat(num_ * r.den_ + r.num_ * den_,den_ * r.den_);
}

Rat& Rat::operator-=(const Rat r)
{
    return *this = Rat(num_ * r.den_ - r.num_ * den_,den_ * r.den_);
}

Rat& Rat::operator*=(const Rat r)
{
    return *this = Rat(num_*r.num_,den_ * r.den_);
}

Rat& Rat::operator/=(const Rat r)
{
    return *this = Rat(num_ * r.den_,den_ * r.num_);
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
    return (r1.num_*r2.den_ == r1.den_*r2.num_);
}

bool operator!=(const Rat& r1, const Rat& r2)
{
    return !(r1 == r2);
}

bool operator<(const Rat& r1, const Rat& r2)
{
    return (r1 != r2 && r1.den_ > r2.den_);
}

bool operator<=(const Rat& r1, const Rat& r2)
{
    return (r1 < r2 || r1 == r2);
}

bool operator>(const Rat& r1, const Rat& r2)
{
    return !(r1 <= r2);
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