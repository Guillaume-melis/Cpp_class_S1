#ifndef BMAT_HPP
#define BMAT_HPP

#include <iostream>
#include <ostream>

class  BMat
{
    int nl_;
    int nc_;

    friend std::ostream& operator<<(std::ostream& os, const BMat&);

    public :
    BMat(int nl,int nc);
    const int get_nl() const {return nl_;} 
    const int get_nc() const {return nc_;}

    //définir l'opérateur d'égalité en taille
    const bool same_size(const BMat& m) const;

    //définir les opérateurs virtuels
    virtual double& operator()(int l, int c) = 0;
    virtual double operator()(int l, int c) const = 0;


    //operateur de transposé
    //virtual BMat* transp() const = 0;

    //operateur de sortie 
    virtual void print(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const BMat&);
};



#endif