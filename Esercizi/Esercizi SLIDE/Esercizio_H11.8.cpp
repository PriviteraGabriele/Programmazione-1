/* Codificare in linguaggio C++ un algoritmo che stampi le prime N potenze di 2, dove N `e un parametro scelto dall’utente
(input da tastiera). */

#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int x = 2;
    int y = 0;
    int N;

    cout << "Inserire un numero: " << endl;
    cin >> N;
    cout << "Output: " << endl;

    for(x; y <= N; y++){
        cout << pow(x, y) << endl;
    }

    return 0;
}