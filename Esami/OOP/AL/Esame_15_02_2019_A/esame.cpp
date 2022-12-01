#include<iostream>
#include<typeinfo>
#include<cmath>
#include<cstdlib>
#include<ctime>

#define DIM 50

using namespace std;

class A {
    private:
        double *w;
        short len;

    protected:
        double get(short i){
            return w[i%len];
        }

    public:
        A(short m){
            w = new double[m];
            for(int i = 0; i<m; i++){
                w[i] = (double)rand()/RAND_MAX;
            }
            len = m;
        }

        virtual double foo(short a) = 0;

        short getLen(){
            return len;
        }

        //Punto 1
        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", w=[";
            for(int i = 0; i<len; i++){
                os << w[i] << " ";
            }
            os << "], ";
            return os;
        }    

        //Punto 3
        double& operator[](short i){
            return w[i % len];
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
        double sum(short s){
            double somma = 0;
            for(int i = s; i<A::getLen(); i++){
                somma += A::get(i);
            }

            return somma;
        }

    public:
        B(short m, int x) : A(m){
            p = x;
        }

        double foo(short a){
            return sum(a)/p;
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
        C(short n) : A(n){
            if(typeid(n) == typeid(short)){
                x = n;
            }
            else{
                x = log(1+(sin(n))*2);
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
                vett[i] = new B(n, rand() % 10 + 1);
                break;
            case 1:
                vett[i] = new C<double>(n);
                break;
            case 2:
                vett[i] = new C<short>(n);
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double max = 0;
    double somma = 0;
    int count = 0;
    for(int i = 0; i<DIM; i++){
        if(vett[i]->foo(3) > max){
            max = vett[i]->foo(3);
        }
        if(typeid(*vett[i]) == typeid(C<double>)){
            somma += ((C<double>*)(vett[i]))->g(5);
            count++;
        }
    }
    cout << "Max(foo(3))=" << max << ", Media(g(5))=" << somma/count << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vett[5] << endl;
    (*vett[5])[0] = 9.99999;
    cout << *vett[5] << endl;
}