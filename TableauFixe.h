//
// Created by matou on 12/09/2024.
//

#ifndef TABLEAUFIXE_H
#define TABLEAUFIXE_H


template<typename T>
class TableauFixe {
private:
    T *tabPtr;
    size_t size;

public:
    TableauFixe();

    TableauFixe(int pLongueur);

    TableauFixe(int pLongueur, T pArray[]);

    TableauFixe(TableauFixe &pTableauACopier);

    TableauFixe(TableauFixe &&pTableauAMouvoir);

    int taille() const;

    bool estVide() const;

    T &operator[](int pIndex);

    T &element(int pIndex);

    T premier();

    T dernier();

    void remplis(T pValeur);

    void echange(TableauFixe &pTabAEchanger);

    TableauFixe &fusion(TableauFixe &pTabAFusionner);

    template<size_t S>
    TableauFixe sousEnsemble(int pIndex);

    ~TableauFixe();
};

template<typename T>
TableauFixe<T>::TableauFixe(): TableauFixe(0) {
}

template<typename T>
TableauFixe<T>::TableauFixe(const int pLongueur) {
    size = pLongueur;
    tabPtr = new T[taille()];
}

template<typename T>
TableauFixe<T>::TableauFixe(const int pLongueur, T pArray[]) {
    size = pLongueur;
    tabPtr = new T[taille()];
    for (int i = 0; i < taille(); i++) {
        tabPtr[i] = pArray[i];
    }
}

template<typename T>
TableauFixe<T>::TableauFixe(TableauFixe &pTableauACopier) {
    size = pTableauACopier.taille();
    tabPtr = new T[taille()];

    for (int i = 0; i < taille(); i++) {
        tabPtr[i] = pTableauACopier.element(i);
    }
}

template<typename T>
TableauFixe<T>::TableauFixe(TableauFixe &&pTableauAMouvoir) {
    size = pTableauAMouvoir.taille();
    tabPtr = pTableauAMouvoir.tabPtr;
    pTableauAMouvoir.tabPtr = nullptr;
    pTableauAMouvoir.size = 0;
}

template<typename T>
int TableauFixe<T>::taille() const {
    return size;
}

template<typename T>
bool TableauFixe<T>::estVide() const {
    return size == 0;
}

template<typename T>
T &TableauFixe<T>::operator[](int pIndex) {
    return tabPtr[pIndex];
}

template<typename T>
T &TableauFixe<T>::element(int pIndex) {
    if (pIndex < 0 || pIndex >= taille()) {
        throw std::invalid_argument("L'index doit etre entre 0 et " + std::to_string(pIndex));
    }
    return tabPtr[pIndex];
}

template<typename T>
T TableauFixe<T>::premier() {
    return *tabPtr;
}

template<typename T>
T TableauFixe<T>::dernier() {
    return tabPtr[taille() - 1];
}

template<typename T>
void TableauFixe<T>::remplis(T pValeur) {
    for (int i = 0; i < taille(); i++) {
        tabPtr[i] = pValeur;
    }
}

template<typename T>
template<size_t S>
TableauFixe<T> TableauFixe<T>::sousEnsemble(int pIndex) {
    TableauFixe<T> arr(S);
    for (int i = 0; i < S; i++) {
        arr[i] = tabPtr[pIndex + i];
    }
    return arr;
}


template<typename T>
TableauFixe<T>::~TableauFixe() {
    delete[] tabPtr;
}

#endif //TABLEAUFIXE_H
