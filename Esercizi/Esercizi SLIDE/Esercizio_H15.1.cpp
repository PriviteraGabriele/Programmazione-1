/* Scrivere un programma in C++ nel quale si chiede all’utente un
numero qualunque p. Successivamente:
• Se il numero p `e minore di 1, stampare un messaggio di errore.
• Se il numero p `e maggiore o uguale a 1, arrotondare il numero
stesso allo intero pi`u vicino e allocare un array di quella
dimensione.
• Inizializzare lo array con valori a piacere per tre volte
mediante un ciclo: i) con il costrutto for, ii) con il costrutto
while, iii) con il costrutto do-while.
• Stampare tutti i valori dello array con un ciclo usando un
costrutto a scelta. */

#include <iostream>
using namespace std;

int main(){

    float p;
    int dim=0;

    cout << "Inserire un numero qualunque (p): " << endl;
    cin >> p;

    if(p<1){
        cerr << "ERRORE: Il numero inserito non deve essere minore di 1!" << endl;
        return -1;
    }
    else{
        dim = p + 0.5;
    }

    int V[dim] = {0};
    

    for(int i=1; i<dim; i++){
        V[i] = V[i-1] + 2;
    }

    cout << "I valori degli arrey sono (for): " << endl;
    for(int i=0; i<dim; i++){
        cout << V[i] << endl;
    }

    int i=1;
    while(i<dim){
        V[i] = V[i-1] + 2;
        i++;
    }

    cout << "I valori degli arrey sono (while): " << endl;
    for(int i=0; i<dim; i++){
        cout << V[i] << endl;
    }

    i = 1;
    do{
        V[i] = V[i-1] + 2;
        i++;
    }while(i<dim);

    cout << "I valori degli arrey sono (do while): " << endl;
    for(int i=0; i<dim; i++){
        cout << V[i] << endl;
    }

    return 0;
}