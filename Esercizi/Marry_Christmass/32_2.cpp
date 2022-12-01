/* Scrivere un metodo che prenda in input una 
matrice quadrata di puntatori a stringhe e due caratteri 
c1 e c2. Calcolare O1 come numero di occorrenze del 
carattere c1 che figurano nella diagonale principale. 
Calcolare O2 come numero di occorrenze del carattere 
c2 che che figurano nella secondaria. Restituire il 
rapportoO1/O2. NB: si faccia attenzione alle stringhe 
mancanti. */

#include<iostream>
using namespace std;

double ex32(string*** A, int n, char c1, char c2){
    int counter_1 = 0;          //occorrenze c1 nella diagonale principale
    int counter_2 = 0;          //occorrenze c2 nella diagonale secondaria
    string sum_1 = "";      //somma stringhe diagonale principale
    string sum_2 = "";      //somma stringhe diagonale secondaria

    //diagonale principale
    for(int i = 0; i<n; i++){
        if(A[i][i]){
            sum_1 += *A[i][i];
        }
    }
    for(int p = 0; p<sum_1.length(); p++){
        if(sum_1[p] == c1){
            counter_1++;
        }
    }

    //diagonale secondaria
    for(int i = 0; i<n; i++){
        if(A[i][n - i - 1]){
            sum_2 += *A[i][n - i - 1];
        }
    }
    for(int p = 0; p<sum_2.length(); p++){
        if(sum_2[p] == c2){
            counter_2++;
        }
    }
    return (double)counter_1/counter_2;
}

void Stampa_Matrice(string*** A, int n){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(A[i][j]){
                cout << *A[i][j] << "    \t";
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
    char c1 = 'a';
    char c2 = 'l';

    string*** A = new string**[n];
    for(int i = 0; i<n; i++){
        A[i] = new string*[n];
    }

    A[0][0] = new string("casa");
    A[0][1] = new string("porta");
    A[0][2] = new string("canale");
    A[0][3] = new string("portatile");
    A[1][0] = new string("nonna");
    A[1][1] = new string("cacciagione");
    A[1][2] = new string("corsale");
    A[1][3] = new string("cacca");
    A[2][0] = new string("padrino");
    A[2][1] = new string("cortile");
    A[2][2] = new string("montagna");
    A[2][3] = new string("ginepro");
    A[3][0] = new string("arancia");
    A[3][1] = new string("partire");
    A[3][2] = new string("arto");
    A[3][3] = new string("casale");
    
    Stampa_Matrice(A, n);

    cout << "Il rapporto tra le occorrenze è: " << ex32(A, n, c1, c2) << endl;
}