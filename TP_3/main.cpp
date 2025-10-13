#include <iostream>
#include "tvect.hpp"

int main() {
    // Crée un vecteur de 5 entiers
    TVect<int> v(5);

    // Accès et assignation
    for (int i = 0; i < static_cast<int>(v.get_size()); ++i)
        v[i] = i + 1;

    // Affiche le contenu
    std::cout << "Vecteur : ";
    for (int i = 0; i < static_cast<int>(v.get_size()); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    // Calcul de la norme
    std::cout << "Norme L2 = " << v.norm() << std::endl;

    return 0;
}