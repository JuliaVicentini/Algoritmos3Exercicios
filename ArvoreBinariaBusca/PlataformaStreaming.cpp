#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Filme {
    string nome;
    string genero;
    int duracao;
    int classificacao;
    int ano;
    Filme* left;
    Filme* right;

    Filme(string n, string g, int d, int c, int a) 
        : nome(n), genero(g), duracao(d), classificacao(c), ano(a), left(NULL), right(NULL) {} // Substituímos nullptr por NULL
};

// Função para inserir um novo filme na árvore binária de busca
Filme* inserirFilme(Filme* root, string nome, string genero, int duracao, int classificacao, int ano) {
    if (root == NULL) { // Substituímos nullptr por NULL
        return new Filme(nome, genero, duracao, classificacao, ano);
    }
    if (nome < root->nome) {
        root->left = inserirFilme(root->left, nome, genero, duracao, classificacao, ano);
    } else if (nome > root->nome) {
        root->right = inserirFilme(root->right, nome, genero, duracao, classificacao, ano);
    }
    return root;
}

// Função para buscar e exibir as informações de um filme
void buscarFilme(Filme* root, string nome) {
    if (root == NULL) { // Substituímos nullptr por NULL
        cout << "Filme nao encontrado" << endl;
        return;
    }
    if (root->nome == nome) {
        cout << "Nome: " << root->nome << endl;
        cout << "Genero: " << root->genero << endl;
        cout << "Duracao: " << root->duracao << " mins" << endl;
        cout << "Classificacao: " << root->classificacao << endl;
        cout << "Ano: " << root->ano << endl;
    } else if (nome < root->nome) {
        buscarFilme(root->left, nome);
    } else {
        buscarFilme(root->right, nome);
    }
}

int main() {
    Filme* root = NULL;
    int opcao;

    while (true) {
        cin >> opcao;
        
        if (opcao == 0) {
            break;
        }
        else if (opcao == 1) {
            string nome, genero;
            int duracao, classificacao, ano;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nome);
            getline(cin, genero);
            cin >> duracao >> classificacao >> ano;
            
            root = inserirFilme(root, nome, genero, duracao, classificacao, ano);
        }
        else if (opcao == 2) {
            string nome;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nome);
            buscarFilme(root, nome);
        }
        else {
            cout << "Operacao invalida" << endl;
        }
    }

    return 0;
}