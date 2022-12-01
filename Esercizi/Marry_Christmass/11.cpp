/* Scrivere un metodo che prenda come parametri 
formali una matrice quadrata A n×n di puntatori ad int 
e restituisca in output un bool che indichi se la somma 
degli elementi puntati dalla diagonale sottostante la 
diagonale secondaria è divisibile per n. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool esercizio11(int*** A, int n){
    int somma_sotto_diagonale = 0;
    cout << "Array:   ";
    for(int i = 0; i+1<n; i++){
        somma_sotto_diagonale += *A[i+1][n - 1 - i];
        cout << *A[i+1][n - 1 - i] << "  ";
    }
    //cout di controllo
    cout << endl << "somma_sotto_diagonale = " << somma_sotto_diagonale << endl;
    cout << somma_sotto_diagonale%n << endl;

    if((somma_sotto_diagonale%n)==0){      
        return true;
    }
    cout << endl;
    return false;
}

void Stampa_Matrice(int*** A, int n){
    cout << "Matrice: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(j!=n-1){
                cout << *A[i][j] << "\t";
            }
            else{
                cout << *A[i][j] << endl;
            }
        }
    }
    cout << endl;
}

int main(){
    int n = 4;
    int*** A = new int**[n];
    for(int i = 0; i<n; i++){
      A[i] = new int*[n];  
    }

    srand(time(0));
    A[0][0] = new int(rand()%15);
    A[0][1] = new int(rand()%15);
    A[0][2] = new int(rand()%15);
    A[0][3] = new int(rand()%15);
    A[1][0] = new int(rand()%15);
    A[1][1] = new int(rand()%15);
    A[1][2] = new int(rand()%15);
    A[1][3] = new int(rand()%15);
    A[2][0] = new int(rand()%15);
    A[2][1] = new int(rand()%15);
    A[2][2] = new int(rand()%15);
    A[2][3] = new int(rand()%15);
    A[3][0] = new int(rand()%15);
    A[3][1] = new int(rand()%15);
    A[3][2] = new int(rand()%15);
    A[3][3] = new int(rand()%15);

    Stampa_Matrice(A, n);

    if(esercizio11(A, n)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}