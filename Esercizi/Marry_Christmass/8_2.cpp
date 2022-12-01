/* Scrivere un metodo che prenda in input una matrice 
quadrata di puntatori a stringhe Q ed una stringa s. Il 
metodo restituisca il valore booleano true se e solo se 
il numero di stringhe che contengono s, presenti nella 
diagonale principale di Q, e maggiore del numero di 
stringhe che contengono s presenti nella diagonale 
secondaria di Q. */

#include<iostream>
using namespace std;

bool ex8(string*** Q, int n, string s){
    int counter1 = 0;           //contatore ricorrenze nella diagonale principale
    int counter2 = 0;           //contatore ricorrenze nella diagonale secondaria
    for(int i = 0; i<n; i++){
        //controllo se la stringa s sottostringa di una o più stringhe della diagonale principale
        if(Q[i][i]){
            if((*Q[i][i]).find(s) != string::npos){
                counter1++;
            }
        }
                
        //controllo se la stringa s sottostringa di una o più stringhe della diagonale secondaria
        if(Q[i][n-i-1]){
            if((*Q[i][n-i-1]).find(s) != string::npos){
                counter2++;
            }
        }
    }
    if(counter1 > counter2){
        return true;
    }
    return false;
}

void Stampa_Matrice(string*** Q, int n){
    //Stampa matrice con controllo se la stringa è nulla
    cout << "Matrice: " << endl << endl;
     for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(Q[i][j]){
                cout << *Q[i][j] << "    \t";
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
    string s = "ia";

    string*** Q = new string**[n];
    for(int i = 0; i < n; i++){
        Q[i] = new string*[n];
    }    
    Q[0][0] = new string("casa");
    Q[0][1] = new string("oiapprppaio");
    Q[0][2] = new string("oo");
    Q[0][3] = new string("abekeba");
    Q[1][0] = new string("abeiokoieba");
    Q[1][1] = new string("piano");
    Q[1][2] = new string("ossa");
    Q[1][3] = new string("ala");
    Q[2][0] = new string("ciao");
    Q[2][1] = new string("oo");
    Q[2][2] = new string("abekeba");
    Q[2][3] = new string("abeiokoieba");
    Q[3][0] = new string("piano");
    Q[3][1] = new string("ossa");
    Q[3][2] = new string("ala");
    Q[3][3] = new string("ciao");
    Stampa_Matrice(Q, n);

    if(ex8(Q, n, s)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}