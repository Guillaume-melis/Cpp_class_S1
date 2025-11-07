#include <iostream>
#include <ostream>

#include "BMat.hpp"
#include "Mat.hpp"
#include "MatTD.hpp"
#include "MatS.hpp"


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
    std::cout << "Matrice m (3x3) :" << std::endl;
    m.print(std::cout);
    std::cout << "--------------------" << std::endl;
    std::cout << "Matrice m^T :" << std::endl;
    Mat m_prime = m.transp();
    m_prime.print(std::cout);
    std::cout << "--------------------" << std::endl;
    std::cout << "Matrice TD m2 : " << std::endl;
    m2.print(std::cout);
    std::cout << "--------------------" << std::endl;

    MatTD m3 = m2.transp();
    
    std::cout << "Matrice m3 = m2^T : " << std::endl;
    m3.print(std::cout);
    std::cout << "--------------------" << std::endl;

    std::cout << "Matrice m4 : " << std::endl;
    Mat m4(3,3);

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            m4(i,j) = i + j;
    
    m4.print(std::cout);
    std::cout << "--------------------" << std::endl;

    std::cout << "Matrice m5 = m4 + m" << std::endl;
    Mat m5 = m4 + m;
    m5.print(std::cout);
    std::cout << "--------------------" << std::endl;


    MatS sym(3); 
    sym(0,0) = sym(1,1) = sym(2,2) = 1.0;
    sym(0,1) = sym(1,0) = 2.0; 
    sym(0,2) = sym(2,0) = 5.0;
    sym(1,2) = sym(2,1) = 3.0;

    sym.print(std::cout);
    std::cout << "--------------------" << std::endl;
    std::cout << sym.det() << std::endl;
    std::cout << sym.trace() << std::endl;

    return 0;
}