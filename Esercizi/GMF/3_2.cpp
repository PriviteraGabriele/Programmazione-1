/* [Esercizio 3] Scrivere un metodo che prenda in input tre parametri formali: una matrice di stringhe S di dimensioni n×m,
un array di caratteri C che contiene elementi distinti, ed un float w. Il metodo restituisca true se esiste almeno una riga o una
colonna della matrice tale che la percentuale di caratteri di C presenti in essa `e maggiore di w. */

#include<iostream>
using namespace std;

bool ex3(string** S, int n, int m, char* C, float w){

    int counter;
    int somma;
    float percentuale;

    //Righe
    for(int i = 0; i<n; i++){
        counter = 0;
        somma = 0;
        percentuale = 0;
        for(int j = 0; j<m; j++){
            somma += S[i][j].length();
            for(int p = 0; p<S[i][j].length(); p++){
                for(int x = 0; x<n; x++){
                    if(S[i][j][p] == C[x]){
                        counter++;
                    }
                }
            }
        }
        percentuale = (float)((counter*100)/somma);
        if(percentuale > w){
            return true;
        }
    }

    //Colonne
    for(int j = 0; j<m; j++){
        counter = 0;
        somma = 0;
        percentuale = 0;
        for(int i = 0; i<n; i++){
            somma += S[i][j].length();
            for(int p = 0; p<S[i][j].length(); p++){
                for(int x = 0; x<n; x++){
                    if(S[i][j][p] == C[x]){
                        counter++;
                    }
                }
            }
        }
        percentuale = (float)((counter*100)/somma);
        if(percentuale > w){
            return true;
        }
    }

    return false;
}

void Stampa_Matrice(string** S, int n, int m){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << S[i][j] << "    \t";
        }
        cout << endl;
    }
    cout << endl;
}

void Stampa_Array(char* C, int n){
    cout << "Array:    ";
    for(int i = 0; i < n; i++) {
        cout << C[i] << "     ";
    }
    cout << endl << endl;
}

int main(){
    int n = 4;
    int m = 4;
    float w = 23.2;

    string** S = new string*[n];
    for(int i = 0; i<n; i++){
        S[i] = new string[m];
    }

    S[0][0] = "aless";
    S[0][1] = "malle";
    S[0][2] = "oo";
    S[0][3] = "abekeba";
    S[1][0] = "abeio";
    S[1][1] = "piano";
    S[1][2] = "ossapia";
    S[1][3] = "ala";
    S[2][0] = "ciaos";
    S[2][1] = "casa";
    S[2][2] = "oiapprppaio";
    S[2][3] = "corno";
    S[3][0] = "abeke";
    S[3][1] = "abeiokoieba";
    S[3][2] = "piano";
    S[3][3] = "ossa";
    
    Stampa_Matrice(S, n, m);

    char* C = new char[n];

    C[0] = 'a';
    C[1] = 'b';
    C[2] = 'c';
    C[3] = 'd';
    
    Stampa_Array(C, n);

    if(ex3(S, n, m, C, w)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}