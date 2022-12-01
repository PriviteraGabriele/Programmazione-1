#include<iostream>
#include<cmath>
using namespace std;

class Rettangolo{
    public:
    double b;          //base
    double a;          //altezza

    double Area(){
        return (b*a)*2;
    }

    double Perimetro(){
        return (b+a)*2;
    }

};

class Cerchio{
    public:
    double r;          //raggio

    double Area(){
        return r*r*3.14;
    }

    double Perimetro(){
        return 2*r*3.14;
    }

    bool encloses(Rettangolo rettangolo1){
        double i = sqrt((rettangolo1.b*rettangolo1.b)+(rettangolo1.a*rettangolo1.a));
        if(i <= (r*2)){
            return true;
        }
        return false;
    }
};

int main(){
    cout << endl << "La mia classe rettangolo" << endl;
    Rettangolo rettangolo1;

    //imposto valori rettangolo
    rettangolo1.b = 5;
    rettangolo1.a = 7;

    cout << "L'area del mio rettangolo vale: " << rettangolo1.Area() << endl;
    cout << "Il perimetro del mio rettangolo vale: " << rettangolo1.Perimetro() << endl;
    cout << endl;

    cout << "La mia classe Cerchio" << endl;
    Cerchio cerchio1;

    //imposto valori cerchio
    cerchio1.r = 3;

    cout << "L'area del mio cerchio vale: " << cerchio1.Area() << endl;
    cout << "Il perimetro del mio cerchio vale: " << cerchio1.Perimetro() << endl;
    cout << endl;

    cout << "Il mio rettangolo è completamente contenuto all'interno del cerchio? ";
    if(cerchio1.encloses(rettangolo1)){
        cout << "Si" << endl;
    }
    else{
        cout << "No" << endl;
    }
}