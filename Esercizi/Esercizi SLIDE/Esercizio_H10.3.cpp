/*Siano s1, s2 ed s3 tre oggetti di tipo string e mys un
altro oggetto di tipo string.
• Se (A) la lunghezza di una delle tre stringhe s1, s2, s3 `e
maggiore di 10 e se (B) almeno una di esse `e lunga almeno
20 caratteri, allora copia nella variabile di tipo string
denominata mys la concatenazione dei primi tre caratteri in
s2 e degli ultimi tre caratteri in s3.
• Se la condizione (A) `e verificata ma non la (B), allora copia in
mys la concatenazione delle tre stringhe, in ordine.
• In tutti gli altri casi stampa la somma delle lunghezze delle
tre stringhe.*/

#include <iostream>
#include <string>
using namespace std;

int main(){

    string s1;
    string s2;
    string s3;
    string mys;
    
    cout << "Inserisci la prima parola: " << endl;
    cin >> s1;
    cout << "Inserisci la seconda parola: " << endl;
    cin >> s2;
    cout << "Inserisci la terza parola: " << endl;
    cin >> s3;

    int nc_s1 = s1.length();            //Lunghezza s1
    int nc_s2 = s2.length();            //Lunghezza s2
    int nc_s3 = s3.length();            //Lunghezza s3
    int somma = nc_s1 + nc_s2 + nc_s3;      //Somma delle lunghezze s1, s2, s3

    int max = (nc_s1<nc_s2? (nc_s2<nc_s3? nc_s3:nc_s2) : (nc_s1<nc_s3? nc_s3:nc_s1));       //La stringa più lunga

    if(max>10){
        if(max>=20){
            mys = s2.substr(0, 3) + " and " + s3.substr(s3.length()-3, s3.length());      //Concatenazione dei primi tre caratteri di s2 e degli ultimi tre caratteri di s3  
            cout << mys << endl;
        }
        else{
            mys = s1 + " and " + s2 + " and " + s3;     //Concatenazione delle tre stringhe, in ordine
            cout << mys << endl;
        }
    }
    else{
        cout << somma  << endl;     //stampa somma lunghezze delle 3 stringhe
    }  

}