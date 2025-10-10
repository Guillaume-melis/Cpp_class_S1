#include "BMat.hpp"
#include "Mat.hpp"
#include <ostream>

BMat::BMat(int nl, int nc) : nl_(nl), nc_(nc)
{
    
}

const bool BMat::same_size(const BMat& m) const
{
    return (nc_ == m.nc_ && nl_ == m.nl_);
}

std::ostream& operator<<(std::ostream& os, const BMat& M)
{
    M.print(os);  // polymorphisme : appelle la bonne méthode selon le type réel
    return os;
}
