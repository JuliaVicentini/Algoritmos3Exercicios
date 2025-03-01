#include <iostream>
#include <list>
using namespace std;

void bfs(int nSalas, list<int> adj[], int entrada, int dragao) {
    bool visitado[1001] = {false};  
    int distancia[1001] = {0};      
    int parent[1001];               
    int fila[1001];                 
    int inicio = 0, fim = 0;    

    for (int i = 1; i <= nSalas; i++) {
        parent[i] = -1;
    }

    // Adiciona a sala de entrada na fila
    fila[fim++] = entrada;
    visitado[entrada] = true;
    distancia[entrada] = 1;         // A entrada é o primeiro vértice no caminho

    // Início da BFS simulando uma fila manualmente
    while (inicio < fim) {
        int sala = fila[inicio++];
        
        // Visita todos os vizinhos da sala atual
        for (int vizinho : adj[sala]) {
            if (!visitado[vizinho]) {
                visitado[vizinho] = true;
                distancia[vizinho] = distancia[sala] + 1;
                parent[vizinho] = sala;
                fila[fim++] = vizinho; // Adiciona o vizinho à fila

                // Se chegarmos à sala onde o dragão está, podemos parar
                if (vizinho == dragao) {
                    break;
                }
            }
        }
    }

    // Verifica se o dragão foi alcançado
    if (!visitado[dragao]) {
        cout << "IMPOSSIVEL" << endl;
    } else {
        cout << distancia[dragao] << endl;
    }
}

int main() {
    int nSalas, nCorredores;
    
    cin >> nSalas >> nCorredores;

    list<int> adj[1001];

    // Leitura dos corredores e construção do grafo
    for (int i = 0; i < nCorredores; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // O grafo é não direcionado
    }

    int entrada, dragao;
    cin >> entrada >> dragao;

    // Chama a função BFS para encontrar o menor caminho
    bfs(nSalas, adj, entrada, dragao);

    return 0;
}
