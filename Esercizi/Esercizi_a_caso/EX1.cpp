/*
[Esercizio 10] Scrivere un metodo che prenda in input un parametro formale matrice di stringhe A di dimensioni n × m,
una matrice di caratteri C di dimensioni k × z, uno short w e restituisca true se esiste almeno una riga o una colonna di A che
contiene almeno una sequenza contigua di w o piu’ caratteri che si trovano in una riga o in una colonna di C.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

bool e10 (int n, int m, string **a, int k, int z, char **c, short w);

int main ()
{    
    int n=5,m=3;
    int k=2,z=2;
    short w=1;
    
    string **a = new string *[n];
    for(int i=0;i<n;i++)
    a[i]=new string[m];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            a[i][j]="ciao";
            cout << a[i][j] << "\t\t";
        }
        cout << "\n";
    }

    char **c = new char *[k];
    for(int i=0;i<n;i++)
    c[i]=new char[z];
    
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<z;j++)
        {
            c[i][j] = 'a';
            //c[i][j] = rand()%(122-97 + 1) + 97;
            cout << c[i][j] << "\t\t";
        }
        cout << "\n";
    }


   
    if( e10 (n,m,a,k,z,c,w) ) cout << "\n\nok";

    delete a;
    delete c;

}

bool e10 (int n, int m, string **a, int k, int z, char **c, short w){
    short contatore=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            for(int g=0; g<a[i][j].length(); g++){
                char carattere;
                for(int ii=0; ii<k; ii++){
                    for(int jj=0; jj<z; jj++){
                        carattere = c[ii][jj]; 
                        cout << "\n" << carattere << " " << a[i][j][g];
                    }
                }
                if( a[i][j][g] == carattere ){
                    contatore++; 
                    cout << "" << contatore;
                }
            }
            if (contatore >= w) return true;
            contatore=0;
        }
    }
    return false;
}