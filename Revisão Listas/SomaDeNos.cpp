#include <iostream>
#include <list>
using namespace std;

int soma(list<int> lista) {
    int total = 0;
    for (int numero : lista) {
        total += numero;
    }
    return total;
}

int main() {
    list<int> lista;
    int numero;

    while (cin >> numero && numero != 0) {
        lista.push_back(numero);
    }

    cout << soma(lista) << endl;

    return 0;
}