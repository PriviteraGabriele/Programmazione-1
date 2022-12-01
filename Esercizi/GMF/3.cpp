/* [Esercizio 3] Scrivere un metodo che prenda in input tre parametri formali: una matrice di stringhe S di dimensioni n×m,
un array di caratteri C che contiene elementi distinti, ed un float w. Il metodo restituisca true se esiste almeno una riga o una
colonna della matrice tale che la percentuale di caratteri di C presenti in essa `e maggiore di w. */

#include<iostream>
using namespace std;

bool esercizio3(string** S, int n, int m, char* C, float w){
    int counter_caratteri;
    int somma_caratteri;
    //Controllo righe
    //cout << "RIGHE: " << endl << endl;
    for(int i = 0; i<n; i++){
        somma_caratteri = 0;
        counter_caratteri = 0;
        for(int j = 0; j<m; j++){
            //cout << S[i][j] << endl;
            //cout << S[i][j].length() << endl;
            somma_caratteri += S[i][j].length();
            for(int p = 0; p<S[i][j].length(); p++){
                for(int t = 0; t<n; t++){
                    if(S[i][j][p] == C[t]){
                        counter_caratteri++;
                    }
                }
            }
        }
        //cout << "counter_caratteri = " << counter_caratteri << endl;
        //cout << "somma_caratteri = " << somma_caratteri << endl;
        //cout << "percentuale = " << ((float)counter_caratteri/somma_caratteri)*100 << endl;
        if(((float)counter_caratteri/somma_caratteri)*100 > w){
            return true;
        }
    }

    //Controllo colonne
    //cout << endl << "COLONNE: " << endl << endl;
    for(int j = 0; j<m; j++){
        somma_caratteri = 0;
        counter_caratteri = 0;
        for(int i = 0; i<n; i++){
            //cout << S[i][j] << endl;
            //cout << S[i][j].length() << endl;
            somma_caratteri += S[i][j].length();
            for(int p = 0; p<S[i][j].length(); p++){
                for(int t = 0; t<n; t++){
                    if(S[i][j][p] == C[t]){
                        counter_caratteri++;
                    }
                }
            }
        }
        //cout << "counter_caratteri = " << counter_caratteri << endl;
        //cout << "somma_caratteri = " << somma_caratteri << endl;
        //cout << "percentuale = " << ((float)counter_caratteri/somma_caratteri)*100 << endl;
        if(((float)counter_caratteri/somma_caratteri)*100 > w){
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

    if(esercizio3(S, n, m, C, w)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}