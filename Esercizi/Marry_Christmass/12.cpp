/* .Scrivere un metodo che prenda come parametri 
formali una matrice A di stringhe ed uno short w, e 
restituisca in output un bool che indichi se esiste una 
riga di A in cui siano presenti almeno due stringhe 
consecutive in cui i primi w caratteri della prima 
stringa siano uguali agli ultimi w caratteri della 
seconda stringa (nello stesso ordine). */

#include<iostream>
using namespace std;

bool esercizio12(string** A, int n, int m, short w){
    string temp1;
    string temp2; 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m-1; j++){
            temp1 = "";
            temp2 = "";
            cout << "A[" << i << "][" << j << "] = " << A[i][j] << endl;
            cout << "A[" << i << "][" << j+1 << "] = " << A[i][j+1] << endl;
            for(int p = 0; p<w; p++){
                temp1 += A[i][j][p];
                temp2 += A[i][j+1][(A[i][j+1].length() - w + p)];
            }
            cout << "temp1 = " << temp1 << endl;
            cout << "temp2 = " << temp2 << endl;
            if(temp1 == temp2){
                return true;
            }
        }
    }
    return false;
}

void Stampa_Matrice(string** A, int n, int m){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << A[i][j] << " \t";
        }
        cout << endl;
    }
}

int main(){
    int n = 4;
    int m = 4;
    short w = 3;
    string** A = new string*[n];
    for(int i = 0; i < n; i++){
        A[i] = new string[m];
    }    
    A[0][0] = "alessio";
    A[0][1] = "malle";
    A[0][2] = "oo";
    A[0][3] = "abekeba";
    A[1][0] = "abeiokoieba";
    A[1][1] = "piano";
    A[1][2] = "ossapia";
    A[1][3] = "ala";
    A[2][0] = "ciao";
    A[2][1] = "casa";
    A[2][2] = "oiapprppaio";
    A[2][3] = "oo";
    A[3][0] = "abekeba";
    A[3][1] = "abeiokoieba";
    A[3][2] = "piano";
    A[3][3] = "ossa";

    Stampa_Matrice(A, n, m);

    if(esercizio12(A, n, m, w)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    } 
}