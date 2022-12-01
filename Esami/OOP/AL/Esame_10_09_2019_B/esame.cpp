#include<iostream>
#include<cstdlib>
#include<climits>
#include<typeinfo>
#include<cmath>

#define DIM 50

using namespace std;

class A {
    private:
        double *arr;
        short len;

    public:
        A(short m){
            len = m;
            arr = new double[len];
            for(int i = 0; i<len; i++){
                arr[i] = rand() / (double)RAND_MAX;
            }
        }

        short getLen(){
            return len;
        }

        virtual double f(short a) = 0;

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", arr=[";
            for(int i = 0; i<len; i++){
                os << arr[i] << " ";
            }
            os << "], ";
            return os;
        }

        double operator()(int i1, int i2){
            double somma = 0;
            for(int i = i1; i<=i2; i++){
                somma += arr[i];
            }
            return somma;
        }

    protected:
        double get(short i){
            return arr[i % len];
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        double p;

    protected:
        double foo(short s, int k){
            double somma = 0;
            for(int i = (s % getLen()); i<getLen(); i++){
                somma += get(i);
            }
            return somma*k;
        }
    
    public:
        B(short m) : A(m){
            double somma = 0;
            for(int i = 0; i<getLen(); i++){
                somma += get(i);
            }
            p = (double)somma/getLen();
        }

        double f(short a){
            return log(foo(a, 2*a))/p;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "p=" << p << ", f(3)=" << f(3);
            return os;
        }
};

template<typename T>
class C : public A {
    private:
        T x;

    public:
        C(short n) : A(n){
            if(typeid(x) == typeid(short)){
                x = n;
            }
            else{
                x = log(1 + pow(sin(n), 2));
            }
        }

        T g(T k){
            return 2 * x * (k + 1);
        }

        double f(short r){
            return g(r);
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "x=" << x << ", f(3)=" << f(3);
            return os;
        }
};

using namespace std;

int main(){
    srand(111222333);

    A* vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        switch (rand() % 3){
        case 0:
            vett[i] = new B(n);
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
    int counter = 0;
    for(int i = 0; i<DIM; i++){
        if(vett[i]->f(3) > max){
            max = vett[i]->f(3);
        }

        if(typeid(*vett[i]) == typeid(C<double>)){
            somma += ((C<double>*)(vett[i]))->g(5);
            counter++;
        }
    }
    cout << "Max(f(3))=" << max << ", Avg(g(5))=" << (double)somma/counter << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << "vett[10]=" << *vett[10] << endl;
    cout << "vett[10](2, 3)=" << (*vett[10])(2, 3) << endl;
}