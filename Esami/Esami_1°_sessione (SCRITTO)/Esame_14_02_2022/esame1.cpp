/* Scrivere una funzione che prenda in input una matrice A di dimensione m x n
(si assuma m > n) di puntatori a double, uno short k e un double q e restituisca 
il numero di sequenze di lunghezza k di media superiore a q che si trovano sulle 
diagonali principali delle matrici quadrate di dimensione n x n contenute in A. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int esame1(double*** A, int m, int n, short k, double q){
    int counter = 0;
    double array[n] = {0};
    double somma;
    short salvataggio_k = k;
    for(int j = 0; j<=(m-n); j++){
        cout << "-----------------------------------------------" << endl;
        cout << "Array: ";
        k = salvataggio_k;
        for(int i = 0; i<n; i++){
            array[i] = *A[i+j][i];
            cout << array[i] << "  ";
        }
        cout << endl;

        //Contigui diagonale principale
        for(int x = 0; x<(n-1); x++){
            for(int p = x; p<(k+x); p++){
                somma += array[p];
            }
            cout << "somma = " << somma << endl;
            cout << "**(somma/k) = " << (double)somma/k << endl;
            if((double)somma/k > q){
                counter++;
                cout << "counter = " << counter << endl;
            }
            somma = 0;
        }
        cout << "-----------------------------------------------" << endl;
    }
    return counter;
}

void Stampa_Matrice(double*** A, int m, int n){
    cout << "Matrice: " << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j]){
                cout << *A[i][j] << " \t";
            }
            else{
                cout << "* \t"; 
            }
        }
        cout << endl;
    }
}

int main(){
    int m = 4;
    int n = 3;
    short k = 2;
    double q = 0.7;
    double*** A = new double**[m];
    for(int i = 0; i < m; i++){
        A[i] = new double*[n];
    }       

    srand(time(0));

    A[0][0] = new double(rand()/(double)RAND_MAX * 10);
    A[0][1] = new double(rand()/(double)RAND_MAX * 10);
    A[0][2] = new double(rand()/(double)RAND_MAX * 10);
    A[1][0] = new double(rand()/(double)RAND_MAX * 10);
    A[1][1] = new double(rand()/(double)RAND_MAX * 10);
    A[1][2] = new double(rand()/(double)RAND_MAX * 10);
    A[2][0] = new double(rand()/(double)RAND_MAX * 10);
    A[2][1] = new double(rand()/(double)RAND_MAX * 10);
    A[2][2] = new double(rand()/(double)RAND_MAX * 10);
    A[3][0] = new double(rand()/(double)RAND_MAX * 10);
    A[3][1] = new double(rand()/(double)RAND_MAX * 10);
    A[3][2] = new double(rand()/(double)RAND_MAX * 10);

    Stampa_Matrice(A, m, n);

    cout << esame1(A, m, n, k, q) << endl;
}