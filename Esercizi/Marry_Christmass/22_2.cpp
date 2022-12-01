/* Scrivere un metodo che prenda in input una 
matrice quadrata Q di stringhe e restituisca il valore 
booleano true se la stringa piu lunga della diagonale 
principale di Q contiene un numero di vocali minore 
della stringa piu corta della diagonale stessa. NB: Si 
assuma che le stringhe della diagonale principale 
abbiano lunghezze differenti e sempre maggiori di 
zero */

#include<iostream>
using namespace std;

bool Check_Vocali(char a){
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U'){
        return true;
    }
    return false;
}

bool ex22(string** Q, int n){
    int max = 0; 
    string save_max = "";           //Salvataggio stringa più lunga
    int min = 1000;
    string save_min = "";           //Salvataggio stringa più corta

    //Controlo stringhe
    for(int i = 0; i<n; i++){
        //Controllo stringa più lunga
        if(max < Q[i][i].length()){
            max = Q[i][i].length();
            save_max = Q[i][i];
        }

        //Controllo stringa più corta
        if(min > Q[i][i].length()){
            min = Q[i][i].length();
            save_min = Q[i][i];
        } 
    }

    //Controllo numero vocali
    int counter_max = 0;
    for(int p = 0; p<save_max.length(); p++){
        if(Check_Vocali(save_max[p])){
            counter_max++;
        }
    }

    int counter_min = 0;
    for(int p = 0; p<save_min.length(); p++){
        if(Check_Vocali(save_min[p])){
            counter_min++;
        }
    }

    if(counter_max < counter_min){
        return true;
    }
    return false;
}

void Stampa_Matrice(string** Q, int n){
    cout << "Matrice:" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << Q[i][j] << "   \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){ 
    int n = 4;

    string** Q = new string*[n];
    for(int i = 0; i<n; i++){
        Q[i] = new string[n]; 
    }
    
    Q[0][0] = "cavallino";
    Q[0][1] = "cavallo";
    Q[0][2] = "siepe";
    Q[0][3] = "carne";
    Q[1][0] = "orsopolar";
    Q[1][1] = "spaghett";
    Q[1][2] = "fieno";
    Q[1][3] = "borsa";
    Q[2][0] = "chiamate";
    Q[2][1] = "valorant";
    Q[2][2] = "pomxdxrxnx";
    Q[2][3] = "orso";
    Q[3][0] = "orologio";
    Q[3][1] = "appello";
    Q[3][2] = "cassetto";
    Q[3][3] = "ape";
    
    Stampa_Matrice(Q, n);

    cout << endl;
    if(ex22(Q,n)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}
