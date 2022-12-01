/* Scrivere una funzione che prenda in input una matrice quadrata A 
di short, e restituisca un bool che indichi se la diagonale principale è 
identica (procedendo dall’alto verso il basso) alla secondaria. */

#include<iostream>
using namespace std;

int main(){

    short A[][4] = {1,0,0,1,0,2,2,0,0,3,3,0,4,0,0,4};

	//Stampo tutti i valori della matrice
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(j!=3){
                cout << A[i][j] << " ";
            }
            else{
                cout << A[i][j] << endl;
            }
        }
    }
    cout << endl;

    short W[4] = {0};
	short K[4] = {0};
	bool diag = true;

	//Copia della diagonale principale, partendo dall'alto verso il basso, nell'Array W
	for(int i = 0; i<4; i++){
		for(int j = 0; j<4; j++){
			W[i] = A[i][i];
		}
	}

	//Stampa Array
	for(int i = 0; i<4; i++){
		cout << W[i] << "  ";
	}
	cout << endl;

	//Copia della diagonale secondaria, partendo dall'alto verso il basso, nell'Array K
	for(int i = 0; i<4; i++){
		for(int j = 3; j<=0; j--){
			K[i] = A[i][j];
		}
	}
	
	//Stampa Array
	for(int i = 0; i<4; i++){
		cout << K[i] << "  ";
	}
	cout << endl;

	//Controllo delle diagonali
	for(int i = 0; i<4; i++){
		if(W[i]!=K[i]){
			diag = false;
            cout << "La diagonale principale non è identica alla secondaria!\n";
			return 0;
		}
	}
    cout << "La diagonale principale è identica alla secondaria!\n";
		
    return 0;
}