/* [Esercizio 4] Scrivere un metodo che prenda in input due parametri formali: una matrice A di dimensioni n × m ed una
matrice B di dimensioni k × n entrambe di interi positivi. Il metodo restituisca un array C di double di dimensione n nel quale
lo i-esimo elemento dello array C sia uguale al rapporto tra la somma degli elementi della riga i-esima di A e il prodotto degli
elementi della colonna i-esima di B. */

#include<iostream>
using namespace std;

double* ex4(int** A, int n, int m, int** B, int k){

    double* R = new double[n];

    //Inizializzazione a 0
    for(int i = 0; i<n; i++){
        R[i] = 0;
    }

    //Salvataggio somma delle righe di A nell'array
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            R[i] += A[i][j];
        }
    }

    double prod;
    for(int j = 0; j<k; j++){
        prod = 1;
        for(int i = 0; i<n; i++){
            prod *= B[i][j];
        }
        if(prod == 0){
            R[j] = 0; 
        }
        else{
            R[j] /= prod;
        }
    }

    return R;
}

void Stampa_Matrice(int** A , int n, int m){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << A[i][j] << "\t";
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
        cout << ex4(A, n, m, B, k)[i] << "      ";
    }
    cout << endl;
}