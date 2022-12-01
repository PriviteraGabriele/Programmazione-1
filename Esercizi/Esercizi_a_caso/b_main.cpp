/* Scrivere una funzione che prenda in input una matrice quadrata A 
di short, e restituisca un bool che indichi se la diagonale principale è 
identica (procedendo dall’alto verso il basso) alla secondaria. */

#include<iostream>
#include "b.h"
using namespace std;

int main(){

    short A[4][4] = {1,0,0,1,0,2,2,0,0,3,3,0,4,0,0,4};

    cout << identica(A);

}