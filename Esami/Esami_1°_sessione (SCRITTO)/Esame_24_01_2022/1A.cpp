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



int*** test1(int*** A, int n, int m, int a, int b, short s){
    int*** R = new int**[n];
    for(int i = 0; i<n; i++){
        R[i] = new int*[m];
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j]){
                R[i][j] = A[i][j];
            }
        }
    }
    
    int counter;
    int temp;
    bool save[n];
    for(int i = 0; i<n; i++){
        save[i] = false;
    }

    srand(time(0));
    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            counter = 0;
            if(A[i][j]){
                temp = *A[i][j];
                //cout << "-----------------------------------------------" << endl;
                //cout << "*A[" << i << "][" << j << "] = " << *A[i][j] << endl;
                //cout << "temp = " << temp << endl;
                //cout << "-----------------------------------------------" << endl;
                for(int t = 0; t<n; t++){       
                    //cout << "-----------------------------------------------" << endl;
                    //cout << "temp = " << temp << endl;
                    //cout << "*A[" << t << "][" << j << "] = " << *A[t][j] << endl;
                    if(A[t][j] && temp == *A[t][j]){
                        counter++;
                        //cout << "counter = " << counter << endl;
                        save[t] = true;
                        //cout << "save[" << t << "] = " << save[t] << endl;
                    }
                }
                //cout << "-----------------------------------------------" << endl;
                //cout << "-----------------------------------------------" << endl;
                //cout << "counter = " << counter << endl;
                //cout << "s = " << s << endl;
                //cout << "-----------------------------------------------" << endl;
                if(counter >= s){
                    for(int t = 0; t<n; t++){     
                        if(save[t]){
                            R[t][j] = new int((rand() % (b - a + 1) + a) * (-1));
                        }
                    }
                }
                for(int i = 0; i<n; i++){
                    save[i] = false;
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
    int*** R = test1(A, n, m, a, b, s);
    Stampa_Matrice(R, n, m);
}
    