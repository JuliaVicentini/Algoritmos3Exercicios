#include <iostream>
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

// Função para encontrar o menor elemento da árvore
int menor(node *arvore) {
    if (arvore == NULL) {
        return -1;
    }
    node *curr = arvore;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr->info;
}

// Função para encontrar o maior elemento da árvore
int maior(node *arvore) {
    if (arvore == NULL) {
        return -1;
    }
    node *curr = arvore;
    while (curr->right != NULL) {
        curr = curr->right; 
    }
    return curr->info;
}

int main() {
    node *root = NULL;
    int N = 0;

    while (cin >> N && N != -1) {
        insert(root, N);
    }

    int menorElemento = menor(root);
    int maiorElemento = maior(root);

    cout << menorElemento << " e " << maiorElemento << endl;

    return 0;
}