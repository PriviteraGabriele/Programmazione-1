/* Codificare in linguaggio C++ un algoritmo che stampi a ritroso i numeri pari minori o uguali a mille; Il loop deve comunque
terminare se la somma dei numeri precedentemente stampati è maggiore o uguale a centomila. */

#include <iostream>
using namespace std;

int main(){

    int x = 1000;
    int somma = 0;


    cout << "I valori sono: " << endl;

    for(x = 1000; x <= 1000 && somma < 100000; x = x - 2)
        if(x % 2 == 0){
            cout << x << endl;
            somma = somma + x;
        }

}
            