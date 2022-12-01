/* Scrivere una funzione che prenda in input una matrice quadrata A di short, e restituisca un bool 
che indichi se la diagonale principale è identica (procedendo dall’alto verso il basso) alla secondaria. */

#define N 4
#include<iostream>
using namespace std;

bool ritorno(short A[][N]){
    bool risposta = true;
    short d1 = 0;
    short d2 = 0;
    for(int i = 0; i<N; i++){
        d1 = A[i][i];
        d2 = A[i][N-1-i];
        if(d1!=d2){
            risposta = false;
            return risposta;
        }
    }
    return risposta;
}

int main(){
    /*short A[N][N] = {{1, 2, 3, 1}, 
                     {5, 6, 6, 4},      //si
                     {8, 9, 9, 7}, 
                     {2, 5, 6, 2}};*/

    /*short A[N][N] = {{1, 2, 3, 8}, 
                     {5, 6, 6, 4}, 
                     {8, 9, 9, 7},          //no
                     {2, 5, 6, 2}};*/

    /*short A[N][N] = {{1, 2, 3, 1}, 
                     {5, 6, 7, 4},      //no
                     {8, 9, 9, 7}, 
                     {2, 5, 6, 4}};*/

    /*short A[N][N] = {{8, 2, 3, 8}, 
                     {5, 7, 7, 4}, 
                     {8, 9, 9, 7},      //si
                     {3, 5, 6, 3}};*/

    short A[N][N] = {{0, 0, 0, 0}, 
                     {0, 0, 0, 0}, 
                     {0, 0, 0, 0},          //si
                     {0, 0, 0, 0}};                 

    //stampa matrice
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(j==3){
                cout << A[i][j] << endl;
            }
            else{
                cout << A[i][j] << " ";
            }
        }
    }

    if(ritorno(A)){
        cout << "La diagonale principale è identica (procedendo dall’alto verso il basso) alla secondaria!" << endl;
    }
    else{
        cout << "La diagonale principale non è identica (procedendo dall’alto verso il basso) alla secondaria!" << endl;
    }
    
    
}