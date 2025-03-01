#include <iostream>
#include <list>
using namespace std;

int main() {
    int N; // Número de operações
    cin >> N;

    list<int> estoque; // Lista para produtos no estoque
    list<int> venda;   // Lista para produtos disponíveis para venda

    for (int i = 0; i < N; i++) {
        int operacao;
        cin >> operacao;

        if (operacao == 1) {
            int codigoProduto;
            cin >> codigoProduto;
            estoque.push_back(codigoProduto);
        } else if (operacao == 2) {
            
            if (!estoque.empty()) {
                venda.push_front(estoque.front()); 
                estoque.pop_front();
            }
        }
    }

    cout << "Estoque:";
    if (!estoque.empty()) {
        for (int codigo : estoque) {
            cout << " " << codigo;
        }
    }
    cout << " " << endl; 

    cout << "Venda:";
    if (!venda.empty()) {
        for (int codigo : venda) {
            cout << " " << codigo;
        }
    }
    cout << " " << endl; 

    return 0;
}