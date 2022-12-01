/* Scrivere un metodo che prenda come parametro 
formale un array A di stringhe (tutte di lunghezza 
dispari), e restituisca in output la massima lunghezza 
delle stringhe palindrome contenute al centro delle 
stringhe di A. */

#include<iostream>
using namespace std;

int esercizio28(string* A, int n){
    int max = 0;
    for(int i = 0; i<n; i++){
        string temp = A[i];
        int mid = temp.length()/2;
        int c1 = mid - 1;
        int c2 = mid + 1;
        string pal = "";
        pal+= temp[mid];
        while(c1 > 0){
            if(temp[c1] == temp[c2]){
                pal = temp[c1] + pal + temp[c2];
            }
            else{
                break;
            }
            c1--;
            c2++;
        }

        if(max<pal.length()){
            max = pal.length();
        }
    }
    return max;
}

void Stampa_Array(string* A, int n){
    cout << "A: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << "  ";
    }
    cout << endl << endl;
}

int main(){
    int n = 5;
    string* A = new string[n];
    A[0] = "cassa";
    A[1] = "ciaoalolaciao";
    A[2] = "cioroci";
    A[3] = "ebekeba";
    A[4] = "aaeiokoieba";

    Stampa_Array(A, n);

    cout << "La massima lunghezza delle stringhe palindrome contenute al centro delle stringhe di A è: " << esercizio28(A, n) << endl;
    
}