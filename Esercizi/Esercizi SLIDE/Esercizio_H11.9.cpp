/* Codificare in C++ un programma che chiede all’utente di
inserire due numeri decimali maggiori di zero e diversi tra
loro (ES: 10.2 e 24.7), ed un numero intero N.
• il programma calcola lo arrotondamento per eccesso o
per difetto di entrambi i numeri, a seconda che la parte
decimale sia maggiore o uguale a 0.5 oppure minore di
0.5 rispettivamente. Siano a e b i due numeri ottenuti,
con a < b.
• per ogni numero a ≤ p ≤ b, calcola e stampa la
somma degli N-1 numeri minori di p e la somma dei
2N numeri maggiori di p; */

#include <iostream>
using namespace std;

int main(){

    float x, y;
    int N, a, b, p, s, i = 0;
    int somma_minori = 0;
    int somma_maggiori = 0;


    cout << "Inserire un numero decimale (x): " << endl;
    cin >> x;
    cout << "Inserire un secondo numero decimale (y) (diverso da quello precedente): " << endl;
    cin >> y;

    a = x + 0.5;
    //cout << "a approssimato: " << a << endl;
    b = y + 0.5;
    //cout << "b approssimato: " << b << endl;

    if(a > b){
        a = a + b;      //swap delle due variabili
        b = a - b;
        a = a - b;
    }

    cout << "Inserire un numero intero (N): " << endl;
    cin >> N;
    cout << "Inserire un altro numero intero (p): " << endl;
    cin >> p;

    s = p;      //salvataggio valore p

    if(a <= p && b >= p){
        for(p; i < N-1; i++){
            p--;
            somma_minori = somma_minori + p;
        }
        cout << "La somma degli N-1 numeri minori di p è: " << somma_minori << endl;
        
        i = 0;      //riinizializzazione contatore
        p = s;      //riinizializzazione p

        for(p; i < 2*N; i++){
            p++;
            somma_maggiori = somma_maggiori + p;
        }
        cout << "La somma dei 2N numeri maggiori di p è: " << somma_maggiori << endl;
    }
    else{
        cout << "ERRORE" << endl;       //Perchè deve essere a ≤ p ≤ b
        return 0;
    }

    return 0;
}