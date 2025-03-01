#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int* v = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> *(v + i);
    }

    int maior = *v;

    for (int i = 1; i < N; i++) {
        if (*(v + i) > maior) {
            maior = *(v + i);
        }
    }

    cout << maior << endl;

    return 0;
}