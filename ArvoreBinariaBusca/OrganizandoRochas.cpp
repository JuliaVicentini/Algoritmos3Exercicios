#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    string type;
    Node* left;
    Node* right;

    Node(const string& n, const string& t) : name(n), type(t), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, const string& name, const string& type) {
    if (!root) return new Node(name, type);
    
    if (name < root->name)
        root->left = insert(root->left, name, type);
    else if (name > root->name)
        root->right = insert(root->right, name, type);
    
    return root;
}

Node* search(Node* root, const string& name) {
    if (!root || root->name == name) return root;

    if (name < root->name)
        return search(root->left, name);
    else
        return search(root->right, name);
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* remove(Node* root, const string& name, const string& type) {
    if (!root) {
        cout << "Rocha nao encontrada para remocao" << endl;
        return nullptr;
    }

    if (name < root->name)
        root->left = remove(root->left, name, type);
    else if (name > root->name)
        root->right = remove(root->right, name, type);
    else {
        if (root->type != type) {
            cout << "Rocha nao encontrada para remocao" << endl;
            return root;
        }
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            cout << "Rocha removida com sucesso" << endl;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            cout << "Rocha removida com sucesso" << endl;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->name = temp->name;
        root->type = temp->type;
        root->right = remove(root->right, temp->name, temp->type);
        cout << "Rocha removida com sucesso" << endl;
    }
    return root;
}

// Função principal para o programa
int main() {
    Node* root = nullptr;
    int option;

    while (cin >> option && option != 0) {
        if (option == 1) { // Inserção
            string name, type;
            cin >> name >> type;
            root = insert(root, name, type);
        } else if (option == 2) { // Pesquisa
            string name;
            cin >> name;
            Node* result = search(root, name);
            if (result) {
                cout << "Nome: " << result->name << "\nTipo: " << result->type << endl;
            } else {
                cout << "Rocha nao encontrada" << endl;
            }
        } else if (option == 3) { // Remoção
            string name, type;
            cin >> name >> type;
            root = remove(root, name, type);
        } else {
            cout << "Operacao invalida" << endl;
        }
    }
    
    return 0;
}