/* Codificare un programma in linguaggio C++ che chieda
all’utente di inserire da tastiera il proprio nome e cognome.
Successivamente il programma dovr`a stampare le seguenti
informazioni:
1. il primo e l’ultimo carattere del nome, il secondo ed il
terzo carattere del cognome.
2. una stringa formata da tutti i caratteri che sono presenti
sia nel nome che nel cognome. ES: se nome=”Mario”,
cognome= ”Rossi” lo output sar`a ”io”.
3. le segg. ulteriori informazioni:
a un messaggio che comunica all’utente se la prima
lettera del nome `e uguale all’ultima lettera del cognome.
b un messaggio che comunica all’utente se il numero di
caratteri del nome `e uguale al numero di lettere del
cognome.
c il numero di consonanti del nome e del cognome. */

#include<iostream>
#include<string>
using namespace std;

int main(){

    string nome;
    string cognome;

    cout << "Inserire il proprio nome: " << endl;
    cin >> nome;
    cout << "Inserire il proprio cognome: " << endl;
    cin >> cognome;

    // 1) Stampo il primo e l’ultimo carattere del nome, il secondo ed il terzo carattere del cognome
    int n = nome.length();
    cout << "Il primo e l’ultimo carattere del nome sono: " << endl;
    cout << nome[0] << " - " << nome[n-1] << endl;
    cout << "Il secondo ed il terzo carattere del cognome sono: " << endl;
    cout << cognome[1] << " - " << cognome[2] << endl;

    // 2) Stampo una stringa formata da tutti i caratteri che sono presenti sia nel nome che nel cognome
    cout << "La stringa formata da tutti i caratteri che sono presenti sia nel nome che nel cognome è: " << endl;
    for(int i = 0; i<nome.length(); i++){
        for(int j = 0; j<cognome.length(); j++){
            if(nome[i]==cognome[j]){
                cout << nome[i] << " ";
            }
        }
    }
    cout << endl;

    // 3. a) Stampo un messaggio che comunica all’utente se la prima lettera del nome `e uguale all’ultima lettera del cognome
    int m = cognome.length();
    if(nome[0]==cognome[m-1]){
        cout << "La prima lettera del nome è uguale all’ultima lettera del cognome!" << endl;
    }
    else{
        cout << "La prima lettera del nome non è uguale all’ultima lettera del cognome!" << endl;
    }

    // 3. b) Stampo un messaggio che comunica all’utente se il numero di caratteri del nome è uguale al numero di lettere del cognome
    if(n == m){
        cout << "Il numero di caratteri del nome è uguale al numero di lettere del cognome!" << endl;
    }
    else{
        cout << "Il numero di caratteri del nome non è uguale al numero di lettere del cognome!" << endl;
    }

    // 3. c) Stampo il numero di consonanti del nome e del cognome
    int consonanti = 0;
    string a = "a";
    string e = "e";
    string i = "i";
    string o = "o";
    string u = "u";
    for(int c = 0; c<nome.length(); c++){
        if(nome[c] != a[0] && nome[c] != e[0] && nome[c] != i[0] && nome[c] != o[0] && nome[c] != u[0]){
            consonanti++;
        }
    }

    for(int j = 0; j<cognome.length(); j++){
        if(cognome[j] != a[0] && cognome[j] != e[0] && cognome[j] != i[0] && cognome[j] != o[0] && cognome[j] != u[0]){
            consonanti++;
        }
    }

    cout << "Il numero di consonanti del nome e del cognome è: " << endl << consonanti << endl;
     

    return 0;
    

}
