#include<iostream>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<typeinfo>
#include<cfloat>

#define DIM 50

using namespace std;

class A {
    private:
        int *v;
        short len;

    public:
        A(short k, short n){
            len = k;
            v = new int[len];
            for(int i = 0; i<len; i++){
                v[i] = rand() % n;
            }
        }

        virtual double doit(short a) = 0;

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", v = [";
            for(int i = 0; i<len; i++){
                os << v[i] << " ";
            }
            os << "], ";
            return os;
        }

    protected:
        double mat(short i){
            int S = 0;
            for(int j = 0; j<i; j++){
                S += v[j];
            }
            return sin(S);
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        int p;

    public:
        B(short k, short n, int p) : A(k, n){
            this->p = p; 
        }

        double doit(short a){
            return mat(a) * log(p * rand() % 100);
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "p=" << p << ", doit(3)=" << doit(3);
            return os;
        }

        B* operator++(){
            ++p;
            return this;
        }

    protected:
        bool test(short i){
            if(mat(i) > 0){
                return true;
            }
            return false;
        }
};

class C : public A {
    private:
        double x;

    public:
        C(short k, short n, double c) : A(k, n){
            x = c;
        }

        double doit(short r){
            return x * (mat(r) + 1);
        }

        int g(int c){
            double r = rand() / (double)RAND_MAX;
            return round(x + (c * r));
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "x=" << x << ", doit(3)=" << doit(3);
            return os;
        }
};

int main(){
    srand(111222333);

    A* vett[DIM];

    for(int i = 0; i<DIM; i++) {
	    short n = 1 + rand() % 10;
	    short k = 1 + rand() % 10; 
	    if(rand() % 2 == 0){
		    vett[i] = new B(k, n, (int)rand() % 10 + 1);
	    }
        else{
		    vett[i] = new C (k, n, rand() / (double)RAND_MAX * 10 + 1);
	    }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double max = DBL_MIN;
    double somma = 0;
    int counter = 0;
    for(int i = 0; i<DIM; i++){
        if(vett[i]->doit(3) >max){
            max = vett[i]->doit(3);
        }
        if(typeid(*vett[i]) == typeid(C)){
            somma += ((C*)vett[i])->g(5);
            counter++;
        }
    }
    cout << "Max(doit(3))=" << max << ", Mean(g(5)=" << (double)somma/counter << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << "0) " << *vett[0] << endl;
    cout << "0) " << *(++(*((B*)vett[0]))) << endl;
}