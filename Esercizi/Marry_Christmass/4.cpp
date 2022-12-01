/* Scrivere un metodo che prenda in input una matrice 
di puntatori a stringhe P di dimensioni nm, due short a 
e b, ed una stringa s. Il metodo restituisca il valore 
booleano true se esiste almeno una colonna in P tale 
che la stringa s sia sottostringa di un numero 
compreso tra a e b (inclusi) di stringhe della colonna 
stessa. PS: Si assuma 0 < a b < n */

#include<iostream>
using namespace std;

bool esercizio4(string*** P, int n, int m, short a, short b, string s){
    int counter;
    for(int j = 0; j<m; j++){
        counter = 0;
        for(int i = 0; i<n; i++){
            if((*P[i][j]).find(s) != string::npos){
                counter++;
            }
        }
        if(counter >= a && counter <= b){
            return true;
        }
    }
    return false;
}

void Stampa_Matrice(string*** P, int n, int m){
    //Stampa matrice con controllo se la stringa è nulla
    cout << "Matrice: " << endl << endl;
     for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(P[i][j]){
                cout << *P[i][j] << "    \t";
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
    int n = 5;
    int m = 3;
    short a = 1;
    short b = 3;
    string s = "gioi";

    string*** P = new string**[n];
    for(int i = 0; i<n; i++){
        P[i] = new string*[m];
    }

    P[0][0] = new string("casa");
    P[0][1] = new string("babba");
    P[0][2] = new string("fallo");
    P[1][0] = new string("portone");
    P[1][1] = new string("orto");
    P[1][2] = new string("fischietto");
    P[2][0] = new string("gioia");
    P[2][1] = new string("batteria");
    P[2][2] = new string("giostre");
    P[3][0] = new string("gioiello");
    P[3][1] = new string("cosa");
    P[3][2] = new string("clave");
    P[4][0] = new string("porta");
    P[4][1] = new string("portone");
    P[4][2] = new string("mostro");
    Stampa_Matrice(P, n, m);

    if(esercizio4(P, n, m, a, b, s)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}