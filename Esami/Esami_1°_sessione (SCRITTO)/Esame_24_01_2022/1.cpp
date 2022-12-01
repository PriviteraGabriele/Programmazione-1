/* Scrivere un metodo in linguaggio C++ che prenda in imput una matrice di puntatori ad interi 
di dimensione n x m, due interi positivi a e b ed uno short s (si assuma a < b ed s < n). Il 
metodo restituisca una copia della matrice in cui ogni numero di una singola colonna della 
matrice di origine che risulti presente almeno s volte nella colonna stessa sia sostituito, nella 
corrispondente colonna della matrice copia, con un numero pseudo-casuale negativo appartenente
all'intervallo [-b, -a] (tranne gli elementi che risultano nullptr nella matrice originale!) */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int*** ex1(int*** M, int n, int m, int a, int b, short s){

    //Inizializzazione Matrice di ritorno
    int *** R = new int**[n];
    for(int i = 0; i<n; i++){
        R[i] = new int*[m];
    }

    //Copio la Matrice M nella nuova Matrice R
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(M[i][j]){
                R[i][j] = M[i][j];
            }
        }
    }

    

    int temp;
    int counter;
    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            if(M[i][j]){
                temp = *M[i][j];
                counter = 0;

                //Controllo se ci sono numeri, nella stessa, colonna che si ripetono
                for(int t = 0; t<n; t++){
                    if(M[t][j] && temp == *M[t][j]){
                        counter++;
                    }
                }

                //Sostituisco i numeri che si ripetono con numeri randomici conpresi tra -b e -a
                srand(time(NULL));

                if(counter >= s){
                    for(int r = 0; r<n; r++){
                        if(temp == *R[r][j]){
                            *R[r][j] = (rand() % (b - a + 1 ) + a)*(-1);
                        }
                    }
                }
            }
        }
    }
    
    return R;
}

void Stampa_Matrice(int*** A, int n, int m){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
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
    int n = 5; 
    int m = 4;
    int a = 1;
    int b = 5;
    short s = 3;

    srand(time(0));
    int*** A = new int**[n];
    for(int i = 0; i<n; i++){
        A[i] = new int*[m];
        for(int j = 0; j < m; j++) {
            A[i][j] = new int(rand() % (b - a + 1) + a);
        }
    }

    cout << "Matrice di partenza:" << endl;
    Stampa_Matrice(A, n, m);

    cout << endl << "Matrice risultante:" << endl;
    int*** R = ex1(A, n, m, a, b, s);
    Stampa_Matrice(R, n, m);
}