/* 33.Scrivere un metodo che prenda in input una 
matrice quadrata A di puntatori ad interi e restituisca 
un double calcolato come il rapporto tra la somma 
degli elementi della diagonale principale di A e la 
somma degli elementi della diagonale secondaria di A 
stessa. NB: Si presti attenzione ai numeri mancanti! */

#include<iostream>
using namespace std;

double esercizio33(int*** M, int n){
    int principale[n];
    for(int i = 0; i<n; i++){
        principale[i] = 0;
        
    }
    
    int secondaria[n];
    for(int i = 0; i<n; i++){
        secondaria[i] = 0;
    }

    int somma_principale = 0;
    int somma_secondaria = 0;

    for(int i = 0; i<n; i++){
        if(M[i][i]){
            principale[i] = *M[i][i];
            somma_principale += principale[i];
        }
    }
    
    for(int i = 0; i<n; i++){
        if(M[i][n - i - 1]){
            secondaria[i] = *M[i][n - i - 1];
            somma_secondaria += secondaria[i];
        }
    }

    return (double)somma_principale/somma_secondaria;
}

void Stampa_Matrice(int*** M, int n){
    cout << "Matrice: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(j!=n-1){
                cout << *M[i][j] << "\t";
            }
            else{
                cout << *M[i][j] << endl;
            }
        }
    }
    cout << endl;
}

int main(){
    int n = 3;
    int*** M = new int**[n];
    for(int i = 0; i<n; i++){
      M[i] = new int*[n];  
    }

    srand(time(0));

    M[0][0] = new int(rand()%15);
    M[0][1] = new int(rand()%15);
    M[0][2] = new int(rand()%15);
    M[1][0] = new int(rand()%15);
    M[1][1] = new int(rand()%15);
    M[1][2] = new int(rand()%15);
    M[2][0] = new int(rand()%15);
    M[2][1] = new int(rand()%15);
    M[2][2] = new int(rand()%15);

    Stampa_Matrice(M, n);

    cout << "Il rapporto tra la somma degli elementi della diagonale principale e della secondaria è: " << esercizio33(M, n) << endl;
}