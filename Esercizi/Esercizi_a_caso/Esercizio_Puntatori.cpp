/* Si dichiari un array `array` di double contenente i seguenti 5 elementi: [2.0, 4.2, 9.6, 9.2, 0.1].
Facendo uso della aritmetica dei puntatori:

-Si cambi il valore del terzo elemento in 9.9;

-Si sostituisca il valore del primo elemento nella somma dei valori dell’ultimo e del quarto elemento;

-Si mostrino a schermo tutti i valori dell’array in sequenza inversa. */

#include<iostream>
using namespace std;

int main(){

    double A[5] = {2.0, 4.2, 9.6, 9.2, 0.1};
    double *ptr = &A[0];

    //Cambio il valore del terzo elemento in 9.9
    *(ptr+2) = 9.9;

    //Sostituisco il valore del primo elemento nella somma dei valori dell’ultimo e del quarto elemento
    *ptr = *(ptr+4) + *(ptr+3);

    //Stampo i valori dell'Array in sequenza inversa
    for(int i = 4; i>=0; i--){
        cout << A[i] << "  ";
    }
    cout << endl;

    return 0;
}