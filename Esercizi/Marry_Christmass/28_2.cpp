/* Scrivere un metodo che prenda come parametro 
formale un array A di stringhe (tutte di lunghezza 
dispari), e restituisca in output la massima lunghezza 
delle stringhe palindrome contenute al centro delle 
stringhe di A. */

#include<iostream>
using namespace std;

int ex28(string* A, int n){
    int counter;            //contatore lunghezza stringa palindroma partendo dal centro
    int max = 0;            //ritorno
    string temp = "";
    for(int i = 0; i<n; i++){
        temp = A[i];
        //cout << "temp = " << temp << endl;
        int mid = temp.length()/2 + 1;
        //cout << "mid = " << mid << endl;
        //counter = 0;
        int m = 2;
        for(int p = mid; p<temp.length(); p++){
            //cout << "temp[" << p << "] = " << temp[p] << endl;
            //cout << "temp[" << mid - m << "] = " << temp[mid - m] << endl;
            if(temp[p] == temp[mid - m]){
                counter++;
                //cout << "*counter = " << counter << endl;
                m++;
            }
            else{
                m = 2;
                break;
            }
        }
        m = 2;
        if(max < counter){
            max = counter;
            //cout << "max = " << max << endl;
        }
        counter = 0;
    }
    return (max*2)+1;
}

void Stampa_Array(string* A, int n){
    cout << "A:   ";
    for(int i = 0; i<n; i++){
        cout << A[i] << "    ";
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

    cout << "La massima lunghezza delle stringhe palindrome contenute al centro delle stringhe di A è: " << ex28(A, n) << endl;
    
}