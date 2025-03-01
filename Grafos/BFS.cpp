#include <iostream>
#include <list>
using namespace std;

// Estrutura para armazenar os nós de adjacência
struct no {
    int v;  // Vértice de destino
    int peso;  // Peso da aresta (não utilizado no BFS, mas faz parte da entrada)
};

// Função para realizar o BFS
void bfs(list<no> adj[], int nVertices, int s) {
    char state[nVertices];  // Array para armazenar o estado de cada vértice ('u', 'd', 'p')
    int pai[nVertices];     // Array para armazenar os pais dos vértices no percurso BFS
    list<int> Q;            // Fila para gerenciar os vértices descobertos

    // Inicialização dos estados e pais
    for (int u = 0; u < nVertices; u++) {
        if (u != s) {
            state[u] = 'u';  // Não descoberto (undiscovered)
            pai[u] = -1;     // Sem pai
        }
    }
    state[s] = 'd';  // Descoberto (discovered)
    pai[s] = -1;     // Vértice inicial não tem pai
    Q.push_back(s);  // Adiciona o vértice inicial à fila

    // Inicia o BFS
    while (!Q.empty()) {
        int u = Q.front();  // Pega o primeiro vértice da fila
        Q.pop_front();      // Remove o vértice da fila
        cout << u << endl;  // Imprime o vértice

        // Itera pelos vértices adjacentes de u
        for (auto p = adj[u].begin(); p != adj[u].end(); p++) {
            int v = p->v;
            cout << u << " " << v << endl;  // Imprime a aresta (u, v)

            if (state[v] == 'u') {  // Se o vértice adjacente não foi descoberto
                state[v] = 'd';     // Marca como descoberto
                pai[v] = u;         // Define o pai do vértice v
                Q.push_back(v);     // Adiciona v à fila
            }
        }
        state[u] = 'p';  // Marca o vértice u como processado (processed)
    }
}

int main() {
    int nVertices, verticeInicial;
    
    // Lê o número de vértices e o vértice inicial
    cin >> nVertices >> verticeInicial;

    // Lista de adjacências para armazenar o grafo
    list<no> adj[nVertices];

    // Leitura das arestas do grafo
    int origem, destino, peso;
    while (true) {
        cin >> origem >> destino >> peso;
        if (origem == -1 && destino == -1 && peso == -1) {
            break;  // Encerra a leitura ao encontrar (-1, -1, -1)
        }
        no nodo1 = {destino, peso};
        no nodo2 = {origem, peso};
        adj[origem].push_back(nodo1);  // Aresta de origem para destino
        adj[destino].push_back(nodo2); // Como o grafo é não orientado, adiciona a aresta na direção oposta também
    }

    // Chama o BFS para realizar o percurso a partir do vértice inicial
    bfs(adj, nVertices, verticeInicial);

    return 0;
}