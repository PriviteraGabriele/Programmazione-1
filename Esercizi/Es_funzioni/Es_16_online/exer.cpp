/* Es 16. Creare una funzione che ricevuti tre valori sottrae al maggiore metà del valore del minore.
Creare una programma che applica tre volte la funzione a valori inseriti dall’utente. */

#include<iostream>
using namespace std;

float es16(int x, int y, int z){

    int max = 0;
    int min = 0;
    float ritorno = 0;

    //Cerco il valore massimo
    if(x>y){
        max = x;
    }
    else{
        max = y;
    }

    if(max<z){
        max = z;
    }

    //Cerco il valore minimo
    if(x<y){
        min = x;
    }
    else{
        min = y;
    }

    if(min>z){
        min = z;
    }

    ritorno = max - min/2;

    return ritorno;
}