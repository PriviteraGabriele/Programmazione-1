/* Si costruisca una classe Cerchio che metta a disposizione metodi per calcolare il perimetro e l’area. */

#include<iostream>
using namespace std;

class Cerchio{
    public:
    int r;
    int Area(){
        return r*r*3.14;
    }
    int Perimetro(){
        return 2*r*3.14;
    }
};

int main(){
    cout << "La mia classe Cerchio" << endl;
    Cerchio cerchio1;
    Cerchio cerchio2;

    //imposto valori
    cerchio1.r = 3;
    cerchio2.r = 5;

    cout << "L'area del mio primo cerchio vale: " << cerchio1.Area() << endl;
    cout << "L'area del mio secondo cerchio vale: " << cerchio2.Area() << endl;
    cout << "Il perimetro del mio primo cerchio vale: " << cerchio1.Perimetro() << endl;
    cout << "Il perimetro del mio secondo cerchio vale: " << cerchio2.Perimetro() << endl;

}
