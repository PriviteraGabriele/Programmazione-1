/* Definire una funzione che prende in input un array
monodimensionale di interi senza segno e inverte il valore massimo
con il valore minimo. ES: [ 1 2 6 4 5 ] −− > [ 6 2 1 4 5 ]. */

#include<iostream>
using namespace std;

int main(){

    int x = 0;
    cout << "Inserire la dimensione dll'arrey: \n";
    cin >> x;

    unsigned int A[x] = {0};
    //Inizializzazione array
    cout << "Inseire i valori dell'Array: \n";
    for(int i = 0; i<x; i++){
        cin >> A[i];
    }

    //Stampa Array
    cout << "L'Array è :\n";
    for(int i = 0; i<x; i++){
        cout << A[i] << "  ";
    }
    cout << endl;

    unsigned int max = A[0], min = A[0];
    int p = 0, q = 0;       //Salvataggio posizione massimo e minimo dell'array

    //Ricerca valore massimo e minimo dell'Array e inversione di essi
    for(int i = 0; i<x; i++){
        if(max<A[i]){
            max = A[i];
            p = i;
        }
        else if(min>A[i]){
            min = A[i];
            q = i;
        }
    }

    A[p] = min;
    A[q] = max;

    //Stampa Array modificato
    cout << "Il nuovo Array è :\n";
    for(int i = 0; i<x; i++){
        cout << A[i] << "  ";
    } 
    cout << endl;

    return 0;
}