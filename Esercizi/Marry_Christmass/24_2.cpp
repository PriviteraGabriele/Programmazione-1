/* Scrivere un metodo che prenda in input una 
matrice di stringhe S di dimensioni n x m, uno short k, 
ed una stringa w. Il metodo restituisca il valore 
booleano true se esiste almeno una riga in S tale che 
la stringa w sia sottostringa di un numero di stringhe 
della riga stessa che sia minore o uguale a k. */

#include<iostream>
using namespace std;

bool ex24(string** S, int n, int m, short k, string w){

    int counter;
    for(int i = 0; i<n; i++){
        counter = 0;
        for(int j = 0; j<m; j++){
            if(S[i][j].find(w) != string::npos){
                counter++;
            }
        }

        if(counter <= k){
            return true;
        }
    }

    return false;
}

void Stampa_Matrice(string** S, int n, int m){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << S[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 3;
    int m = 4;
    short k = 2;
    string w = "ciao";

    string** S = new string*[n];
    for(int i = 0; i<n; i++){
        S[i] = new string[m];
    }

    S[0][0] = "miaociao";
    S[0][1] = "gattodi";
    S[0][2] = "spiaggia";
    S[0][3] = "comodi";
    S[1][0] = "orchestra";
    S[1][1] = "fisarmonica";
    S[1][2] = "gioiello";
    S[1][3] = "pesce";
    S[2][0] = "costarica";
    S[2][1] = "Monster";
    S[2][2] = "Hunter ";
    S[2][3] = "Iceborn";

    Stampa_Matrice(S, n, m);

    cout << endl;
    if(ex24(S, n, m, k, w)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}   