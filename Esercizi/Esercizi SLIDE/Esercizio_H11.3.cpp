/* Codificare un programma completo in linguaggio C++ in cui:
• l’utente deve inserire da tastiera il capitale iniziale (C), il
tasso di interesse (TI), il target (T) e numero di anni (N);
• se uno tra T ed N `e un numero minore o uguale a zero,
allora il programma non dovr`a tener conto di tale
parametro; nel caso in cui sia T che N siano minori o
uguali a zero allora il programma terminer`a con un
messaggio di errore;
• il programma dar`a in output il capitale finale ed il numero
totale di anni di accumulo; come nello esercizio
precedente, l’accumulo degli interessi sul montante si
interrompe quando il capitale raggiunge o supera la cifra
target T e comunque il numero di anni di accumulo non
deve superare N.
*/

#include <iostream>
using namespace std;

int main(){

    double C;       //capitale iniziale
    double TI;      //tasso di interesse
    double T;       //target
    int N;          //numero di anni
    int anno = 0; 
    double capitale_finale;         

    cout << "Inserire capitale iniziale: " << endl;
    cin >> C;
    cout << "Inserire tasso di interesse: " << endl;
    cin >> TI;
    cout << "Inserire target: " << endl;
    cin >> T;
    cout << "Inserire numero di anni: " << endl;
    cin >> N;

    if(T <= 0 && N <= 0){
        cout << "ERRORE: Valori inseriti non validi!" << endl;
        return 0;
    }
    else if(T <= 0 || N <= 0){
        cout << "Il Programma non terrà conto di tale paramentro" << endl;    //da sistemare
    }
    else{
        while(C <= T && anno < N){
        capitale_finale = C;                //che alla fine del ciclo rispetta le condizioni
        C = C + C * TI;

        anno++;
        }
    
        anno = anno - 1;
        cout <<  "Il capitale finale è: " << capitale_finale << endl;      //capitale_finale = C - C * TI;
        cout << "Il numero di anni di accumulo è: " << anno << endl;   
    }
    
}