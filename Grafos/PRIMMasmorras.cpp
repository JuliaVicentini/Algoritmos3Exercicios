#include <iostream>
#include <list>
using namespace std;

// Estrutura para armazenar uma aresta
struct Aresta {
    int sala1;  // Primeiro vértice da aresta
    int sala2;  // Segundo vértice da aresta
    int dificuldade; // Nível de dificuldade da aresta
};

// Estrutura para armazenar informações sobre um conjunto
struct Conjunto {
    int pai;
    int rank;
};

// Função para encontrar o conjunto de um elemento
int encontrar(Conjunto conjuntos[], int i) {
    if (conjuntos[i].pai != i) {
        conjuntos[i].pai = encontrar(conjuntos, conjuntos[i].pai); // Path compression
    }
    return conjuntos[i].pai;
}

// Função para unir dois conjuntos
void unir(Conjunto conjuntos[], int x, int y) {
    int raizX = encontrar(conjuntos, x);
    int raizY = encontrar(conjuntos, y);

    if (raizX != raizY) {
        if (conjuntos[raizX].rank < conjuntos[raizY].rank) {
            conjuntos[raizX].pai = raizY;
        } else if (conjuntos[raizX].rank > conjuntos[raizY].rank) {
            conjuntos[raizY].pai = raizX;
        } else {
            conjuntos[raizY].pai = raizX;
            conjuntos[raizX].rank++;
        }
    }
}

// Função que implementa o algoritmo de Kruskal
void kruskal(int S, int C, Aresta arestas[]) {
    // Ordena as arestas por dificuldade (bubble sort)
    for (int i = 0; i < C - 1; i++) {
        for (int j = 0; j < C - i - 1; j++) {
            if (arestas[j].dificuldade > arestas[j + 1].dificuldade) {
                Aresta temp = arestas[j];
                arestas[j] = arestas[j + 1];
                arestas[j + 1] = temp;
            }
        }
    }

    Conjunto *conjuntos = new Conjunto[S];
    for (int v = 0; v < S; v++) {
        conjuntos[v].pai = v;
        conjuntos[v].rank = 0;
    }

    // Número de arestas na MST
    int count = 0;
    for (int i = 0; i < C; i++) {
        int sala1 = arestas[i].sala1;
        int sala2 = arestas[i].sala2;
        int dificuldade = arestas[i].dificuldade;

        // Verifica se adiciona a aresta ao MST
        if (encontrar(conjuntos, sala1) != encontrar(conjuntos, sala2)) {
            unir(conjuntos, sala1, sala2);
            cout << sala1 << " " << sala2 << " " << dificuldade << endl;
            count++;
        }
        // Se já temos S-1 arestas, a MST está completa
        if (count == S - 1) {
            break;
        }
    }

    delete[] conjuntos;
}

int main() {
    int S, C;

    // Leitura do número de salas e conexões
    cin >> S >> C;
    Aresta *arestas = new Aresta[C];

    // Leitura das arestas
    for (int i = 0; i < C; i++) {
        cin >> arestas[i].sala1 >> arestas[i].sala2 >> arestas[i].dificuldade;
    }

    // Chama a função para encontrar a MST
    kruskal(S, C, arestas);

    delete[] arestas;
    return 0;
}