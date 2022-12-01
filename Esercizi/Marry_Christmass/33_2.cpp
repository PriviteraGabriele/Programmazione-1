/* 33.Scrivere un metodo che prenda in input una 
matrice quadrata A di puntatori ad interi e restituisca 
un double calcolato come il rapporto tra la somma 
degli elementi della diagonale principale di A e la 
somma degli elementi della diagonale secondaria di A 
stessa. NB: Si presti attenzione ai numeri mancanti! */

#include<iostream>
using namespace std;

double ex33(int*** A, int n){
    int sum1 = 0;
    int sum2 = 0;

    //Somma diagonale principale
    for(int i = 0; i<n; i++){
        if(A[i][i]){
            sum1 += *A[i][i];
        }
    }

    //Somma diagonale secondaria
    for(int i = 0; i<n; i++){
        if(A[i][n - i - 1]){
            sum2 += *A[i][n - i - 1];
        }
    }

    return (double)sum1/sum2;
}

void Stampa_Matrice(int*** A, int n){
    cout << "Matrice:" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(A[i][j]){
                cout << *A[i][j] << "\t";
            }
            else{
                cout << "*\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 3;
    int*** A = new int**[n];
    for(int i = 0; i<n; i++){
      A[i] = new int*[n];  
    }

    srand(time(0));

    A[0][0] = new int(rand()%15);
    A[0][1] = new int(rand()%15);
    A[0][2] = new int(rand()%15);
    A[1][0] = new int(rand()%15);
    A[1][1] = new int(rand()%15);
    A[1][2] = new int(rand()%15);
    A[2][0] = new int(rand()%15);
    A[2][1] = new int(rand()%15);
    A[2][2] = new int(rand()%15);

    Stampa_Matrice(A, n);

    cout << "Il rapporto tra la somma degli elementi della diagonale principale e della secondaria è: " << ex33(A, n) << endl;
}