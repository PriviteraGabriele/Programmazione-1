/* Scrivere un metodo che prenda come parametro formale una matrice S di dimensione n×m 
di stringhe ed una stringa X, e modifichi con un ‘*’ ogni carattere delle stringhe in S 
contenenti la sottostringa X. N.B.: Non è possibile usare substr. */

#include<iostream>
#include<string>
using namespace std;

void metodo(string **S, int n, int m, string X){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int long1 = S[i][j].length()-1;
            for(int p = 0; p<long1; p++){
                int long2 = X.length()-1;
                for(int q = 0; q<long2; q++){
                    if(S[i][j][p]==X[q]){
                        S[i][j][p] = '*';
                    }
                }
            }
        }
    }
}


int main(){
    string X = "cielo";
    int n = 2;
    int m = 3;
    string S[][m] = {{"ciccio", "ciao", "pesce"},
                      {"ape", "grillo", "casa"}};

    
    //stampa matrice
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(j==2){
                cout << S[i][j] << endl;
            }
            else{
                cout << S[i][j] << " ";
            }
        }
    }
    cout << metodo(S,n,m,X);
}