#include <iostream>
#include <string>
using namespace std;

struct User {
    string name;
    User* next;
};

struct AdjacencyList {
    User* head;
};

struct Graph {
    int numUsers;
    AdjacencyList* list;

    Graph(int n) {
        numUsers = n;
        list = new AdjacencyList[n];
        for (int i = 0; i < n; i++) {
            list[i].head = nullptr;
        }
    }

    void addEdge(int from, int to, string* userNames) {
        User* newUser = new User;
        newUser->name = userNames[to];
        newUser->next = list[from].head;
        list[from].head = newUser;
    }

    void printFollowers(int userIndex, string* userNames) {
        cout << "Seguidores de " << userNames[userIndex] << ":\n";
        for (int i = 0; i < numUsers; i++) {
            User* current = list[i].head;
            while (current != nullptr) {
                if (current->name == userNames[userIndex]) {
                    cout << userNames[i] << endl;
                    break;
                }
                current = current->next;
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < numUsers; i++) {
            User* current = list[i].head;
            while (current != nullptr) {
                User* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] list;
    }
};

int main() {
    int N;
    cin >> N;
    cin.ignore();

    string* userNames = new string[N];
    for (int i = 0; i < N; i++) {
        getline(cin, userNames[i]);
    }

    Graph g(N);

    for (int i = 0; i < N; i++) {
        cout << "Usuário " << userNames[i] << " segue: ";
        int follows;
        while (cin >> follows && follows != -1) {
            g.addEdge(i, follows, userNames);
        }
    }

    int userToCheck;
    cin >> userToCheck;

    g.printFollowers(userToCheck, userNames);

    delete[] userNames;

    return 0;
}
