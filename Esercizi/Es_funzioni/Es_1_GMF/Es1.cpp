/* [Esercizio 1] Scrivere un metodo che prenda in input un parametro formale array A di interi di dimensione k × n × n
ed un double w, e restituisca il valore di verit`a true se esiste un valore dell’indice relativo alla prima dimensione (k) tale che,
nella corrispondente matrice quadrata di dimensioni n × n, la media tra il valore minimo ed il valore massimo della diagonale
principale sia minore o uguale a w. */

#define n 4
#define k 5

#include<iostream>
using namespace std;

bool es1(int A[k][n][n], double w){

    bool risposta = false;
    int max = 0;
    int min = 0;
    int media = 0;

    int diagonale[n] = {0};

    for(int p = 0; p<k; p++){
        //copio la diagonale principale in un Array
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                diagonale[i] = A[p][i][i];
            }
        }   

        for(int i =  0; i<n; i++){
            if(max<diagonale[i]){
                max = diagonale[i];
            }
            if(min>diagonale[i]){
                min = diagonale[i];
            }

        }

        media = (max + min)/2;

        if(media<=w){
            risposta = true;
            return risposta;
        }
    }
    return risposta;
}
