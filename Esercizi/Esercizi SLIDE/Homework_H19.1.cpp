#include<iostream>
using namespace std;

int main(){

    double x, y;
    int somma;

    cout << "Inserire due numeri: " << endl;
    cin >> x >> y;

    somma = x + y + 0.5;

    cout << "Il valore somma degli argomenti arrotondato all'intero più vicino è: \n" << somma << endl;

    return 0;
}