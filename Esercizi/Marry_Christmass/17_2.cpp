/* Scrivere un metodo che prenda in input una 
matrice A di numeri interi e due double w e v, e 
restituisca il valore booleano true se esiste almeno una 
colonna di A in cui la media dei suoi elementi e 
compresa tra w e v. NB: Si assuma che w <=v. */

#include<iostream>
using namespace std;

bool fun(int** A, int n, int m, double w, double v){

    int somma_colonna;
    for(int j = 0; j<m; j++){
        somma_colonna = 0;
        for(int i = 0; i<n; i++){
            somma_colonna += A[i][j]; 
        }
        double media = somma_colonna/n;
        if(media < v && media > w){
            return true;
        }
    }
    return false;
}

void Stampa_Matrice(int** M, int n, int m){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(j!=m-1){
                cout << M[i][j] << "\t";
            }
            else{
                cout << M[i][j] << endl;
            }
        }
    }
    cout << endl;
}

int main(){
    int n = 3;
    int m = 4;
    double w = 4.5;
    double v = 7.6;

    int** A = new int*[n];
    for(int i = 0; i<n; i++){
        A[i] = new int[m];
    }

    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            A[i][j] = rand()%25;
        }
    }

    Stampa_Matrice(A, n, m);

    if(fun(A, n, m, w, v)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    } 
}