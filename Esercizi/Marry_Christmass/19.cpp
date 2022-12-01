/* Scrivere un metodo che prenda in input una 
matrice quadrata M di short e restituisca il valore 
booleano true se M e una matrice triangolare inferiore 
o superiore. */

#include<iostream>
using namespace std;

bool esercizio19(short** A, int n){
    int counter = 0;
    //Controllo Matrice diagonale superiore
    for(int i = 0; i<n; i++){
        for(int j = 1 + i; j<n; j++){
            if(A[i][j] == 0){
                counter++;
            }
        }
    }
    if(counter == ((n*n)-n)/2){
        return true;
    }

    //Controllo Matrice diagonale inferiore
    for(int j = 0; j<n; j++){
        for(int i = 1 + j; i<n; i++){
            if(A[i][j] == 0){
                counter++;
            }
        }
    }
    if(counter == ((n*n)-n)/2){
        return true;
    }
    return false;
}

void Stampa_Matrice(short** A, int n){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;

    short** A = new short*[n];
    for(int i = 0; i<n; i++){
        A[i] = new short[n];
    }

    //Matrice diagonale superiore
    /*A[0][0] = 1;
    A[0][1] = 0;
    A[0][2] = 0;
    A[0][3] = 0;
    A[1][0] = 5;
    A[1][1] = 2;
    A[1][2] = 0;
    A[1][3] = 0;
    A[2][0] = 8;
    A[2][1] = 6;
    A[2][2] = 3;
    A[2][3] = 0;
    A[3][0] = 10;
    A[3][1] = 9;
    A[3][2] = 7;
    A[3][3] = 4;*/

    //Matrice diagonale inferiore
    /*A[0][0] = 1;
    A[0][1] = 5;
    A[0][2] = 8;
    A[0][3] = 10;
    A[1][0] = 0;
    A[1][1] = 2;
    A[1][2] = 6;
    A[1][3] = 9;
    A[2][0] = 0;
    A[2][1] = 0;
    A[2][2] = 3;
    A[2][3] = 7;
    A[3][0] = 0;
    A[3][1] = 0;
    A[3][2] = 0;
    A[3][3] = 4;*/

    //Matrice caso falso
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[0][3] = 0;
    A[1][0] = 5;
    A[1][1] = 2;
    A[1][2] = 8;
    A[1][3] = 9;
    A[2][0] = 8;
    A[2][1] = 6;
    A[2][2] = 3;
    A[2][3] = 4;
    A[3][0] = 10;
    A[3][1] = 9;
    A[3][2] = 7;
    A[3][3] = 4;

    Stampa_Matrice(A, n);

    if(esercizio19(A, n)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    } 
}