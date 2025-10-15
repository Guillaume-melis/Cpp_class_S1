#include <iostream>
#include <cmath>
#include "BMat.hpp"
#include "Mat.hpp"
#include "MatS.hpp"
#include "MatTD.hpp"
#include "Vect.hpp"


using namespace std;
using namespace std::chrono;

int main() {
    try {
        cout << "=== Test Mat (pleine) ===" << endl;
        Mat A(3,3);
        Mat B(3,3);

        // Remplissage simple
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                A(i,j) = i + j + 1;  // exemple : 1 2 3 / 2 3 4 / 3 4 5

        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                B(i,j) = (i==j) ? 1.0 : 0.0; // matrice identité

        cout << "A = \n" << A << endl;
        cout << "B = \n" << B << endl;


        Mat a(2, 2);
        a(0,0) = 1.0; a(0,1) = 2.0;
        a(1,0) = 3.0; a(1,1) = 4.0;

        Mat b = a;
        b(0,0) = 10.0;

        std::cout << a(0,0) << std::endl; // doit afficher 1.0, pas 10.0


        cout << "\n=== Test MatS (carrée) ===" << endl;
        MatS S(10);
        for (int i = 0; i < 10; ++i) 
        {
            for (int j = 0; j < 10; ++j) 
            {
                if (i == j) 
                    S(i, j) = i + 1;       // diagonale : 1, 2, ..., 10
                else
                    S(i, j) = (i + j) % 3 + 1; // valeurs arbitraires hors diagonale
            }
        }
        
        /*for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                S(i,j) = (i<=j) ? i+j+1 : S(j,i);*/ // remplissage symétrique

        cout << "S = \n" << S << endl;
        cout << "Trace(S) = " << S.trace() << endl;
        auto start = high_resolution_clock::now();
        cout << "Det(S) = " << S.det() << endl;
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(end - start);
        cout << "Temps d'exécution : " << duration.count() << " ms" << endl;

        cout << "\n=== Test MatTD (tridiagonale) ===" << endl;
        MatTD T(4);
        for(int i=0;i<4;i++) T(i,i) = 2.0;           // diag principale
        for(int i=0;i<3;i++) {
            T(i,i+1) = -1.0;                        // diag supérieure
            T(i+1,i) = -1.0;                        // diag inférieure
        }
        cout << "T = \n" << T << endl;

        cout << "\n=== Test polymorphisme BMat* ===" << endl;
        BMat* ptr = &S;
        cout << "*ptr (via BMat*) = \n" << *ptr << endl;

        cout << "\n=== Test Vect (vecteur colonne) ===" << endl;
        Vect v(3);
        for(int i=0;i<3;i++) v[i] = i+1;  // [1 2 3]^T
        cout << "v = \n" << v << endl;
        //cout << "A * v = \n" << (A * v) << endl;
        cout << "v * v (produit scalaire) = " << (v * v) << endl;

        cout << "\n=== Tous les tests terminés avec succès ===" << endl;

    } catch (const exception& e) {
        cerr << "Erreur : " << e.what() << endl;
    }

    return 0;
}
