#include "MatS.hpp"
#include "Mat.hpp"

#include <algorithm>
#include <vector>
#include <cmath>
#include <stdexcept>


MatS::MatS(int n) : Mat(n, n) {n_ = n;}

const double MatS::trace() const
{
    double sum = 0.0;
    for(int i=0; i< (*this).get_size(); i++)
        for(int j=0; j< (*this).get_size() ; j++)
        {
            if(j==i)
                sum += (*this)(i,j);
        }
    return sum;
}

double MatS::det() const
{
    size_t n = this->get_size();
    MatS A = *this; 
    double det = 1.0;
    int nb_swaps = 0;

    for (size_t k = 0; k < n; ++k) {
        size_t pivot = k;
        double max_val = std::abs(A(k,k));
        for (size_t i = k+1; i < n; ++i) {
            if (std::abs(A(i,k)) > max_val) {
                max_val = std::abs(A(i,k));
                pivot = i;
            }
        }

        if (max_val == 0)
            return 0.0; 

        if (pivot != k) {
            for (size_t j = 0; j < n; ++j)
                std::swap(A(k,j), A(pivot,j));
            nb_swaps++;
        }

        det *= A(k,k);

        for (size_t i = k+1; i < n; ++i) {
            double factor = A(i,k) / A(k,k);
            for (size_t j = k; j < n; ++j)
                A(i,j) -= factor * A(k,j);
        }
    }

    if (nb_swaps % 2 != 0)
        det = -det;

    return det;
}



