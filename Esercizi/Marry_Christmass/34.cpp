/* Scrivere un metodo che prenda in input una 
matrice di puntatori a stringhe S di dimensioni n×m, 
una stringa x ed un array di double W di dimensione 
m; il metodo restituisca un array di bool R di 
dimensione m tale che l’i-esimo elemento di R sarà 
true se e solo se il rapporto tra il numero di stringhe 
della i-esima colonna di S delle quali x è sottostringa 
ed il numero n è minore o uguale dello i-esimo 
elemento di W. NB: Si presti attenzione alle stringhe 
mancanti! */

#include<iostream>
using namespace std;

bool* esercizio34(string*** S, int n, int m, string x, double* W){
    bool* R = new bool[m];

    for(int i = 0; i<m; i++){
        R[i] = false;
    }

    int counter_sottostringhe;
    //(Per seguire i dati della consegna) i sono le colonne e j sono le righe
    for(int i = 0; i<m; i++){
        counter_sottostringhe = 0;
        for(int j = 0; j<n; j++){
            if(S[j][i]){
                //cout << "*S[" << j << "][" << i << "] = " << *S[j][i] << endl;
                if((*S[j][i]).find(x) != string::npos){
                    counter_sottostringhe++;
                }
            }
        }
        //cout << "n. sottostringhe = " << counter_sottostringhe << endl;
        //cout << "rapporto = " << (double)counter_sottostringhe/n << " <= " << W[i] << endl;
        if((double)counter_sottostringhe/n <= W[i]){
            R[i] = true;
        }
    }
    return R;
}

void Stampa_Matrice(string*** S, int n, int m){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(S[i][j]){
                cout << *S[i][j] << "    \t";
            }
            else{
                cout << "*    \t" << endl;
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Stampa_Array(double* W, int m){
    cout << "Array W:   ";
    for(int i = 0; i<m; i++){
        cout << W[i] << "    ";
    }
    cout << endl << endl;
}

int main(){
    int n = 4; 
    int m = 4; 
    string x = "a";

    string*** S = new string**[n];
    for(int i = 0; i<n; i++){
        S[i] = new string*[m];
    }

    S[0][0] = new string("casa");
    S[0][1] = new string("porta");
    S[0][2] = new string("canale");
    S[0][3] = new string("portatile");
    S[1][0] = new string("nonna");
    S[1][1] = new string("cacciagione");
    S[1][2] = new string("corsale");
    S[1][3] = new string("cacca");
    S[2][0] = new string("padrino");
    S[2][1] = new string("cortile");
    S[2][2] = new string("montagna");
    S[2][3] = new string("ginepro");
    S[3][0] = new string("arancia");
    S[3][1] = new string("partire");
    S[3][2] = new string("arto");
    S[3][3] = new string("casale");

    Stampa_Matrice(S, n, m);

    double* W = new double[m];

    srand(time(0));
    W[0] = rand()/(double)RAND_MAX*1.1;
    W[1] = rand()/(double)RAND_MAX*1.1;
    W[2] = rand()/(double)RAND_MAX*1.1;
    W[3] = rand()/(double)RAND_MAX*1.1;

    Stampa_Array(W, m);

    cout << "Array R:    ";
    for(int i = 0; i<n; i++){
        cout << esercizio34(S, n, m, x, W)[i] << "    ";
    }
    cout << endl;
}