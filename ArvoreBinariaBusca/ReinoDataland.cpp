#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);
    return root;
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* remove(Node* root, int value) {
    if (!root) return nullptr;
    if (value < root->value)
        root->left = remove(root->left, value);
    else if (value > root->value)
        root->right = remove(root->right, value);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->value = temp->value;
        root->right = remove(root->right, temp->value);
    }
    return root;
}

bool search(Node* root, int value) {
    if (!root) return false;
    if (value == root->value)
        return true;
    else if (value < root->value)
        return search(root->left, value);
    else
        return search(root->right, value);
}

int main() {
    int N;
    cin >> N;
    Node* root = nullptr;

    while (N--) {
        char op;
        int x;
        cin >> op >> x;
        
        if (op == 'i') {
            root = insert(root, x);
        } else if (op == 'r') {
            root = remove(root, x);
        } else if (op == 'b') {
            if (search(root, x))
                cout << "Sim\n";
            else
                cout << "Não\n";
        }
    }
    
    return 0;
}