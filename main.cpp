#include <iostream>

#include "TableauFixe.h"

int main() {
    TableauFixe<int> tab(2);
    tab[0] = 8;
    tab[1] = 2;
    std::cout << std::to_string(tab.element(0)) + "," + std::to_string(tab[1]) << std::endl;
    std::cout << std::to_string(tab.taille()) << std::endl;
    std::cout << std::to_string(tab.estVide()) << std::endl;

    int arr[3] = {4, 5, 7};
    TableauFixe<int> tab2(3, arr);
    std::cout << std::to_string(tab2.element(0)) + "," + std::to_string(tab2[1]) << std::endl;
    std::cout << std::to_string(tab2.premier()) << std::endl;
    std::cout << std::to_string(tab2.dernier()) << std::endl;

    tab2.remplis(6);
    std::cout << std::to_string(tab2[0]) + "," + std::to_string(tab2[1]) + "," + std::to_string(tab2[2]) << std::endl;

    TableauFixe<int> tab3(tab2);
    std::cout << std::to_string(tab2[0]) + "," + std::to_string(tab2[1]) + "," + std::to_string(tab2[2]) << std::endl;

    return 0;
}
