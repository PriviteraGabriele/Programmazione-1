/* Scrivere un metodo che prenda come parametro 
formale un cubo (array tridimensionale) C di stringhe, 
e restituisca in output una stringa contenente tutte le 
desinenze di due caratteri delle stringhe sulla faccia 
superiore del cubo C. */

#include<iostream>
using namespace std;

/*string esercizio6(string*** M, int n, int m, int z){
    string x = "";
    //scorro profondità
    for(int h = 0; h<z; h++){
        //colonna
        for(int j = 0; j<m; j++){
            cout << "M[" << h << "][" << 0 << "][" << j << "] = " << M[h][0][j] << endl;
            cout << "length() = " << M[h][0][j].length() << endl;
            //scorro stringa dall'ultimo carattere
            for(int p = (M[h][0][j].length()-3); p<M[h][0][j].length(); p++){
                x += M[h][0][j][p];
                //cout << "x = " << x << endl; 
            }
        }
    }
    return x;
}*/

int main(){
    int n = 3;
    int m = 3;
    int z = 3;

    string M[3][3][3] = {
    {
    {"amare", "odiare", "dormire"} ,
    {"no buono", "no buono", "no buono"},
    {"no buono", "no buono", "no buono"},
    } ,
    { 
    {"raccogliere", "vedere", "ammazzare"} ,
    {"no buono", "no buono", "no buono"},
    {"no buono", "no buono", "no buono"},
    },
    {
    {"finire", "maledire", "sbagliare"},
    {"no buono", "no buono", "no buono"},
    {"no buono", "no buono", "no buono"},
    }, 
    };

    //Stampa Matrice
    for(int h = 0; h<z; h++){
        cout << "Matrice [" << h << "]: " << endl << endl;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout << M[h][i][j] << "      ";
            }
            cout << endl;
        }
    }

    string x = "";
    //scorro profondità
    for(int h = 0; h<z; h++){
        //colonna
        for(int j = 0; j<m; j++){
            cout << "M[" << h << "][" << 0 << "][" << j << "] = " << M[h][0][j] << endl;
            cout << "length() = " << M[h][0][j].length() << endl;
            //scorro stringa dall'ultimo carattere
            for(int p = (M[h][0][j].length()-3); p<M[h][0][j].length(); p++){
                x += M[h][0][j][p];
                //cout << "x = " << x << endl; 
            }
        }
    }
    cout << "x = " << x << endl;
}