/* Si costruisca una classe “Persona” che abbia gli attributi:

string: nome: contiene il nome della persona;

string: cognome: contiene il cognome della persona;

int: eta: contiene l’età della persona;

e i seguenti metodi:

Persona(): il costruttore: deve prendere in input i parametri appropriati per costruire l’oggetto inizializzando gli attributi;

saluta(): stampa a schermo un testo a caso tra “Buongiorno”, “Buonasera” e “Ciao”;

dici_nome(): stampa a schermo il testo “Mi chiamo nome cognome”, dove nome e cognome sono i valori degli omonimi attributi;

dici_eta(): stampa a schermo il testo “La mia eta’ e’: eta”, dove eta è il valore dell’attributo eta;

invecchia(): incrementa l’età di una unità;

saluta_persona(): prende in input un oggetto di tipo Persona e stampa il testo “saluto nome cognome, piacere di conoscerti”, 
dove nome e cognome sono i valori degli omonimi attributi dell’oggetto Persona preso in input, mentre saluto è uguale a 
“Buongiorno” se l’età della persona salutata è superiore all’età della persona che saluta, “Ciao” altrimenti.

La classe dovrà contenere inoltre i metodi setter e getter per ciascun attributo.

Definire quindi un main che costruisca più oggetti persona e li faccia interagire. */

#include<iostream>
using namespace std;

class Persona{
    private:
    string nome;
    string cognome;
    int eta;
    public:
    Persona(string x, string y, int z) : nome(x), cognome(y), eta(z){}

    string getnome() {return nome;}
    string getcognome() {return cognome;}
    int geteta() {return eta;}

    void saluta(){
        int random = rand()%3;
        if(random == 0){
            cout << "Buongiorno." << endl;
        }
        else if(random == 1){
            cout << "Buonasera." << endl;
        }
        else{
            cout << "Ciao." << endl;
        }
    }

    void chi_parla(){               //extra
        cout << nome << ": ";
    }

    void dici_nome(){
        cout << "Mi chiamo " << nome << " " << cognome << "." << endl;
    }
    void dici_eta(){
        cout << "La mia età è " << eta << "." << endl;
    }
    void invecchia(){
        eta++;
    }
    void saluta_persona(Persona persona1){
        if(eta >= persona1.geteta()){
            cout << "Ciao " << persona1.getnome() << " " << persona1.getcognome() << ", piacere di conoscerti!" << endl;
        }
        else{
            cout << "Buongiorno " << persona1.getnome() << " " << persona1.getcognome() << ", piacere di conoscerti!" << endl;
        }
    }
};

int main(){
    srand(time(NULL)); 

    int n = 4;
    Persona *p[n];

    p[0] = new Persona("Saro", "Cacocciola", 40);
    p[1] = new Persona("Lucio", "Vespa", 34);
    p[2] = new Persona("Nino", "Mexican", 28);
    p[3] = new Persona("Jessica", "Stock", 22);

    for(int i = 0; i<n; i++){
        p[i]->chi_parla(); p[i]->saluta();
        p[i]->chi_parla(); p[i]->dici_nome();
        p[i]->chi_parla(); p[i]->dici_eta();
        p[i]->invecchia();
        p[i]->chi_parla(); p[i]->dici_eta();
        p[i]->chi_parla(); p[i]->saluta_persona(*p[n-i-1]);
        cout << endl;
    }
}