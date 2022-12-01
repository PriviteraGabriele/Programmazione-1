/* Scrivere un metodo che prenda in input una 
matrice di double D ed un intero a, e restituisca il 
valore booleano true se esiste almeno una colonna in 
D nella quale la somma di una qualsiasi coppia di 
elementi adiacenti, approssimata all'intero piu vicino, 
sia uguale ad a. */

#include<iostream>
using namespace std;

bool ex21(double** D, int n, int m, int a){
    double sum;
    for(int j = 0; j<m; j++){
        for(int i = 0; i<n-1; i++){
            sum = D[i][j] + D[i+1][j];
            cout << "sum = " << sum << endl;
            cout << "arrotondato = " << (int)(sum + 0.5) << endl;
            if((int)(sum + 0.5) == a){
                return true;
            }
        }
    }
    return false;
}

void Stampa_Matrice(double** A, int n, int m){
    cout << "Matrice:" << endl << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << A[i][j] << "    \t";
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

    if(ex21(D, n, m, a)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    } 
}