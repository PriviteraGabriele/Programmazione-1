/* [Esercizio 18] Scrivere un metodo che preveda un parametro formale matrice A 
di double di dimensioni n × k ed un array B di interi di dimensione n, e restituisca 
l’indice della colonna in A che contiene il maggior numero di elementi tali che 
l’approssimazione dell’elemento stesso al numero intero più vicino sia uguale al 
corrispondente elemento intero in B (NB: in pratica il generico elemento di indice 
(i,j) va confrontato con l’elemento in B di indice i). */

#include<iostream>
using namespace std;

short ex18(double** A, int n, int k, int* B){

    short ritorno;
    int counter;
    int max = 0;
    for(int j = 0; j<k; j++){
        counter = 0;
        for(int i = 0; i<n; i++){
            //cout << "A[" << i << "][" << j << "] = " <<(int)(A[i][j] + 0.5) << endl;
            if((int)(A[i][j] + 0.5) == B[i]){
                counter++;
            }
        }
        if(max < counter){
            max = counter;
            ritorno = j;
        }
    }

    return ritorno;
}

void Stampa_Array(int* B, int n){
    cout << "Array:      ";
    for(int i = 0; i<n; i++){
        cout << B[i] << "      ";
    }
    cout << endl << endl;
}

void Stampa_Matrice(double** A, int n, int k){
    cout << "Matrice:" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<k; j++){
            cout << A[i][j] << "      ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4; 
    int k = 4;

    double** A = new double*[n];
    for(int i = 0; i<n; i++){
        A[i] = new double[k];
    }

    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<k; j++){
            A[i][j] = rand()/(double)RAND_MAX*10;
        }
    }

    Stampa_Matrice(A, n, k);

    srand(time(0));
    int* B = new int[n];
    for(int i = 0; i<n; i++){
        B[i] = rand()%10;
    }
    
    Stampa_Array(B, n);

    cout << "L'indice è: " << ex18(A, n, k, B) << endl;
}