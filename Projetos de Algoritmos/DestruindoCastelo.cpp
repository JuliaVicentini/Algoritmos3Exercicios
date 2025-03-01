#include <iostream>

using namespace std;

int maxDestruicao(int capacidade, int projeteis[][2], int n) {
    int dp[capacidade + 1] = {0};

    for (int i = 0; i < n; ++i) {
        int poder = projeteis[i][0];
        int peso = projeteis[i][1];
        
        for (int j = capacidade; j >= peso; --j) {
            if (dp[j - peso] + poder > dp[j]) {
                dp[j] = dp[j - peso] + poder;
            }
        }
    }
    
    return dp[capacidade];
}

int main() {
    int casos;
    cin >> casos;
    
    while (casos--) {
        int N;
        cin >> N;
        
        int projeteis[50][2];
        
        for (int i = 0; i < N; ++i) {
            int poder, peso;
            cin >> poder >> peso;
            projeteis[i][0] = poder;
            projeteis[i][1] = peso;
        }
        
        int capacidade;
        cin >> capacidade;
        
        int resistencia;
        cin >> resistencia;
        
        int danoMaximo = maxDestruicao(capacidade, projeteis, N);
        
        if (danoMaximo >= resistencia) {
            cout << "Missao completada com sucesso" << endl;
        } else {
            cout << "Falha na missao" << endl;
        }
    }
    
    return 0;
}
