#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<typeinfo>

#define DIM 50

using namespace std;

class A {
    private:
        int x;

    public:
        A(int m) : x(m) {}

        virtual double const v(int a) = 0;

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", x=" << x << ", ";
            return os;
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        int *ptr;
        int l;

    protected:
        int const sum(int t){
            int somma = 0; 
            for(int i = 0; i<l; i++){
                if(ptr[i] <= t){
                    somma += ptr[i];
                }
            }
            return somma;
        }

    public:
        B(int z, int y) : A(z){
            l = y;
            ptr = new int[l];
            for(int i = 0; i<l; i++){
                ptr[i] = rand() % (100 - 1 + 1) + 1;
            }
        }

        double const v(int a){
            return (double)l * 1000/(sum(a) + 1);
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "ptr=[";
            for(int i = 0; i<l; i++){
                os << ptr[i] << " ";
            }
            os << "], v(50)=" << v(50);
            return os;
        }
        
        int& operator[](short i){
            return ptr[i % l];
        }
};

template<typename T>
class C : public A {
    private:
        T k;

    public:
        C(int n) : A(n){
            if(typeid(k) == typeid(int)){
                k = 2 * n;
            }
            else{
                k = log(1 + pow(sin(n), 2));
            }
        }

        T const g(T w){
            return k * (w + 1);
        }

        double const v(int r){
            return g(r);
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "k=" << k << ", v(50)=" << v(50);
            return os;
        }
};

int main(){
    srand(111222333);

    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        int n = 1 + rand() % 10;
        switch (rand() % 3){
        case 0:
            vett[i] = new B(n, rand() % 10 + 1);
            break;
        case 1:
            vett[i] = new C<int>(n);
            break;
        case 2:
            vett[i] = new C<double>(n);
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
    double min = 999999;
    double somma = 0;
    int counter = 0;
    for(int i = 0; i<DIM; i++){
        if(vett[i]->v(50) > max){
            max = vett[i]->v(50);
        }
        if(vett[i]->v(50) < min){
            min = vett[i]->v(50);
        }
        if(typeid(*vett[i]) == typeid(C<double>)){
            somma += ((C<double>*)(vett[i]))->g(5);
            counter++;
        }
    }
    cout << "min(v(50))=" << min << ", max(v(50))=" << max << ", Avg(g(5))=" << (double)somma/counter << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << "2): " << *vett[2] << endl;
    ((B*)vett[2])->operator[](2) = 1000;
    cout << "2): " << *vett[2] << endl;
}