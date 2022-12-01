/* 1.Un santone induista si trova nella regione indiana del 
Rajasthan, quest'ultima simulata con una matrice 
quadrata di boolean in cui il valore true indica la 
presenza di un libro sacro. Scrivere un metodo che 
prenda in input una matrice di boolean e restituisca il 
numero di libri raccolti dal santone che, partendo dal 
centro della regione, esegue un movimento casuale 
unitario alla volta in una delle quattro direzioni prima 
che egli sia traviato dalle usanze oltre colonne. */

#include<iostream>
#include<cstdlib>
using namespace std;

int main(){

    int x, num, libri = 0;

    cout << "Inserire la dimensione dell matrice quadrata: \n";
    cin >> x;

    bool A[x][x];

    for(int i = 0; i<x; i++){
        for(int j = 0; j<x; j++){
            num = rand()%2;
            A[i][j] = num;
        }
    }

    cout << "La matrice sotto esame è: \n";
    for(int i = 0; i<x; i++){
        for(int j = 0; j<x; j++){
            if(j<x-1){
                cout << A[i][j] << "  ";
            }
            else{
                cout << A[i][j] << endl;
            }
        }
    }

    for(int i = 0; i<x; i++){
        for(int j = 0; j<x; j++){
            if(A[i][j]==1){
                libri++;
            }
        }
    }

    cout << "Il numero di libri trovati dal Santone dello Svapo durante il suo viaggio nei meandri delle Filippine è: " << libri << endl;

    

    return 0;
}
