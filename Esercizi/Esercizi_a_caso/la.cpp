/*Descrivere un algoritmo in notazione NLS che prende in input
una matrice V di dimensioni N × M ed uno array W di dimensione L.
L’algoritmo dovra calcolare e stampare, per ogni riga di V, il
numero di elementi dello array W che sono compresi tra
il minimo e il massimo valore (estremi inclusi) della riga stessa.*/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void calcola_e_stampa(int **V, int N, int M, int *W, int L){

    int riga = 0;
    int max = 0;
    int min = 26;
    int contatore = 0;
    for(int i = 0; i<N; i++){
        max = 0;
        min = 26;
        contatore = 0;
        for(int j = 0; j<M; j++){
            if(max < V[i][j]){
                max = V[i][j];
            }
            if (min > V[i][j]){
                min = V[i][j];
            }
        }
        for(int q = 0; q<L; q++){
            if(W[q]>=min && W[q]<=max){
                contatore++;
            }
        }
        cout << "Il massimo è: " << max << endl;
        cout << "Il minimo è: " << min << endl;
        cout << "Il numero di elementi compresi tra il minimo e il massimo valore (estremi inclusi) della riga " << riga << " sono: " << contatore << endl << endl;
        riga++;
    }
}


int main(){

    int N = 3;
    int M = 4;
    int L = 5;

    //Inizializzazione dinamica di una Matrice con numeri randomici tra 0 e 25
    int**V = new int*[N];
    for(int i = 0; i<N; i++){
	    V[i] = new int[M];
    }
    
    srand(time(0));
    for(int i= 0; i<N; i++){
        for(int j = 0; j<M; j++){
            V[i][j] = rand()/double(RAND_MAX)*25;
        }
    }

    //Stampa Matrice
    cout << "Matrice: " << endl;
    for(int i= 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(j == M-1){
                cout << V[i][j] << endl;
            }
            else{
                cout << V[i][j] << "  ";
            }
        }
    }
    cout << endl;

    //Inizializzazione dinamica di un Array con numeri randomici tra 0 e 25
    int *W = new int[L];

    for(int i = 0; i<L; i++){
        W[i] = rand()/double(RAND_MAX)*25;
    }

    //Stampa Array
    cout << "Array: " << endl;
    for(int i = 0; i<L; i++){
        cout << W[i] << "  ";
    }
    cout << endl << endl;
   
    calcola_e_stampa(V, N, M, W, L);
}
