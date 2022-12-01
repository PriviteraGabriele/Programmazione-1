/* Si costruisca una classe Moneta che implementi una moneta a due facce. Il costruttore prende in 
input un double p e controlla che questa sia compreso tra 0 e 1. Quando la moneta viene lanciata, 
uscirà “testa” con probabilità p e “croce” con probabilità 1−p. Prevedere un costruttore che non 
prende in input alcun parametro e imposta p = 0.5. Costruire un programma che crei due monete con 
probabilità p casuali, le lanci 1000 volte e mostri, le probabilità assegnate e il numero di teste 
ottenute da entrambe le monete.

NOTA: Un modo semplice per eseguire una riga di codice con probabilità p è il seguente:

double rnd = double(rand())/RAND_MAX;
if(rnd>p) {
    //codice
} */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Moneta{
    public:
    double p;
    Moneta(double p){
        if(p >= 0 && p <= 1){
            this->p = p;
        }
    }
    Moneta(){
        p = 0.5;
    }
    void Lancia(){
        double random = (double)rand()/RAND_MAX;
        //cout << "***random = " << random << endl;
        if(random > p){
            cout << "Testa" << endl;
        }
        else{
            cout << "Croce" << endl;
        }
    }
};

int main(){
    Moneta *moneta1;
    Moneta *moneta2;
    
    srand(time(NULL));
    for(int i = 0; i<100; i++){
        double p1 = (double)rand()/RAND_MAX;
        cout << "p1 = " << p1 << endl;
        moneta1 = new Moneta(p1);
        moneta1->Lancia();
        double p2 = (double)rand()/RAND_MAX;
        cout << "p2 = " << p2 << endl;
        moneta2 = new Moneta(p2);
        moneta2->Lancia();
        cout << endl;
    }
}

