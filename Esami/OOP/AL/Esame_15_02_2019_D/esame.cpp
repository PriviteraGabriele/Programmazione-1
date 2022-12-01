#include<iostream>
#include<cstdlib>
#include<cmath>
#include<typeinfo>
#include<climits>
#define DIM 50

using namespace std;

class A {
    private:
        int* ptr;
        short len;

    public:
        A(short m, short k){
            ptr = new int[m];
            for(int i = 0; i<m; i++){
                ptr[i] = rand() % k + 1;
            }
            len = m;
        }

        virtual const double f() = 0;       //se ho una funzione const conviene mettere pure le altre funzioni della stessa classe a const

        int const get(short i){
            return ptr[i % len];
        }

        short const getLen(){
            return len;
        }

        //Punto 1
        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", ptr=[ ";
            for(int i = 0; i<len; i++){
                os << ptr[i] << " ";
            }
            os << "], ";
            return os;
        }

        //Punto 3
        int& operator[](int i){
            return ptr[i % len];
        }
};

//Punto 1 (Overloading dell'operatore <<)
ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        double p;

    public:
        B(short m, short k, double y) : A(m, k) {       //Bisogna sempre richiamare il costruttore della classe padre! (es. : A(m, k) )
            p = y;
        }

        double const f(){
            int somma = 0;
            for(int i = 0; i<A::getLen(); i++){         //Lo scop (es. A::) si può anche omettere in quanto non ci sono funzioni in B che si chiamano come quelle in A
                if(get(i) % 2 == 0){
                    somma += A::get(i);
                }   
            }
            return somma/p;
        }

        //Punto 1
        ostream& put(ostream& os){
            A::put(os);
            os << "p=" << p << ", f()=" << f();
            return os;
        }
};

class C : public A {
    private:
        char x;

    public:
        C(short n, short k, char c) : A(n, k){
            x = c;
        }

        double const f(){
            int count = 0;
            double somma = 0;
            for(int i = 0; i<A::getLen(); i++){
                if(get(i) % 2 == 1){
                    somma += A::get(i);
                    count++;
                }
            }
            if(count > 0){
                return somma/count;
            }
            else{
                return 0;
            }
        }

        string const g(char c){
            string s = "";
            s += x;
            s += c;
            return s;
        }

        //Punto 1
        ostream& put(ostream& os){
            A::put(os);
            os << "x=" << x << ", f()=" << f();
            return os;
        }
};

int main(){
    srand(111222333);
    A *vett[DIM];

    for(int i = 0; i<DIM; i++){
        short n = 1 + rand() % 10;
        short m = 1 + rand() % 8;
        if(rand() % 2 == 0){
            vett[i] = new B(n, m, rand() / (double)RAND_MAX + 0.05);
        }
        else{
            vett[i] = new C(n, m, (char)(rand() % ('z' - 'a' + 1) + 'a'));
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double somma = 0;
    string concat = "";
    for(int i = 0; i<DIM; i++){
        somma += vett[i]->f();
        if(typeid(*vett[i]) == typeid(C)){
            concat += ((C*)(vett[i]))->g('h');
        }
    }
    cout << "Avg(f())=" << somma/DIM << ", concat=" << concat << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vett[5] << endl;
    (*vett[5])[0] = -1;
    cout << *vett[5] << endl;
}