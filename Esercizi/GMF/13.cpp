/* [Esercizio 13] Scrivere un metodo che preveda due parametri formali matrici di interi, A e B di dimensioni k × n ed
n × k rispettivamente, e restituisca uno array monodimensionale di k elementi double in cui lo i-esimo elemento sia uguale alla
differenza tra la media aritmetica degli elementi della riga i-esima di A ed il minimo valore degli elementi della colonna i-esima
di B. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

double* esercizio13(int** A, int k, int n, int** B){
    double* R = new double[k];
    int somma;
    int min;
    for(int i = 0; i<k; i++){
        somma = 0;
        min = 5000;
        for(int j = 0; j<n; j++){
            somma += A[i][j];
            //cout << "somma = " << somma << endl;
            //ricerca del minimo valore della colonna i-esima   
            if(min > B[j][i]){
                min = B[j][i];
                //cout << "min = " << min << endl;
            }     
        }
        cout << "somma = " << somma << endl;
        cout << "min = " << min << endl;
        cout << "media = " << ((double)somma/k) << endl;
        R[i] = ((double)somma/k) - min;
    }

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
    srand(time(0));
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
    srand(time(0));
    cout << "Matrice (B):" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<k; j++){
            B[i][j] = rand()%25;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    esercizio13(A, k, n, B);

}