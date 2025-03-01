#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int contaPrimos(Node* arvore) {
    if (arvore == nullptr) return 0;
    int count = isPrime(arvore->value) ? 1 : 0;
    count += contaPrimos(arvore->left);
    count += contaPrimos(arvore->right);
    return count;
}

int main() {
    Node* root = nullptr;
    int value;

    while (cin >> value && value != -1) {
        root = insert(root, value);
    }

    int totalPrimos = contaPrimos(root);
    cout << totalPrimos << " numeros primos" << endl;

    return 0;
}