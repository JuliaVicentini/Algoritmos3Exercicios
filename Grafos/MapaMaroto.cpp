#include <iostream>
#include <list>
using namespace std;

struct no {
    int v;    // vértice adjacente
    int peso; // peso da aresta
};

void cria_aresta(list<no> adj[], int u, int v, int p, int orientado) {
    // Adiciona a aresta u -> v com peso p
    adj[u].push_back({v, p});
    
    // Se o grafo não for orientado, adiciona a aresta v -> u
    if (!orientado) {
        adj[v].push_back({u, p});
    }
}

int main() {
    int num_vertices, orientado;
    cin >> num_vertices >> orientado;

    list<no> adj[num_vertices];

    int u, v, p;
    while (true) {
        cin >> u >> v >> p;
        if (u == -1 && v == -1 && p == -1) {
            break;
        }
        cria_aresta(adj, u, v, p, orientado);
    }

    for (int i = 0; i < num_vertices; ++i) {
        for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
            cout << i << " " << it->v << " " << it->peso << endl;
        }
    }
    return 0;
}