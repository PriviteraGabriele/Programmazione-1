/* In un videogioco fantasy ci sono dei personaggi che posseggono delle armi.
Ogni arma è caratterizzata da una tipologia rappresentata da un carattere e da i punti danno che arreca.
Ogni personaggio ha un numero di punti ferita (compresi tra 20 e 50) e un numero di punti forza 
(calcolati come la somma del risultato di tre dadi a 6 facce) e inizialmente non possiede armi.
Quando si scontrano due personaggi bisogna calcolare quale dei due ha più punti combattimento 
che sono dati dalla somma dei punti forza e dei danni della propria arma, il personaggio che ha 
meno punti combattimento perde un numero di punti vita pari alla differenza tra i suoi punti 
combattimento e quelli dell’avversario, ma in ogni caso questi non possono essere superiori ai 
punti danno dell’arma dell’avversario.

Creare poi un programma che costruisce un personaggio e ne crea un secondo duplicato dal primo e poi un terzo.
In seguito assegna due armi una al primo e una al secondo e al terzo la stessa arma del primo.
In seguito fa scontrare il primo personaggio con il secondo, il secondo con il terzo e il terzo 
con il primo e stampa le condizioni dei personaggi. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Dado{
    private:
    int valore;
    public:
    Dado(){}

    void Lancia(){
        valore = (rand()%6)+1;
    }

    int getValore(){
        return valore;
    }
};

class Arma{
    private:
    string nome;
    char tipologia;
    int danno;
    public:
    Arma(string o, char y, int z) : nome(o), tipologia(y), danno(z){}

    string getNome() {return nome;}
    char getTipologia() {return tipologia;}
    int getDanno() {return danno;}
};

class Personaggio{
    private:
    string nome;
    int punti_ferita;
    int punti_forza;
    public:
    Personaggio(string p, int k, int l) : nome(p), punti_ferita(k), punti_forza(l){}

    string getNome() {return nome;}
    int getPuntiForza() {return punti_forza;}
    int getPuntiFerita() {return punti_ferita;}

    void setPuntiFerita(int v){
        punti_ferita = v;
    }

    void setPuntiForza(int n){
        punti_forza = n;
    }
};

int main(){
    srand(time(NULL));
    cout << "*Inizio Gioco*" << endl << endl;
    Dado *dado1;
    dado1 = new Dado();
    Dado *dado2;
    dado2 = new Dado();
    Dado *dado3;
    dado3 = new Dado();

    Arma *arma1;
    arma1 = new Arma("SpaccaCuli", 'S', 30);
    Arma *arma2;
    arma2 = new Arma("Ak77", 'A', 22);

    Personaggio *personaggio1;
    personaggio1 = new Personaggio("Pdor", 0, 0);
    Personaggio *personaggio2;
    personaggio2 = new Personaggio("Grillo", 0, 0);

    int a = 20;
    int b = 50;
    int vita1 = rand()%(b - a + 1) + a;
    personaggio1->setPuntiFerita(vita1);
    int danno1 = 0;
    dado1->Lancia();
    dado2->Lancia();
    dado3->Lancia();
    danno1 = dado1->getValore() + dado2->getValore() + dado3->getValore();
    personaggio1->setPuntiForza(danno1);
    cout << personaggio1->getNome() << ": " << endl;
    cout << "Punti Ferita = " << personaggio1->getPuntiFerita() << endl;
    cout << "Punti Forza = " << personaggio1->getPuntiForza() << endl;
    cout << endl;
    cout << "+ " << personaggio1->getNome() << " ottiene " << arma1->getNome() << endl;
    cout << endl;
    cout << arma1->getNome() << ": " << endl;
    cout << "Tipologia = " << arma1->getTipologia() << endl;
    cout << "Danno = " << arma1->getDanno() << endl;
    cout << "-----------------------------" << endl << endl;

    int vita2 = rand()%(b - a + 1) + a;
    personaggio2->setPuntiFerita(vita2);
    int danno2 = 0;
    dado1->Lancia();
    dado2->Lancia();
    dado3->Lancia();
    danno2 = dado1->getValore() + dado2->getValore() + dado3->getValore();
    personaggio2->setPuntiForza(danno2);
    cout << personaggio2->getNome() << ": " << endl;
    cout << "Punti Ferita = " << personaggio2->getPuntiFerita() << endl;
    cout << "Punti Forza = " << personaggio2->getPuntiForza() << endl;
    cout << endl;
    cout << "+ " << personaggio2->getNome() << " ottiene " << arma2->getNome() << endl;
    cout << endl;
    cout << arma2->getNome() << ": " << endl;
    cout << "Tipologia = " << arma2->getTipologia() << endl;
    cout << "Danno = " << arma2->getDanno() << endl;
    cout << "-----------------------------" << endl << endl;

    //Simulazione scontro
    int ferita = 0;
    cout << "*Battaglia*" << endl << endl;
    cout << personaggio1->getNome() << " vs " << personaggio2->getNome() << endl << endl;
    if(personaggio1->getPuntiForza() + arma1->getDanno() > personaggio2->getPuntiForza() + arma2->getDanno()){ 
        if((personaggio1->getPuntiForza() + arma1->getDanno() - personaggio2->getPuntiForza() - arma2->getDanno()) > arma1->getDanno()){
            ferita = personaggio2->getPuntiFerita() - arma1->getDanno();
            personaggio2->setPuntiFerita(ferita);
            cout << personaggio1->getNome() << " ha più punti combattimento! -----> " << personaggio2->getNome() << " danno subito: " << arma1->getDanno() << "  /  "<< personaggio2->getNome() << " Punti ferita rimanenti = " << personaggio2->getPuntiFerita()  << endl;

        }
        else{
            ferita = personaggio2->getPuntiFerita() - (personaggio1->getPuntiForza() + arma1->getDanno() - personaggio2->getPuntiForza() - arma2->getDanno());
            personaggio2->setPuntiFerita(ferita);
            cout << personaggio1->getNome() << " ha più punti combattimento! -----> " << personaggio2->getNome() << " danno subito: " << (personaggio1->getPuntiForza() + arma1->getDanno() - personaggio2->getPuntiForza() - arma2->getDanno()) << "  /  "<< personaggio2->getNome() << " Punti ferita rimanenti = " << personaggio2->getPuntiFerita() << endl;
        }
    }
    else if(personaggio1->getPuntiForza() + arma1->getDanno() < personaggio2->getPuntiForza() + arma2->getDanno()){
        if((personaggio2->getPuntiForza() + arma2->getDanno()) - (personaggio1->getPuntiForza() - arma1->getDanno()) > arma2->getDanno()){
            ferita = personaggio1->getPuntiFerita() - arma2->getDanno();
            personaggio1->setPuntiFerita(ferita);
            cout << personaggio2->getNome() << " ha più punti combattimento! -----> " << personaggio1->getNome() << " danno subito: " << arma2->getDanno() << "  /  " << personaggio1->getNome() << " Punti ferita rimanenti = " << personaggio1->getPuntiFerita() << endl;

        }
        else{
            ferita = personaggio1->getPuntiFerita() - (personaggio2->getPuntiForza() + arma2->getDanno() - personaggio1->getPuntiForza() - arma1->getDanno());
            personaggio1->setPuntiFerita(ferita);
            cout << personaggio2->getNome() << " ha più punti combattimento! -----> " << personaggio1->getNome() << " danno subito: " << (personaggio2->getPuntiForza() + arma2->getDanno() - personaggio1->getPuntiForza() - arma1->getDanno()) << "  /  "<< personaggio1->getNome() << " Punti ferita rimanenti = " << personaggio1->getPuntiFerita() << endl;
        }
    }
    else{
        cout << "Punti combattimento equivalenti!" << endl;
    }

}