#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

bool search(Node* root, int x) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == x) {
        return true;
    } else if (x < root->data) {
        return search(root->left, x);
    } else {
        return search(root->right, x);
    }
}

int main() {
    int N, X;
    cin >> N;

    Node* root = nullptr;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        root = insert(root, num);
    }

    cin >> X;

    if (search(root, X)) {
        cout << "Encontrado" << endl;
    } else {
        cout << "Nao encontrado" << endl;
    }

    return 0;
}