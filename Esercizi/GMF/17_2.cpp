/* [Esercizio 17] Scrivere un metodo che prenda un parametro formale matrice di stringhe S 
di dimensione n × m e due array di caratteri C e D di egual dimensione n e restituisca un 
array di short nel quale il generico elemento di posto i contiene il numero di stringhe che 
iniziano con il carattere di C avente indice i e finiscono con il carattere in D avente indice i. */

#include<iostream>
using namespace std;

short* ex17(string** S, int n, int m, char* C, char* D){

    short* R = new short[n];
    for(int i = 0; i<n; i++){
        R[i] = 0;
    }

    for(int i = 0; i<n; i++){
        int counter = 0;
        for(int j = 0; j<m; j++){
            if(S[i][j][0] == C[i] && S[i][j][S[i][j].length()-1] == D[i]){
                counter++;
            }
        }
        R[i] = counter;
    }

    //Stampa Array
    cout << "Array (Ritorno):     ";
    for(int i = 0; i<n; i++){
        cout << R[i] << "     ";
    }
    cout << endl << endl;

    return R;
}

void Stampa_Array(char* C, int n){
    for(int i = 0; i<n; i++){
        cout << C[i] << "     ";
    }
    cout << endl << endl;
}

void Stampa_Matrice(string** S, int n, int m){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << S[i][j] << "    \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4; 
    int m = 4;

    string** S = new string*[n];
    for(int i = 0; i<n; i++){
        S[i] = new string[m];
    }
    S[0][0] = "camion";
    S[0][1] = "barella";
    S[0][2] = "bonucci";
    S[0][3] = "chiellini";
    S[1][0] = "adani";
    S[1][1] = "palla";
    S[1][2] = "orchestra";
    S[1][3] = "molletta";
    S[2][0] = "gioco";
    S[2][1] = "rajang";
    S[2][2] = "teostra";
    S[2][3] = "lunastra";
    S[3][0] = "chimera";
    S[3][1] = "hunter";
    S[3][2] = "picnic";
    S[3][3] = "rick";

    Stampa_Matrice(S, n, m);

    char* C = new char[n];

    C[0] = 'b';
    C[1] = 'a';
    C[2] = 'c';
    C[3] = 'd'; 

    cout << "Array (C):     ";
    Stampa_Array(C, n);

    char* D = new char[n];

    D[0] = 'a';
    D[1] = 'i';
    D[2] = 's';
    D[3] = 'k';

    cout << "Array (D):     ";
    Stampa_Array(D, n);

    ex17(S, n, m, C, D);
}