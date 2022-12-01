/* Scrivere una funzione che prenda come parametro una Matrice di dimensione 
n x m di stringhe e restituisca una stringa che contenga tutte le vocali delle 
stringhe nelle posizioni A[i][j] tali che A[j%n][i%m] di almeno i+j unità. */

#include<iostream>
using namespace std;

string e4(string** A, int n, int m){
    string x = "";
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if((A[i][j].length() - A[j%m][i%m].length()) >= (i+j)){
                for(int p = 0; p<A[i][j].length(); p++){
                    if(A[i][j][p] == 'a' || A[i][j][p] == 'e' || A[i][j][p] == 'i' || A[i][j][p] == 'o' || A[i][j][p] == 'u' || A[i][j][p] == 'A' || A[i][j][p] == 'E' || A[i][j][p] == 'I' || A[i][j][p] == 'O' || A[i][j][p] == 'U'){
                        x += A[i][j][p];
                    }
                }
            }
        }
    }
    return x;
}

void Stampa_Matrice(string** A, int n, int m){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << A[i][j] << "    \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;

    string** A = new string*[n];
    for(int i = 0; i<n; i++){
        A[i] = new string[m];
    }

    A[0][0] = "camion";
    A[0][1] = "barella";
    A[0][2] = "bonucci";
    A[0][3] = "chiellini";
    A[1][0] = "adani";
    A[1][1] = "palla";
    A[1][2] = "orchestra";
    A[1][3] = "molletta";
    A[2][0] = "gioco";
    A[2][1] = "rajang";
    A[2][2] = "teostra";
    A[2][3] = "lunastra";
    A[3][0] = "pane";
    A[3][1] = "hunter";
    A[3][2] = "picnic";
    A[3][3] = "rick";

    Stampa_Matrice(A, n, m);

    cout << e4(A, n, m) << endl;
}