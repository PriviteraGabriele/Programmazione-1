/* Scrivere un metodo che prenda in input una 
matrice quadrata Q di stringhe e restituisca il valore 
booleano true se la stringa piu lunga della diagonale 
principale di Q contiene un numero di vocali minore 
della stringa piu corta della diagonale stessa. NB: Si 
assuma che le stringhe della diagonale principale 
abbiano lunghezze differenti e sempre maggiori di 
zero */

#include<iostream>
#include<string>
using namespace std;

bool esercizio_22(string **Q, int n){
    bool risposta = false;
    int s_max = 0;
    int s_min = 100;
    string s1;                  //più lunga 
    string s2;                  //più corta
    
    //Controllo stringa più lunga e stringa più corta della diagonale principale
    for(int i = 0; i<n; i++){
        if(s_max<Q[i][i].length()){
            s_max = Q[i][i].length();
            s1 = Q[i][i];
        }

        if(s_min>Q[i][i].length()){
            s_min = Q[i][i].length();
            s2 = Q[i][i];
        }
    }

    //Controllo numero di vocali
    int s1_vocali = 0;
    int s2_vocali = 0;

    for(int i = 0; i<s_max; i++){
        if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u' || s1[i] == 'A' || s1[i] == 'E' || s1[i] == 'I' || s1[i] == 'O' || s1[i] == 'U'){
            s1_vocali++;
        }
    }

    for(int i = 0; i<s_min; i++){
        if(s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u' || s2[i] == 'A' || s2[i] == 'E' || s2[i] == 'I' || s2[i] == 'O' || s2[i] == 'U'){
            s2_vocali++;
        }
    }

    if(s1_vocali < s2_vocali){
        risposta = true;
        return risposta;
    }

    return risposta;    
}

int main(){ 
    int n;
    cout << "Inserire dimensione matrice: "; 
    cin >> n;
    cout << endl;
    string** Q = new string*[n];
    for(int i = 0; i<n; i++){
        Q[i] = new string[n]; 
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << "Inserisci Q[" << i << "][" << j << "] " << endl; 
            cin >> Q[i][j]; 
        }
    }
    
    cout << endl;
    if(esercizio_22(Q,n) == 1){
        cout << "VERO!" << endl;
    }
    else{
        cout << "FALSO!" << endl;
    }
}
