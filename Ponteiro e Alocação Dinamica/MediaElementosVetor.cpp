#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    int N;
    cin >> N;

    int* v = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> *(v + i);
    }

    int soma = 0;
    for (int i = 0; i < N; i++) {
        soma += *(v + i);
    }

    double media = static_cast<double>(soma) / N;

    cout << fixed << setprecision(2);
    cout << media << endl;

    return 0;
}