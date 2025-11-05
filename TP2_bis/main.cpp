#include <iostream>
#include <ostream>

#include "BMat.hpp"
#include "Mat.hpp"
#include "MatTD.hpp"


int main()
{
    Mat m(3,3);
    MatTD m2(3);

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            m(i,j) = i + j/2.0;
            m2(i,j) = i*j;
        }
    }

    m.print(std::cout);
    m2.print(std::cout);

    MatTD m3 = m2.transp();

    m3.print(std::cout);

    Mat m4(3,3);

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            m(i,j) = i + j - 2.0;

    Mat m5 = m4 + m;
    m5.print(std::cout);

    return 0;
}