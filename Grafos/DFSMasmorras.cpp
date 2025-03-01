#include <iostream>
using namespace std;

const int MAX_S = 20; // Limite máximo de salas
bool graph[MAX_S][MAX_S]; // Matriz de adjacência para conexões
int S; // Número de salas
bool visited[MAX_S]; // Array para verificar se uma sala foi visitada

// Função recursiva para encontrar o ciclo Hamiltoniano
bool hamiltonianCycle(int pos, int count, int start) {
    if (count == S) { // Se todas as salas foram visitadas
        return graph[pos][start]; // Retorna ao início se houver conexão
    }

    // Tenta visitar todas as salas
    for (int next = 0; next < S; next++) {
        // Verifica se há uma conexão e se não foi visitada
        if (graph[pos][next] && !visited[next]) {
            visited[next] = true; // Marca como visitada
            // Chama recursivamente
            if (hamiltonianCycle(next, count + 1, start)) {
                return true;
            }
            visited[next] = false; // Desmarca se não for possível
        }
    }
    return false; // Não encontrou ciclo
}

int main() {
    int C; // Número de conexões
    cin >> S >> C;

    // Inicializa a matriz e o array de visitados
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            graph[i][j] = false;
        }
        visited[i] = false;
    }

    // Lê as conexões
    for (int i = 0; i < C; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        graph[u][v] = true; // Conexão entre as salas
        graph[v][u] = true; // O grafo é não direcionado
    }

    // Começa a busca pelo ciclo Hamiltoniano
    visited[0] = true; // Começa da sala 0
    if (hamiltonianCycle(0, 1, 0)) {
        cout << "Yes" << endl; // Ciclo Hamiltoniano encontrado
    } else {
        cout << "No" << endl; // Ciclo Hamiltoniano não encontrado
    }

    return 0;
}