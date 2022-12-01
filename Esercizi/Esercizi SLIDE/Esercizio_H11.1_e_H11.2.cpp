/* Sulla base degli esempi precedenti, codificare un
ciclo while in linguaggio C++ nel quale:
• il loop si ferma quando il capitale o montante
raggiunge o supera la cifra target definita in una
costante T;
• tuttavia il periodo di accumulo di interessi sul
montante non deve in ogni caso superare il
numero di anni definito in una costante N. 

Eseguire Hand Tracing del ciclo while codificato
nell’esercizio precedente con i seguenti valori ( in
tutti casi deve essere tasso interesse 10% e capitale
iniziale 1000 euro):
1. N=5, TARGET=1500 ---> Il capitale finale è: 1464.1
2. N=3, TARGET=1200 ---> Il capitale finale è: 1100
3. N=10, TARGET=1600 ---> Il capitale finale è: 1464.1
*/

#include <iostream>
using namespace std;

int main(){

    const double TARGET = 1600.0;            //Target
    const double tasso_interesse = 0.1;
    double capitale = 1000.0;
    double capitale_finale;
    const int N = 10;         //costante anni da non superare
    int anno = 0;

    while(capitale <= TARGET && anno < N){
        capitale_finale = capitale;                //che alla fine del ciclo rispetta le condizioni
        capitale = capitale + capitale * tasso_interesse;
        anno++;
    }
    
    anno = anno - 1;
    cout <<  "Il capitale finale è: " << capitale_finale << endl;       //capitale_finale = capitale - capitale * tasso_interesse;
    cout << "Il numero di anni di accumulo è: " << anno <<endl;
    
}