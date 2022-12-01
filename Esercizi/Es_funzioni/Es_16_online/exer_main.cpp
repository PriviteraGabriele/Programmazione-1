/* Es 16. Creare una funzione che ricevuti tre valori sottrae al maggiore metà del valore del minore.
Creare una programma che applica tre volte la funzione a valori inseriti dall’utente. */

#include<iostream>
//#include"exer.h"
using namespace std;

int main(){

    int x, y, z;
    cout << "Inserire tre valori: \n";
    cin >> x >> y >> z;

    cout << "Il valore è: \n" << es16(x, y, z) << endl;  

    return 0;
}