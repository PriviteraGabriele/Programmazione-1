/* Scrivere un metodo che prenda in input una 
matrice di stringhe di dimensioni n×m, due stringhe x 
e y e due short k e w; il metodo restituisca la 
percentuale di colonne della matrice che contengono 
almeno k stringhe contenenti almeno w caratteri 
presenti sia in x che in y. NB: si assuma, per 
semplicità, che ognuna delle stringhe della matrice non 
che le stringhe x e y non contengano lo stesso 
carattere più di una volta. */

#include<iostream>
using namespace std;

double esercizio36(string** M, int n, int m, string x, string y, short k, short w){
    int counter_x;           //caratteri x
    int counter_y;           //caratteri y
    int counter_stringhe; 
    int counter_colonne = 0;
    for(int j = 0; j<m; j++){
        counter_stringhe = 0;
        for(int i = 0; i<n; i++){
            counter_x = 0;
            counter_y = 0;
            for(int p = 0; p<M[i][j].length(); p++){
                //stringa x
                for(int r = 0; r<x.length(); r++){
                    if(M[i][j][p] == x[r]){
                        counter_x++;
                    }
                }
                //cout << "x = " << counter_x << endl;
                //stringa y
                for(int t = 0; t<y.length(); t++){
                    if(M[i][j][p] == y[t]){
                        counter_y++;
                    }
                }
                //cout << "y = " << counter_y << endl;
            }
            if(counter_x >= w && counter_y >= w){
                counter_stringhe++;
            }
            //cout << "stringhe = " << counter_stringhe << endl;
        }
        if(counter_stringhe >= k){
            counter_colonne++;
        }
        //cout << "colonne = " << counter_colonne << endl;
    }
    return ((double)counter_colonne/m)*100;
}

void Stampa_Matrice(string** M, int n, int m){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << M[i][j] << "    \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;
    string x = "abc";
    string y = "def";
    short k = 2;        //stringhe
    short w = 1;        //caratteri

    string** M = new string*[n];
    for(int i = 0; i<n; i++){
        M[i] = new string[m];
    }

    M[0][0] = "ghilmae";
    M[0][1] = "ghilcdm";
    M[0][2] = "ghiaelm";
    M[0][3] = "ghilm";
    M[1][0] = "ghibflm";
    M[1][1] = "ghilm";
    M[1][2] = "ghibflm";
    M[1][3] = "ghilm";
    M[2][0] = "ghilm";
    M[2][1] = "ghicdlm";
    M[2][2] = "ghilm";
    M[2][3] = "ghiaelm";
    M[3][0] = "ghilm";
    M[3][1] = "ghilm";
    M[3][2] = "ghilm";
    M[3][3] = "ghilbfm";

    Stampa_Matrice(M, n, m);

    cout << "La percentuale è = " << esercizio36(M, n, m, x, y, k, w) << "%" << endl;
}