#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    
    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);
    
    return root;
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* remove(Node* root, int value) {
    if (!root) return nullptr;

    if (value < root->value) {
        root->left = remove(root->left, value);
    } else if (value > root->value) {
        root->right = remove(root->right, value);
    } else {
        // Caso 1: Nó folha ou com um único filho
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Caso 2: Nó com dois filhos
        Node* temp = findMin(root->right);
        root->value = temp->value;
        root->right = remove(root->right, temp->value);
    }
    return root;
}

Node* removeAllOccurrences(Node* root, int value) {
    Node* newRoot = root;
    while (newRoot && newRoot->value == value) {
        newRoot = remove(newRoot, value);
    }
    if (newRoot) {
        newRoot->left = removeAllOccurrences(newRoot->left, value);
        newRoot->right = removeAllOccurrences(newRoot->right, value);
    }
    return newRoot;
}

// Função principal
int main() {
    Node* root = nullptr;
    int num;

    while (cin >> num && num != 0) {
        root = insert(root, num);
    }

    int x;
    cin >> x;

    root = removeAllOccurrences(root, x);

    inOrder(root);
    cout << endl;

    return 0;
}