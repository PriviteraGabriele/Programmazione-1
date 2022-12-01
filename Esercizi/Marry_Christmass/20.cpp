/* 20.Scrivere un metodo che prenda in input una 
matrice di puntatori a stringhe S di dimensione nxm, 
una stringa s1 ed uno short k, e restituisca la 
percentuale di stringhe, tra quelle presenti nelle prime 
k colonne di S, che siano piu lunghe di s1. NB: si 
assuma k<=m. */

#include<iostream>
using namespace std;

int esercizio20(string ***S, int n, int m, string s1, short k){
    int l_s1 = s1.length();         //Lunghezza stringa s1
    int counter = 0;            //contatore stringhe più lunghe
    int percentuale;
    for(int j = 0; j<k; j++){
        int l = 0;                  //Lunghezza stringa della matrice
        string s = " ";
        for(int i = 0; i<n; i++){
            s = *S[i][j];
            cout << endl << "s: " << s << endl;
            l = s.length();
            cout << "l: " << l << endl;
            cout << "l_s1: " << l_s1 << endl;
            if(l>l_s1){
                counter++;

            }
            cout << "counter: " << counter << endl;
        }
        int numero_stringhe = k*n;
        percentuale = (counter*100)/numero_stringhe;
    }
    return percentuale;
}

void Stampa_Matrice(string*** S, int n, int m){
    //Stampa matrice con controllo se la stringa è nulla
    cout << "Matrice: " << endl << endl;
     for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(S[i][j]){
                cout << *S[i][j] << "   ";
            }
            else{
                cout << "*  "; 
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 3;
    int m = 3;
    short k = 2;
    string s1 = "casa";
    string*** S = new string**[n];
    for(int i = 0; i < n; i++){
        S[i] = new string*[m];
    }    
    S[0][0] = new string("casa");
    S[0][1] = new string("oiapprppaio");
    S[0][2] = new string("oo");
    S[1][0] = new string("abekeba");
    S[1][1] = new string("abeiokoieba");
    S[1][2] = new string("piano");
    S[2][0] = new string("ossa");
    S[2][1] = new string("ala");
    S[2][2] = new string("ciao");
    Stampa_Matrice(S, n, m);
    cout << "La percentuale di stringhe più lunghe di s1, rispetto al numero di stringhe totali della colonna, è: " << esercizio20(S, n, m, s1, k)  << "%"<< endl;
}
