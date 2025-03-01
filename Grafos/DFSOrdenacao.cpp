#include <iostream>
#include <list>
using namespace std;

// Estrutura para armazenar uma aresta
struct No {
    int vertice;  // Vértice do grafo
};

// Função para mostrar a ordenação topológica
void ordenacao_topologica(int f[], int nVertices);

// Função para realizar a DFS
void dfsVisit(int u, list<No> adj[], bool color[], int pi[], int d[], int f[], int& time) {
    color[u] = true; // Marcar como descoberto
    time++;
    d[u] = time; // Tempo de descoberta

    // Explorar as arestas
    for (auto& v : adj[u]) {
        if (!color[v.vertice]) {
            pi[v.vertice] = u; // Armazenar o predecessor
            dfsVisit(v.vertice, adj, color, pi, d, f, time);
        }
    }

    color[u] = false; // Marcar como processado
    time++;
    f[u] = time; // Tempo de finalização
}

// Função para iniciar a DFS e calcular a ordenação topológica
void dfs(list<No> adj[], int nVertices) {
    bool* color = new bool[nVertices]; // Estado dos vértices
    int* pi = new int[nVertices];       // Predecessores
    int* d = new int[nVertices];        // Tempo de descoberta
    int* f = new int[nVertices];        // Tempo de finalização
    int time = 0;                       // Tempo global

    // Inicializa os arrays
    for (int u = 0; u < nVertices; u++) {
        color[u] = false; // Todos os vértices não descobertos
        pi[u] = -1;       // Sem predecessor
    }

    // Realiza DFS em todos os vértices
    for (int u = 0; u < nVertices; u++) {
        if (!color[u]) {
            dfsVisit(u, adj, color, pi, d, f, time);
        }
    }

    // Chama a função para mostrar a ordenação topológica
    ordenacao_topologica(f, nVertices);

    // Libera a memória alocada
    delete[] color;
    delete[] pi;
    delete[] d;
    delete[] f;
}

// Função para mostrar a ordenação topológica em ordem crescente
void ordenacao_topologica(int f[], int nVertices) {
    // Array para armazenar os vértices com suas finalizações
    pair<int, int>* vertices = new pair<int, int>[nVertices];

    for (int i = 0; i < nVertices; i++) {
        vertices[i] = make_pair(f[i], i);
    }

    // Ordena os vértices com base no tempo de finalização (bubble sort)
    for (int i = 0; i < nVertices - 1; i++) {
        for (int j = 0; j < nVertices - i - 1; j++) {
            if (vertices[j].first > vertices[j + 1].first) { // Muda a ordem para crescente
                swap(vertices[j], vertices[j + 1]);
            }
        }
    }

    // Exibe a ordenação topológica em ordem crescente
    for (int i = 0; i < nVertices; i++) {
        cout << vertices[i].second;
        if (i < nVertices - 1) { // Não imprime espaço após o último elemento
            cout << " ";
        }
    }
    cout << endl;

    // Libera a memória alocada
    delete[] vertices;
}

int main() {
    int nVertices, orientado;

    // Leitura do número de vértices e se o grafo é orientado
    cin >> nVertices >> orientado;
    list<No>* adj = new list<No>[nVertices];

    // Leitura das arestas
    int origem, destino;
    while (true) {
        cin >> origem >> destino;
        if (origem == -1 && destino == -1) {
            break; // Condição de parada
        }
        No novoNo;
        novoNo.vertice = destino;
        adj[origem].push_back(novoNo); // Adiciona aresta

        if (orientado == 0) { // Se o grafo não é orientado, adiciona a aresta inversa
            novoNo.vertice = origem;
            adj[destino].push_back(novoNo);
        }
    }

    // Chama a função DFS para calcular a ordenação topológica
    dfs(adj, nVertices);

    delete[] adj; // Libera a memória alocada
    return 0;
}