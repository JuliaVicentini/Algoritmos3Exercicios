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

int contaFolhas(Node* arvore) {
    if (arvore == nullptr) return 0;

    if (arvore->left == nullptr && arvore->right == nullptr)
        return 1;

    return contaFolhas(arvore->left) + contaFolhas(arvore->right);
}

int main() {
    Node* root = nullptr;
    int value;

    while (cin >> value && value != -1) {
        root = insert(root, value);
    }

    int totalFolhas = contaFolhas(root);
    cout << totalFolhas << endl;

    return 0;
}