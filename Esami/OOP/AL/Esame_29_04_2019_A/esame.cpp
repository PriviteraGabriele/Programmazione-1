#include<iostream>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<typeinfo>

#define DIM 50

using namespace std;

class A {
    private:
        double *ptr;
        short len;

    public:
        A(short m){
            len = m;
            ptr = new double[len];
            for(int i = 0; i<len; i++){
                ptr[i] = rand() / (double)RAND_MAX;
            }
        }

        short getLen(){
            return len;
        }

        virtual double f(short i) = 0;

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", ptr=[";
            for(int i = 0; i<len; i++){
                os << ptr[i] << " ";
            }
            os << "], ";
            return os;
        }

        double& operator[](short i){
            return ptr[i % len];
        }

    protected:
        double get(short i){
            return ptr[i % len];
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        int p;

    public:
        B(short m, int y) : A(m){
            p = y;
        }

        double f(short i){
            double somma = 0;
            for(int j = 0; j<=i; j++){
                somma += get(i);
            }
            return (double)somma/p;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "p=" << p << ", f(3)=" << f(3);
            return os;
        }
};

class C : public A {
    private:
        char x;

    public:
        C(short n, char c) : A(n){
            x = c;
        }

        double f(short i){
            double somma = 0;
            for(int i = 0; i<getLen(); i++){
                somma += get(i);
            }
            return (double)get(i)/somma;
        }

        string g(char c){
            string tmp = "";
            tmp += x;
            tmp += c;
            return tmp;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "x=" << x << ", f(3)=" << f(3);
            return os;
        }
};

int main(){
    srand(111222333);
    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        if (rand() % 2 == 0)
            vett[i] = new B(n, rand() % 10);
        else
            vett[i] = new C(n, (char)(rand() % ('z' - 'a' + 1) + 'a'));
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
        somma += vett[i]->f(3);
        if(typeid(*vett[i]) == typeid(C)){
            concat += ((C*)vett[i])->g('h');
        }
    }
    cout << "Avg(f(3))=" << (double)somma/DIM << ", concat=" << concat << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vett[0] << endl;
    (*vett[0])[2] = 6.9;
    cout << *vett[0] << endl;
}