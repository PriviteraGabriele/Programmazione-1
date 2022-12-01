/* Creare una classe Matita che serve per rappresentare delle matite e memorizzarne la lunghezza.
Creare una sottoclasse MatitaConGommino che serve per rappresentare delle matite con gommino, la 
classe memorizza le caratteristiche delle matite e il numero cancellature rimaste a disposizione 
tramite il gommino (tali matite partono con 10 possibilità di cancellature). Creare le classi e provarle. */

#include<iostream>
using namespace std;

class Matita{

    public:
    int lunghezza;

    Matita(int x) : lunghezza(x){}

    int getLunghezza(){
        return lunghezza;
    }

    void Scrivi(){
        cout << "Scrivo!" << endl;
    }

    void TemperaMatita(){
        cout << "Tempero la matita!" << endl;
        lunghezza--;
    }

};

class MatitaConGommino : public Matita{
    
    public:
    int cancellatura;

    //MatitaconGommino(int x, int y) : lunghezza(x), cancellatura(y){}
    MatitaconGommino(int , int);

    int getCancellatura(){
        return cancellatura;
    }

    void Cancella(){
        cout << "Errore cancellato!" << endl;
        cancellatura--;
    }

};

MatitaConGommino::MatitaConGommino(int x, int y){

    lunghezza = x;
    cancellatura = y;
}

int main(){

    Matita *m1;
    m1 = new Matita(20);

    m1->getLunghezza();
}