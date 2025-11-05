#include "BMat.hpp"
#include <ostream>

BMat::BMat(int nl, int nc) : nl_(nl), nc_(nc) {}

const bool BMat::same_size(const BMat& m) const
{
    if(nl_ == m.nl_ && nc_ == m.nc_)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& os, const BMat& M)
{
    M.print(os);
    return os;
}