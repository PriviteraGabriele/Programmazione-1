#include<iostream>
#include<cstdlib>
#include<climits>
#include<typeinfo>
#include<cmath>

#define DIM 50

using namespace std;

class A {
    private:
        double *vec;
        short len;

    public:
        A(short w, double a, double b){
            len = w;
            vec = new double[len];
            for(int i = 0; i<len; i++){
                vec[i] = rand() / (double)RAND_MAX * ((b - a + 1) + a);
            }
        }

        virtual bool test(short a) = 0;

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << " [";
            for(int i = 0; i<len; i++){
                os << vec[i] << " ";
            }
            os << "] ";
            return os;
        }

        double& operator[](short i){
            return vec[i % len];
        }

    protected:
        double select(double x){
            double somma = 0;
            int counter = 0;
            for(int i = 0; i<len; i++){
                if(vec[i] <= x){
                    somma += vec[i];
                    counter++;
                }
            }
            return somma/counter;
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        short p;

    public:
        B(short m, short a, short b) : A(m, a, b){
            p = (rand() % (b - a + 1) + a)*(-1);
        }

        bool test(short a){
            if(p >= a){
                return true;
            }
            return false;
        }

        ostream& put(ostream& os){
            A::put(os);
                os << "p=" << p;
                return os;
        }
};

template<typename T>
class C : public A {
    private:
        T alfa;

    public:
        C(short n, double x, double y) : A(n, x, y){
            if(typeid(alfa) == typeid(short)){
                alfa = n;
            }
            else{
                alfa = rand() / (double)RAND_MAX * ((y + x + 1) + x)*(-1);
            }
        }

        double g(double k){
            return select(k)*2;
        }

        bool test(short r){
            if(g(r)/alfa >= 1){
                return true;
            }
            return false;
        }

        ostream& put(ostream& os){
            A::put(os);
                os << "alpha=" << alfa;
                return os;
        }
};

int main(){
    srand(11223367);

    A* vec[DIM];

    for (unsigned short i = 0; i < DIM; i++){
        short r = rand() % 3;
        if(r == 0){
            vec[i] = new C<double>(rand() % 5 + 5, rand() % 5 + 5 + rand() / (RAND_MAX * 1.0), rand() % 10 + 10 + rand() / (RAND_MAX * 1.0));
        }
        else if(r == 1){
            vec[i] = new C<short>(rand() % 5 + 5, rand() % 5 + 5 + rand() / (RAND_MAX * 1.0), rand() % 10 + 10 + rand() / (RAND_MAX * 1.0));
        }
        else{
            vec[i] = new B(rand() % 5 + 5, rand() % 5 + 5, rand() % 15 + 10);
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vec[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double max = 0;
    int counter = 0;
    for(int i = 0; i<DIM; i++){
        if(typeid(*vec[i]) == typeid(C<double>)){
            if(max < ((C<double>*)(vec[i]))->g(12)){
                max = ((C<double>*)(vec[i]))->g(12);
            }
        }

        if(vec[i]->test(12)){
            counter++;
        }
    }
    cout << "max(g(12))=" << max << ", counter(test(12) == true)=" << counter << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vec[2] << endl;
    (*vec[2])[2] = 6.9;
    cout << *vec[2] << endl;
}