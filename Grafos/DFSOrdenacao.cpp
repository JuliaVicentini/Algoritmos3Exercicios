#include <iostream>
#include <list>
using namespace std;

// Estrutura para armazenar uma aresta
struct No {
    int vertice;  // V�rtice do grafo
};

// Fun��o para mostrar a ordena��o topol�gica
void ordenacao_topologica(int f[], int nVertices);

// Fun��o para realizar a DFS
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
    f[u] = time; // Tempo de finaliza��o
}

// Fun��o para iniciar a DFS e calcular a ordena��o topol�gica
void dfs(list<No> adj[], int nVertices) {
    bool* color = new bool[nVertices]; // Estado dos v�rtices
    int* pi = new int[nVertices];       // Predecessores
    int* d = new int[nVertices];        // Tempo de descoberta
    int* f = new int[nVertices];        // Tempo de finaliza��o
    int time = 0;                       // Tempo global

    // Inicializa os arrays
    for (int u = 0; u < nVertices; u++) {
        color[u] = false; // Todos os v�rtices n�o descobertos
        pi[u] = -1;       // Sem predecessor
    }

    // Realiza DFS em todos os v�rtices
    for (int u = 0; u < nVertices; u++) {
        if (!color[u]) {
            dfsVisit(u, adj, color, pi, d, f, time);
        }
    }

    // Chama a fun��o para mostrar a ordena��o topol�gica
    ordenacao_topologica(f, nVertices);

    // Libera a mem�ria alocada
    delete[] color;
    delete[] pi;
    delete[] d;
    delete[] f;
}

// Fun��o para mostrar a ordena��o topol�gica em ordem crescente
void ordenacao_topologica(int f[], int nVertices) {
    // Array para armazenar os v�rtices com suas finaliza��es
    pair<int, int>* vertices = new pair<int, int>[nVertices];

    for (int i = 0; i < nVertices; i++) {
        vertices[i] = make_pair(f[i], i);
    }

    // Ordena os v�rtices com base no tempo de finaliza��o (bubble sort)
    for (int i = 0; i < nVertices - 1; i++) {
        for (int j = 0; j < nVertices - i - 1; j++) {
            if (vertices[j].first > vertices[j + 1].first) { // Muda a ordem para crescente
                swap(vertices[j], vertices[j + 1]);
            }
        }
    }

    // Exibe a ordena��o topol�gica em ordem crescente
    for (int i = 0; i < nVertices; i++) {
        cout << vertices[i].second;
        if (i < nVertices - 1) { // N�o imprime espa�o ap�s o �ltimo elemento
            cout << " ";
        }
    }
    cout << endl;

    // Libera a mem�ria alocada
    delete[] vertices;
}

int main() {
    int nVertices, orientado;

    // Leitura do n�mero de v�rtices e se o grafo � orientado
    cin >> nVertices >> orientado;
    list<No>* adj = new list<No>[nVertices];

    // Leitura das arestas
    int origem, destino;
    while (true) {
        cin >> origem >> destino;
        if (origem == -1 && destino == -1) {
            break; // Condi��o de parada
        }
        No novoNo;
        novoNo.vertice = destino;
        adj[origem].push_back(novoNo); // Adiciona aresta

        if (orientado == 0) { // Se o grafo n�o � orientado, adiciona a aresta inversa
            novoNo.vertice = origem;
            adj[destino].push_back(novoNo);
        }
    }

    // Chama a fun��o DFS para calcular a ordena��o topol�gica
    dfs(adj, nVertices);

    delete[] adj; // Libera a mem�ria alocada
    return 0;
}