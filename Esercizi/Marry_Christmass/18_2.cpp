/* Scrivere un metodo che prenda in input una 
matrice di puntatori a stringhe M e due numeri short 
senza segno, k ed s, e restituisca il numero di colonne 
contenenti almeno k stringhe con un numero di lettere 
vocali minore di s. */

#include<iostream>
using namespace std;

int ex18(string*** M, int n, int m, unsigned short k, unsigned short s){

    int numero_colonne = 0;
    int counter_stringhe;
    for(int j = 0; j<m; j++){
        counter_stringhe = 0;
        for(int i = 0; i<n; i++){
            if(M[i][j]){
                string w = *M[i][j];
                int counter_vocali;
                for(int p = 0; p<M[i][j]->length(); p++){
                    if(w[p] == 'a' || w[p] == 'e' || w[p] == 'i' || w[p] == 'o' || w[p] == 'u' || w[p] == 'A' || w[p] == 'E' || w[p] == 'I' || w[p] == 'O' || w[p] == 'U'){
                        counter_vocali++;
                    }
                }
                if(counter_vocali < s){
                    counter_stringhe++;
                }
            }
        }
        if(counter_stringhe >= k){
            numero_colonne++;
        }
    }

    return numero_colonne;
}

void Stampa_Matrice(string*** M, int n, int m){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(M[i][j]){
                cout << *M[i][j] << " \t";
            }
            else{
                cout << "* \t"; 
            }
        }
        cout << endl;
    }
}

int main(){
    int n = 3;
    int m = 3;
    unsigned short k = 2;
    unsigned short s = 6;
    string*** M = new string**[n];
    for(int i = 0; i < n; i++){
        M[i] = new string*[m];
    }    
    M[0][0] = new string("casa");
    M[0][1] = new string("aereo");
    M[0][2] = new string("bghtl");
    M[1][0] = new string("be");
    M[1][1] = new string("abeiokoieba");
    M[1][2] = new string("piano");
    M[2][0] = new string("ossa");
    M[2][1] = new string("ala");
    M[2][2] = new string("ciaoo");

    Stampa_Matrice(M, n, m);

    cout << endl << "Il numero di colonne che soddisfano la condizione è: " << ex18(M, n, m, k, s) << endl;
}