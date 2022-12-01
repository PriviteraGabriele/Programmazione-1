/* Una matrice 5×5 rappresenta il numero di punti realizzati da dei giocatori di basket 
in un piccolo torneo, in ogni riga c’è il totale dei punti realizzati da un giocatore in 
per ogni partita, in ogni colonna ci sono i punti realizzati dai giocatori in una specifica 
partita. Stampare il numero di punti realizzati nella partita in cui sono stati fatti più 
punti dal giocatore che nel totale delle partite ha realizzato più punti. (Per semplicità si 
consideri che non ci siano giocatori con lo stesso numero di punti o partite con lo stesso 
numero di punti totali). */

#include<iostream>
using namespace std;

int es_20(int** M, int n){

    //Creazione e inizializzazione a zero di un array GIOCATORI
    int* G = new int[n];
    for(int i = 0; i<n; i++){
        G[i] = 0;
    }

    //Salvataggio della somma dei punti fatti dai 5 giocatori nelle 5 partite
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            G[i] += M[i][j];
        }
    }

    //Controllo giocatore che ha fatto più punti
    int max = 0;
    int temp_i;
    for(int i = 0; i<n; i++){
        if(max < G[i]){
            temp_i = i;
            max = G[i];
        }
    }

    //Creazione e inizializzazione a zero di un array PARTITE
    int* P = new int[n];
    for(int i = 0; i<n; i++){
        P[i] = 0;
    }

    //Salvataggio della somma dei punti fatti nelle 5 partie 
    for(int j = 0; j<n; j++){
        for(int i = 0; i<n; i++){
            P[i] += M[i][j];
        }
    }

    //Controllo partita con più punti
    max = 0;
    int temp_j;
    for(int j = 0; j<n; j++){
        if(max < P[j]){
            temp_j = j;
            max = P[j];
        }
    }

    int ritorno = M[temp_i][temp_j];
    return ritorno;
}

void Stampa_Matrice(int** M, int n){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){

    int n = 5;

    int** M = new int*[n];
    for(int i = 0; i<n; i++){
        M[i] = new int[n];
    }

    M[0][0] = 1;
    M[0][1] = 2;
    M[0][2] = 3;
    M[0][3] = 4;
    M[0][4] = 5;
    M[1][0] = 6;
    M[1][1] = 7;
    M[1][2] = 8;
    M[1][3] = 9;
    M[1][4] = 10;
    M[2][0] = 11;
    M[2][1] = 12;
    M[2][2] = 13;
    M[2][3] = 14;
    M[2][4] = 15;
    M[3][0] = 16;
    M[3][1] = 17;
    M[3][2] = 18;
    M[3][3] = 19;
    M[3][4] = 20;
    M[4][0] = 21;
    M[4][1] = 22;
    M[4][2] = 23;
    M[4][3] = 24;
    M[4][4] = 25;

    Stampa_Matrice(M, n);

    cout << "Il giocatore che ha fatto più punti nelle 5 partite disputate, nella partita in cui sono stati fatti più punti in totale dai 5 giocatore, ha fatto " << es_20(M, n) << " punti." << endl;
}