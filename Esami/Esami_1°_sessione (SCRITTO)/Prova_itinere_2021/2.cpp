/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice A
di puntatori a stringhe ed un array B di caratteri. Il metodo operi sulle 
stringhe delle colonne di indice dispari di A depurandole delle vocali 
eventualmente presenti in B. */

#include<iostream>
using namespace std;

void es2(string*** A, int n, int m, char* B){
    string r = "";
    for(int j = 1; j<m; j+=2){
        for(int i = 0; i<n; i++){
            if(A[i][j]){
                r = *A[i][j];
                for(int p = 0; p<r.length(); p++){
                    if(r[p] == 'a' || r[p] == 'e' || r[p] == 'i' || r[p] == 'o' || r[p] == 'u' || r[p] == 'A' || r[p] == 'E' || r[p] == 'I' || r[p] == 'O' || r[p] == 'U'){
                        for(int x = 0; x<n; x++){
                            if(r[p] == B[x]){
                                r[p] = '*';
                            }
                        }
                    }
                }
                *A[i][j] = r;
            }
        }
    }
}

void Stampa_Matrice(string*** A, int n, int m){
    cout << "Matrice: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j]){
                cout << *A[i][j] << "    \t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4; 
    int m = 4;

    string*** A = new string**[n];
    for(int i = 0; i<n; i++){
        A[i] = new string*[m];
    }
    
    A[0][0] = new string("casa");
    A[0][1] = new string("chiosco");
    A[0][2] = new string("chiesa");
    A[0][3] = new string("ciao");
    A[1][0] = new string("giardino");
    A[1][1] = new string("penisola");
    A[1][2] = new string("catacombe");
    A[1][3] = new string("albero");
    A[2][0] = new string("dita");
    A[2][1] = new string("saladin");
    A[2][2] = new string("rutilia");
    A[2][3] = new string("salute");
    A[3][0] = new string("intelletto");
    A[3][1] = new string("fede");
    A[3][2] = new string("magia");
    A[3][3] = new string("cane");

    Stampa_Matrice(A, n, m);

    char* B = new char[n];

    B[0] = 'g';
    B[1] = 'o';
    B[2] = 'a';
    B[3] = 'e';

    cout << "Array:     ";
    for(int i = 0; i<n; i++){
        cout << B[i] << "     ";
    }
    cout << endl << endl;

    es2(A, n, m, B);

    Stampa_Matrice(A, n, m);
}