/* [Esercizio 5] Scrivere un metodo che prenda in input un parametro formale array A di interi di dimensioni n×m di elementi
distinti ed un array B di double di dimensioni k × n, e restituisca un array di n interi nel quale lo i-esimo elemento sia uguale
alla media aritmetica degli elementi presenti sia nella riga i-esima di A che nella colonna i-esima di B. NB: per decidere se un
elemento int della matrice A `e uguale ad un elemento double della matrice B si calcoli l’approssimazione all’intero più vicino di
quest’ultimo. */

#include<iostream>
using namespace std;

int* esercizio5(int** A , int n, int m, double** B, int k){
    
    //Ritorno
    int* C = new int[n];
    for(int i = 0; i<n; i++){
        C[i] = 0;
    }

    //temporaneo
    double* AB = new double[n];
    for(int i = 0; i<n; i++){
        AB[i] = 0;
    }

    double somma;

    //righe
    for(int i = 0; i<n; i++){
        somma = 0;
        for(int j = 0; j<m; j++){
            somma += A[i][j];
        }
        AB[i] += somma;
    }
    
    //colonne
    for(int i = 0; i<k; i++){
        somma = 0;
        for(int j = 0; j<n; j++){
            somma += B[j][i];
        }
        AB[i] += somma;
    }

    for(int i = 0; i<n; i++){
        //cout << "------------------------------------" << endl;
        //cout << "AB[" << i << "] = " << AB[i] << endl;
        //cout << "media = " << (AB[i]/(k+m)) << endl;
        //cout << "int media = " << (int)(AB[i]/(k+m) + 0.5) << endl;
        //cout << "------------------------------------" << endl;
        C[i] = (int)(AB[i]/(k+m) + 0.5);
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

    //Stampa Matrice
    cout << "Matrice (A):" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << A[i][j] << "      ";
        }
        cout << endl;
    }
    cout << endl;

    double** B = new double*[k];
    for(int i = 0; i<k; i++){
        B[i] = new double[n];
    }

    srand(time(0));
    for(int i = 0; i<k; i++){
        for(int j = 0; j<n; j++){
            B[i][j] = rand()/(double)RAND_MAX*15;
        }
    }

    //Stampa Matrice
    cout << "Matrice (B):" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << B[i][j] << "      ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Array:     ";
    for(int i = 0; i<n; i++){
        cout << esercizio5(A, n, m, B, k)[i] << "      ";
    }
    cout << endl;
}