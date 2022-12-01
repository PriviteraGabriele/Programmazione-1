/* [Esercizio 13] Scrivere un metodo che preveda due parametri formali matrici 
di interi, A e B di dimensioni k × n ed n × k rispettivamente, e restituisca 
uno array monodimensionale di k elementi double in cui lo i-esimo elemento sia 
uguale alla differenza tra la media aritmetica degli elementi della riga i-esima 
di A ed il minimo valore degli elementi della colonna i-esima di B. */

#include<iostream>
using namespace std;

double* ex13(int** A, int k, int n, int** B){

    double* R = new double[k];      //Ritono

    double* S = new double[k];        //Array temporanero per la media
    int* M = new int[k];        //Array temporaneo per il minimo

    //Mi calcolo la media di tutti i valori delle righe di A
    int sum;
    for(int i = 0; i<k; i++){
        sum = 0;
        for(int j = 0; j<n; j++){
            sum += A[i][j];
        }
        S[i] = (double)sum/n;
    }

    //Cerco il valore minimo di tutte le colonne di B
    int min;
    for(int j = 0; j<k; j++){
        min = 500;
        for(int i = 0; i<n; i++){
            if(min > B[i][j]){
                min = B[i][j];
            }
        }
        M[j] = min;
    }

    for(int i = 0; i<k; i++){
        R[i] = S[i] - M[i];
    }

    //Stampa Array
    cout << "Array:\t";
    for(int i = 0; i<k; i++){
        cout << R[i] << "\t";
    }
    cout << endl;

    return R;
}

int main(){
    int k = 4;
    int n = 4;

    int** A = new int*[k];
    for(int i = 0; i<k; i++){
        A[i] = new int[n];
    }

    //Inizializzazione casuale della matrice e stampa
    srand(time(NULL));
    cout << "Matrice (A):" << endl << endl;
    for(int i = 0; i<k; i++){
        for(int j = 0; j<n; j++){
            A[i][j] = rand()%25;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    int** B = new int*[n];
    for(int i = 0; i<n; i++){
        B[i] = new int[k];
    }

    //Inizializzazione casuale della matrice e stampa
    srand(time(NULL));
    cout << "Matrice (B):" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<k; j++){
            B[i][j] = rand()%25;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    ex13(A, k, n, B);

}