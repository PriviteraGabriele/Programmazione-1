/* Scrivere un metodo che prenda in input una 
matrice di double D ed un intero a, e restituisca il 
valore booleano true se esiste almeno una colonna in 
D nella quale la somma di una qualsiasi coppia di 
elementi adiacenti, approssimata all'intero piu vicino, 
sia uguale ad a. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool esercizio21(double** D, int n, int m, int a){
    double somma_coppie;
    for(int j = 0; j<m; j++){
        for(int i = 0; i<n-1; i++){
            somma_coppie = 0;
            cout << "----------------------------------------------" << endl;
            for(int p = i; p<2+i; p++){
                somma_coppie += D[p][j];
                cout << "D[" << p << "][" << j << "] = " << D[p][j] << endl;
            }
            cout << "somma = " << somma_coppie << endl;
            cout << "**somma = " << (int)(somma_coppie + 0.5) << endl;
            cout << "a = " << a << endl;
            if((int)(somma_coppie + 0.5) == a){
                return true;
            }
            cout << "----------------------------------------------" << endl;
        }
    }
    return false;
}

void Stampa_Matrice(double** A, int n, int m){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << A[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;
    int a = 8;

    double** D = new double*[n];
    for(int i = 0; i<n; i++){
        D[i] = new double[m];
    }

    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            D[i][j] = rand()/(double)RAND_MAX*8;
        }
    }

    Stampa_Matrice(D, n, m);

    if(esercizio21(D, n, m, a)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    } 
}