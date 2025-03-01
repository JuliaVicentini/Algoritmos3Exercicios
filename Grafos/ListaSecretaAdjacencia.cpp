#include <iostream>
using namespace std;

struct Node {
    int city;
    Node* next;
};

struct AdjacencyList {
    Node* head;
};

struct Graph {
    int numCities;
    AdjacencyList* list;

    Graph(int n) {
        numCities = n;
        list = new AdjacencyList[n];
        for (int i = 0; i < n; i++) {
            list[i].head = nullptr;
        }
    }

    void addEdge(int u, int v) {
        Node* newNodeU = new Node;
        newNodeU->city = v;
        newNodeU->next = list[u].head;
        list[u].head = newNodeU;

        Node* newNodeV = new Node;
        newNodeV->city = u;
        newNodeV->next = list[v].head;
        list[v].head = newNodeV;
    }

    void printConnections() {
        for (int i = 0; i < numCities; i++) {
            int connections[100]; 
            int count = 0;

            Node* current = list[i].head;
            while (current != nullptr) {
                connections[count++] = current->city + 1; 
                current = current->next;
            }

            for (int j = 0; j < count - 1; j++) {
                for (int k = j + 1; k < count; k++) {
                    if (connections[j] > connections[k]) {
                        int temp = connections[j];
                        connections[j] = connections[k];
                        connections[k] = temp;
                    }
                }
            }

            cout << count;
            for (int j = 0; j < count; j++) {
                cout << " " << connections[j];
            }
            cout << endl;
        }
    }

    ~Graph() {
        for (int i = 0; i < numCities; i++) {
            Node* current = list[i].head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] list;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Graph g(N);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        g.addEdge(A - 1, B - 1);
    }

    g.printConnections();

    return 0;
}