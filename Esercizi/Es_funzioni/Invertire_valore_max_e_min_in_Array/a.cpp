/* Definire una funzione che prende in input un array
monodimensionale di interi senza segno e inverte il valore massimo
con il valore minimo. ES: [ 1 2 6 4 5 ] −− > [ 6 2 1 4 5 ]. */

#include<iostream>
using namespace std;

void inv(unsigned int A[], int x){         

    unsigned int max = A[0], min = A[0];
    int p = 0, q = 0;       //Salvataggio posizione massimo e minimo dell'array

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

}
