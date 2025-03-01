#include <iostream>
#include <iomanip>
using namespace std;

struct node {
    int info;
    node *left, *right;
};

void insert(node *&curr, int new_info) {
    if (curr == NULL) {
        curr = new node;
        curr->info = new_info;
        curr->left = NULL;
        curr->right = NULL;
    } else {
        if (new_info < curr->info) {
            insert(curr->left, new_info);
        } else {
            insert(curr->right, new_info);
        }
    }
}

int soma(node *arvore) {
    if (arvore == NULL) return 0;
    return arvore->info + soma(arvore->left) + soma(arvore->right);
}

int contarNos(node *arvore) {
    if (arvore == NULL) return 0;
    return 1 + contarNos(arvore->left) + contarNos(arvore->right);
}

float media(node *arvore) {
    int totalNos = contarNos(arvore);
    if (totalNos == 0) return 0; 
    int somaTotal = soma(arvore);
    return static_cast<float>(somaTotal) / totalNos;
}

int main() {
    node *root = NULL;
    int N = 0;

    while (cin >> N && N != -1) {
        insert(root, N);
    }

    cout << fixed << setprecision(2);
    cout << "Media: " << media(root) << endl;

    return 0;
}