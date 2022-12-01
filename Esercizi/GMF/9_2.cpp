/* [Esercizio 9] Scrivere un metodo che prenda in input un parametro formale A matrice 
di stringhe di dimensione n × m, ed una stringa s. Il metodo restituisca true se esistono 
almeno due stringhe in A che contengono la stringa s e che abbiano differenti indici di riga e di colonna. */

#include<iostream>
using namespace std;

bool ex9(string** A, int n, int m, string s){

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j].find(s) != string::npos){
                int temp_i = i;
                int temp_j = j;
                for(int x = 0; x<n; x++){
                    for(int y = 0; y<m; y++){
                        if(A[x][y].find(s) != string::npos && temp_i != x && temp_j != y){
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
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
    string s = "AAA";

    string** A = new string*[n];
    for(int i = 0; i<n; i++){
        A[i] = new string[m];
    }

    A[0][0] = "camAAAion";
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

    if(ex9(A, n, m, s)){
        cout << "Vero" << endl;
    }
    else{
        cout << "False" << endl;
    }
}