/*Un falegname realizza scaffali di legno per ambienti interni o
esterni. I clienti si recano presso il suo laboratorio con alcune
richieste (input) in base alle quali il falegname opera alcune
scelte:
1. ambiente: esterno o interno
2. massimo carico (in kg) che il singolo ripiano deve essere
in grado di sopportare;
3. lunghezza in metri di ogni ripiano;
Il falegname dovrà operare nel modo seguente:
1. Se lo scaffale va sistemato all’esterno allora va impiegato
legno di castagno, altrimenti legno di pino;
2. lo spessore di ogni ripiano va calcolato in base alla
formula S = [B + max(0, L − 1) × P] × Q, dove:
• L `e la lunghezza (in metri) di ogni ripiano fornita dal
cliente;
• B = 0.018 metri se si usa il castagno, B = 0.02 metri
se si usa il pino;
• P = 0.02 per il castagno, P = 0.022 per il pino
• Q = 1.1 se il legno scelto è il castagno e se il
massimo carico che il singolo ripiano deve supportare
è maggiore di 100 kg, altrimenti Q = 1.0;
• Q = 1.2 se il legno scelto è il pino e se il carico
massimo che il singolo ripiano deve supportare è
maggiore di 80kg, altrimenti Q = 1.0.
Descrivere una soluzione del problema tale che, dati in input i
parametri ambiente, lunghezza L e carico massimo del singolo
ripiano dello scaffale, produca in output:
• essenza da usare (pino o castagno)
• spessore ripiani.
In particolare:
1. Realizzare un diagramma di flusso (o a blocchi) per la
risoluzione del problema del falegname;
2. Codificare in C++ un programma che si base sul
diagramma di flusso realizzato per il punto precedente;
3. Testare il programma in C++ mediante hand tracing per i
seguenti input:
a Carico max 80kg, scaffale non destinato all’esterno, ---> Lo spessore dello scaffale (in m) è: 0.031
lunghezza ripiani 150cm;
b Carico max 100kg, scaffale destinato all’esterno, ---> Lo spessore dello scaffale (in m) è: 0.018
lunghezza ripiani 100cm;
c Carico max 120kg, scaffale non destinato all’esterno, ---> Lo spessore dello scaffale (in m) è: 0.024
lunghezza ripiani 100cm;
*/

#include <iostream>
using namespace std;

#define YES 'Y'
#define NO 'N'

int main(){

    float B;   
    float L;                //Espresso in m   
    float max;
    float P;     
    float Q;     
    float S;                //Spessore
    char risposta;          //Ambiente: Interno?
    float max_carico;       //Espresso in Kg
    bool Pino;

    
    cout << "Ambiente: Interno (Y/N)? " << endl;
    cin >> risposta;

    switch(risposta){

        case YES:
            Pino = true;
            cout << "Carico massimo del singolo ripiano dello scaffale (Espresso in Kg): " << endl;
            cin >> max_carico;
            cout << "Lunghezza dello scaffale (Espresso in m): " << endl;
            cin >> L;
            B = 0.02;
            P = 0.022;
            if(max_carico > 80){
                Q = 1.2;
            }
            else{
                Q = 1.0;
            }
            if(0 > L-1)        //max(0, L - 1)
                max = 0;
            else
                max = L-1;
            S = (B + max * P) * Q;
            cout << "Essenza da usare: PINO" << endl;
            cout << "Lo spessore dello scaffale (in m) è: " << S << endl;
            break;
        case NO:
            Pino = false;
            cout << "Carico massimo del singolo ripiano dello scaffale (Espresso in Kg): " << endl;
            cin >> max_carico;
            cout << "Lunghezza dello scaffale (Espresso in m): " << endl;
            cin >> L;
            B = 0.018;
            P = 0.02;
            if(max_carico > 100){
                Q = 1.1;
            }
            else{
                Q = 1.0;
            }
            if(0 > L-1)        //max(0, L - 1)
                max = 0;
            else
                max = L-1;
            S = (B + max * P) * Q;
            cout << "Essenza da usare: CASTAGNO" << endl;
            cout << "Lo spessore dello scaffale (in m) è: " << S << endl;
            break;
        default:
            cout << "Risposta non valida!" << endl;
            break;
    }
}   