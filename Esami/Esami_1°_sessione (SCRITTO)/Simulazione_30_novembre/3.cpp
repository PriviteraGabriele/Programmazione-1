/*Scrivere una funzione che prenda come parametri formali una matrice bidimensionale A 
di double (usare un doppio puntatore a double) e due interi m e n indicanti le dimensioni 
della matrice (dunque m x n) e restituisca una matrice B di double di dimensioni (n x m) 
il cui elemento B[i][j] sia pari a A[j][i] è maggiore di un numero casuale s compreso tra 
0 e 1, mentre sia uguale a A [i%m][j%n] altrimenti. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

double** e3(double** A, int m, int n){
    double** B = new double*[n];
    for(int i = 0; i<n; i++){
        B[i] = new double[m];
    }

    srand(time(0));
    double x = rand()/(double)RAND_MAX;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j] < x){
                B[i][j] = A[j][i];
            }
            else{
                B[i][j] = A[i%m][j%n];
            }
        }
    }

    ////////////////////////////////////

    cout << "x = " << x << endl << endl;

    cout << "Matrice (B):" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << B[i][j] << "     \t";
        }
        cout << endl;
    }
    cout << endl;
    ////////////////////////////////////
    return B;
}

void Stampa_Matrice(double** A, int m, int n){
    cout << "Matrice (A):" << endl << endl;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout << A[i][j] << "     \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int m = 4;
    int n = 3;

    double** A = new double*[m];
    for(int i = 0; i<m; i++){
        A[i] = new double[n];
    }

    srand(time(0));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            A[i][j] = rand()/(double)RAND_MAX;
        }
    }

    Stampa_Matrice(A, m, n);

    e3(A, m, n);
}