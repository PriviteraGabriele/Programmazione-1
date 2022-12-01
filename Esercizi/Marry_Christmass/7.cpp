/* Scrivere un metodo che prenda in input un 
parametro formale matrice A di puntatori ad interi di 
dimensione nxm, due double d1 e d2 ed uno short s, e 
restituisca il numero di colonne di A nelle quali 
esistano almeno s coppie di elementi contigui (ES: 
A[1][1] e A[2][1]) tali che il rapporto tra il primo ed il 
secondo elemento sia compreso tra d1 e d2. NB: Si 
assuma a priori che s<=n-1 e che d1 < d2. Si presti 
attenzione ai numeri "mancanti"nella matrice A. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int esercizio7(int*** M, int n, int m, double d1, double d2, short s){
    int counter_colonne = 0;
    int counter_coppie;
    int temp1 = 0;
    int temp2 = 0;
    for(int j = 0; j<m; j++){
        counter_coppie = 0;
        for(int i = 0; i<n-1; i++){
            if(M[i][j] && M[i+1][j]){
                temp1 = *M[i][j];
                cout << "--------------------------------------------------" << endl;
                cout << "temp1 = " << temp1 << endl;
                temp2 = *M[i+1][j];      
                cout << "temp2 = " << temp2 << endl;
                cout << "temp1/temp2 = " << (double)temp1/temp2 << endl;
                if((double)temp1/temp2 > d1 && (double)temp1/temp2 < d2){
                    counter_coppie++;
                    cout << "counter_coppie = " << counter_coppie << endl;
                }  
                cout << "--------------------------------------------------" << endl;
            }
        }
        if(counter_coppie>=s){
            counter_colonne++;
            cout << "counter_colonne = " << counter_colonne << endl;
        }
    }
    return counter_colonne;
}

void Stampa_Matrice(int*** M, int n, int m){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(M[i][j]){
                cout << *M[i][j] << " \t";
            }
            else{
                cout << "* \t"; 
            }
        }
        cout << endl;
    }
}

int main(){
    int n = 4;
    int m = 3;
    double d1 = 0.2;
    double d2 = 1.2;
    short s = 2;
    int*** M = new int**[n];
    for(int i = 0; i<n; i++){
      M[i] = new int*[m];  
    }

    srand(time(0));
    M[0][0] = new int(rand()%15);
    M[0][1] = new int(rand()%15);
    M[0][2] = new int(rand()%15);
    M[1][0] = new int(rand()%15);
    M[1][1] = new int(rand()%15);
    M[1][2] = new int(rand()%15);
    M[2][0] = new int(rand()%15);
    M[2][1] = new int(rand()%15);
    M[2][2] = new int(rand()%15);
    M[3][0] = new int(rand()%15);
    M[3][1] = new int(rand()%15);
    M[3][2] = new int(rand()%15);

    Stampa_Matrice(M, n, m);

    cout << esercizio7(M, n, m, d1, d2, s) << endl;
}