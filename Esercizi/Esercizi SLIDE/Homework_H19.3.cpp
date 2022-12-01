#include<iostream>
using namespace std;

int main(){

    int x;      //Dimensione Array
    double somma = 0;
    int somma_arrotondata = 0;

    //Inserimento dimensione Array
    cout << "Inserire la dimensione dell'Array: " << endl;
    cin >> x;

    double A[x] = {0};

    //Inizializzazione Array
    cout << "Inserire i valori dell'Array: " << endl;

    for(int i=0; i<x; i++){
        cin >> A[i];
    }

    //Calcolo e stampo la somma arrotondata al valore intero più vicino di tutti i valori dell'Array
    for(int i=0; i<x; i++){
        somma += A[i];
    }

    somma_arrotondata = somma + 0.5;

    cout << "La somma arrotondata al valore intero più vicino di tutti i valori dell'Array è: \n" << somma_arrotondata << endl;

    return 0;
}