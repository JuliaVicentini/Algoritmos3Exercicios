#include <iostream>
#include <list>
using namespace std;

bool encontrar(list<int> lista, int x) {
    for (int numero : lista) {
        if (numero == x) {
            return true;
        }
    }
    return false;
}

int main() {
    list<int> lista;
    int numero;

    while (cin >> numero && numero != 0) {
        lista.push_back(numero);
    }

    int x;
    cin >> x;

    if (encontrar(lista, x)) {
        cout << "Encontrado" << endl;
    } else {
        cout << "Nao encontrado" << endl;
    }

    return 0;
}
