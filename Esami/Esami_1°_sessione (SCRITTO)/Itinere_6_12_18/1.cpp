/* Scrivere un metodo che prenda in input un parametro formale matrice A di interi di dimensioni n × n ed
un double w, e restituisca un valore booleano true se esiste almeno una colonna della matrice A per cui il
rapporto tra la somma degli elementi della colonna stessa e la somma degli elementi della diagonale principale
di A sia maggiore di w. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool ex1(int** A, int n, double w){
    //Mi calcolo la somma degli elementi della diagonale principale
    int sum_principale = 0;
    for(int i = 0; i<n; i++){
        sum_principale += A[i][i];
    }


    int sum_colonna;
    for(int j = 0; j<n; j++){
        sum_colonna = 0;
        for(int i = 0; i<n; i++){
            sum_colonna += A[i][j];
        }
        cout << "---------------------------------" << endl;
        cout << "sum_colonna (" << j << ") = " << sum_colonna << endl;
        cout << "sum_principale = " << sum_principale << endl;
        cout << "rapporto (" << j << ") = " << (double)sum_colonna/sum_principale << endl;
        cout << "w = " << w << endl;
        cout << "---------------------------------" << endl;
        if((double)sum_colonna/sum_principale > w){
            return true;
        }
    }
    return false;
}

int main(){
    int n = 4;
    double w = 1.8;

    int** A =new int*[n];
    for(int i = 0; i<n; i++){
        A[i] = new int[n];
    }

    srand(time(0));
    cout << "Matrice:" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            A[i][j] = rand()%15;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    if(ex1(A, n, w)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}