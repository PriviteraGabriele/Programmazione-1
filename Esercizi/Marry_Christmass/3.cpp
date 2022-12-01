/* Scrivere un metodo che prenda in input un
parametro formale matrice quadrata Q di interi ed un
double w, e restituisca un valore booleano true se
esiste almeno una colonna della matrice Q tale che il
rapporto tra la somma degli elementi della colonna
stessa e la somma degli elementi della diagonale
secondaria di Q sia maggiore di w. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool esercizio3(int** Q, int n, double w){
    int somma_diagonale_secondaria = 0;
    int somma_colonna;
    for(int i = 0; i<n; i++){
        somma_diagonale_secondaria += Q[i][n - 1 - i];
    }

    for(int j = 0; j<n; j++){
        somma_colonna = 0;
        for(int i = 0; i<n; i++){
            somma_colonna += Q[i][j];
        }
        cout << "----------------------------------------" << endl;
        cout << "somma_colonna = " << somma_colonna << endl;
        cout << "somma_diagonale_secondaria = " << somma_diagonale_secondaria << endl;
        cout << "rapporto = " << (double)somma_colonna/somma_diagonale_secondaria << endl;
        cout << "----------------------------------------" << endl;
        if((double)somma_colonna/somma_diagonale_secondaria > w){
            return true;
        }
    }
    return false;
}

void Stampa_Matrice(int** Q, int n){
    cout << "Matrice: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(j!=n-1){
                cout << Q[i][j] << "\t";
            }
            else{
                cout << Q[i][j] << endl;
            }
        }
    }
    cout << endl;
}


int main(){
    int n = 3;
    double w = 0.9;
    
    int** Q = new int*[n];
    for(int i = 0; i<n; i++){
      Q[i] = new int[n];  
    }

    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            Q[i][j] = rand()%15;
        }
    }

    Stampa_Matrice(Q, n);
    
    if(esercizio3(Q, n, w)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}