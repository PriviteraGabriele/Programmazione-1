/* Una stampante è caratterizzata dal livello di inchiostro delle singole cartucce C M Y K, 
le cartucce non possono essere ricaricate ma sostituite, la stampante permette di stampare 
singoli fogli (bisogna passando i livelli di inchiostro richiesti per la stampa di quel foglio), 
o più copie di uno stesso foglio, si può sempre verificare il livello di inchiostro di una cartuccia.
Ragionare su quali attributi e metodi sono presenti e sul codice dei metodi (in particolare si ragioni 
su come gestire le stampe soprattutto nel caso non ci sia inchiostro sufficiente).
Creare la classe e un main. */

#include<iostream>
using namespace std;

class Stampante{
    private:
    int C;
    int M;
    int Y;
    int K;

    public:
    Stampante(int x, int y, int z, int k) : C(x), M(y), Y(z), K(k){}

    void StampaBiancoNero(int n){
        cout << "Stampa in corso..." << endl;
        for(int i = 1; i<=n; i++){
            if(K-5 >= 0){
                K = K - 5;
                cout << i << "/" << n << endl;
            }
            else{
                cout << "Inchiostro insufficente, sostituire la cartuccia K (NERO)!" << endl;
                cout << endl;
                break;
            }
        }
        cout << endl;
    }

    void StampaColori(int n){
        cout << "Stampa in corso..." << endl;
        for(int i = 1; i<=n; i++){
            if(C-3 >= 0 && M-4 >= 0 && Y-2 >= 0 && K-1 >= 0){
                C = C - 3;
                M = M - 4;
                Y = Y - 2;
                K = K - 1;
                cout << i << "/" << n << endl;
            }
            else{
                cout << "Inchiostro insufficente, sostituire la cartuccia ";
                if(C-3 < 0){
                    cout << "C (CIANO)!" << endl;
                }
                if(M-4 < 0){
                    cout << "M (MAGENTA)!" << endl;
                }
                if(Y-2 < 0){
                    cout << "Y (GIALLO)!" << endl;
                }
                if(K-1 < 0){
                    cout << "K (NERO)!" << endl;
                }
                break;
            }
        }
        cout << endl;
    }

    void QuantitaInchiostro(){
        cout << "C (CIANO) = " << C << "%" << endl;
        cout << "M (MAGENTA) = " << M << "%" << endl;
        cout << "Y (GIALLO) = " << Y << "%" << endl;
        cout << "K (NERO) = " << K << "%" << endl;
        cout << endl;
    }

    void SostituzioneCartuccia(){
        if(C-3 < 0){
            C = 100;
            cout << "Cartuccia C (CIANO) sostituita!";
        }

        if(M-4 < 0){
            M = 100;
            cout << "Cartuccia M (MAGENTA) sostituita!";
        }

        if(Y-2 < 0){
            Y = 100;
            cout << "Cartuccia Y (GIALLO) sostituita!";
        }

        if(K-1 < 0 || K-5 < 0){
            K = 100;
            cout << "Cartuccia K (NERO) sostituita!";
        }
        cout << endl << endl;
    }
};

int main(){
    Stampante *s;
    s = new Stampante(100, 100, 100, 100);

    s->QuantitaInchiostro();
    s->StampaBiancoNero(2);
    s->StampaColori(3);
    s->StampaBiancoNero(5);
    s->QuantitaInchiostro();
    s->StampaColori(6);
    s->SostituzioneCartuccia();
    s->QuantitaInchiostro();
    s->StampaBiancoNero(2);
    s->StampaColori(3);
    s->StampaBiancoNero(5);
    s->QuantitaInchiostro();
    s->StampaColori(6);
    s->SostituzioneCartuccia();
    s->QuantitaInchiostro();
    s->StampaBiancoNero(2);
    s->StampaColori(3);
    s->SostituzioneCartuccia();
    s->QuantitaInchiostro();
    s->StampaBiancoNero(5);
    s->StampaColori(6);
    s->QuantitaInchiostro();
    s->SostituzioneCartuccia();
    s->QuantitaInchiostro();
}