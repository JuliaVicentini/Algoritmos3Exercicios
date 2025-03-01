#include <iostream>
#include <list>
using namespace std;

// Estrutura para armazenar os n�s de adjac�ncia
struct no {
    int v;  // V�rtice de destino
    int peso;  // Peso da aresta (n�o utilizado no BFS, mas faz parte da entrada)
};

// Fun��o para realizar o BFS
void bfs(list<no> adj[], int nVertices, int s) {
    char state[nVertices];  // Array para armazenar o estado de cada v�rtice ('u', 'd', 'p')
    int pai[nVertices];     // Array para armazenar os pais dos v�rtices no percurso BFS
    list<int> Q;            // Fila para gerenciar os v�rtices descobertos

    // Inicializa��o dos estados e pais
    for (int u = 0; u < nVertices; u++) {
        if (u != s) {
            state[u] = 'u';  // N�o descoberto (undiscovered)
            pai[u] = -1;     // Sem pai
        }
    }
    state[s] = 'd';  // Descoberto (discovered)
    pai[s] = -1;     // V�rtice inicial n�o tem pai
    Q.push_back(s);  // Adiciona o v�rtice inicial � fila

    // Inicia o BFS
    while (!Q.empty()) {
        int u = Q.front();  // Pega o primeiro v�rtice da fila
        Q.pop_front();      // Remove o v�rtice da fila
        cout << u << endl;  // Imprime o v�rtice

        // Itera pelos v�rtices adjacentes de u
        for (auto p = adj[u].begin(); p != adj[u].end(); p++) {
            int v = p->v;
            cout << u << " " << v << endl;  // Imprime a aresta (u, v)

            if (state[v] == 'u') {  // Se o v�rtice adjacente n�o foi descoberto
                state[v] = 'd';     // Marca como descoberto
                pai[v] = u;         // Define o pai do v�rtice v
                Q.push_back(v);     // Adiciona v � fila
            }
        }
        state[u] = 'p';  // Marca o v�rtice u como processado (processed)
    }
}

int main() {
    int nVertices, verticeInicial;
    
    // L� o n�mero de v�rtices e o v�rtice inicial
    cin >> nVertices >> verticeInicial;

    // Lista de adjac�ncias para armazenar o grafo
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
        adj[destino].push_back(nodo2); // Como o grafo � n�o orientado, adiciona a aresta na dire��o oposta tamb�m
    }

    // Chama o BFS para realizar o percurso a partir do v�rtice inicial
    bfs(adj, nVertices, verticeInicial);

    return 0;
}