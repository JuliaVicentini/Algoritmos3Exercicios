#include <iostream>
#include <list>
using namespace std;

struct No {
    int v;     
    int tempo; 
};

void dijkstra(list<No> adj[], int nCidades, int origem, int destino) {
    bool intree[100];       // Marca se a cidade j� est� na �rvore de caminhos
    int tempo[100];         // Tempo m�nimo da origem para cada cidade
    const int INF = 1000000; // Um valor grande para representar "infinito"
    int parent[100];        // Vetor de pais para reconstruir o caminho

    // Inicializa as dist�ncias e a �rvore
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

        // Seleciona o pr�ximo v�rtice com menor tempo ainda n�o processado
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

    // Sa�da do tempo m�nimo de viagem da origem at� o destino
    if (tempo[destino] == INF) {
        cout << "N�o existe rota entre a cidade " << origem << " e a cidade " << destino << endl;
    } else {
        cout << tempo[destino] << endl;
    }
}

int main() {
    int nCidades, nEstradas;
    
    cin >> nCidades >> nEstradas;

    list<No> adj[100]; // Lista de adjac�ncias para no m�ximo 100 cidades

    for (int i = 0; i < nEstradas; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t}); // Grafo n�o orientado, ent�o adiciona em ambas as dire��es
    }

    int origem, destino;
    // Leitura da cidade de origem e destino
    cin >> origem >> destino;

    // Chama a fun��o de Dijkstra para encontrar o menor tempo de viagem
    dijkstra(adj, nCidades, origem, destino);

    return 0;
}
