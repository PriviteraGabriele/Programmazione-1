/* Si scriva una funzione che prenda in input due stringhe (string object)
e restituisca una terza stringa (string object) che contenga i caratteri 
in comune tra la prima e la seconda stringa. */

#include<iostream>
#include<string>
using namespace std;

int main(){

    
    
    string s1 = "pippo";
    string s2 = "paperino";
    string s3;
    int contatore_s1 = s1.length();
    int contatore_s2 = s2.length();

    for(int i = 0; i<contatore_s1; i++){
        for(int j = 0; i<contatore_s2; j++){
            if(s1[i]==s2[j]){
                s3 += s1[i];
            }
        }   
    }
    cout << "I caratteri in comune sono: \n" << s3 << endl;;

    return 0;
}