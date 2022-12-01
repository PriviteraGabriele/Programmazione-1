/* .Scrivere un metodo che prenda in input tre 
parametri formali: una matrice di puntatori a stringhe 
A di dimensioni nxm, uno short k ed una stringa s. Il 
metodo restituisca un array di bool di dimensione n in 
cui il singolo elemento di indice i assume valore true se 
la stringa s e sottostringa di almeno k stringhe della 
riga i-esima della matrice A. */

#include<iostream>
#include<string>
using namespace std;

bool* esercizio10(string*** A, int n, int m, short k, string s){
    bool* B = new bool[n];
    for(int i = 0; i<n; i++){
        B[i] = 0;
    }

    int counter;
    string s1 = "";
    for(int i = 0; i<n; i++){
        counter = 0;
        for(int j = 0; j<m; j++){
            s1 = *A[i][j];
            if(s1.find(s) != string::npos){
                counter++;
            }
        }
        if(counter >= k){
            B[i] = 1;
        }
    }
    return B;
}

void Stampa_Matrice(string*** A, int n, int m){
    //Stampa matrice con controllo se la stringa è nulla
    cout << "Matrice: " << endl << endl;
     for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j]){
                cout << *A[i][j] << "    \t";
            }
            else{
                cout << "*   \t"; 
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
    string s = "r";
    string*** A = new string**[n];
    for(int i = 0; i < n; i++){
        A[i] = new string*[m];
    }    
    A[0][0] = new string("porta");
    A[0][1] = new string("portone");
    A[0][2] = new string("portinaio");
    A[0][3] = new string("por");
    A[1][0] = new string("cipresso");
    A[1][1] = new string("cesso");
    A[1][2] = new string("gesso");
    A[1][3] = new string("ciao");
    A[2][0] = new string("carta");
    A[2][1] = new string("mobile");
    A[2][2] = new string("bue");
    A[2][3] = new string("nastro");
    A[3][0] = new string("piede");
    A[3][1] = new string("naso");
    A[3][2] = new string("bocca");
    A[3][3] = new string("ascella");
    Stampa_Matrice(A, n, m);

    cout << "Array:   ";
    for(int i = 0; i<n; i++){
        cout << esercizio10(A, n, m, k, s)[i] << "   ";
    }
    cout << endl;
}
