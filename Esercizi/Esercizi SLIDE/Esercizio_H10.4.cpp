/*Scrivere del codice C++ per testare le seguenti
disuguaglianze:
"sale" < "sole"? ---> VERO
"uova" < "suola"? ---> FALSO
"Marco" < "marco"? ---> VERO
"asta" < "canasta"? ---> VERO
"123prova" < "Abaco"? ---> VERO
*/

#include <iostream>
#include <string>
using namespace std;

int main(){

    string a;
    string b;

    cout << "Scrivi la prima parola: " << endl;
    cin >> a;
    cout << "Scrivi la seconda parola: " << endl;
    cin >> b;

     cout << (a<b? "a<b" : "b<a") << endl;






}