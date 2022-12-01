/* Scrivere un metodo che prenda in input una matrice di puntatori a interi di dimensioni n x m, 
un double s ed uno short k (si assuma k < n). Il metodo restituisca il numero di colonne che 
contengano almeno k elementi contigui la cui media aritmetica risulti minore di s. */

#include<iostream>
using namespace std;

int esercizio1(int ***M)

int fun(***A, int n, int m, double s, short k){
    for(int j = 0; j<m; j++){
        int risposta = 0;
        int somma = 0;
        int contatore = 0;
        double media = 0;
        for(int i = 0; i<n; i++){
            somma += *A[j][i];
            contatore++;
            if(i>=k){
                media = (double)somma/contatore;
            }
            if(media<s){
                risposta++;
                continue;
            }
            else{
                i = i - (k-1);
                somma = 0;
                contatore = 0;
            }
        }
    }
    return risposta;
}





/*int fun(***A, int n, int m, double s, short k){
    int B[k] = {0};
    int somma = 0;
    double media = 0;
    int risposta = 0; // ritorno funzione
    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            B[i] = *A[j][i];
            if(i==k){
                for(int p = 0; p<k; p++){
                    somma += B[p];
                    media = (double)somma/k;
                    if(media<s){
                        risposta++;
                        continue;
                    }
                }
            }
        }    
    }
}*/