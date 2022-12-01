/* Scrivere un metodo che prenda come parametri 
formali una matrice A n×m di long ed un long x, e 
restituisca in output l’indice della colonna di A con il 
maggior numero di occorrenze di x. */

#include<iostream>
using namespace std;

int ex5(long** A, int n, int m, long x){
    int counter;
    int max = 0;
    int save;
    for(int j = 0; j<m; j++){
        counter = 0;
        for(int i = 0; i<n; i++){
            if(A[i][j] == x){
                counter++;
            }
        }
        if(max < counter){
            max = counter;
            save = j;
        }
    }
    return save;
}

void Stampa_Matrice(long** A, int n, int m){
    cout << "Matrice: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(j!=m-1){
                cout << A[i][j] << "\t";
            }
            else{
                cout << A[i][j] << endl;
            }
        }
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 5;
    long x = 250;

    long** A = new long*[n];
    for(int i = 0; i<n; i++){
        A[i] = new long[m];
    }

    A[0][0] = 250;
    A[0][1] = 143;
    A[0][2] = 78;
    A[0][3] = 250;
    A[0][4] = 250;
    A[1][0] = 250;
    A[1][1] = 250;
    A[1][2] = 93;
    A[1][3] = 250;
    A[1][4] = 250;
    A[2][0] = 250;
    A[2][1] = 47;
    A[2][2] = 250;
    A[2][3] = 86;
    A[2][4] = 246;
    A[3][0] = 250;
    A[3][1] = 250;
    A[3][2] = 76;
    A[3][3] = 963;
    A[3][4] = 250;

    /*srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            A[i][j] = rand()%1000;
        }
    }*/

    Stampa_Matrice(A, n, m);

    cout << "L’indice della colonna di A con il maggior numero di occorrenze di x è: " << ex5(A, n, m, x) << ", quindi la colonna: " << (ex5(A, n, m, x) + 1) << endl;
}