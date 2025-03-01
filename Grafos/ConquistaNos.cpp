#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int adjMatrix[100][100] = {0}; 

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adjMatrix[A-1][B-1] = 1;  // Ajustando para índices começando em 0
        adjMatrix[B-1][A-1] = 1;  // Como o grafo é bidirecional
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
