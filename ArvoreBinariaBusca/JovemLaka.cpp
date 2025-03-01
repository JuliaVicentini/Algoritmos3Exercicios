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

int preOrder(Node* root, int target, int& count) {
    if (root == nullptr) return -1;
    if (root->value == target) return count;
    count++;
    int left = preOrder(root->left, target, count);
    if (left != -1) return left;
    int right = preOrder(root->right, target, count);
    return right;
}

int inOrder(Node* root, int target, int& count) {
    if (root == nullptr) return -1;
    int left = inOrder(root->left, target, count);
    if (left != -1) return left;
    if (root->value == target) return count;
    count++;
    int right = inOrder(root->right, target, count);
    return right;
}

int postOrder(Node* root, int target, int& count) {
    if (root == nullptr) return -1;
    int left = postOrder(root->left, target, count);
    if (left != -1) return left;
    int right = postOrder(root->right, target, count);
    if (right != -1) return right;
    if (root->value == target) return count;
    count++;
    return -1;
}

int main() {
    Node* root = nullptr;
    int value;

    while (cin >> value && value != -1) {
        root = insert(root, value);
    }

    int target;
    cin >> target;

    int preCount = 0, inCount = 0, postCount = 0;
    int prePos = preOrder(root, target, preCount);
    int inPos = inOrder(root, target, inCount);
    int postPos = postOrder(root, target, postCount);

    if (prePos < inPos && prePos < postPos)
        cout << "Pre" << endl;
    else if (inPos < prePos && inPos < postPos)
        cout << "Em" << endl;
    else
        cout << "Pos" << endl;

    return 0;
}