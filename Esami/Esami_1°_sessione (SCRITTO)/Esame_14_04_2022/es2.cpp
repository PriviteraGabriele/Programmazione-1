/* Scrivere una funzione che prenda come paramentri formali un array A di puntatori a stringhe 
di lunghezza n e una reference a intero m e restituisca il numero di coppie ordinate (a, b) di
stringhe di uguale lunghezza in a tali che A contenga a almeno m elementi nelle sue posizioni
pari che esistono in b in posizioni dispari. La funzione ponga infine in m la lunghezza media 
delle stringhe in a opportunatamente arrotondata al numero intro più vicino. */

#include<iostream>
using namespace std;

int ex2(string** A, int n, int &m){

    //Salvataggio lunghezza array
    int lunghezza[n] = {0};
    int ritorno = 0;
    int counter = 0;            //Salvataggio numero di stringhe non nulle

    for(int i = 0; i<n; i++){
        if(A[i]){
            lunghezza[i] = (*A[i]).length();
            counter++;
        }
    }

    int counter_caratteri;
    for(int i = 0; i<n-1; i++){
        for(int j = i + 1; j<n; j++){
            counter_caratteri = 0;
            //cout << "*A[" << i << "] = " << *A[i] << ", lunghezza[" << i << "] = " << lunghezza[i] << endl;
            //cout << "*A[" << j << "] = " << *A[j] << ", lunghezza[" << j << "] = " << lunghezza[j] << endl;
            if(lunghezza[i] == lunghezza[j]){
                string temp1 = *A[i];
                string temp2 = *A[j];
                for(int x = 0; x<temp1.length(); x+=2){
                    for(int y = 1; y<temp2.length(); y+=2){
                        //cout << "temp1[" << x << "] = " << temp1[x] << endl;
                        //cout << "temp2[" << y << "] = " << temp2[y] << endl;
                        if(temp1[x] == temp2[y]){
                            counter_caratteri++;
                            //cout << "counter_caratteri = " << counter_caratteri << endl;
                        }
                    }
                }
                if(counter_caratteri >= m){
                    ritorno++;
                    //cout << "ritorno = " << ritorno << endl;
                }
            }
        }
    }

    double somma = 0;
    for(int i = 0; i<n; i++){
        somma += lunghezza[i];
    }
    m = (somma/counter) + 0.5;

    return ritorno;
}

void Stampa_Array(string** A, int n){
    cout << "Array:    ";
    for(int i = 0; i<n; i++){
        if(A[i]){
            cout << *A[i] << "    ";
        }
    }
    cout << endl;
}

int main(){

    int n = 4;
    int m = 2;

    string** A = new string*[n];

    A[0] = new string("casa");
    A[1] = new string("acas");
    A[2] = new string("divano");
    A[3] = new string("bcks");

    Stampa_Array(A, n);

    cout << ex2(A, n, m) << endl;
}