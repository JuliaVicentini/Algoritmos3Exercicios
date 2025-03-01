#include <iostream>
#include <list>
#include <climits> // Para usar INT_MAX
using namespace std;

struct Aresta {
    int u, v, c; // u, v são as cidades e c é o custo da conexão
};

// Função para encontrar a raiz de um vértice
int find(int pai[], int i) {
    if (pai[i] == -1)
        return i;
    return find(pai, pai[i]);
}

// Função para unir dois conjuntos
void unionSets(int pai[], int x, int y) {
    int xset = find(pai, x);
    int yset = find(pai, y);
    pai[xset] = yset;
}

// Função para implementar o algoritmo de Kruskal
int kruskal(Aresta arestas[], int N, int M) {
    int custoTotal = 0;
    int pai[100]; // Para armazenar o pai de cada cidade

    // Inicializa o array pai
    for (int i = 0; i < N; i++) {
        pai[i] = -1;
    }

    // Ordena as arestas com base no custo (Bubble Sort para simplicidade)
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < M - i - 1; j++) {
            if (arestas[j].c > arestas[j + 1].c) {
                // Troca as arestas
                Aresta temp = arestas[j];
                arestas[j] = arestas[j + 1];
                arestas[j + 1] = temp;
            }
        }
    }

    // Processa as arestas em ordem de custo
    for (int i = 0; i < M; i++) {
        int u = arestas[i].u;
        int v = arestas[i].v;

        int set_u = find(pai, u);
        int set_v = find(pai, v);

        // Se u e v não estão no mesmo conjunto, une-os
        if (set_u != set_v) {
            unionSets(pai, set_u, set_v);
            custoTotal += arestas[i].c; // Adiciona o custo da aresta
        }
    }
    return custoTotal;
}

int main() {
    int N, M; // N = número de cidades, M = número de conexões
    cin >> N >> M;

    Aresta arestas[100]; // Array para armazenar as arestas

    // Lê as arestas
    for (int i = 0; i < M; i++) {
        cin >> arestas[i].u >> arestas[i].v >> arestas[i].c;
    }

    // Calcula o custo mínimo para conectar todas as cidades
    int custoMinimo = kruskal(arestas, N, M);
    cout << custoMinimo << endl;

    return 0;
}