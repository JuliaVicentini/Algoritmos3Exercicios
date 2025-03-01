#include <iostream>
#include <iomanip>
using namespace std;

struct Aluno {
    int notas[4];
    double media;
};

int main() {
    Aluno* aluno = new Aluno;

    for (int i = 0; i < 4; i++) {
        cin >> aluno->notas[i];
    }

    int soma = 0;
    for (int i = 0; i < 4; i++) {
        soma += aluno->notas[i];
    }
    aluno->media = static_cast<double>(soma) / 4;

    cout << fixed << setprecision(2);
    cout << aluno->media << endl;

    return 0;
}