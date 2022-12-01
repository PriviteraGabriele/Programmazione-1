/* Scrivere una classe Ora_giorno che permetta di rappresentare l’ora 
del giorno in ore e minuti (formato 24 ore). La classe deve sovraccaricare 
l’operatore << per stampare l’ora nel formato HH:MM e gli operatori ++ e -- 
(sia prefissi che postfissi) per incrementare/decrementare l’ora di minuti. */

#include<iostream>
using namespace std;

class Ora_giorno {
    private:
        int ora;
        int minuto;

    public:
        Ora_giorno(int _ora, int _minuto) : ora(_ora), minuto(_minuto) {}

        ostream& operator<<(ostream& out, const Ora_giorno )
};
