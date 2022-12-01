/* Realizzare una classe cellulare, ogni cellulare contiene una batteria, ogni batteria è caratterizzata 
dalla capacità di carica (misurata in unità intere u) e dal livello di carica. Con il cellulare si possono 
mandare sms e fare telefonate, ovviamente entrambe queste cose vanno a incidere sul livello della batteria, 
un sms consuma un’unità di carica una chiamata consuma un’unità di carica ogni 5 secondi (approssimando per eccesso).
Ovviamente si può sapere il livello di carica del cellulare. Implementare le classi con tutti i metodi che 
si ritiene opportuno al fine di simulare gli oggetti reali. Dopo aver realizzato le classi provarle. */

#include<iostream>
using namespace std;

class Batteria{
    private:
    int capacita_di_carica;
    int livello_carica;

    public:
    Batteria(int x, int y) : capacita_di_carica(x), livello_carica(y) {}

    int getCapacita(){
        return capacita_di_carica;
    }

    void setCapacita(int x){
        capacita_di_carica = x;
    }

    int getLivello(){
        return livello_carica;
    }

    void setLivello(int y){
        livello_carica = y;
    }
};


class Cellulare{
    private:
    Batteria *batteria;

    public:
    Cellulare(Batteria* batteria1) : batteria(batteria1) {}

    void Chiamata(int tempo){
        cout << "- Ho fatto una chiamata da " << tempo << "  secondi a Tizio." << endl;
        int consumo = tempo/5;
        batteria->setLivello(batteria->getLivello() - consumo);
    }

    void Messaggio(int n){
        cout << "- Ho invianto " << n << " messaggi a Tizio." << endl;
        batteria->setLivello(batteria->getLivello() - n);
    }

    int BatteriaResidua(){
        return batteria->getLivello();
    }

    void Youtube(int tempo){
        cout << "- Ho guardando un video di " << tempo << " secondi su Youtube." << endl;
        int consumo = tempo/2;
        batteria->setLivello(batteria->getLivello() - consumo);
    }

    void Internet(int tempo){
        cout << "- Ho navigando su internet per " << tempo << " secondi." << endl;
        int consumo = tempo/3;
        batteria->setLivello(batteria->getLivello() - consumo);
    }

    void Caricabatterie(int tempo){
        cout << "+ Ho caricato il mio telefono per " << tempo << " secondi." << endl;
        int carica = tempo/2;
        batteria->setLivello(batteria->getLivello() + carica);
    }
};

int main(){

    Batteria *batteria;
    batteria = new Batteria(3200, 100);

    Cellulare *cellulare;
    cellulare = new Cellulare(batteria);

    cout << "*Batteria residua: " << cellulare->BatteriaResidua() << " %" << endl;
    cellulare->Chiamata(25);
    cout << "*Batteria residua: " << cellulare->BatteriaResidua() << " %" << endl;
    cellulare->Messaggio(7);
    cout << "*Batteria residua: " << cellulare->BatteriaResidua() << " %" << endl;
    cellulare->Youtube(80);
    cout << "*Batteria residua: " << cellulare->BatteriaResidua() << " %" << endl;
    cellulare->Internet(22);
    cout << "*Batteria residua: " << cellulare->BatteriaResidua() << " %" << endl;
    cellulare->Caricabatterie(100);
    cout << "*Batteria residua: " << cellulare->BatteriaResidua() << " %" << endl;
}


