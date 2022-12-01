/* Scrivere un metodo che prenda in input un 
parametro formale matrice A di interi di dimensioni 
nxn ed un double w, e restituisca un valore booleano 
true se esiste almeno una colonna della matrice A per 
cui il rapporto tra la somma degli elementi della 
colonna stessa e la somma degli elementi della 
diagonale principale di A sia maggiore di w. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool esercizio9(int** A, int n, double w){
    int somma_diagonale = 0;
    int somma_colonna;
    for(int i = 0; i<n; i++){
        somma_diagonale += A[i][i];
    }
    cout << "somma_diagonale = " << somma_diagonale << endl;
    for(int j = 0; j<n; j++){
        somma_colonna = 0;
        for(int i = 0; i<n; i++){
            somma_colonna += A[i][j];
        }
        cout << "somma_colonna = " << somma_colonna << endl;
        cout << "rapporto = " << (double)somma_colonna/somma_diagonale << endl;
        cout << "--------------------------------------------" << endl;
        if((double)somma_colonna/somma_diagonale > w){
            return true;
        }
    }
    return false;
}

void Stampa_Matrice(int** A, int n){
    cout << "Matrice: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(j!=n-1){
                cout << A[i][j] << "\t";
            }
            else{
                cout << A[i][j] << endl;
            }
        }
    }
    cout << endl;
}


int main(){
    int n = 4;
    double w = 1.2;

    int** A = new int*[n];
    for(int i = 0; i<n; i++){
        A[i] = new int[n];
    }

    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            A[i][j] = rand()%25;
        }
    }
    Stampa_Matrice(A, n);

    if(esercizio9(A, n, w)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}