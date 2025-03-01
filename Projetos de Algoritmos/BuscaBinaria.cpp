#include <iostream>
using namespace std;

int buscaBinaria(int vetor[], int valor, int inicio, int fim) {
    if (inicio > fim) {
        return -1; // Valor não encontrado
    }
    
    int meio = inicio + (fim - inicio) / 2;
    
    if (vetor[meio] == valor) {
        return meio;
    }
    
    if (valor < vetor[meio]) {
        return buscaBinaria(vetor, valor, inicio, meio - 1);
    }
    
    return buscaBinaria(vetor, valor, meio + 1, fim);
}

int main() {
    int N;
    cin >> N; 
    
    int* vetor = new int[N];
    
    for (int i = 0; i < N; ++i) {
        cin >> vetor[i];
    }
    
    int valor;
    cin >> valor; 
    
    int resultado = buscaBinaria(vetor, valor, 0, N - 1);
    
    cout << resultado << endl;
    
    return 0;
}
