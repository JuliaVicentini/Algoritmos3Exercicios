#include <iostream>
#include <list>
using namespace std;

// Estrutura para armazenar os n�s da lista de adjac�ncia
struct no {
    int v;     // V�rtice de destino
    int peso;  // Peso da aresta
};

// Fun��o para implementar o algoritmo de Dijkstra
void dijkstra(list<no> adj[], int nVertices, int start, int end) {
    bool intree[10];          // Array para verificar se o v�rtice est� na �rvore
    int distance[10];         // Array para armazenar as dist�ncias dos v�rtices
    int parent[10];           // Array para armazenar os pais dos v�rtices

    // Inicializa os arrays
    for (int i = 0; i < nVertices; i++) {
        intree[i] = false;     // Nenhum v�rtice est� inicialmente na �rvore
        distance[i] = 100000;  // Usamos 100000 como um valor alto para representar o "infinito"
        parent[i] = -1;        // Todos os v�rtices come�am sem pai
    }

    distance[start] = 0;  // A dist�ncia do v�rtice inicial � 0
    int v = start;        // Come�a com o v�rtice inicial

    // Executa o algoritmo de Dijkstra
    while (true) {
        int nextVertex = -1;
        int minDist = 100000;  // Inicializa a menor dist�ncia como um valor alto

        // Encontra o pr�ximo v�rtice a ser inclu�do na �rvore
        for (int u = 0; u < nVertices; u++) {
            if (!intree[u] && distance[u] < minDist) {
                minDist = distance[u];
                nextVertex = u;
            }
        }

        // Se n�o houver mais v�rtices a serem adicionados, quebra o loop
        if (nextVertex == -1) {
            break;
        }

        // Adiciona o pr�ximo v�rtice � �rvore
        intree[nextVertex] = true;

        // Atualiza as dist�ncias dos v�rtices adjacentes
        for (auto p = adj[nextVertex].begin(); p != adj[nextVertex].end(); p++) {
            int destino = p->v;
            int weight = p->peso;

            // Se a nova dist�ncia for menor
            if (distance[destino] > distance[nextVertex] + weight) {
                distance[destino] = distance[nextVertex] + weight; // Atualiza a menor dist�ncia
                parent[destino] = nextVertex; // Define o pai do v�rtice adjacente
            }
        }
    }

    // Mostra o caminho mais curto
    if (distance[end] == 100000) {
        cout << "Caminho n�o encontrado" << endl;
    } else {
        cout << "Menor caminho: ";
        int current = end;
        list<int> path;  // Lista para armazenar o caminho
        while (current != -1) {
            path.push_front(current); // Adiciona o v�rtice ao in�cio da lista
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

    // Leitura do n�mero de v�rtices, se o grafo � orientado, e os v�rtices inicial e final
    cin >> nVertices >> isOriented >> start >> end;

    // Lista de adjac�ncias para armazenar o grafo
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

        // Se o grafo n�o for orientado, adiciona a aresta na dire��o oposta tamb�m
        if (!isOriented) {
            no nodo2 = {origem, peso};
            adj[destino].push_back(nodo2);
        }
    }

    // Chama a fun��o para encontrar o menor caminho
    dijkstra(adj, nVertices, start, end);

    return 0;
}