/* Scrivere un metodo che prenda in input tre parametri formali: una matrice di puntatori a stringhe A di
dimensioni n × m, uno short k ed una stringa s. Il metodo restituisca un array di bool di dimensione n in
cui il singolo elemento di indice i assume valore true se la stringa s `e sottostringa di almeno k stringhe della
riga i-esima della matrice A. */

#include<iostream>
using namespace std;

bool* ex2(string*** A, int n, int m, short k, string s){
    bool* B = new bool[n];
    for(int i = 0; i<n; i++){
        B[i] = false;
    }

    int counter;
    for(int i = 0; i<n; i++){
        counter = 0;
        for(int j = 0; j<m; j++){
            if(A[i][j]){
                if(A[i][j]->find(s) != string::npos){
                    counter++;
                    if(counter >= k){
                        B[i] = true;
                    }
                }
            }
        }
    }

    cout << "Array:\t";
    for(int i = 0; i<n; i++){
        cout << B[i] << "     \t";
    }
    cout << endl;

    return B;
}

void Stampa_Matrice(string*** A, int n, int m){
    cout << "Matrice:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j]){
                cout << *A[i][j] << " \t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;
    short k = 2;
    string s = "AA";

    string*** A = new string**[n];
    for(int i = 0; i<n; i++){
        A[i] = new string*[m];
    }

    A[0][0] = new string("porAAta");
    A[0][1] = new string("portone");
    A[0][2] = new string("porAAtinaio");
    A[0][3] = new string("por");
    A[1][0] = new string("cipresso");
    A[1][1] = new string("cesAAso");
    A[1][2] = new string("geAAsso");
    A[1][3] = new string("ciao");
    A[2][0] = new string("carta");
    A[2][1] = new string("mobile");
    A[2][2] = new string("bue");
    A[2][3] = new string("nastro");
    A[3][0] = new string("piede");
    A[3][1] = new string("naAAso");
    A[3][2] = new string("boAAcca");
    A[3][3] = new string("asceAAlla");

    Stampa_Matrice(A, n, m);

    ex2(A, n, m, k, s);    
}