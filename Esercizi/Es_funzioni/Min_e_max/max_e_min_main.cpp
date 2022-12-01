/* Si definiscano due funzioni min e max che permettano di calcolare 
rispettivamente in minimo e il massimo di due numeri interi. */

#include<iostream>
#include "max_e_min.h"
using namespace std;

int main(){

    int x, y;
    
    cout << "Inserire due numeri: \n";
    cin >> x >> y;
    cout << "Il numero più grande è: \n" << max(x, y) << endl;
    cout << "Il numero più piccolo è: \n" << min(x, y) << endl;

    return 0;
}