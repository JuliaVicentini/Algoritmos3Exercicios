#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> a; // criando uma lista de inteiros
	int n;
	for(int i = 0; i<4; i++){
	    cin >> n;
	    a.push_front(n);
	}
	
	list<int>::iterator p;
    for(p = a.begin(); p != a.end(); p++){
		cout << *(p) << " "; // aprensetando os elementos
	}
	return 0;
}