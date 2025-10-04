#ifndef RAT_HPP
#define RAT_HPP

#include <ostream>
#include <stdexcept>
#include <numeric>

class Rat
{
    int den_;
    int num_;

    friend std::ostream& operator<<(std::ostream& os,const Rat&);
    friend bool operator==(const Rat&, const Rat&);
    friend bool operator<(const Rat&, const Rat&);


    public :
    Rat(int num, int den=1);
    int get_den() const {return den_;}; 
    int get_num() const {return num_;};

    //Surcharge opérateurs internes
    Rat & operator+=(Rat r1);
    Rat & operator-=(Rat r1);
    Rat & operator*=(Rat r1);
    Rat & operator/=(Rat r1);

    //gérer le cas non irréductible
    void reduce();

};

//Surcharge opérateurs externes
std::ostream & operator<<(std::ostream & st,const Rat& r);
Rat operator+(Rat r1,const Rat& r2);
Rat operator-(Rat r1,const Rat& r2); 
Rat operator*(Rat r1,const Rat& r2);
Rat operator/(Rat r1,const Rat& r2);

bool operator==(const Rat& r1,const Rat& r2);
bool operator!=(const Rat& r1,const Rat& r2);
bool operator<(const Rat& r1,const Rat& r2);
bool operator<=(const Rat& r1,const Rat& r2); 
bool operator>(const Rat& r1,const Rat& r2);
bool operator>=(const Rat& r1,const Rat& r2);

#endif