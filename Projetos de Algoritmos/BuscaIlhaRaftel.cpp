#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string array[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                // Troca os elementos
                string temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


int buscaBinaria(string array[], const string& pista, int inicio, int fim) {
    if (inicio > fim) {
        return -1; // Pista não encontrada
    }
    
    int meio = inicio + (fim - inicio) / 2;
    
    if (array[meio] == pista) {
        return meio;
    }
    
    if (pista < array[meio]) {
        return buscaBinaria(array, pista, inicio, meio - 1);
    }
    
    return buscaBinaria(array, pista, meio + 1, fim);
}

int main() {
    const int tamanhoMaximo = 100;
    string array[tamanhoMaximo];
    int quantidade = 0;
    
    while (quantidade < tamanhoMaximo) {
        string entrada;
        getline(cin, entrada);
        
        if (entrada.empty()) {
            break; // Fim da entrada
        }
        
        array[quantidade++] = entrada;
    }
    
    string pista = array[quantidade - 1];
    
    bubbleSort(array, quantidade - 1);
    
    int resultado = buscaBinaria(array, pista, 0, quantidade - 2);
    
    cout << "Índice da pista encontrada: " << resultado << endl;
    
    return 0;
}
