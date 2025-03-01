#include <iostream>
#include <list>

using namespace std;

int contar(list<int> lista) {
    return lista.size();
}

int main() {
    list<int> lista;
    int numero;

    while (cin >> numero && numero != 0) {
        lista.push_back(numero);
    }

    cout << contar(lista) << endl;

    return 0;
}