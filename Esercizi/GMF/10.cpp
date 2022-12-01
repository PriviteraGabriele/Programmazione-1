/* [Esercizio 10] Scrivere un metodo che prenda in input un parametro formale matrice di stringhe A di dimensioni n × m,
una matrice di caratteri C di dimensioni k × z, uno short w e restituisca true se esiste almeno una riga o una colonna di A che
contiene almeno una sequenza contigua di w o piu’ caratteri che si trovano in una riga o in una colonna di C. */

#include<iostream>
using namespace std;

bool esercizio10(string** A, int n, int m, char** C, int k, int z, short w){
    int counter;
    //Scorro la Matrice A per riga
    for(int i = 0; i<n; i++){
        string main = "";
        for(int j = 0; j<m; j++){
            main += A[i][j];
        }
        //Scorro la matrice C per riga
        for(int a = 0; a<k; a++){
            string temp = "";
            for(int b = 0; b<z; b++){
                temp += C[a][b];
            }
            counter = 0;
            for(int x = 0; x < main.length(); x++){
                if(temp.find(main[x]) != string::npos){
                    counter++;
                    if(counter >= w){
                        return true;
                    }
                }
                else{
                    counter = 0;
                }
            }
        }
        //Scorro la matrice C per colonna
        for(int b = 0; b<z; b++){
            string temp = "";
            for(int a = 0; a<k; a++){
                temp += C[a][b];
            }
            counter = 0;
            for(int x = 0; x < main.length(); x++){
                if(temp.find(main[x]) != string::npos){
                    counter++;
                    if(counter >= w){
                        return true;
                    }
                }
                else{
                    counter = 0;
                }
            }
        }
    }
    //Scorro la Matrice A per colonna
    for(int j = 0; j<m; j++){
        string main = "";
        for(int i = 0; i<n; i++){
            main += A[i][j];
        }
        //Scorro la matrice C per riga
        for(int a = 0; a<k; a++){
            string temp = "";
            for(int b = 0; b<z; b++){
                temp += C[a][b];
            }
            counter = 0;
            for(int x = 0; x < main.length(); x++){
                if(temp.find(main[x]) != string::npos){
                    counter++;
                    if(counter >= w){
                        return true;
                    }
                }
                else{
                    counter = 0;
                }
            }
        }
        //Scorro la matrice C per colonna
        for(int b = 0; b<z; b++){
            string temp = "";
            for(int a = 0; a<k; a++){
                temp += C[a][b];
            }
            counter = 0;
            for(int x = 0; x < main.length(); x++){
                if(temp.find(main[x]) != string::npos){
                    counter++;
                    if(counter >= w){
                        return true;
                    }
                }
                else{
                    counter = 0;
                }
            }
        }
    }
    return false;
}

int main(){
    int n = 4; 
    int m = 4;
    int k = 3;
    int z = 3;
    short w = 2;
    
    string** A = new string*[n];
    for(int i = 0; i<n; i++){
        A[i] = new string[m];
    }

    A[0][0] = "casa";
    A[0][1] = "pane";
    A[0][2] = "cane";
    A[0][3] = "gene";
    A[1][0] = "amare";
    A[1][1] = "odiare";
    A[1][2] = "canzone";
    A[1][3] = "gioco";
    A[2][0] = "melodia";
    A[2][1] = "elden";
    A[2][2] = "monster";
    A[2][3] = "hunter";
    A[3][0] = "sekiro";
    A[3][1] = "dark";
    A[3][2] = "souls";
    A[3][3] = "ring";

    //Stampa Matrice A
    cout << "Matrice A:" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    char** C = new char*[k];
    for(int i = 0; i<k; i++){
        C[i] = new char[z];
    }

    C[0][0] = 'a';
    C[0][1] = 'p';
    C[0][2] = 'g';
    C[1][0] = 'h';
    C[1][1] = 'n';
    C[1][2] = 'h';
    C[2][0] = 's';
    C[2][1] = 'e';
    C[2][2] = 'a';

    //Stampa Matrice A
    cout << "Matrice C:" << endl << endl;
    for(int i = 0; i<k; i++){
        for(int j = 0; j<z; j++){
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    //Finisci main..

    if(esercizio10(A, n, m, C, k, z, w)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}