/*Siano a, b e c tre variabili di tipo int. Trovare il massimo
dei tre numeri usando l’operatore condizionale.*/

#include <iostream>
#include <string>
using namespace std;

int main(){

    int a;
    int b;
    int c;

    cout << "Inserisci il primo numero: " << endl;
    cin >> a;
    cout << "Inserisci il secondo numero: " << endl;
    cin >> b;
    cout << "Inserisci il terzo numero: " << endl;
    cin >> c;

    cout << "Max(a, b, c)= " << (a<b? (b<c? c:b) : (a<c? c:a) ) << endl;

}



