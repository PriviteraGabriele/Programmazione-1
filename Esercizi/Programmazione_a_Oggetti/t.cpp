#include<iostream>
using namespace std;

class Matita{
    public:
    int lunghezza;
    Matita();
    Matita(int);
    void Scrivi();
    void TemperaMatita();
    void Stato1();
};

Matita::Matita(){
    lunghezza = 20;
}

Matita::Matita(int x){
    lunghezza = x;
}

void Scrivi(){
    cout << "Scrivo!" << endl;
}

void TemperaMatita(){
    cout << "Tempero la matita!" << endl;
    lunghezza--;
}

void Stato1(){
    cout << "Lunghezza rimanente: " << lunghezza << endl;
}

class MatitaConGommino : public Matita{
    public:
    int cancellatura;
    MatitaConGommino();
    MatitaConGommino(int, int);
    void Cancella();
    void Stato2();
};

MatitaConGommino::MatitaConGommino(){
    cancellatura = 10;
}

MatitaConGommino::MatitaConGommino(int x, int y){
    lunghezza = x;
    cancellatura = y;
}

Void Cancella(){
    cout << "Errore cancellato!" << endl;
    cancellatura--;
}

void Stato2(){
    cout << "Lunghezza rimanente: " << lunghezza << endl;
    cout << "Cancellature rimanenti: " << cancellatura << endl;
}

int main(){

    MatitaConGommino gommino;

    gommino.Stato2();
    //gommino.Cancella();
    //gommino.Stato2();




}

