#include <iostream>
#include <list>
using namespace std;

// Estrutura para armazenar os n�s da lista de adjac�ncia
struct no {
    int v;     // V�rtice de destino
    int peso;  // Peso da aresta
};

// Fun��o para encontrar a �rvore geradora m�nima (MST) usando o algoritmo de Prim
void prim(list<no> adj[], int nVertices, int start) {
    bool intree[10];       // Array para verificar se o v�rtice est� na �rvore geradora m�nima
    int distance[10];      // Array para armazenar as dist�ncias dos v�rtices para a MST
    int parent[10];        // Array para armazenar os pais dos v�rtices na MST

    // Inicializa os arrays
    for (int i = 0; i < nVertices; i++) {
        intree[i] = false;     // Nenhum v�rtice est� inicialmente na �rvore
        distance[i] = 100000;  // Usamos 100000 como um valor alto para representar o "infinito"
        parent[i] = -1;        // Todos os v�rtices come�am sem pai
    }

    // Define a dist�ncia do v�rtice inicial como 0
    distance[start] = 0;
    int v = start;  // Come�a com o v�rtice inicial

    int totalCost = 0;  // Vari�vel para armazenar o custo total da MST

    // Executa o algoritmo de Prim at� que todos os v�rtices sejam inclu�dos na �rvore
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
        totalCost += minDist;  // Adiciona o custo da aresta � �rvore geradora m�nima

        // Atualiza as dist�ncias dos v�rtices adjacentes
        for (auto p = adj[nextVertex].begin(); p != adj[nextVertex].end(); p++) {
            int destino = p->v;
            int weight = p->peso;

            // Se a aresta tem menor peso e o v�rtice adjacente ainda n�o est� na �rvore
            if (weight < distance[destino] && !intree[destino]) {
                distance[destino] = weight;  // Atualiza a menor dist�ncia
                parent[destino] = nextVertex; // Define o pai do v�rtice adjacente
            }
        }
    }

    // Imprime as arestas da �rvore geradora m�nima
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

    // Leitura do n�mero de v�rtices, se o grafo � orientado e o v�rtice inicial
    cin >> nVertices >> isOriented >> start;

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
        no nodo2 = {origem, peso};
        adj[origem].push_back(nodo1);  // Adiciona a aresta de origem para destino

        // Se o grafo n�o for orientado, adiciona a aresta na dire��o oposta tamb�m
        if (!isOriented) {
            adj[destino].push_back(nodo2);
        }
    }

    // Chama a fun��o para encontrar a �rvore geradora m�nima
    prim(adj, nVertices, start);

    return 0;
}