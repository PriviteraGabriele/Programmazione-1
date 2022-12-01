/* Scrivere un programma in C++ che permetta di simulare una sequenza 
di N lanci di una coppia di dadi, dove N è un numero scelto dall’utente. 
Il programma dovrà stampare le sequenze dei due numeri (output primo 
dado e output secondo dado) in due colonne separate. */

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){

    int N;
    cout << "Inserire il numero di lanci da fare: \n";
    cin >> N;
    cout << endl;

    int a = 1;
    int b = 6;

    srand(time(0));

    for(int i = 0; i<N; i++){

        int dado1 = rand() % (b-a+1)+a;
        int dado2 = rand() % (b-a+1)+a;
        cout << dado1 << "   " << dado2 << endl;
    }

    return 0;
}