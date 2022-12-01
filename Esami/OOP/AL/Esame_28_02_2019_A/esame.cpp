#include<iostream>
#include<typeinfo>      //Per info delle classi (?)
#include<climits>       //Per massimi e minimi
#include<cmath>         //Per funzioni matematiche
#include<cstdlib>
#include<string>

#define DIM 50

using namespace std;

class A {
    private:
        short* arr;
        short len;

    public:
        A(short m){
            len = m;
            arr = new short[len];
            for(int i = 0; i<len; i++){
                arr[i] = rand() % 10 + 1;       //numeri compresi tra 1 e 10
            }
        }

        virtual double f(short a) = 0;          //Bisogna sempre porlo uguale a 0 (Perchè è come se dico che esiste ma non fa niente)

        short getLen(){
            return len;
        }

        virtual ostream& put(ostream& os) = 0;      //Overloading dell'operatore di stampa

    protected:
        short get(short i){
            return arr[i%len];
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

template<class T>       //abbiamo creato una classe B, figlia della classe A, col template
class B : public A {
    private:
        T x;

    public:
        B(short m, char c) : A::A(m){        //Richiamo il costruttore della classe madre con uno scoop     
            if(typeid(x) == typeid(char)){      //Controllo se il tipo di x è un char
                x = c;
            }
            else{
                for(int i = 0; i<m; i++){
                    x += c;
                }
            }
        }

        double f(short a){
            double media = 0;
            int count = 0;
            for(int i = a%A::getLen(); i<A::getLen(); i++){
                media += A::get(i);
                count++;
            }
            return media/count;
        }

        double foo(short s){
            return log(s) + sin(f(s));
        }

        ostream& put(ostream& os){
            if(typeid(x) == typeid(char)){
                os << "B<char>";
            }
            else{
                os << "B<string>";
            }
            os << " arr=[";
            for(int i = 0; i<A::getLen(); i++){
                os << A::get(i) << " ";
            }
            os << "], x=" << x << ", f(3)=" << f(3);
            return os;
        }
};

class C : public A {
    private:
        int y;

    public:
        C(short n, int k) : A::A(n){
            y = k;
        }

        double f(short a){
            short r = A::get(rand() % A::getLen());
            return ((double)(a + y))/r;
        }

        double g(short w){
            return sin(w + y);
        }

        C* operator++(){       //Overloading dell'operatore prefisso "++"
            ++y;
            return this;
        }

        ostream& put(ostream& os){
            os << "C arr=[";
            for(int i = 0; i<A::getLen(); i++){
                os << A::get(i) << " ";
            }
            os << "], y=" << y << ", f(3)=" << f(3);
            return os;
        }
};

int main(){
    srand(111222333);

    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        switch (rand() % 3)
        {
        case 0:
            vett[i] = new C(n, rand() % 10 + 1);
            break;
        case 1:
            vett[i] = new B<string>(n, rand() % ('z' - 'a' + 1) + 'a');
            break;
        case 2:
            vett[i] = new B<char>(n, rand() % ('z' - 'a' + 1) + 'a');
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double max = INT_MIN;
    double media = 0;
    for(int i = 0; i<DIM; i++){
        if(max < vett[i]->f(3)){
            max = vett[i]->f(3);
        }
        if(typeid(C) == typeid(*vett[i])){
            media += (dynamic_cast<C*>(vett[i]))->g(5);
        }
    }
    cout << "Max(f(3))= " <<  max << ", avg(g(5))= " << media/DIM << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vett[48] << endl;
    cout << *(++(*((dynamic_cast<C*>)(vett[48])))) << endl;
}