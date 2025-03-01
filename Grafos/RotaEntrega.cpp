#include <iostream>
#include <list>
using namespace std;

struct No {
    int v;     
    int tempo; 
};

void dijkstra(list<No> adj[], int nCidades, int origem, int destino) {
    bool intree[100];       // Marca se a cidade já está na árvore de caminhos
    int tempo[100];         // Tempo mínimo da origem para cada cidade
    const int INF = 1000000; // Um valor grande para representar "infinito"
    int parent[100];        // Vetor de pais para reconstruir o caminho

    // Inicializa as distâncias e a árvore
    for (int i = 1; i <= nCidades; i++) {
        intree[i] = false;
        tempo[i] = INF;
        parent[i] = -1;
    }
    tempo[origem] = 0;

    int v = origem;
    while (!intree[v]) {
        intree[v] = true;

        // Atualiza os tempos de viagem para os vizinhos de v
        for (auto p : adj[v]) {
            int destino = p.v;
            int t = p.tempo;
            if (tempo[destino] > tempo[v] + t) {
                tempo[destino] = tempo[v] + t;
                parent[destino] = v;
            }
        }

        // Seleciona o próximo vértice com menor tempo ainda não processado
        v = -1;
        int minTempo = INF;
        for (int i = 1; i <= nCidades; i++) {
            if (!intree[i] && tempo[i] < minTempo) {
                minTempo = tempo[i];
                v = i;
            }
        }

        if (v == -1) break; 
    }

    // Saída do tempo mínimo de viagem da origem até o destino
    if (tempo[destino] == INF) {
        cout << "Não existe rota entre a cidade " << origem << " e a cidade " << destino << endl;
    } else {
        cout << tempo[destino] << endl;
    }
}

int main() {
    int nCidades, nEstradas;
    
    cin >> nCidades >> nEstradas;

    list<No> adj[100]; // Lista de adjacências para no máximo 100 cidades

    for (int i = 0; i < nEstradas; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t}); // Grafo não orientado, então adiciona em ambas as direções
    }

    int origem, destino;
    // Leitura da cidade de origem e destino
    cin >> origem >> destino;

    // Chama a função de Dijkstra para encontrar o menor tempo de viagem
    dijkstra(adj, nCidades, origem, destino);

    return 0;
}
