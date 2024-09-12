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
    TableauFixe(int pLongueur);
    TableauFixe(TableauFixe& pTableauACopier);
    TableauFixe(TableauFixe&& pTableauAMouvoir);
    int taille();
    bool estVide();
    T& operator[]();
    T& element(int pIndex);
    T premier();
    T dernier();
    void remplis(T pValeur);
    void echange(TableauFixe& pTabAEchanger);
    TableauFixe& fusion(TableauFixe& pTabAFusionner);
    TableauFixe& sousEnsemble(int pIndex,int pNbElement);
    TableauFixe& sousEnsemble(int pIndex);
};

template<typename T>
TableauFixe<T>::TableauFixe(const int pLongueur) {
    size = pLongueur;
    tabPtr = new T[size];
}

template<typename T>
TableauFixe<T>::TableauFixe(): TableauFixe(0) {
}


#endif //TABLEAUFIXE_H
