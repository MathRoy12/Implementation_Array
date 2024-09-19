//
// Created by matou on 12/09/2024.
//

#ifndef TABLEAUFIXE_H
#define TABLEAUFIXE_H


template<typename T, size_t S>
class TableauFixe {
private:
    T *tabPtr;

public:
    TableauFixe();

    TableauFixe(const TableauFixe &pTableauACopier);

    TableauFixe(TableauFixe &&pTableauAMouvoir);

    int taille() const;

    bool estVide() const;

    T &operator[](size_t pIndex) const;

    TableauFixe &operator=(const TableauFixe &pTableauACopier);

    TableauFixe &operator=(TableauFixe &&pTableauACopier);

    bool operator==(TableauFixe &pTableauACopier);

    T &element(size_t pIndex) const;

    T &premier() const;

    T &dernier() const;

    void remplis(T pValeur);

    void echange(TableauFixe &pTabAEchanger);

    TableauFixe &fusion(TableauFixe &pTabAFusionner);

    template<size_t Size>
    TableauFixe sousEnsemble(int pIndex);

    ~TableauFixe();
};

template<typename T, size_t S>
TableauFixe<T,S>::TableauFixe(){
    tabPtr = new T[S];
}

template<typename T, size_t S>
TableauFixe<T,S>::TableauFixe(const TableauFixe &pTableauACopier) {
    tabPtr = new T[taille()];

    for (int i = 0; i < taille(); i++) {
        tabPtr[i] = pTableauACopier.element(i);
    }
}

template<typename T, size_t S>
TableauFixe<T,S>::TableauFixe(TableauFixe &&pTableauAMouvoir) {
    tabPtr = pTableauAMouvoir.tabPtr;
    pTableauAMouvoir.tabPtr = nullptr;
}

template<typename T, size_t S>
int TableauFixe<T,S>::taille() const {
    return S;
}

template<typename T, size_t S>
bool TableauFixe<T,S>::estVide() const {
    return S == 0;
}

template<typename T, size_t S>
T &TableauFixe<T,S>::operator[](size_t pIndex) const {
    return tabPtr[pIndex];
}

template<typename T, size_t S>
TableauFixe<T,S> &TableauFixe<T,S>::operator=(const TableauFixe &pTableauACopier) {
    if (&pTableauACopier == this) {
        return *this;
    }

    tabPtr = new T[taille()];

    for (int i = 0; i < taille(); i++) {
        tabPtr[i] = pTableauACopier.element(i);
    }

    return *this;
}

template<typename T, size_t S>
TableauFixe<T,S> &TableauFixe<T,S>::operator=(TableauFixe &&pTableauAMouvoir) {
    if (&pTableauAMouvoir == this) {
        return *this;
    }

    tabPtr = pTableauAMouvoir.tabPtr;
    pTableauAMouvoir.tabPtr = nullptr;

    return *this;
}

template<typename T, size_t S>
T &TableauFixe<T,S>::element(size_t pIndex) const {
    if (pIndex >= taille()) {
        throw std::invalid_argument("L'index doit etre inférieure à " + std::to_string(taille()));
    }
    return tabPtr[pIndex];
}

template<typename T, size_t S>
T &TableauFixe<T,S>::premier() const {
    return *tabPtr;
}

template<typename T, size_t S>
T &TableauFixe<T,S>::dernier() const {
    return tabPtr[taille() - 1];
}

template<typename T, size_t S>
void TableauFixe<T,S>::remplis(T pValeur) {
    for (int i = 0; i < taille(); i++) {
        tabPtr[i] = pValeur;
    }
}

template<typename T, size_t S>
template<size_t Size>
TableauFixe<T,S> TableauFixe<T,S>::sousEnsemble(int pIndex) {
    TableauFixe<T,Size> arr();
    for (int i = 0; i < Size; i++) {
        arr[i] = tabPtr[pIndex + i];
    }
    return arr;
}

template<typename T, size_t S>
TableauFixe<T,S>::~TableauFixe() {
    delete[] tabPtr;
}

#endif //TABLEAUFIXE_H
