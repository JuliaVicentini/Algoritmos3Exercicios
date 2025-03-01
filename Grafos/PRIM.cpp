#include <iostream>
#include <list>
using namespace std;

// Estrutura para armazenar os nós da lista de adjacência
struct no {
    int v;     // Vértice de destino
    int peso;  // Peso da aresta
};

// Função para encontrar a árvore geradora mínima (MST) usando o algoritmo de Prim
void prim(list<no> adj[], int nVertices, int start) {
    bool intree[10];       // Array para verificar se o vértice está na árvore geradora mínima
    int distance[10];      // Array para armazenar as distâncias dos vértices para a MST
    int parent[10];        // Array para armazenar os pais dos vértices na MST

    // Inicializa os arrays
    for (int i = 0; i < nVertices; i++) {
        intree[i] = false;     // Nenhum vértice está inicialmente na árvore
        distance[i] = 100000;  // Usamos 100000 como um valor alto para representar o "infinito"
        parent[i] = -1;        // Todos os vértices começam sem pai
    }

    // Define a distância do vértice inicial como 0
    distance[start] = 0;
    int v = start;  // Começa com o vértice inicial

    int totalCost = 0;  // Variável para armazenar o custo total da MST

    // Executa o algoritmo de Prim até que todos os vértices sejam incluídos na árvore
    while (true) {
        int nextVertex = -1;
        int minDist = 100000;  // Inicializa a menor distância como um valor alto

        // Encontra o próximo vértice a ser incluído na árvore
        for (int u = 0; u < nVertices; u++) {
            if (!intree[u] && distance[u] < minDist) {
                minDist = distance[u];
                nextVertex = u;
            }
        }

        // Se não houver mais vértices a serem adicionados, quebra o loop
        if (nextVertex == -1) {
            break;
        }

        // Adiciona o próximo vértice à árvore
        intree[nextVertex] = true;
        totalCost += minDist;  // Adiciona o custo da aresta à árvore geradora mínima

        // Atualiza as distâncias dos vértices adjacentes
        for (auto p = adj[nextVertex].begin(); p != adj[nextVertex].end(); p++) {
            int destino = p->v;
            int weight = p->peso;

            // Se a aresta tem menor peso e o vértice adjacente ainda não está na árvore
            if (weight < distance[destino] && !intree[destino]) {
                distance[destino] = weight;  // Atualiza a menor distância
                parent[destino] = nextVertex; // Define o pai do vértice adjacente
            }
        }
    }

    // Imprime as arestas da árvore geradora mínima
    cout << "Arvore Geradora Minima:" << endl;
    for (int i = 0; i < nVertices; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " " << i << endl;
        }
    }
    cout << "Custo: " << totalCost << endl;
}

int main() {
    int nVertices, isOriented, start;

    // Leitura do número de vértices, se o grafo é orientado e o vértice inicial
    cin >> nVertices >> isOriented >> start;

    // Lista de adjacências para armazenar o grafo
    list<no> adj[10];

    // Leitura das arestas
    int origem, destino, peso;
    while (true) {
        cin >> origem >> destino >> peso;
        if (origem == -1 && destino == -1 && peso == -1) {
            break;  // Encerra a leitura ao encontrar (-1, -1, -1)
        }
        no nodo1 = {destino, peso};
        no nodo2 = {origem, peso};
        adj[origem].push_back(nodo1);  // Adiciona a aresta de origem para destino

        // Se o grafo não for orientado, adiciona a aresta na direção oposta também
        if (!isOriented) {
            adj[destino].push_back(nodo2);
        }
    }

    // Chama a função para encontrar a árvore geradora mínima
    prim(adj, nVertices, start);

    return 0;
}