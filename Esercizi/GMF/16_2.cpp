/* [Esercizio 16] Scrivere un metodo che prenda in input una matrice S di puntatori 
a stringhe di dimensione n × m ed un array B di short di dimensione m e che restituisca 
uno short che rappresenti l’indice della riga in S con il maggior numero di stringhe 
aventi lunghezza minore o uguale del corrispondente numero nello array B (NB: in pratica 
la lunghezza della stringa di indici (i,j) va confrontata con il numero di indice j in B). */

#include<iostream>
using namespace std;

short ex16(string*** S, int n, int m, short* B){

    short ritorno;
    int max = 0;
    int counter;
    for(int i = 0; i<n; i++){
        counter = 0;
        for(int j = 0; j<m; j++){
            if(S[i][j]){
                if((*S[i][j]).length() <= B[j]){
                    counter++;
                }
            }
        }
        if(max < counter){
            max = counter;
            ritorno = i;
        }
    }

    return ritorno;
}

void Stampa_Matrice(string*** S, int n, int m){
    //Stampa matrice con controllo se la stringa è nulla
    cout << "Matrice: " << endl << endl;
     for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(S[i][j]){
                cout << *S[i][j] << "     \t";
            }
            else{
                cout << "*     \t"; 
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;

    string*** S = new string**[n];
    for(int i = 0; i<n; i++){
        S[i] = new string*[m];
    }

    S[0][0] = new string("porta");
    S[0][1] = new string("portone");
    S[0][2] = new string("portinaio");
    S[0][3] = new string("por");
    S[1][0] = new string("cipresso");
    S[1][1] = new string("cesso");
    S[1][2] = new string("gesso");
    S[1][3] = new string("ciao");
    S[2][0] = new string("carta");
    S[2][1] = new string("mobile");
    S[2][2] = new string("bue");
    S[2][3] = new string("nastro");
    S[3][0] = new string("piede");
    S[3][1] = new string("naso");
    S[3][2] = new string("bocca");
    S[3][3] = new string("ascella");

    Stampa_Matrice(S, n, m);

    //Inizializzazione dinamica dell'array con numeri casuali e stampa
    short* B = new short[m];
    srand(time(0));
    cout << "Array:    ";
    for(int i = 0; i<m; i++){
        B[i] = rand()%10;
        cout << B[i] << "    ";
    }
    cout << endl << endl;

    cout << "L’indice della riga in S con il maggior numero di stringhe aventi lunghezza minore o uguale del corrispondente numero nello array B è : " << ex16(S, n, m, B) << endl;
}