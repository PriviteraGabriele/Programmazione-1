/* Scrivere un metodo che prenda in input una 
matrice quadrata A di numeri interi ed un double w, e 
restituisca il valore booleano true se il rapporto tra il 
minimo ed il massimo valore della diagonale 
secondaria di A e minore o uguale a w. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool esercizio29(int**M, int n, double w){
    int secondaria[n];
    for(int i = 0; i<n; i++){
        secondaria[i] = 0;
    }
    cout << "Diagonale secondaria: ";
    for(int i = 0; i<n; i++){
        secondaria[i] = M[i][n - i - 1];
        cout << secondaria[i] << "  ";
    }
    cout << endl;
    int max = 0;
    int min = 100;
    for(int i = 0; i<n; i++){
        if(max < secondaria[i]){
            max = secondaria[i];
        }
        if(min > secondaria[i]){
            min = secondaria[i];
        }
    }
    cout << "max = " << max << endl;
    cout << "min = " << min << endl;
    cout << "min/max = " << (double)min/max << endl;

    if((double)min/max <= w){
        return true;
    }
    return false;
}

void Stampa_Matrice(int** M, int n){
    cout << "Matrice: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(j!=n-1){
                cout << M[i][j] << "\t";
            }
            else{
                cout << M[i][j] << endl;
            }
        }
    }
}

int main(){
    int n = 3;
    double w = 0.5;
    int** M = new int*[n];
    for(int i = 0; i<n; i++){
      M[i] = new int[n];  
    }
    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            M[i][j] = rand()%15;
        }
    }
    Stampa_Matrice(M, n);

    cout << endl;
    if(esercizio29(M, n, w)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}

