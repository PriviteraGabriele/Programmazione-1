/* Definire una funzione che prende in input un array monodimensionale
di double e restituisce l'arrotondamento all'intero più vicino della 
somma degli elementi dello array. */

#include<iostream>
using namespace std;

int arr(double*p, int n){
    int sum_arr = 0;
    double sum = 0;
    for(int i = 0; i<n; i++){
        sum += p[i];
    }
    sum_arr = (int) sum + 0.5;

    return sum_arr;
}

int main(){
    int n = 4;
    double p[n] = {1.1, 2.2, 3.3, 4.9};

    cout << arr(p, n) << endl;
}