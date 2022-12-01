#include<iostream>
using namespace std;

class Cerchio{
    public:
    float raggio;
    float Area();
    Cerchio();
    Cerchio(float);
};

Cerchio::Cerchio(){
    raggio = 1;
}

Cerchio::Cerchio(float r){
    raggio = r;
}

float Cerchio::Area(){
    return raggio * raggio * 3.14;
}

class Cilindro: public Cerchio{
    public:
    float altezza;
    float Volume();
    Cilindro();
    Cilindro(float, float);
};

Cilindro::Cilindro(){
    altezza = 1;
}

Cilindro::Cilindro(float r, float h){
    raggio = r; 
    altezza = h;
}

float Cilindro::Volume(){
    return raggio * raggio * 3.14 * altezza;
}

int main(){
    
    Cilindro cilindro1;
    Cilindro cilindro2(2, 2);

    cout << "I DUE CILINDRI" << endl << endl;

    cout << "L'area della base del primo cilindro è: " << cilindro1.Area() << endl;
    cout << "Il volume del primo cilindro è: " << cilindro1.Volume() << endl << endl;

    cout << "L'area della base del secondo cilindro è: " << cilindro2.Area() << endl;
    cout << "Il volume del secondo cilindro è: " << cilindro2.Volume() << endl;
}

