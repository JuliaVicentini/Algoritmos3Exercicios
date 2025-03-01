#include <iostream>
#include <list>
using namespace std;

const int INF = 1000000; 

void dijkstra(int S, list<pair<int, int>> adj[], int origem) {
    bool visitado[1000] = {false};  
    int distancia[1000];            
    
    for (int i = 0; i < S; i++) {
        distancia[i] = INF;
    }
    
    distancia[origem] = 0;

    // Fila manual para simular o comportamento de uma fila de prioridade
    int fila[1000], inicio = 0, fim = 0;
    fila[fim++] = origem;  // Insere a sala de origem na fila

    // Enquanto houver salas para processar
    while (inicio < fim) {
        // Remove a primeira sala da fila
        int sala = fila[inicio++];
        visitado[sala] = true;

        // Percorre todas as conexões dessa sala
        for (auto conexao : adj[sala]) {
            int vizinho = conexao.first;  // Sala vizinha
            int dificuldade = conexao.second;  // Nível de dificuldade da travessia

            // Relaxamento: se for possível melhorar o caminho até o vizinho, atualizamos
            if (!visitado[vizinho] && distancia[vizinho] > distancia[sala] + dificuldade) {
                distancia[vizinho] = distancia[sala] + dificuldade;
                fila[fim++] = vizinho;  // Adiciona o vizinho à fila para processar posteriormente
            }
        }
    }

    // Exibe as distâncias da sala 0 para as demais
    for (int i = 1; i < S; i++) {
        cout << distancia[i] << endl;
    }
}

int main() {
    int S, C;
    cin >> S >> C;

    list<pair<int, int>> adj[1000];

    for (int i = 0; i < C; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        adj[u].push_back(make_pair(v, k));
        adj[v].push_back(make_pair(u, k));  // O grafo é não-direcionado
    }

    // Chama o algoritmo de Dijkstra a partir da sala 0
    dijkstra(S, adj, 0);

    return 0;
}
