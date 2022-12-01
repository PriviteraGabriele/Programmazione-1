/* 2.Due stringhe si dicono sorelle se hanno lo stesso 
numero di vocali. Scrivere un metodo che prenda in 
input una matrice A di puntatori a stringhe, e 
restituisca un boolean che indichi se esiste una 
colonna di A in cui sono puntate almeno due stringhe 
sorelle. */

#include<iostream>
using namespace std;

bool esercizio2(string***A, int n, int m){
    for(int j = 0; j<m; j++){
        int contatore = 0;
        for(int i = 0; i<n; i++){
            int lunghezza = (*A[i][j]).length();
            cout << "-----------------------------------------------------" << endl;
            cout << "*A[" << i << "][" << j << "] = " << *A[i][j] << endl;
            cout << "lunghezza = " << lunghezza << endl;
            for(int p = i + 1; p<n; p++){
                int lunghezza2 = (*A[p][j]).length();
                cout << "*A[" << p << "][" << j << "] = " << *A[p][j] << endl;
                cout << "lunghezza2 =  " << lunghezza2 << endl;
                if(lunghezza == lunghezza2){
                    contatore++;
                }
                cout << "contatore = " << contatore << endl;
                cout << "-----------------------------------------------------" << endl;
            }        
            if(contatore>=2){
                return true;
            }
        
        }
    }
    return false;
}

void Stampa_Matrice(string*** M, int n, int m){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(M[i][j]){
                cout << *M[i][j] << " \t";
            }
            else{
                cout << "* \t"; 
            }
        }
        cout << endl;
    }
}

int main(){
    int n = 3;
    int m = 3;
    string*** A = new string**[n];
    for(int i = 0; i < n; i++){
        A[i] = new string*[m];
    }    
    A[0][0] = new string("casa");
    A[0][1] = new string("oiapprppaio");
    A[0][2] = new string("ooooo");
    A[1][0] = new string("abekeba");
    A[1][1] = new string("abeiokoieba");
    A[1][2] = new string("piano");
    A[2][0] = new string("ossa");
    A[2][1] = new string("ala");
    A[2][2] = new string("ciaoo");

    Stampa_Matrice(A, n, m);

    if(esercizio2(A, n, m)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}