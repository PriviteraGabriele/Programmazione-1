/* Scrivere un metodo in linguaggio C++ che prenda in imput una matrice di puntatori a stringhe 
di dimensioni n x m, e tre short k, r ed s (si assuma r < s e k < n). Il metodo restituisca il 
numero di colonne aventi il seguente requisito: la colonna contiene almeno k stringhe palindrome 
che abbiano lunghezza r <= l <= s. NB: una stringa si dice palindroma quando si legge allo stesso 
modo da destra e da sonostra (esempio: "abckcba" oppure "trert"). */

#include<iostream>
using namespace std;

bool Check_Palindroma(string s){
    string p = "";
    for(int i = 0; i<s.length(); i++){
        p = s[i] + p;
    }

    return p == s;
}

int ex2(string*** M, int n, int m, short k, short r, short s){

    int counter_colonne = 0;

    for(int j = 0; j<m; j++){
        int counter = 0;
        for(int i = 0; i<n; i++){
            if(M[i][j]){
                if(Check_Palindroma(*M[i][j]) && (*M[i][j]).length() >= r && (*M[i][j]).length() <= s){
                    counter++;
                }
            }
        }

        if(counter >= k){
            counter_colonne++;
        }
    }

    return counter_colonne;
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
    short r = 3;
    short s = 12;
    short k = 2;
    string*** M = new string**[n];
    for(int i = 0; i < n; i++){
        M[i] = new string*[m];
    } 
    M[0][0] = new string("casa");
    M[0][1] = new string("oiapprppaio");
    M[0][2] = new string("oo");
    M[1][0] = new string("abekeba");
    M[1][1] = new string("abeiokoieba");
    M[1][2] = new string("piano");
    M[2][0] = new string("ossa");
    M[2][1] = new string("ala");
    M[2][2] = new string("ciao");
    Stampa_Matrice(M, n, m);
    cout << "Il numero di colonne che soddisfano la condizione del testo sono: " << ex2(M, n, m, k, r, s) << endl;
}
