/* [Esercizio 1] Scrivere un metodo che prenda in input un parametro formale array A di interi di dimensione k × n × n
ed un double w, e restituisca il valore di verit`a true se esiste un valore dell’indice relativo alla prima dimensione (k) tale che,
nella corrispondente matrice quadrata di dimensioni n × n, la media tra il valore minimo ed il valore massimo della diagonale
principale sia minore o uguale a w. */

#include<iostream>
#include<ctime>
#include"Es1.h"
using namespace std;

int main(){

    double w;
    cout << "Inserire w: \n";
    cin >> w;

    int k, n;
    cout << "Inserire, in ordine, k e n: \n";
    cin >> k >> n;
    int A[k][n][n] = {0};

    //Inizializzazione casuale della Matrice tridimensionale
    srand(time(0));

    for(int p = 0; p<k; p++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                A[p][i][j] = rand()%50;
            }
        }
    }

    //Stampa Matrice tridimensionale
    /*for(int p = 0; p<k; p++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout << "A[" << p << "][" << i << "][" << j << "] = " << A[p][i][j] << endl;
            }
        }
    }*/

    if(es1(A, w)){
        cout << "Esiste un valore dell’indice relativo alla prima dimensione (k) tale che la media tra il valore minimo ed il valore massimo della diagonale principale sia minore o uguale a w! \n";
    }
    else{
        cout << "Non esiste un valore dell’indice relativo alla prima dimensione (k) tale che la media tra il valore minimo ed il valore massimo della diagonale principale sia minore o uguale a w! \n";
    }

    return 0;
}
