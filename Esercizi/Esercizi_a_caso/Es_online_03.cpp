/*  Memorizzare in un array bidimensionale 5 per 5 tutti zeri tranne nelle 
celle della diagonale principale dove memorizzare uno (non usare 
l’inizializzazione con parentesi grafe nemmeno per gli zeri) */

#include<iostream>
using namespace std;

int main(){

    int A[5][5];

    //Inizializzo tutti i valori delle caselle delle matrici a 0
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            A[i][j] = 0;
        }

    }

    //Sostituisco i valori della diagonale principale della matrice con 1
    for(int i = 0; i<5; i++){
        A[i][i] = 1;
    }

    //Stampo tutti i valori della matrice
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            if(j!=4){
                cout << A[i][j] << " ";
            }
            else{
                cout << A[i][j] << endl;
            }
        }
    }
    cout << endl;

    return 0;
}