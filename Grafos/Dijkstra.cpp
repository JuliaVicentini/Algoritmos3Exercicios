#include <iostream>
#include <list>
using namespace std;

// Estrutura para armazenar os nós da lista de adjacência
struct no {
    int v;     // Vértice de destino
    int peso;  // Peso da aresta
};

// Função para implementar o algoritmo de Dijkstra
void dijkstra(list<no> adj[], int nVertices, int start, int end) {
    bool intree[10];          // Array para verificar se o vértice está na árvore
    int distance[10];         // Array para armazenar as distâncias dos vértices
    int parent[10];           // Array para armazenar os pais dos vértices

    // Inicializa os arrays
    for (int i = 0; i < nVertices; i++) {
        intree[i] = false;     // Nenhum vértice está inicialmente na árvore
        distance[i] = 100000;  // Usamos 100000 como um valor alto para representar o "infinito"
        parent[i] = -1;        // Todos os vértices começam sem pai
    }

    distance[start] = 0;  // A distância do vértice inicial é 0
    int v = start;        // Começa com o vértice inicial

    // Executa o algoritmo de Dijkstra
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

        // Atualiza as distâncias dos vértices adjacentes
        for (auto p = adj[nextVertex].begin(); p != adj[nextVertex].end(); p++) {
            int destino = p->v;
            int weight = p->peso;

            // Se a nova distância for menor
            if (distance[destino] > distance[nextVertex] + weight) {
                distance[destino] = distance[nextVertex] + weight; // Atualiza a menor distância
                parent[destino] = nextVertex; // Define o pai do vértice adjacente
            }
        }
    }

    // Mostra o caminho mais curto
    if (distance[end] == 100000) {
        cout << "Caminho não encontrado" << endl;
    } else {
        cout << "Menor caminho: ";
        int current = end;
        list<int> path;  // Lista para armazenar o caminho
        while (current != -1) {
            path.push_front(current); // Adiciona o vértice ao início da lista
            current = parent[current];  // Move para o pai
        }
        
        // Imprime o caminho
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
        cout << "Custo: " << distance[end] << endl; // Imprime o custo total
    }
}

int main() {
    int nVertices, isOriented, start, end;

    // Leitura do número de vértices, se o grafo é orientado, e os vértices inicial e final
    cin >> nVertices >> isOriented >> start >> end;

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
        adj[origem].push_back(nodo1);  // Adiciona a aresta de origem para destino

        // Se o grafo não for orientado, adiciona a aresta na direção oposta também
        if (!isOriented) {
            no nodo2 = {origem, peso};
            adj[destino].push_back(nodo2);
        }
    }

    // Chama a função para encontrar o menor caminho
    dijkstra(adj, nVertices, start, end);

    return 0;
}