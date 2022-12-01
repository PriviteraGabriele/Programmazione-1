/* Scrivere un metodo che prenda in input una matrice A di strighe di dimensioni n x m 
ed una matrice B di puntatori a stringhe di dimensione m x l. Il metodo restituisca un 
vettore di booleani C di dimensione l in cui c[j] = true se e solo se è possibile trovare 
almeno una stringa, nella colonna j-iesima di B (sia b[k][j]), la quale sia sottostringa 
della corrispondente stringa presente nella riga j - iesima di A (sia a[j][k]). Si assuma 
n >= l. NB: si presti attenzione alle stringhe mancanti in B. */

#include<iostream>
using namespace std;

bool* e2(string** A, int n, int m, string*** B, int l){
    bool* C = new bool[l];
    for(int i = 0; i<n; i++){
        C[i] = false;
    }

    for(int j = 0; j<l; j++){
        for(int i = 0; i<m; i++){
            if(B[j][i]){
                if(A[i][j].find(*B[j][i]) != string::npos){
                    C[j] = true;
                }
            }
        }
    }

    //////////////////////////////////
    cout << "Array (Ritorno):     ";
    for(int i = 0; i<l; i++){
        cout << C[i] << "      ";
    }
    cout << endl << endl;
    //////////////////////////////////

    return C;
}

int main(){
    int n = 4;
    int m = 4;
    int l = 4;

    string** A = new string*[n];
    for(int i = 0; i<n; i++){
        A[i] = new string[m];
    }

    A[0][0] = "cipolla";
    A[0][1] = "continente";
    A[0][2] = "arpa";
    A[0][3] = "ginepro";
    A[1][0] = "goldrick";
    A[1][1] = "sabaku";
    A[1][2] = "canale";
    A[1][3] = "twich";
    A[2][0] = "pasto";
    A[2][1] = "cannella";
    A[2][2] = "torta";
    A[2][3] = "esercizio";
    A[3][0] = "promosso";
    A[3][1] = "ammesso";
    A[3][2] = "geometrica";
    A[3][3] = "farinella";

    //Stampa Matrice
    cout << "Matrice (A):" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << A[i][j] << "     \t";
        }
        cout << endl;
    }
    cout << endl;

    string*** B = new string**[m];
    for(int i = 0; i<m; i++){
        B[i] = new string*[l];
    }

    B[0][0] = new string("polla"); //
    B[0][1] = new string("casa");
    B[0][2] = new string("orchestra");
    B[0][3] = new string("pane");
    B[1][0] = new string("padella");
    B[1][1] = new string("baku");   //
    B[1][2] = new string("monello");
    B[1][3] = new string("GMF");
    B[2][0] = new string("cane");
    B[2][1] = new string("puglia");
    B[2][2] = new string("orta");   //
    B[2][3] = new string("sicilia");
    B[3][0] = new string("sardegna");
    B[3][1] = new string("molise");
    B[3][2] = new string("veneto");
    B[3][3] = new string("nelrla");  //

    //Stampa Matrice
    cout << "Matrice (B):" << endl << endl;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<l; j++){
            if(B[i][j]){
                cout << *B[i][j] << "     \t";
            }
        }
        cout << endl;
    }
    cout << endl;

    e2(A, n, m, B, l);
}