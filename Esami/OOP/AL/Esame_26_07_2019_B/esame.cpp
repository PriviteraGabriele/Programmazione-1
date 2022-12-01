#include<iostream>
#include<cstdlib>
#include<cmath>
#include<typeinfo>
#include<climits>
#define DIM 50

using namespace std;

class A {
    private:
        int *vec;
        short len;

    protected:
        int get(short i){
            return vec[i % len];
        }

    public:
        A(short m, int a, int b){
            vec = new int[m];
            for(int i = 0; i<m; i++){
                vec[i] = rand() % (b - a + 1) + a;
            }
            len = m;
        }

        virtual double foo(short a) = 0;

        short getLen(){
            return len;
        }

        //Punto 1
        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", vec=[";
            for(int i = 0; i<len; i++){
                os << vec[i] << " ";
            }
            os << "], ";
            return os;
        }

        //Punto 3, Overloading dell'operatore ()
        int operator()(int i1, int i2){
            int somma = 0;
            for(int i = i1; i<=i2; i++){
                somma += vec[i];
            }
            return somma;
        }
};

//Punto 1 (Overloading dell'operatore <<)
ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        int p;

    protected:
        int prod(short s){
            int prodotto = 1;
            for(int i = s; i<A::getLen(); i++){
                prodotto *= A::get(i);
            }
            return prodotto;
        }

    public:
        B(short m, int x, int y) : A(m, x, y){
            p = A::get(rand() % (A::getLen()));
        }

        double foo(short a){
            return prod(a)/(double)p;           //Bisogna fare il cast a uno dei due membri
        }

        //Punto 1
        ostream& put(ostream& os){
            A::put(os);
            os << "p=" << p << ", foo(3)=" << foo(3);
            return os;
        }
};

template<typename T>
class C : public A {
    private:
        T x;

    public:
        C(short n, int a, int b) : A(n, a, b){
            if(typeid(x) == typeid(short)){
                x = n;
            }
            else{
                x = log(1 + pow(sin(n), 2));
            }
        }

        T g(T k){
            return 2*x*(k+1);
        }

        double foo(short r){
            return g(r);
        }

        //Punto 1
        ostream& put(ostream& os){
            A::put(os);
            os << "x=" << x << ", foo(3)=" << foo(3);
            return os;
        }
};

int main(){
    srand(111222333);

    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        switch (rand() % 3){
        case 0:
            vett[i] = new B(n, rand() % 5 + 1, rand() % 10 + 5);
            break;
        case 1:
            vett[i] = new C<double>(n, rand() % 5 + 1, rand() % 10 + 5);
            break;
        case 2:
            vett[i] = new C<short>(n, rand() % 5 + 1, rand() % 10 + 5);
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    int max = 0;
    double somma = 0;
    int counter = 0;
    for(int i = 0; i<DIM; i++){
        if(vett[i]->foo(3) > max){
            max = vett[i]->foo(3);
        }

        if(typeid(*vett[i]) == typeid(C<double>)){
            somma += ((C<double>*)(vett[i]))->g(5);
            counter++;
        }
    }
    cout << "Max=" << max << ", Avg=" << somma/counter << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << "vett[10]=" << *vett[10] << endl;
    cout << "vett[10](2, 3)=" << (*vett[10])(2, 3) << endl;

}