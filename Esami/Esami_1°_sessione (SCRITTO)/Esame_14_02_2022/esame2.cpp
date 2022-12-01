/* Scrivere una funzione che prenda in input una matrice S di dimensione n x n, 
una matrice B di boleani di dimensione n x n e restituisca una stringa ottenuta
concatenando i caratteri di indice pari delle stringhe di S che si trovano in 
corrispondenza di valori di B che sono identici nella corrispettiva trasposta B(T). */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

string esame2(string*** A, int n, bool** B){
    string ritorno = "";
    string s = "";
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(A[i][j]){
                cout << "-------------------------------------" << endl;
                s = *A[i][j];
                cout << "s = " << s << endl;
                cout << "B[" << i << "][" << j << "] = " << B[i][j] << endl;
                cout << "B[" << j << "][" << i << "] = " << B[j][i] << endl;
                for(int p = 0; p<s.length(); p+=2){
                    if(B[i][j] == B[j][i]){
                        ritorno += s[p];
                    }
                }
                cout << "ritorno: " << ritorno << endl;
                cout << "-------------------------------------" << endl;
            }
        }
    }
    return ritorno;
}

int main(){
    int n = 3;
    string*** A = new string**[n];
    for(int i = 0; i < n; i++){
        A[i] = new string*[n];
    }    
    A[0][0] = new string("casa");
    A[0][1] = new string("oiapprppaio");
    A[0][2] = new string("oo");
    A[1][0] = new string("abekeba");
    A[1][1] = new string("abeiokoieba");
    A[1][2] = new string("piano");
    A[2][0] = new string("ossa");
    A[2][1] = new string("ala");
    A[2][2] = new string("ciao");

    cout << "Matrice A: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j]){
                cout << *A[i][j] << " \t";
            }
            else{
                cout << "* \t"; 
            }
        }
        cout << endl;
    }
    cout << endl;

    bool** B = new bool*[n];
    for(int i = 0; i<n; i++){
      B[i] = new bool[n];  
    }
    //Inizializzazione casuale della matrice di boleani
    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            B[i][j] = rand()%2;
        }
    }

    cout << "Matrice B: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << B[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matrice B (Trasposta): " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << B[j][i] << " \t";
        }
        cout << endl;
    }
    cout << endl;

    esame2(A, n, B);
    
}