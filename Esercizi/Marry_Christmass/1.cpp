/* 1.Un santone induista si trova nella regione indiana del 
Rajasthan, quest'ultima simulata con una matrice 
quadrata di boolean in cui il valore true indica la 
presenza di un libro sacro. Scrivere un metodo che 
prenda in input una matrice di boolean e restituisca il 
numero di libri raccolti dal santone che, partendo dal 
centro della regione, esegue un movimento casuale 
unitario alla volta in una delle quattro direzioni prima 
che egli sia traviato dalle usanze oltre colonne.*/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int santone(bool**M, int n){

    int libri = 0;
    int i = 2; 
    int j = 2;

    //Raccolgo il libro della posizione di partenza del santone
    libri++;
    M[i][j] = 0;

    srand(time(0));

    while(i>=0 && i<5 && j>=0 && j<5){
        //Direzione casuale
        int s = rand()/double(RAND_MAX)*4;

        //Impostazioni movimento
        if(s == 0){                 //NORD
            i--;
        }
        else if( s == 1){           //SUD
            i++;
        }
        else if(s == 2){            //EST
            j++;
        }       
        else if(s == 3){            //OVEST
            j--;
        } 

        //Controllo libro
        if(M[i][j] == 1){
            libri++;
            M[i][j] = 0;
        }
    }

    return libri;
}


int main(){

    int N = 5;
    //Inizializzazione dinamica di una Matrice
    bool**M = new bool*[N];
    for(int i = 0; i<N; i++){
	    M[i] = new bool[N];
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            M[i][j] = 1;
        }
    }

    //Stampa Matrice
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(j == N-1){
                cout << M[i][j] << endl;
            }
            else{
                cout << M[i][j] << "   ";
            }
                
        }
    }

    cout << "Il numero di libri raccolti dal santone prima che egli sia traviato dalle usanze oltre colonne è: " << santone(M, N) << endl;
}