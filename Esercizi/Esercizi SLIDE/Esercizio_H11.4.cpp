/* Codificare in linguaggio C++ un algoritmo che produca la
somma dei numeri interi dispari da 1 a 99, facendo uso del
costrutto for. Dalla somma vanno esclusi i numeri divisibili
per tre. */

#include <iostream>
using namespace std;

int main(){

    int x = 1;

    cout << "I valori sono: " << endl;
    cout << x << endl;

    for(x = 1; x <= 99; x = x + 2){
        if(x % 3 != 0)
            cout << x << endl;
    }
return 0;  
}
