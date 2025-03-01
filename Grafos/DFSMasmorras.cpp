#include <iostream>
using namespace std;

const int MAX_S = 20; // Limite m�ximo de salas
bool graph[MAX_S][MAX_S]; // Matriz de adjac�ncia para conex�es
int S; // N�mero de salas
bool visited[MAX_S]; // Array para verificar se uma sala foi visitada

// Fun��o recursiva para encontrar o ciclo Hamiltoniano
bool hamiltonianCycle(int pos, int count, int start) {
    if (count == S) { // Se todas as salas foram visitadas
        return graph[pos][start]; // Retorna ao in�cio se houver conex�o
    }

    // Tenta visitar todas as salas
    for (int next = 0; next < S; next++) {
        // Verifica se h� uma conex�o e se n�o foi visitada
        if (graph[pos][next] && !visited[next]) {
            visited[next] = true; // Marca como visitada
            // Chama recursivamente
            if (hamiltonianCycle(next, count + 1, start)) {
                return true;
            }
            visited[next] = false; // Desmarca se n�o for poss�vel
        }
    }
    return false; // N�o encontrou ciclo
}

int main() {
    int C; // N�mero de conex�es
    cin >> S >> C;

    // Inicializa a matriz e o array de visitados
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            graph[i][j] = false;
        }
        visited[i] = false;
    }

    // L� as conex�es
    for (int i = 0; i < C; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        graph[u][v] = true; // Conex�o entre as salas
        graph[v][u] = true; // O grafo � n�o direcionado
    }

    // Come�a a busca pelo ciclo Hamiltoniano
    visited[0] = true; // Come�a da sala 0
    if (hamiltonianCycle(0, 1, 0)) {
        cout << "Yes" << endl; // Ciclo Hamiltoniano encontrado
    } else {
        cout << "No" << endl; // Ciclo Hamiltoniano n�o encontrado
    }

    return 0;
}