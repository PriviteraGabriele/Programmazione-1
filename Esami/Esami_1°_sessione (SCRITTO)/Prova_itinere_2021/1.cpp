/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice 
di puntatori a interi di dimensioni n x m, un double z ed uno short k 
(si assuma k<n). Il metodo restituisca il numero di colonne che contengono 
almeno k elementi contigui la cui media aritmetica risulti minore di z . */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int es1(int*** M, int n, int m, double z, short k){
    
    int counter = 0;        //ritorno

    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            double somma = 0;
            int seqleg = 0;
            bool found = false;
            for(int l = i; l<n; l++){
                if(M[l][j]){
                    somma += *M[l][j];
                    seqleg++;
                    if(seqleg >= k && (double)somma/seqleg < z){
                        counter++;
                        break;
                    }
                }
                else{
                    somma = 0;
                    seqleg = 0;
                }
            }
        }
    }
    
    return counter;
}

void Stampa_Matrice(int*** M, int n, int m){
    cout << "Matrice: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(M[i][j]){
                cout << *M[i][j] << "    \t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;
    double z = 4.3;
    short k = 2;

    srand(time(0));

    int*** M = new int**[n];
    for(int i = 0; i<n; i++){
        M[i] = new int*[m];
        for(int j = 0; j<m; j++){
            M[i][j] = new int(rand()%15);
        }
    }

    Stampa_Matrice(M, n, m);

    cout << "Il numero di colonne è: " << es1(M, n, m, z, k) << endl;
}

