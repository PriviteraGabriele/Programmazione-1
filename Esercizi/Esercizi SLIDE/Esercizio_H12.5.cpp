/* Codificare un programma in linguaggio C++ che chieda
all’utente di inserire il raggio di un cerchio.
Il programma dovr`a calcolare e stampare l’area e la
circonferenza del cerchio. */

#define PI_GRECO 3.14;

#include<iostream>
using namespace std;

int main(){

    double r;
    double area;
    double circonferenza;

    cout << "Inserie il raggio della circonferenza: " << endl;
    cin >> r;

    if(r<0){
        cerr << "ERRORE: il valore del raggio non può essere minore di zero!" << endl;
        return -1;
    }

    area = r * r * PI_GRECO;
    circonferenza = r * 2 * PI_GRECO;

    cout << "L'area del cerchio con raggio " << r << " è: " << endl << area << endl;
    cout << "La circonferenza del cerchio con raggio " << r << " è: " << endl << circonferenza << endl;
  
    return 0;
}