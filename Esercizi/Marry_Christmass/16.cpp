/* Due stringhe si dicono c-equivalenti se esse 
risultano uguali dopo aver eliminato da ambedue tutte 
le occorrenze del carattere c. Scrivere un metodo che 
prenda in input una matrice A di puntatori a stringhe 
ed un carattere c, e restituisca un boolean che indichi 
se esistono in A due stringhe c-equivalenti. */

#include<iostream>
using namespace std;

void Stampa_Matrice(string*** A, int n, int m){
    //Stampa matrice con controllo se la stringa è nulla
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j]){
                cout << *A[i][j] << "    \t";
            }
            else{
                cout << "*   \t"; 
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool esercizio16(string*** A, int n, int m, char c){
    string temp1 = "";
    //Epurazione stringhe dal carattere del char c
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j]){
                temp1 = *A[i][j];
                //cout << "*A[" << i << "][" << j << "] = " << temp1 << endl;
                for(int p = 0; p<temp1.length(); p++){
                    if(temp1[p] == c){
                        temp1[p] = '\0';
                    }
                }
                *A[i][j] = temp1;
                //cout << "temp1 = " << temp1 << endl;
            }
        }
    }

    cout << "Matrice (Epurata): " << endl << endl;
    Stampa_Matrice(A, n, m);

    //Controllo stringhe c-equivalenti
    string temp2 = "";
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            temp1 = *A[i][j];
            for(int x = 0; x<n; x++){
                for(int y = 0; y<m; y++){
                    temp2 = *A[x][y];
                    if(i != x || j != y){
                        if(temp1 == temp2){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    int n = 4;
    int m = 4;
    char c = 'x';

    string*** A = new string**[n];
    for(int i = 0; i<n; i++){
        A[i] = new string*[m];
    }

    A[0][0] = new string("por");
    A[0][1] = new string("porxtonex");
    A[0][2] = new string("portxinaio");
    A[0][3] = new string("xcasa");
    A[1][0] = new string("cipxresxso");
    A[1][1] = new string("cesxso");
    A[1][2] = new string("gesxso");
    A[1][3] = new string("xciao");
    A[2][0] = new string("carxta");
    A[2][1] = new string("mxobile");
    A[2][2] = new string("casa");
    A[2][3] = new string("nastxro");
    A[3][0] = new string("pixede");
    A[3][1] = new string("naxso");
    A[3][2] = new string("xciao");
    A[3][3] = new string("asxcxelxla");

    cout << "Matrice (Iniziale): " << endl << endl;
    Stampa_Matrice(A, n, m);

    if(esercizio16(A, n, m, c)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    } 
}

