/* Si utilizzino le classi Dado e Mazzo per costruire un programma che simuli un gioco con tre giocatori in cui:

Ad ogni turno i tre giocatori tirano un dado a testa. Chi ottiene il numero più 
alto sarà il primo a pescare una carta. Se due o più giocatori hanno ottenuto lo 
stesso numero, questi tirano nuovamente i dadi finché non viene stabilito un 
ordine univoco tra i tre giocatori;

I giocatori pescano una carte a testa dal mazzo nell’ordine indicato dalla mano 
di dadi e sommano il valore della carta al proprio punteggio;

Il gioco va avanti così per 10 mani. Vince il giocatore che ha ottenuto il punteggio totale maggiore. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Dado{
    private:
    int valore;
    public:
    Dado(){}

    int getValore(){
        return valore;
    }

    void Lancia(){
        cout << "Lancio il dado...  ";
        valore = (rand()%6)+1;
    }
};

class Mazzo{
    private:
    bool m[40];
    public:
    Mazzo(){
        for(int i = 0; i<40; i++){
            m[i] = true;
        }
    }

    bool getMazzo(){return m;}

    int PescaCarta(){
        int rdm;
        do{
            rdm = rand()%40;
            if(m[rdm]){
                m[rdm] = false;
                return rdm+1;
            }
        }
        while(m[rdm] == false);
        return -1;
    }
};

class Persona{
    private:
    string nome;
    int punteggio;
    public:
    Persona(string q, int w) : nome(q), punteggio(w){}

    string getnome() {return nome;} 
    int getpunteggio() {return punteggio;}

    void setPunteggio(int temp){
        punteggio += temp;
    }
};

int main(){
    srand(time(NULL));

    int n = 3;
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    int primo = 0;
    int secondo = 0;
    int terzo = 0;
    Persona *p[n];

    p[0] = new Persona("Kevini", 0);
    p[1] = new Persona("Jonatha", 0);
    p[2] = new Persona("justin", 0);

    Dado *dado1;
    dado1 = new Dado();
    Dado *dado2;
    dado2 = new Dado();
    Dado *dado3;
    dado3 = new Dado();
    Mazzo *mazzo1;
    mazzo1 = new Mazzo();


    //Inizio gioco
    for(int i = 0; i<10; i++){
        //Tiro dado per selezionare l'ordine di inizio della pesca
        do{
            cout << p[0]->getnome() << ": "; dado1->Lancia(); cout << dado1->getValore() << endl;
            cout << p[1]->getnome() << ": "; dado2->Lancia(); cout << dado2->getValore() << endl;
            cout << p[2]->getnome() << ": "; dado3->Lancia(); cout << dado3->getValore() << endl;
            if(dado1->getValore() > dado2->getValore()){
                if(dado1->getValore() > dado3->getValore()){
                    primo = 0;
                    if(dado2->getValore() > dado3->getValore()){
                        secondo = 1;
                        terzo = 2;
                    }
                    else{
                        secondo = 2;
                        terzo = 1;
                    }
                }
                else{
                    primo = 2;
                    secondo = 0; 
                    terzo = 1;
                }
                cout << "L'ordine della pescata è: " << p[primo]->getnome() << ", " << p[secondo]->getnome() << ", " << p[terzo]->getnome() << endl;
            }
            else if(dado1->getValore() < dado2->getValore()){
                if(dado2->getValore() > dado3->getValore()){
                    primo = 1;
                    if(dado1->getValore() > dado3->getValore()){
                        secondo = 0;
                        terzo = 2;
                    }
                    else{
                        secondo = 2;
                        terzo = 0;
                    }
                }
                else{
                    primo = 2;
                    secondo = 1;
                    terzo = 0;
                }
                cout << "L'ordine della pescata è: " << p[primo]->getnome() << ", " << p[secondo]->getnome() << ", " << p[terzo]->getnome() << endl;
            }
            else if(dado2->getValore() > dado3->getValore()){
                if(dado2->getValore() > dado1->getValore()){
                    primo = 1;
                    if(dado1->getValore() > dado3->getValore()){
                        secondo = 0;
                        terzo = 2;
                    }
                    else{
                        secondo = 2;
                        terzo = 0;
                    }
                }
                else{
                    primo = 0;
                    secondo = 1;
                    terzo = 2;
                    }
                }
                cout << "L'ordine della pescata è: " << p[primo]->getnome() << ", " << p[secondo]->getnome() << ", " << p[terzo]->getnome() << endl;
            }
            else if(dado2->getValore() < dado3->getValore()){
                if(dado3->getValore() > dado1->getValore()){
                    primo = 2;
                    if{dado1->getValore() > dado2->getValore()}{
                        secondo = 0;
                        terzo = 1;
                    }
                    else{
                        secondo = 1;
                        terzo = 0;
                    }
                }
                else{
                    primo = 0;
                    secondo = 2;
                    terzo = 1;
                }
                cout << "L'ordine della pescata è: " << p[primo]->getnome() << ", " << p[secondo]->getnome() << ", " << p[terzo]->getnome() << endl;
            }     
        }
        while(dado1->getValore() == dado2->getValore() && dado2->getValore() == dado3->getValore() || dado1->getValore() == dado2->getValore() || dado2->getValore() == dado3->getValore() || dado1->getValore() > dado3->getValore());
        //Pesca della carta e salvataggio punteggio
        temp1 = mazzo1->PescaCarta();
        p[primo]->setPunteggio(temp1);
        cout << p[primo]->getnome() << ": Pesco la carta...  " << temp1 << endl;
        
        temp2 = mazzo1->PescaCarta();
        p[secondo]->setPunteggio(temp2);
        cout << p[secondo]->getnome() << ": Pesco la carta...  " << temp2 << endl;

        temp3 = mazzo1->PescaCarta();
        p[terzo]->setPunteggio(temp3);
        cout << p[terzo]->getnome() << ": Pesco la carta...  " << temp3 << endl;
        cout << endl;
    }

    //Controllo vincitore

    if(p[primo]->getpunteggio() > p[secondo]->getpunteggio()){
        if(p[primo]->getpunteggio() > p[terzo]->getpunteggio()){        
            if(p[secondo]->getpunteggio() > p[terzo]->getpunteggio()){
                cout << "La classifica è: " << p[primo]->getnome() << ", " << p[secondo]->getnome()<< ", " << p[terzo]->getnome() << ".     " << p[primo]->getpunteggio() << " vs " << p[secondo]->getpunteggio() << " vs " << p[terzo]->getpunteggio() << endl;
                        primo = 0;
                        secondo = 1;
                        terzo = 2;
                    }
                    else{
                        secondo = 2;
                        terzo = 1;
                    }
                }
                else{
                    primo = 2;
                    secondo = 0; 
                    terzo = 1;
                }
                cout << "L'ordine della pescata è: " << p[primo]->getnome() << ", " << p[secondo]->getnome() << ", " << p[terzo]->getnome() << endl;
            }
            else if(dado1->getValore() < dado2->getValore()){
                if(dado2->getValore() > dado3->getValore()){
                    primo = 1;
                    if(dado1->getValore() > dado3->getValore()){
                        secondo = 0;
                        terzo = 2;
                    }
                    else{
                        secondo = 2;
                        terzo = 0;
                    }
                }
                else{
                    primo = 2;
                    secondo = 1;
                    terzo = 0;
                }
            }
            else if(dado2->getValore() > dado3->getValore()){
                if(dado2->getValore() > dado1->getValore()){
                    primo = 1;
                    if(dado1->getValore() > dado3->getValore()){
                        secondo = 0;
                        terzo = 2;
                    }
                    else{
                        secondo = 2;
                        terzo = 0;
                    }
                }
                else{
                    primo = 0;
                    secondo = 1;
                    terzo = 2;

                    }
                }
            }
            else if(dado2->getValore() < dado3->getValore()){
                if(dado3->getValore() > dado1->getValore()){
                    primo = 2;
                    if{dado1->getValore() > dado2->getValore()}{
                        secondo = 0;
                        terzo = 1;
                    }
                    else{
                        secondo = 1;
                        terzo = 0;
                    }
                }
                else{
                    primo = 0;
                    secondo = 2;
                    terzo = 1;
                }
            }     
        }

    if(p[primo]->getpunteggio() > p[secondo]->getpunteggio()){
        if(p[primo]->getpunteggio() > p[terzo]->getpunteggio()){

        }
        cout << "Il vincitore è: " << p[primo]->getnome() << "!      " << p[primo]->getpunteggio() << " vs " << p[secondo]->getpunteggio() << endl;
    }
    else if(p[primo]->getpunteggio() < p[secondo]->getpunteggio()){
        cout << "Il vincitore è: " << p[secondo]->getnome() << "!      " << p[secondo]->getpunteggio() << " vs " << p[primo]->getpunteggio() << endl;
    }
    else{
        do{
            cout << p[0]->getnome() << ": "; dado1->Lancia(); cout << dado1->getValore();
            cout << p[1]->getnome() << ": "; dado2->Lancia(); cout << dado2->getValore();
            primo = 0;
            secondo = 0;
            if(dado1->getValore() > dado2->getValore()){
                primo = 0;
                secondo = 1;
                cout << "Pesca per primo " << p[0]->getnome() << endl;
            }
            else{
                primo = 1;
                secondo = 0;
                cout << "Pesca per primo " << p[1]->getnome() << endl;
            }
        }
        while(dado1->getValore() == dado2->getValore());
        int extra1 = mazzo1->PescaCarta();
        int extra2 = mazzo1->PescaCarta();
        if(extra1 > extra2){
            cout << "Il vincitore è: " << p[primo]->getnome() << "!      " << p[primo]->getpunteggio() + extra1 << " vs " << p[secondo]->getpunteggio() + extra2 << endl;
        }
        else{
            cout << "Il vincitore è: " << p[secondo]->getnome() << "!      " << p[secondo]->getpunteggio() + extra2 << " vs " << p[primo]->getpunteggio() + extra1 << endl;
        }
    }
}