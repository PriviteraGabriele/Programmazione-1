/* [Esercizio 14] Scrivere un metodo che preveda un parametro formale array 
monodimensionale S di n puntatori a stringhe, ed inoltre una matrice C di 
caratteri distinti ed uno short k, e restituisca un array di n puntatori a 
stringhe in cui il generico elemento di indice i contiene un puntatore alla 
i-esima stringa in S solo se questa contiene almeno k caratteri in C, altrimenti nullptr. */

#include<iostream>
using namespace std;

string* esercizio14(string** S, int n, char** C, short k){
    string** R = new string*[n];

    //Ho messo gli asterischi, invece che "", per visualizzare meglio il risultato
    R[0] = new string("***");
    R[1] = new string("***");
    R[2] = new string("***");
    R[3] = new string("***");

    int counter;
    string x = "";
    for(int q = 0; q<n; q++){
        counter = 0;
        if(S[q]){
            x = *S[q];
            cout << "*S[" << q << "] = " << *S[q] << endl;
            cout << "x = " << x << endl;
            cout << "x.length() = " << x.length() << endl;
            for(int p = 0; p<x.length(); p++){
                cout << "-------------------------------------------------------------" << endl;
                cout << "x[" << p << "] = " << x[p] << endl;
                for(int i = 0; i<n; i++){
                    for(int j = 0; j<n; j++){
                        cout << "C[" << i << "][" << j << "] = " << C[i][j] << endl;
                        if(x[p] == C[i][j]){
                            counter++;
                            cout << "***counter = " << counter << endl;
                            if(counter >= k){
                                *R[q] = x;
                                cout << "*R[" << q << "] = " << *R[q] << endl;
                            }
                        }
                    }
                }
                cout << "-------------------------------------------------------------" << endl;
            }
        }
    }

    //Stampa ritorno
    cout << endl << "Array:     ";
    for(int i = 0; i<n; i++){
        cout << *R[i] << "     ";
    }
    cout << endl;

    return *R;
}

void Stampa_Array(string** S, int n){
    cout << "Array:    ";
    for(int i = 0; i<n; i++){
        cout << *S[i] << "     ";
    }
    cout << endl << endl;
}

void Stampa_Matrice(char** S, int n){
    cout << "Matrice:" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << S[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    short k = 2;

    string** S = new string*[n];

    S[0] = new string("autobus");
    S[1] = new string("hotel");
    S[2] = new string("monitor");
    S[3] = new string("sedia");

    Stampa_Array(S, n);

    char** C = new char*[n];
    for(int i = 0; i<n; i++){
        C[i] = new char[n];
    }

    C[0][0] = 'a';
    C[0][1] = 'B';
    C[0][2] = 'C';
    C[0][3] = 'D';
    C[1][0] = 'E';
    C[1][1] = 'f';
    C[1][2] = 'G';
    C[1][3] = 'h';
    C[2][0] = 'i';
    C[2][1] = 'L';
    C[2][2] = 'm';
    C[2][3] = 'N';
    C[3][0] = 'O';
    C[3][1] = 'p';
    C[3][2] = 'Q';
    C[3][3] = 'r';

    Stampa_Matrice(C, n);

    esercizio14(S, n, C, k);
}