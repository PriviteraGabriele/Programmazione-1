#include <iostream>
#include <string>
#define n 2

using namespace std;

void func (string ***A){
	
	cout<<"Matrice di puntatori a stringhe : "<<endl;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			for (int k=0; k<5; k++){
				cout<<(*A[i][j])[k]<<" ";
			}
			cout<<endl;
		}
	}
	
	
}

int main(){
	
	string ** *A = new string **[n];  //array esterno
	
	for (int i=0; i<n; i++){
		A[i] = new string * [n];  //array interno
		
		for (int j=0; j<n; j++){
			A[i][j] = new string ;  
			cout<<"Inserisci stringa: "<<endl;
            cin>>*A[i][j];
		}
	}
	
	func (A);
}