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
    tab[0] = 3;
    tab[1] = 8;
    tab[2] = 5;
    std::cout << std::to_string(tab[0]) + "," + std::to_string(tab[1]) + "," + std::to_string(tab[2])<< std::endl;
    std::cout << std::to_string(tab.premier()) << std::endl;
    std::cout << std::to_string(tab.dernier()) << std::endl;

    return 0;
}
