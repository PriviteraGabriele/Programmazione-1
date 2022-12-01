/* Scrivere un programma in C++ nel quale si chiede all’utente di
inserire due numeri N ed M entrambi maggiori di 1.
Successivamente:
• operare i soliti controlli ed eventuali arrotondamenti sui
numeri inseriti dallo utente;
• inizializzare la matrice con numeri a piacere in virgola mobile;
• calcolare e stampare il prodotto di uno scalare scelto a piacere
(es: 3.542) con la matrice;
• definire una ulteriore matrice quadrata avente la dimensione
della pi`u grande matrice quadrata che `e possibile ricavare
dalla matrice esistente. ES: per una matrice 8x9 le dimensioni
della nuova matrice saranno 8x8;
• riempire la nuova matrice con i corrispondnti elementi della
prima matrice. */

#include <iostream>
#include<cmath>
using namespace std;

int main(){

    float N, M;
    int n, m, x = 1;

    cout << "Inserire un numero maggiore di 1 (N): " << endl;
    cin >> N;
    if(N<=1){
        cerr << "ERRORE: Il numero inserito deve essere maggiore di 1!" << endl;
        return -1; 
    }
    n = N + 0.5;

    cout << "Inserire un secondo numero maggiore di 1 (M): " << endl;
    cin >> M;
    if(M<=1){
        cerr << "ERRORE: Il numero inserito deve essere maggiore di 1!" << endl;
        return -1; 
    }
    m = M + 0.5;

    double V[n][m]={0};

    //Inizializzazione matrice con numeri a piacere in virgola mobile 
    for(int i=0;i<n;i++){ 
        for(int j=0;j<m;j++){ 
            V[i][j] = (i+j)*3.24;
        }
    }

    //Calcolo il valore di uno scalare scelto a piacere (es: 3.542) per la matrice e stampo
    for(int i=0;i<n;i++){ 
        for(int j=0;j<m;j++){ 
            V[i][j] = (i+j)*3.24*3.542;
        }
    }
    
    
    cout << "I valori della matrice sono: " << endl;
    for(int i=0;i<n;i++){ 
        for(int j=0;j<m;j++){ 
            cout << V[i][j] << "  ";
        }
    }
    cout << endl;

    //Cerco la maggiore matrice quadrata che è possibile ricavare dalla matrice esistente
    int min;

    if(n<m){
        min = n;
    }
    else{
        min = m;
    }

    double A[min][min];

    //Riempio la nuova matrice con i corrispondnti elementi della prima matrice e stampo
    for(int i=0;i<min;i++){ 
        for(int j=0;j<min;j++){ 
            A[i][j] = (i+j)*3.24;
        }
    }

    cout << "I valori della nuova matrice quadrata sono: " << endl;
    for(int i=0;i<min;i++){ 
        for(int j=0;j<min;j++){ 
            cout << A[i][j] << "  ";
        }
    }
    cout << endl;

    return 0;
}