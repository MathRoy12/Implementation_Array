#include <iostream>

#include "TableauFixe.h"


int main() {
    TableauFixe<int,2> tab;
    tab[0] = 8;
    tab[1] = 2;
    std::cout << std::to_string(tab.element(0)) + "," + std::to_string(tab[1]) << std::endl;
    std::cout << std::to_string(tab.taille()) << std::endl;
    std::cout << std::to_string(tab.estVide()) << std::endl;

    TableauFixe<int,3> tab2;
    tab2[0] = 3;
    tab2[1] = 8;
    tab2[2] = 5;
    std::cout << std::to_string(tab2[0]) + "," + std::to_string(tab2[1]) + "," + std::to_string(tab2[2])<< std::endl;
    std::cout << std::to_string(tab2.premier()) << std::endl;
    std::cout << std::to_string(tab2.dernier()) << std::endl;

    tab = tab2.sousEnsemble<2>(1);
    std::cout << std::to_string(tab[0]) + "," + std::to_string(tab[1]) << std::endl;

    return 0;
}
