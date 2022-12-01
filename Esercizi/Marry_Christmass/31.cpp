/* Scrivere un metodo che prenda in input una 
matrice M di puntatori a double di dimensione n × m e 
due interi a e b e restituisca un array unidimensionale 
di booleani di lunghezza 2m tale che l’elemento 
dell’array di posizione 2i contiene True se e solo se la 
media dei soli elementi della colonna i-esima di M 
compresi tra a e b(estremi inclusi) è maggiore di 
(a+b)/2. Gli elementi dell’array di indice dispari devono 
essere inizializzati a False. NB: Si presti attenzione ai 
numeri mancanti! */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool* esercizio31(double*** M, int n, int m, int a, int b){
    bool* A = new bool[2*m];

    for(int i = 0; i<2*m; i++){
        A[i] = false;
    }

    double somma;
    //(Per seguire i dati della consegna) i sono le colonne e j sono le righe
    for(int i = 0; i<m; i++){
        somma = 0;
        for(int j = 0; j<n; j++){ //j
            if(M[j][i]){
                //cout << "*M[" << j << "][" << i << "] = " << *M[j][i] << endl;
                if(*M[j][i] >= a && *M[j][i] <= b){
                    somma += *M[j][i];
                }
            }
        }
        //cout << "somma = " << somma << endl;
        //cout << "rapporto = " << somma/n << endl;
        if(somma/n > (a+b)/2){
            A[2*i] = true;
            //cout << "A[" << 2*i << "] = " << A[2*i] << endl;
        }
        //cout << "---------------------------------------------" << endl;
    }

    cout << "Array:   ";
    for(int i = 0; i<2*m; i++){
        cout << A[i] << "   ";
    }
    cout << endl;

    return A;
}

void Stampa_Matrice(double*** M, int n, int m){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(M[i][j]){
                cout << *M[i][j] << "    \t";
            }
            else{
                cout << "*    \t" << endl;
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;
    int a = 3;
    int b = 17;

    double*** M = new double**[n];
    for(int i = 0; i<n; i++){
        M[i] = new double*[m];
    }

    srand(time(0));
    M[0][0] = new double(rand()/(double)RAND_MAX*20);
    M[0][1] = new double(rand()/(double)RAND_MAX*20);
    M[0][2] = new double(rand()/(double)RAND_MAX*20);
    M[0][3] = new double(rand()/(double)RAND_MAX*20);
    M[1][0] = new double(rand()/(double)RAND_MAX*20);
    M[1][1] = new double(rand()/(double)RAND_MAX*20);
    M[1][2] = new double(rand()/(double)RAND_MAX*20);
    M[1][3] = new double(rand()/(double)RAND_MAX*20);
    M[2][0] = new double(rand()/(double)RAND_MAX*20);
    M[2][1] = new double(rand()/(double)RAND_MAX*20);
    M[2][2] = new double(rand()/(double)RAND_MAX*20);
    M[2][3] = new double(rand()/(double)RAND_MAX*20);
    M[3][0] = new double(rand()/(double)RAND_MAX*20);
    M[3][1] = new double(rand()/(double)RAND_MAX*20);
    M[3][2] = new double(rand()/(double)RAND_MAX*20);
    M[3][3] = new double(rand()/(double)RAND_MAX*20);

    //Test tutti positivi
    /*M[0][0] = new double(14.5);
    M[0][1] = new double(14.5);
    M[0][2] = new double(14.5);
    M[0][3] = new double(14.5);
    M[1][0] = new double(14.5);
    M[1][1] = new double(14.5);
    M[1][2] = new double(14.5);
    M[1][3] = new double(14.5);
    M[2][0] = new double(14.5);
    M[2][1] = new double(14.5);
    M[2][2] = new double(14.5);
    M[2][3] = new double(14.5);
    M[3][0] = new double(14.5);
    M[3][1] = new double(14.5);
    M[3][2] = new double(14.5);
    M[3][3] = new double(14.5);*/

    Stampa_Matrice(M, n, m);

    esercizio31(M, n, m, a, b);
}