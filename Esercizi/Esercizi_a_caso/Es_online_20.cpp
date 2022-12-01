/* Una matrice 5×5 rappresenta il numero di punti realizzati da dei giocatori di basket
in un piccolo torneo, in ogni riga c’è il totale dei punti realizzati da un giocatore in 
per ogni partita, in ogni colonna ci sono i punti realizzati dai giocatori in una specifica partita.
Stampare il numero di punti realizzati nella partita in cui sono stati fatti più punti 
dal giocatore che nel totale delle partite ha realizzato più punti. (Per semplicità si consideri
che non ci siano giocatori con lo stesso numero di punti o partite con lo stesso numero di punti totali) */

#include<iostream>
using namespace std;

int main(){

    int A[5][5] = {0};
    int num;
    int somma = 0;

    //srand(time(0));

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            num=rand()%25;
	    	A[i][j]=num;     
        }
    }

    //Stampa matrice completa
    cout << "La matrice che rappresenta in numero di punti fatti dai 5 giocatori durante le 5 partite è: " << endl;

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

    //Stampo il numero di punti realizzati nella partita in cui sono stati fatti più punti dal giocatore che nel totale delle partite ha realizzato più punti
    for(int i = 0; i<5; i++){
        somma += A[i][3];
    }
    cout << endl << "Il numero di punti realizzati nella partita in cui sono stati fatti più punti dal giocatore che nel totale delle partite ha realizzato più punti è: " << endl;
    cout << somma << endl;




    return 0;
}

