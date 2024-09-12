//
// Created by matou on 12/09/2024.
//

#ifndef TABLEAUFIXE_H
#define TABLEAUFIXE_H



template <typename T> class TableauFixe {
private:
    T *tabPtr;
    size_t size;
public:
    TableauFixe();
    TableauFixe( int pLongueur);
    TableauFixe(TableauFixe& pTableauACopier);
    TableauFixe(TableauFixe&& pTableauAMouvoir);
    int taille();
    bool estVide() const;
    T& operator[](int pIndex);
    T& element(int pIndex);
    T premier();
    T dernier();
    void remplis(T pValeur);
    void echange(TableauFixe& pTabAEchanger);
    TableauFixe& fusion(TableauFixe& pTabAFusionner);
    TableauFixe& sousEnsemble(int pIndex,int pNbElement);
    TableauFixe& sousEnsemble(int pIndex);
    ~TableauFixe();
};

template<typename T>
TableauFixe<T>::TableauFixe(const int pLongueur) {
    size = pLongueur;
    tabPtr = new T[size];
}

template<typename T>
TableauFixe<T>::TableauFixe(): TableauFixe(0) {
}

template<typename T>
int TableauFixe<T>::taille() {
    return size;
}

template<typename T>
bool TableauFixe<T>::estVide() const {
    return size == 0;
}

template<typename T>
T &TableauFixe<T>::operator[](int pIndex) {
    return (*tabPtr)[pIndex];
}


#endif //TABLEAUFIXE_H
