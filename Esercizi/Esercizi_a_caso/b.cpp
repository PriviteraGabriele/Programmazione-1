/* Scrivere una funzione che prenda in input una matrice quadrata A 
di short, e restituisca un bool che indichi se la diagonale principale è 
identica (procedendo dall’alto verso il basso) alla secondaria. */

#include<iostream>
#define n 4
using namespace std;

bool identica(int n, short A[][n]){

	short W[n] = {0};
	short K[n] = {0};
	bool diag = true;
	//Copia della diagonale principale, partendo dall'alto verso il basso, nell'Array W
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			W[i] = A[i][i];
		}
	}
	//Copia della diagonale secondaria, partendo dall'alto verso il basso, nell'Array K
	for(int i = n-1; i<=0; i--){
		for(int j = n-1; j<=0; j--){
			K[i] = A[i][i];
		}
	}
	for(int i = 0; i<n; i++){
		if(W[i]!=K[i]){
			diag = false;
			return diag;
		}
	}
	return diag;	
}