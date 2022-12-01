/*Tre vasche A, B e C raccolgono acqua da 15 tubi differenti.
• La vasca A riceve l’acqua convogliata nei tubi 1,5,6,10.
• La vasca B riceve l’acqua convogliata nei tubi da 2 a 4 e da 7
a 9.
• La vasca C riceve l’acqua convogliata nei rimanenti tubi.
Inoltre, i tubi con numero dispari hanno una portata di 60 litri al
minuto, mentre quelli con numero pari hanno una portata di 120
litri al minuto. 
Codificare un programma in linguaggio C++ che esegua le seguenti
operazioni:
• il programma chiede in input all’utente 5 numeri distinti, compresi
tra 1 e 15. Tali numeri rappresentano 5 differenti tubi. NB: il
programma deve operare un controllo sulla validit`a dell’input (ad
esempio che i numeri siano tutti differenti tra loro);
• il programma chiede all’utente il numero totale di minuti (M)
durante i quali i tubi specificati forniranno acqua alla rispettiva
vasca. NB: il programma deve operare un controllo sulla validit`a
dello input, ad esempio che il numero immesso sia positivo.
• il programma calcola e stampa la quantit d’acqua raccolta in ogni
vasca dopo gli M minuti speficicati dall’utente. */

#include <iostream>
#define PORTATA_PARI 120;
#define PORTATA_DISPARI 60;
using namespace std;

int main(){

    int Vasca_A = 0;    //1, 5, 6, 10.
    int Vasca_B = 0;    //2, 3, 4, 7, 8, 9.
    int Vasca_C = 0;    //11, 12, 13, 14, 15. 
    int tubo1, tubo2, tubo3, tubo4, tubo5;
    int M;
    
    //Input valore tubi
    cout << "Inserire i valori dei 5 tubi: " << endl;
    cin >> tubo1 >> tubo2 >> tubo3 >> tubo4 >> tubo5;
    int A[5] = {tubo1, tubo2, tubo3, tubo4, tubo5};

    //Controllo input valori tubi compresi tra 1 e 15
    if(tubo1<1 || tubo1>15){
        cerr << "ERRORE: il numero inserito deve essere compreso tra 1 e 15! (tubo1)" << endl;
        return -1;
    }
    else if(tubo2<1 || tubo2>15){
        cerr << "ERRORE: il numero inserito deve essere compreso tra 1 e 15! (tubo2)" << endl;
        return -1;
    }
    else if(tubo3<1 || tubo3>15){
        cerr << "ERRORE: il numero inserito deve essere compreso tra 1 e 15! (tubo3)" << endl;
        return -1;
    }
    else if(tubo4<1 || tubo4>15){
        cerr << "ERRORE: il numero inserito deve essere compreso tra 1 e 15! (tubo4)" << endl;
        return -1;
    }
    else if(tubo5<1 || tubo5>15){
        cerr << "ERRORE: il numero inserito deve essere compreso tra 1 e 15! (tubo5)" << endl;
        return -1;
    }

    //controllo input valori tubi tutti diversi tra loro
    for(int i = 0; i<5; i++){
        for(int j = i + 1; j<5; j++){
            if(A[i] == A[j]){
                cerr << "ERRORE: i valori inseriti devono essere diversi fra loro!" << endl;
                return -1;
            }
        }
    }

    //Input valore tempo
    cout << "Inserisci il numero totale di minuti (M) durante i quali i tubi forniranno acqua alla rispettiva vasca: " << endl;
    cin >> M;

    //controllo input variabile M positiva
    if(M<0){
        cerr << "ERRORE: il valore inserito deve essere positivo!" << endl;
        return -1;
    }

    //Vasca_A
    for(int i = 0; i<5; i++){
        if(A[i]==1 || A[i]==5 || A[i]==6 || A[i]==10){
            if(A[i]%2==0){
                Vasca_A += M * PORTATA_PARI;
            }
            else{
                Vasca_A += M * PORTATA_DISPARI;
            }
        }
    }

    //Vasca_B
    for(int i = 0; i<5; i++){
        if(A[i]==2 || A[i]==3 || A[i]==4 || A[i]==7 || A[i]==8 || A[i]==9){
            if(A[i]%2==0){
                Vasca_B += M * PORTATA_PARI;
            }
            else{
                Vasca_B += M * PORTATA_DISPARI;
            }
        }
    }

    //Vasca_c
    for(int i = 0; i<5; i++){
        if(A[i]==11 || A[i]==12 || A[i]==13 || A[i]==14 || A[i]==15){
            if(A[i]%2==0){
                Vasca_C += M * PORTATA_PARI;
            }
            else{
                Vasca_C += M * PORTATA_DISPARI;
            }
        }
    }

    //Stampo la quantità d'acqua presente nelle varie vasche con i dati inseriti dall'utente
    cout << "La quantità d'acqua nelle varie vasche con i dati inseriti è: " << endl;
    cout << "Vasca_A: " << Vasca_A << endl;
    cout << "Vasca_B: " << Vasca_B << endl;
    cout << "Vasca_C: " << Vasca_C << endl;
    
    return 0;

}