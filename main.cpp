#include <iostream>
<<<<<<< HEAD
#include "SearchingAlgorithm.h"

using namespace std;

int main() {
    cout << "Programme de recherche" << endl;
=======
#include "Complex2D.h"

int main()
{
    Complex2D z1;
    Complex2D z2(2.0, 3.0);
    Complex2D z3(4.0);
    Complex2D z4(z2);

    std::cout << "z2 = "
              << z2.getReel() << " + "
              << z2.getImaginaire() << "i"
              << std::endl;

    std::cout << "z3 = "
              << z3.getReel() << " + "
              << z3.getImaginaire() << "i"
              << std::endl;

    Complex2D addition = z2 + z3;
    Complex2D soustraction = z2 - z3;
    Complex2D multiplication = z2 * z3;
    Complex2D division = z2 / z3;

    std::cout << "Addition : "
              << addition.getReel() << " + "
              << addition.getImaginaire() << "i"
              << std::endl;

    std::cout << "Soustraction : "
              << soustraction.getReel() << " + "
              << soustraction.getImaginaire() << "i"
              << std::endl;

    std::cout << "Multiplication : "
              << multiplication.getReel() << " + "
              << multiplication.getImaginaire() << "i"
              << std::endl;

    std::cout << "Division : "
              << division.getReel() << " + "
              << division.getImaginaire() << "i"
              << std::endl;

    if (z2 < z3)
        std::cout << "z2 < z3" << std::endl;

    if (z2 > z3)
        std::cout << "z2 > z3" << std::endl;
>>>>>>> 7c99bfad8da29e8c1f91d3e027da7d69c72bb4f7

    return 0;
}