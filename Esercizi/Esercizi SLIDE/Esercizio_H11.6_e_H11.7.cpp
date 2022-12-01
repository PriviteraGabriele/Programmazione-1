/* Codificare in linguaggio C++ un algoritmo che stampi a ritroso la sequenza di caratteri da ’a’ a ’z’, ma non le vocali. Codificare due versioni differenti nelle quali si fa uso del
costrutto for e del costrutto while rispettivamente. 
Estendere l’esercizio precedente in modo da conservare tutti
i caratteri stampati in un oggetto stringstream. Infine,
stampare la lunghezza della stringa contenuta in esso. */

#include <iostream>
//#include <sstream>
using namespace std;

int main(){

    char x = 122;
    string stringstream;
    cout << "(1° Metodo): \nI caratteri sono: " << endl;

    for(x = 122; x >= 97; x--){
        if(x != 97 && x != 101 && x != 105 && x != 111 && x != 117){
            cout << x << endl;
            stringstream += x;
        }
        
    }

    //cout << stringstream << endl;
    cout << endl << "La lunghezza della stringa è: " << endl;
    cout << stringstream.length() << endl;

    x = 122;
    cout << "\n" << "(2° Metodo): \nI caratteri sono: " << endl;
    while(x >= 97){
        if(x != 97 && x != 101 && x != 105 && x != 111 && x != 117){
            cout << x << endl;
        }
        x--;
    } 

    return 0;
}