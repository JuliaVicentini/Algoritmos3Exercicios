#include <iostream>
using namespace std;

struct no {
    int v;
    no* next;
};

struct AdjList {
    no* head;
};

struct Graph {
    int numVertices;
    AdjList* list;

    Graph(int V) {
        numVertices = V;
        list = new AdjList[V];
        for (int i = 0; i < V; i++) {
            list[i].head = nullptr;
        }
    }

    void addEdge(int src, int dest) {
        no* newNode = new no;
        newNode->v = dest;
        newNode->next = list[src].head;
        list[src].head = newNode;

        newNode = new no;
        newNode->v = src;
        newNode->next = list[dest].head;
        list[dest].head = newNode;
    }

    void bfs(int start, bool visited[]) {
        int Q[100], front = 0, rear = 0;
        Q[rear++] = start;
        visited[start] = true;

        while (front != rear) {
            int u = Q[front++];
            no* p = list[u].head;
            while (p != nullptr) {
                int v = p->v;
                if (!visited[v]) {
                    visited[v] = true;
                    Q[rear++] = v;
                }
                p = p->next;
            }
        }
    }

    bool isConnected(int start) {
        bool visited[10] = {false};
        bfs(start, visited);

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            no* current = list[i].head;
            while (current != nullptr) {
                no* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] list;
    }
};

int main() {
    int numVertices, startVertex;
    cin >> numVertices >> startVertex;

    Graph g(numVertices);

    while (true) {
        int src, dest;
        cin >> src >> dest;
        if (src == -1 && dest == -1) {
            break;
        }
        g.addEdge(src, dest);
    }

    if (g.isConnected(startVertex)) {
        cout << "Conexo" << endl;
    } else {
        cout << "Nao conexo" << endl;
    }

    return 0;
}