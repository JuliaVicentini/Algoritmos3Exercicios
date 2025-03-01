#include <iostream>
#include <list>
using namespace std;

list<int> unirListasOrdenadas(list<int>& lista1, list<int>& lista2) {
    list<int> listaUniao; // Lista resultante da união

    auto it1 = lista1.begin(); // Iterador para a primeira lista
    auto it2 = lista2.begin(); // Iterador para a segunda lista

    while (it1 != lista1.end() && it2 != lista2.end()) {
        if (*it1 < *it2) {
            listaUniao.push_back(*it1);
            ++it1;
        } else if (*it2 < *it1) {
            listaUniao.push_back(*it2);
            ++it2;
        } else { // Quando os elementos são iguais
            listaUniao.push_back(*it1);
            ++it1;
            ++it2;
        }
    }

    while (it1 != lista1.end()) {
        listaUniao.push_back(*it1);
        ++it1;
    }

    while (it2 != lista2.end()) {
        listaUniao.push_back(*it2);
        ++it2;
    }

    return listaUniao;
}

int main() {
    list<int> lista1, lista2;

    int numero;
    while (cin >> numero && numero != 0) {
        lista1.push_back(numero);
    }

    while (cin >> numero && numero != 0) {
        lista2.push_back(numero);
    }

    list<int> listaUniao = unirListasOrdenadas(lista1, lista2);

    for (int n : listaUniao) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}