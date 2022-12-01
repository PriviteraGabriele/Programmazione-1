/* .Scrivere un metodo che prenda come parametri 
formali una matrice A di stringhe ed un intero k, e 
restituisca in output una copia di A in cui tutte le 
stringhe della colonna k-esima siano state epurate 
dalle lettere non italiane. */ 

#include<iostream>
using namespace std;

string** esercizio14(string** A, int n, int m, int k){
    string temp = "";
    string** B = new string*[n];
    for(int i = 0; i<n; i++){
        B[i] = new string[m];
    }

    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            temp = A[i][j];
            //cout << "temp = " << temp << endl;
            for(int p = 0; p<temp.length(); p++){
                if(j == k-1){
                    //cout << "[p]temp = " << temp[p] << endl;
                    if(temp[p] == 'j'|| temp[p] == 'k'|| temp[p] == 'w'|| temp[p] == 'x'|| temp[p] == 'y'|| temp[p] == 'J'|| temp[p] == 'K'|| temp[p] == 'W'|| temp[p] == 'X'|| temp[p] == 'Y'){
                        temp[p] = '*';
                    }
                }
            }
            //cout << "*temp = " << temp << endl << endl;
            B[i][j] = temp;
        }
    }
    
    cout<< "Matrice Epurata: " << endl << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << B[i][j] << "    \t"; 
        }
        cout << endl;
    }
    cout << endl;

    return B;
}

void Stampa_Matrice(string** A, int n, int m){
    cout<< "Matrice: " << endl << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << A[i][j] << "    \t"; 
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 3;
    int m = 4;
    int k = 3;

    string** A = new string*[n];
    for(int i = 0; i<n; i++){
        A[i] = new string[m];
    }
    A[0][0] = "casale";
    A[0][1] = "portone";
    A[0][2] = "giokco";
    A[0][3] = "orto";
    A[1][0] = "mare";
    A[1][1] = "cappello";
    A[1][2] = "barKcya";
    A[1][3] = "astro";
    A[2][0] = "male";
    A[2][1] = "noialtri";
    A[2][2] = "mWostrxoY";
    A[2][3] = "bastone";
    
    Stampa_Matrice(A, n, m);

    esercizio14(A, n, m, k);
}