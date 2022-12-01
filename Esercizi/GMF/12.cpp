/* [Esercizio 12] Scrivere un metodo che preveda un parametro formale matrice quadrata di stringhe di dimensioni n × n,
uno short k ed una stringa s, e restituisca un array di n puntatori a stringhe in cui il generico elemento di indice i contiene la
i-esima stringa della diagonale secondaria se questa ha lunghezza maggiore o uguale a k e inizia con la stringa s, altrimenti la
corrispondente stringa della diagonale principale. */

#include<iostream>
using namespace std;

string* esercizio12(string** A, int n, short k, string s){
    string** R = new string*[n];

    R[0] = new string("");
    R[1] = new string("");
    R[2] = new string("");
    R[3] = new string("");

    int counter;
    for(int i = 0; i<n; i++){
        counter = 0;
        //controllo che l'i-esima stringa inizia con la stringa s
        for(int p = 0; p<s.length(); p++){
            cout << "A[" << i << "][" << n-1-i << "][" << p << "] = " << A[i][n-1-i][p] << " e " << "s[" << p << "] = " << s[p] << endl;
            if(A[i][n-1-i][p] == s[p]){
                counter++;
            }
            cout << "counter = " << counter << endl;
        }
        cout << "A[i][n-1-i].length() = " << A[i][n-1-i].length() << " e " << "k = " << k << endl;
        cout << "counter = " << counter << " e " << "s.length() = " << s.length() << endl;
        if(A[i][n-1-i].length() >= k && counter == s.length()){
            *R[i] = A[i][n-1-i];
        }
        else{
            *R[i] = A[i][i];
        }
        cout << "*R[i] = " << *R[i] << endl;
    }

    //Stampa ritorno
    cout << endl << "Array:     ";
    for(int i = 0; i<n; i++){
        cout << *R[i] << "     ";
    }
    cout << endl;

    return *R;
}

void Stampa_Matrice(string** A, int n){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << A[i][j] << "    \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    short k = 5;
    string s = "chi";

    string** A = new string*[n];
    for(int i = 0; i<n; i++){
        A[i] = new string[n];
    }

    A[0][0] = "camion";
    A[0][1] = "barella";
    A[0][2] = "bonucci";
    A[0][3] = "chiellini";
    A[1][0] = "adani";
    A[1][1] = "palla";
    A[1][2] = "orchestra";
    A[1][3] = "molletta";
    A[2][0] = "gioco";
    A[2][1] = "rajang";
    A[2][2] = "teostra";
    A[2][3] = "lunastra";
    A[3][0] = "chimera";
    A[3][1] = "hunter";
    A[3][2] = "picnic";
    A[3][3] = "rick";

    Stampa_Matrice(A, n);

    esercizio12(A, n, k, s);
}