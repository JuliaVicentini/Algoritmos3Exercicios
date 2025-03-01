#include <iostream>
#include <iomanip>
using namespace std;

struct Aluno {
    int notas[4];
    double media;
};

int main() {
    int N; 
    
    cin >> N;

    Aluno* alunos = new Aluno[N];

    for (int i = 0; i < N; i++) {
        int soma = 0;
        for (int j = 0; j < 4; j++) {
            cin >> alunos[i].notas[j];
            soma += alunos[i].notas[j];
        }
        alunos[i].media = static_cast<double>(soma) / 4;
    }

    double somaMedias = 0;
    for (int i = 0; i < N; i++) {
        somaMedias += alunos[i].media;
    }
    double mediaTurma = somaMedias / N;

    cout << fixed << setprecision(2);
    cout << mediaTurma << endl;

    return 0;
}