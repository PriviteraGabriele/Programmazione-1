/* Si scriva un programma che prenda in input 10 numeri dall’utente e una stringa e stampi a schermo:

La somma dei valori, se la stringa inserita è uguale a “sum”;

Il prodotto dei valori, se la stringa inserita è uguale a “prod”;

La somma dei valori pari inseriti, se la stringa inserita è uguale a “sumeven”;

La lista dei numeri in tutti gli altri casi (suggerimento: si usi uno stringstream per stampare la lista dei numeri inseriti). */

#include<iostream>
using namespace std;

int main(){

    int a, b, c, d, e, f, g, h, i, l, somma = 0, prodotto = 0, somma_pari = 0;
    string comando;


    cout << "Inserire 10 numeri: " << endl;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> l;
    cout << "Inserire il contenuto della stringa: " << endl;
    cin >> comando;

    //Comando somma di tutti i numeri
    if(comando == "sum"){
        somma = a + b + c + d + e + f + g + h + i + l;
        cout << "La somma di tutti i numeri inseriti è: " << endl;
        cout << somma << endl;
    }
    //Comando prodotto di tutti i numeri
    else if(comando == "prod"){
        prodotto = a * b * c * d * e * f * g * h * i * l;
        cout << "Il prodotto di tutti i numeri inseriti è: " << endl;
        cout << prodotto << endl;
    }
    //Comando somma di tutti i numeri pari
    else if(comando == "sumeven"){
        int A[] = {a, b, c, d, e, f, g, h, i, l};
        cout << "La somma di tutti i numeri pari inseriti è: " << endl;
        for(int i = 0; i<10; i++){
            if(A[i]%2==0){
                somma_pari += A[i];
            }
        }
        cout << somma_pari << endl;
    }
    //Comando lista dei numeri in tutti gli altri casi
    else{
        int A[] = {a, b, c, d, e, f, g, h, i, l};
        cout << "La lista di tutti i numeri inseriti è: " << endl;
        for(int i = 0; i<10; i++){
        cout << "- " << A[i] << endl;
        }
    }



    return 0;
}