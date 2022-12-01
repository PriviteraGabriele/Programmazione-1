#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
    int a = 1;
    int b = 6;

    srand(time(0));

    // Tiro i due dadi del giocatore 1
    int dado11 = rand() % (b-a+1)+a;
    int dado12 = rand() % (b-a+1)+a;

    // Tiro i due dadi del giocatore 2
    int dado21 = rand() % (b-a+1)+a;
    int dado22 = rand() % (b-a+1)+a;

    
    if (dado11+dado12 > dado21+dado22) {
        cout << "Il vincitore e' il giocatore 1 con il punteggio "<<dado11+dado12 << " contro " << dado21+dado22;
    } else if (dado11 + dado12 < dado21 + dado22) {
        cout << "Il vincitore e' il giocatore 2 con il punteggio "<<dado21+dado22 << " contro " << dado11+dado12;
    } else {
        cout << "Pari! Entrambi i giocatori hanno ottenuto un punteggio pari a " << dado11+dado12;
    }
}