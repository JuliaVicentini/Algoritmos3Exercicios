#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int* v = new int[N];

    int* p = v;
    
    for (int i = 0; i < N; i++) {
        cin >> *(p + i); 
    }

    for (int i = 0; i < N; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;

    return 0;
}