/* Scrivere un metodo che prenda in input una matrice 
quadrata di puntatori a stringhe Q ed una stringa s. Il 
metodo restituisca il valore booleano true se e solo se 
il numero di stringhe che contengono s, presenti nella 
diagonale principale di Q, e maggiore del numero di 
stringhe che contengono s presenti nella diagonale 
secondaria di Q. */

#include<iostream>
#include<string>
using namespace std;

bool esercizio8(string*** Q, int n, string s){
    int counter1 = 0;       //Diagonale principale
    int counter2 = 0;       //Diagonale secondaria
    string s1 = "";
    string s2 = "";
    for(int i = 0; i<n; i++){
        cout << "---------------------------" << endl;
        //Diagonale principale
        s1 = *Q[i][i];
        cout << "s1 = " << s1 << endl;
        if(s1.find(s) != string::npos){
            counter1++;
        }
        cout << "counter1 = " << counter1 << endl;
        //Diagonale secondaria
        s2 = *Q[i][n - 1 - i];
        cout << "s2 = " << s2 << endl;
        if(s2.find(s) != string::npos){
            counter2++;
        }
        cout << "counter2 = " << counter2 << endl;
        cout << "---------------------------" << endl;
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

    if(esercizio8(Q, n, s)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}