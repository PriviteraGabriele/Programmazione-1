/*Codificare un programma in C++ che chiede all’utente di
inserire un carattere. Il programma dovrà dare il seguente
output:
• Se il carattere `e una vocale minuscola, stampa il
numero che rappresenta la sua codifica;
• Se il carattere `e una vocale maiuscola, stampa il
carattere stesso sullo standard output;
• Se il carattere `e un numero compreso tra 1 e 3, stampa
il numero stesso moltiplicato 10;*/

#include <iostream>
using namespace std;

int main(){

    char a;
    
    cout << "Inserisci un carattere: " << endl;
    cin >> a;
    cout << "Output: " << endl;


    switch(a){

        case 'a':
            cout << 97 << endl;
            break;
        case 'e':
            cout << 101 << endl;
            break;
        case 'i':
            cout << 105 << endl;
            break;
        case 'o':
            cout << 111 << endl;
            break;
        case 'u':
            cout << 117 << endl;
            break;
        case 'A':
            cout << 'A' << endl;
            break;
        case 'E':
            cout << 'E' << endl;
            break;
        case 'I':
            cout << 'I' << endl;
            break;
        case 'O':
            cout << 'O' << endl;
            break;
        case 'U':
            cout << 'U' << endl;
            break;
        case '1':
            cout << 1 * 10 << endl;
            break;
        case '2':
            cout << 2 * 10 << endl;
            break;
        case '3':
            cout << 3 * 10 << endl;
            break;
        default:
            cout << "Valore non valido" << endl;
            break; 
    }

}