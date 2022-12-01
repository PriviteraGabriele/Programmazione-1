#include<iostream>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<typeinfo>

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
            len = m;
            vec = new int[len];
            for(int i = 0; i<len; i++){
                vec[i] = rand() % (b - a + 1) + a;
            }
        }

        short getLen(){
            return len;
        }

        virtual double foo(short a) = 0;

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", vec=[";
            for(int i = 0; i<len; i++){
                os << vec[i] << " ";
            }
            os << "], ";
            return os;
        }

        int operator()(int i1, int i2){
            int somma = 0;
            for(int i = i1; i<=i2; i++){
                somma += vec[i];
            }
            return somma;
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:   
        int p;

    protected:
        int prod(short s){
            int prod = 1;
            for(int i = s; i<getLen(); i++){
                prod *= get(i % getLen());
            }
            return prod;
        }

    public:
        B(short m, int x, int y) : A(m, x, y){
            int rnd = rand() % getLen();
            p = get(rnd);
        }

        double foo(short a){
            return (double)prod(a)/p;
        }

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
    double max = 0;
    double somma = 0;
    int counter = 0;
    for(int i = 0; i<DIM; i++){
        if(vett[i]->foo(3) > max){
            max = vett[i]->foo(3);
        }

        if(typeid(*vett[i]) == typeid(C<double>)){
            somma += ((C<double>*)vett[i])->g(5);
            counter++;
        }
    }
    cout << "Max(foo(3))=" << max << ", Avg(g(5))=" << (double)somma/counter << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vett[10] << endl;
    cout << "vett[10](2, 3)=" << (*vett[10])(2, 3) << endl;

}