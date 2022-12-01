/* Scrivere una funzione che prenda come parametri formali un array tridimensione A
di puntatori a interi di dimensione nxnxn e uno short q. Sia m la media dei valori contenuti
nella diagonale principale del cubo. La funzione restituisca il numero di elementi di A che 
puntano ad un qualche valore a tale che |a - m| <= q. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int ex1(int**** A, int n, short q){

    int ritorno = 0;        //ritorno funzione
    int counter = 0;
    double somma = 0;

    //Media diagonale principale
    for(int i = 0; i<n; i++){
        if(A[i][i][i]){
            somma += *A[i][i][i];
            cout << "*A[" << i << "][" << i << "][" << i << "] = " << *A[i][i][i] << endl;
            counter++;
            cout << "*counter = " << counter << endl;
        }
    }

    cout << "somma = " << somma << endl;
    double m = (double)somma/counter;
    cout << "m = " << m << endl;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int z = 0; z<n; z++){
                if(A[i][j][z]){
                    //Controllo valore assoluto
                    cout << "*A[" << i << "][" << j << "][" << z << "] = " << *A[i][j][z] << endl;
                    double temp = *A[i][j][z] - m;
                    cout << "temp = " << temp << endl;
                    if(temp < 0){
                        cout << "Controllo valore assoluto" << endl;
                        temp = temp *(-1);
                        cout << "temp = " << temp << endl;
                    }

                    //Controllo condizione
                    cout << "q = " << q << endl;
                    if(temp <= q){
                        ritorno++;
                        cout << "+ritorno = " << ritorno << endl;
                    }
                }
            }
        }
    }

    return ritorno;
}

void Stampa_Matrice(int**** A, int n){
    cout << "Stampa Matrice:" << endl << endl;
    for(int h = 0; h<n; h++){
        cout << "Matrice [" << h << "]: " << endl << endl;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout << *A[h][i][j] << "      ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main(){

    int n = 4;
    short q = 4;

    srand(time(NULL));
    int**** A = new int***[n];
    for(int i =0; i<n; i++){
        A[i] = new int**[n];
        for(int j =0; j<n; j++){
            A[i][j] = new int*[n];
            for(int k = 0; k<n;k++){
                A[i][j][k] = new int(rand()%10);
            }
        }
    }

    Stampa_Matrice(A, n);

    cout << ex1(A, n, q) << endl;
}