#include <iostream>
#include "Vect.hpp"

/*int main()
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
}*/

int main()
{
    try
    {
        // --- Création de deux vecteurs de taille 3
        Vect v1(3);
        Vect v2(3);

        // --- Initialisation manuelle
        v1[0] = 1.0;
        v1[1] = 2.0;
        v1[2] = 3.0;

        v2[0] = 4.0;
        v2[1] = 5.0;
        v2[2] = 6.0;

        // --- Affichage
        std::cout << "v1 = " << v1 << std::endl;
        std::cout << "v2 = " << v2 << std::endl;

        // --- Somme et différence
        Vect sum = v1 + v2;
        Vect diff = v1 - v2;

        std::cout << "v1 + v2 = " << sum << std::endl;
        std::cout << "v1 - v2 = " << diff << std::endl;

        // --- Produit scalaire
        double dot = v1 * v2;
        std::cout << "v1 . v2 = " << dot << std::endl;

        // --- Multiplication et division par un scalaire
        Vect scaled = v1 * 2.0;
        Vect divided = v2 / 2.0;

        std::cout << "2 * v1 = " << scaled << std::endl;
        std::cout << "v2 / 2 = " << divided << std::endl;

        // --- Norme
        std::cout << "||v1||₂ = " << v1.norm() << std::endl;
        std::cout << "||v2||₃ = " << v2.norm(3.0) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}