#include <iostream>
using namespace std;

const int MAX = 100;
bool adjMatrix[MAX][MAX];  // Matriz de adjacência para armazenar o grafo
bool visited[MAX];  // Vetor para marcar as cidades visitadas

// Função para inicializar a matriz de adjacência
void initializeMatrix(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = false;
        }
        visited[i] = false;
    }
}

// Função de busca em profundidade (DFS)
void dfs(int u, int n) {
    visited[u] = true;
    for (int v = 0; v < n; v++) {
        if (adjMatrix[u][v] && !visited[v]) {
            dfs(v, n);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;  // Número de cidades (nós) e caminhos (arestas)

    // Inicializa a matriz de adjacência
    initializeMatrix(N);

    // Lê as arestas e preenche a matriz de adjacência
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adjMatrix[A-1][B-1] = true;
        adjMatrix[B-1][A-1] = true;
    }

    // Lê a ponte que será destruída
    int X, Y;
    cin >> X >> Y;

    // Remove a ponte da matriz de adjacência
    adjMatrix[X-1][Y-1] = false;
    adjMatrix[Y-1][X-1] = false;

    // Realiza uma DFS a partir da cidade X para encontrar cidades acessíveis
    dfs(X-1, N);

    // Verifica quais cidades ficaram inacessíveis
    bool isolated = true;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && i != (X-1)) {
            cout << i+1 << " ";  // Imprime as cidades inacessíveis
            isolated = false;
        }
    }

    if (isolated) {
        cout << "Nenhuma cidade se tornou inacessível";
    }

    cout << endl;

    return 0;
}