/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice quadrata S 
di dimensioni n x n di puntatori a interi senza segno, un double w ed uno short k 
(si assumak < n). Il metodo restituisca il valore booleano true se esiste almeno k 
colonne in S che soddisfano il seguente requisito: la media aritmetica degli elementi 
della colonna stessa sia minore o uguale a w. NB: si presti attenzione ai numeri mancanti.. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool e1(unsigned int*** S, int n, double w, short k){
    int counter = 0;
    int somma;
    for(int j = 0; j<n; j++){
        somma = 0; 
        for(int i = 0; i<n; i++){
            if(S[i][j]){
                cout << "*S[" << i << "][" << j << "] = " << *S[i][j] << endl;
                somma += *S[i][j];
            }
        }
        cout << "somma = " << somma << endl;
        cout << "media = " << (double)somma/n << endl;
        if((double)somma/n <= w){
            counter++;
            cout << "***counter = " << counter << endl;
            
        }
    }
    if(counter >= k){
        return true;
    }
    return false;
}

void Stampa_Matrice(unsigned int*** S, int n){
    cout << "Matrice:" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(S[i][j]){
                cout << *S[i][j] << "     \t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    double w = 7.2;
    short k = 2;

    unsigned int*** S = new unsigned int**[n];
    for(int i = 0; i<n; i++){
        S[i] = new unsigned int*[n];
    }

    srand(time(0));
    S[0][0] = new unsigned int(rand()%15);
    S[0][1] = new unsigned int(rand()%15);
    S[0][2] = new unsigned int(rand()%15);
    S[0][3] = new unsigned int(rand()%15);
    S[1][0] = new unsigned int(rand()%15);
    S[1][1] = new unsigned int(rand()%15);
    S[1][2] = new unsigned int(rand()%15);
    S[1][3] = new unsigned int(rand()%15);
    S[2][0] = new unsigned int(rand()%15);
    S[2][1] = new unsigned int(rand()%15);
    S[2][2] = new unsigned int(rand()%15);
    S[2][3] = new unsigned int(rand()%15);
    S[3][0] = new unsigned int(rand()%15);
    S[3][1] = new unsigned int(rand()%15);
    S[3][2] = new unsigned int(rand()%15);
    S[3][3] = new unsigned int(rand()%15);

    Stampa_Matrice(S, n);

    if(e1(S, n, w, k)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}