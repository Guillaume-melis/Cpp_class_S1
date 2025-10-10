#include "BMat.hpp"
#include "Mat.hpp"

BMat::BMat(int nl, int nc) : nl_(nl), nc_(nc)
{
    
}

const bool BMat::same_size(const BMat& m) const
{
    return (nc_ == m.nc_ && nl_ == m.nl_);
}

const Mat BMat::transp()
{
    Mat m(nc_,nl_);
    return m;
}