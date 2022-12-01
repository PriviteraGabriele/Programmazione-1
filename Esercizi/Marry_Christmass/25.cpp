/* .Scrivere un metodo che prenda in input una 
matrice di interi M di dimensioni nx m, uno short k ed 
un double x, e restituisca il valore booleano true se 
esiste almeno una colonna in M contenente 
esattamente k coppie di elementi adiacenti tali che il 
rapporto tra il primo elemento ed il secondo elemento 
di ogni coppia sia minore di x. NB: Si assuma k <= n -
1 e si presti attenzione alle divisioni per zero! */

#include<iostream>
using namespace std;

bool esercizio25(int** M, int n, int m, short k, double x){
    int temp1 = 0;
    int temp2 = 0;
    double rapporto = 0;
    for(int j = 0; j<m; j++){
        int counter = 0;
        for(int i = 0; i<n-1; i++){
            temp1 = M[i][j];
            temp2 = M[i+1][j];
            cout << "----------------------------------" << endl;
            cout << "temp1 = " << temp1 << endl;
            cout << "temp2 = " << temp2 << endl;
            if(temp2 != 0){
                rapporto = (double)temp1/temp2;
                cout << "rapporto = " << rapporto << endl;
                if(rapporto < x){
                    counter++;
                    cout << "counter = " << counter << endl;
                }
            }
            cout << "----------------------------------" << endl;
        }
        if(counter == k){
            return true;
        }
    }
    return false;
}

void Stampa_Matrice(int** M, int n, int m){
    cout << "Matrice: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(j!=m-1){
                cout << M[i][j] << "\t";
            }
            else{
                cout << M[i][j] << endl;
            }
        }
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 3;
    short k = 2;
    double x = 0.5;
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

    Stampa_Matrice(M, n, m);

    cout << endl;
    if(esercizio25(M, n, m, k, x)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}