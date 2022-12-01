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

double esercizio32(string*** M ,int n, int m, char c1, char c2){
    int x = 0;     //contatore occorenze diagonale principale (01)
    int y = 0;     //contatore occorenze diagonale secondaria (02)
    string temp1 = "";
    string temp2 = "";
    
    //Occorrenze diagonale principale
    for(int i = 0; i<n; i++){
        if(M[i][i]){
            temp1 = *M[i][i];
            for(int p = 0; p<temp1.length(); p++){
                if(temp1[p] == c1){
                    x++;
                }
            }
        }
    }
    //cout << "01 = " << x << endl; 

    //Occorrenze diagonale secondaria
    for(int i = 0; i<n; i++){
        if(M[i][n - 1 - i]){
            temp2 = *M[i][n - 1 - i];
            for(int p = 0; p<temp2.length(); p++){
                if(temp2[p] == c2){
                    y++;
                }
            }
        }
    }
    //cout << "02 = " << y << endl;

    return (double)x/y;
}

void Stampa_Matrice(string*** M, int n, int m){
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
    char c1 = 'a';
    char c2 = 'l';

    string*** M = new string**[n];
    for(int i = 0; i<n; i++){
        M[i] = new string*[m];
    }

    M[0][0] = new string("casa");
    M[0][1] = new string("porta");
    M[0][2] = new string("canale");
    M[0][3] = new string("portatile");
    M[1][0] = new string("nonna");
    M[1][1] = new string("cacciagione");
    M[1][2] = new string("corsale");
    M[1][3] = new string("cacca");
    M[2][0] = new string("padrino");
    M[2][1] = new string("cortile");
    M[2][2] = new string("montagna");
    M[2][3] = new string("ginepro");
    M[3][0] = new string("arancia");
    M[3][1] = new string("partire");
    M[3][2] = new string("arto");
    M[3][3] = new string("casale");

    Stampa_Matrice(M, n, m);

    cout << "Il rapporto tra le occorrenze è: " << esercizio32(M, n, m, c1, c2) << endl;
}