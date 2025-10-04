#include <iostream>
#include "Rat.hpp"

int main()
{
    Rat a(1, 2), b(3, 4), c(8), d(-2, -4);

    std::cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << '\n';

    std::cout << "a + b = " << a + b << '\n';
    std::cout << "a - b = " << a - b << '\n';
    std::cout << "a * b = " << a * b << '\n';
    std::cout << "a / b = " << a / b << '\n';

    a += b;
    std::cout << "a += b -> " << a << '\n';

    std::cout << std::boolalpha;
    std::cout << "a == b ? " << (a == b) << '\n';
    std::cout << "a != b ? " << (a != b) << '\n';
    std::cout << "a < b ? " << (a < b) << '\n';
    std::cout << "a >= b ? " << (a >= b) << '\n';

    return 0;
}