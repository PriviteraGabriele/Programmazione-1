/* [Esercizio 4] Scrivere un metodo che prenda in input due parametri formali: una matrice A di dimensioni n × m ed una
matrice B di dimensioni k × n entrambe di interi positivi. Il metodo restituisca un array C di double di dimensione n nel quale
lo i-esimo elemento dello array C sia uguale al rapporto tra la somma degli elementi della riga i-esima di A e il prodotto degli
elementi della colonna i-esima di B. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

double* esercizio4(int** A, int n, int m, int** B , int k){
    //ritorno
    double* C = new double[n];
    for(int i = 0; i<n; i++){
        C[i] = 0;
    }

    //Array temporaneo
    double* A1 = new double[n];
    for(int i = 0; i<n; i++){
        A1[i] = 0;
    }

    //Array temporaneo
    double* B1 = new double[n];
    for(int i = 0; i<n; i++){
        B1[i] = 0;
    }

    int somma_riga;
    for(int i = 0; i<n; i++){
        somma_riga = 0;
        for(int j = 0; j<m; j++){
            somma_riga += A[i][j];
        }
        A1[i] = somma_riga; 
    }

    /*cout << "A1:    ";
    for(int i = 0; i<n; i++){
        cout << A1[i] << "     ";
    }
    cout << endl;*/

    int prodotto_colonna;
    for(int i = 0; i<k; i++){
        prodotto_colonna = 1;
        for(int j = 0; j<n; j++){
            prodotto_colonna *= B[j][i];
        }
        B1[i] = prodotto_colonna;
    }

    /*cout << "B1:    ";
    for(int i = 0; i<n; i++){
        cout << B1[i] << "     ";
    }
    cout << endl;*/

    for(int i = 0; i<n; i++){
        if(B1[i] != 0){
            C[i] = (float)A1[i]/B1[i];
        }
        else{
            C[i] = 0;
        }
    }

    return C;
}

void Stampa_Matrice(int** A , int n, int m){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << A[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4; 
    int m = 4; 
    int k = 4; 

    int** A = new int*[n];
    for(int i = 0; i<n; i++){
        A[i] = new int[m];
    }

    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            A[i][j] = rand()%15;
        }
    }
    cout << "Matrice (A):" << endl << endl;
    Stampa_Matrice(A, n, m);

    int** B = new int*[k];
    for(int i = 0; i<k; i++){
        B[i] = new int[n];
    }

    srand(time(0));
    for(int i = 0; i<k; i++){
        for(int j = 0; j<n; j++){
            B[i][j] = rand()%15;
        }
    }
    cout << "Matrice (B):" << endl << endl;
    Stampa_Matrice(B, k, n);

    cout << "Array:     ";
    for(int i = 0; i<n; i++){
        cout << esercizio4(A, n, m, B, k)[i] << "      ";
    }
    cout << endl;
}