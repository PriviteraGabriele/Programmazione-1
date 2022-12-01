/* [Esercizio 7] Scrivere un metodo che prenda in input un parametro formale matrice S di puntatori a stringhe di dimensione
n × m, uno short w ed uno short k, e restituisca il valore booleano true se in S sono presenti almeno una riga ed almeno una
colonna che presentano ciascuna almeno w stringhe di lunghezza minore di k. */

#include<iostream>
using namespace std;

bool esercizio7(string*** S, int n, int m, short w, short k){
    int counter_stringhe;
    int counter_righe = 0;
    int counter_colonne = 0;

    //Controllo stringhe per riga
    //cout << "RIGHE:" << endl << endl;
    for(int i = 0; i<n; i++){
        counter_stringhe = 0;
        for(int j = 0; j<m; j++){
            if(S[i][j]){
                //cout << "--------------------------------------------------" << endl;
                //cout << "S[" << i << "][" << j << "] = " << *S[i][j] << endl;
                //cout << "lunghezza = " << S[i][j]->length() << endl;
                if(S[i][j]->length() < k){
                    counter_stringhe++;
                    //cout << "*counter_stringhe = " << counter_stringhe << endl;
                }
                //cout << "--------------------------------------------------" << endl;
            }
        }
        if(counter_stringhe >= w){
            counter_righe++;
            //cout << "***counter_righe = " << counter_righe << endl;
        }
    }

    //Controllo stringhe per colonna
    //cout << endl << "COLONNE:" << endl << endl;
    for(int j = 0; j<m; j++){
        counter_stringhe = 0;
        for(int i = 0; i<n; i++){
            if(S[i][j]){
                //cout << "--------------------------------------------------" << endl;
                //cout << "S[" << i << "][" << j << "] = " << *S[i][j] << endl;
                //cout << "lunghezza = " << S[i][j]->length() << endl;
                if(S[i][j]->length() < k){
                    counter_stringhe++;
                    //cout << "*counter_stringhe = " << counter_stringhe << endl;
                }
                //cout << "--------------------------------------------------" << endl;
            }
        }
        if(counter_stringhe >= w){
            counter_colonne++;
            //cout << "***counter_colonne = " << counter_colonne << endl;
        }
    }

    //Controllo per ritorno
    if(counter_righe >= 1 && counter_colonne >= 1){
        return true;
    }
    return false;
}

void Stampa_Matrice(string*** S, int n, int m){
    cout << "Matrice:" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(S[i][j]){
                cout << *S[i][j] << "     \t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;
    short w = 2;
    short k = 5;
    
    string*** S = new string**[n];
    for(int i = 0; i<n; i++){
        S[i] = new string*[m];
    }

    S[0][0] = new string("casa"); 
    S[0][1] = new string("ape");
    S[0][2] = new string("cipolla");
    S[0][3] = new string("anello");
    S[1][0] = new string("elden");
    S[1][1] = new string("capitale");
    S[1][2] = new string("fogne");
    S[1][3] = new string("nani");
    S[2][0] = new string("madonna");
    S[2][1] = new string("cosa");
    S[2][2] = new string("strega");
    S[2][3] = new string("inizio");
    S[3][0] = new string("vestito");
    S[3][1] = new string("chiosco");
    S[3][2] = new string("albero");
    S[3][3] = new string("madre");

    Stampa_Matrice(S, n, m);

    if(esercizio7(S, n, m, w, k)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}