/* 9.Scrivere un metodo che prenda in input un 
parametro formale matrice A di interi di dimensioni 
nxn ed un double w, e restituisca un valore booleano 
true se esiste almeno una colonna della matrice A per 
cui il rapporto tra la somma degli elementi della 
colonna stessa e la somma degli elementi della 
diagonale principale di A sia maggiore di w. */

#include<iostream>
using namespace std;

int main(){

    int x;      //Dimensione Matrice quadrata
    double w;
    bool b = false;
    int somma_colonna = 0;
    int somma_diagonale = 0;


    //Input dimensione della Matrice quadrata
    cout << "Inseirire la dimensione della Matrice quadrata: \n";
    cin >> x;

    int A[x][x] = {0};

    //Inizializzazione della matrice con input da tastiera
    cout << "Inserire i valori della matrice quadrata: \n";
    for( int i = 0; i<x; i++){
        for(int j = 0; j<x; j++){
            cin >> A[i][j];
        }
    }
    cout << endl;

    //Input w
    cout << "Inserire il valore di w: \n";
    cin >> w;

    //Calcolo la somma dei valori della diagonale principale della matrice quadrata
    for(int i = 0; i<x; i++){
        somma_diagonale += A[i][i];
    }
    
    //Calcolo la somma dei valori delle colonne della matrice quadrata e vedo se il rapporto tra la somma delle colonne e e quello della diagonale principale è maggiore di w
    for(int i = 0; i<x; i++){
        for(int j = 0; j<x; j++){
            somma_colonna += A[i][j];
            if((somma_colonna/somma_diagonale)>w){
                b = true;
                cout << "Esiste una colonna della matrice A per cui il rapporto tra la somma degli elementi della colonna stessa e la somma degli elementi della diagonale principale di A sia maggiore di w" << endl;;
                return 0;
            }
        }
    }

    cout << "Non esiste nessuna colonna della matrice A per cui il rapporto tra la somma degli elementi della colonna stessa e la somma degli elementi della diagonale principale di A sia maggiore di w. \n";





    return 0;
}