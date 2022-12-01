/*Codificare un programma in C++ che chiede all’utente di
inserire un carattere. Il programma dovrà dare il seguente
output:
• Se il carattere `e una vocale minuscola, stampa il
numero che rappresenta la sua codifica;
• Se il carattere `e una vocale maiuscola, stampa il
carattere stesso sullo standard output;
• Se il carattere `e un numero compreso tra 1 e 3, stampa
il numero stesso moltiplicato 10;*/

#include <iostream>
using namespace std;

int main(){

    char a;
    
    cout << "Inserisci un carattere: " << endl;
    cin >> a;
    cout << "Output: " << endl;


        
    if(a=='a'){
        cout << 97 << endl;
    }
    else if(a=='e'){
        cout << 101 << endl;          
    }     
    else if(a=='i'){
            cout << 105 << endl;
    }
    else if(a=='o'){
            cout << 111 << endl;
    }
    else if(a=='u'){
            cout << 117 << endl;
    }
    else if(a=='A'){
            cout << 'A' << endl;
    }
    else if(a=='E'){
            cout << 'E' << endl;
    }
    else if(a=='I'){
            cout << 'I' << endl;
    }
    else if(a=='O'){
            cout << 'O' << endl;
    }
    else if(a=='U'){
            cout << 'U' << endl;
    }
    else if(a=='1'){
            cout << 1 * 10 << endl;
    }
    else if(a=='2'){
            cout << 2 * 10 << endl;
    }
    else if(a=='3'){
            cout << 3 * 10 << endl;
    }
    else {
        cout << "Valore non valido" << endl;
    }

}