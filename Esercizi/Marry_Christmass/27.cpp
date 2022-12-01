/* .Scrivere un metodo che prenda come parametro 
formale una matrice A n×m di puntatori ad intero, e 
restituisca in output un bool che indichi se esistono 
due elementi in A che puntano allo stesso valore intero 
(anche in locazioni differenti). */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool esercizio27(int*** A, int n, int m){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){  
            for(int x = 0; x<n; x++){
                for(int y = 0; y<m; y++){
                    if(i != x || j != y){
                        if(*A[i][j] == *A[x][y]){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void Stampa_Matrice(int*** A, int n, int m){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j]){
                cout << *A[i][j] << "\t";
            }
            else{
                cout << "*\t" << endl;
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;

    int*** A = new int**[n];
    for(int i = 0; i<n; i++){
        A[i] = new int*[m];        
    }

    srand(time(0));
    A[0][0] = new int(rand()%150);
    A[0][1] = new int(rand()%150);
    A[0][2] = new int(rand()%150);
    A[0][3] = new int(rand()%150);
    A[1][0] = new int(rand()%150);
    A[1][1] = new int(rand()%150);
    A[1][2] = new int(rand()%150);
    A[1][3] = new int(rand()%150);
    A[2][0] = new int(rand()%150);
    A[2][1] = new int(rand()%150);
    A[2][2] = new int(rand()%150);
    A[2][3] = new int(rand()%150);
    A[3][0] = new int(rand()%150);
    A[3][1] = new int(rand()%150);
    A[3][2] = new int(rand()%150);
    A[3][3] = new int(rand()%150);

    Stampa_Matrice(A, n, m);

    if(esercizio27(A, n, m)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}