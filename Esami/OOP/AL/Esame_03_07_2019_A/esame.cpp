#include<iostream>
#include<cmath>
#include<typeinfo>
#include<climits>
#include<cstdlib>

#define DIM 50

using namespace std;

class A {
    private:
        int *arr;
        short len;

    public:
        A(short m, int a, int b){
            len = m;
            arr = new int[len];
            for(int i = 0; i<len; i++){
                arr[i] = rand() % (b - a + 1) + a;
            }
        }

        virtual double func(short i) = 0;


        short getLen(){
            return len;
        }

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", arr=[ ";
            for(int i = 0; i<len; i++){
                os << arr[i] << " ";
            }
            os << "], ";
            return os;
        }

        int& operator[](short i){
            return arr[i % len];
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

    public:
        B(short m, int y, int z, double x) : A(m, y, z){
            p = x;
        }

        double func(short i){
            int max = 0;
            int min = 99999;
            for(int i = 0; i<A::getLen(); i++){
                if(A::get(i) > max){
                    max = A::get(i);
                }
                if(A::get(i) < min){
                    min = A::get(i);
                }
            }
            return (double)(min/max) + p;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "p=" << p << ", func(3)=" << func(3);
            return os;
        }
};

class C : public A {
    private:
        char t;

    public:
        C(short n, char c, int a, int b) : A(n, a, b){
            t = c;
        }

        double func(short i){
            double somma = 0; 
            for(int i = 0; i<A::getLen(); i++){
                somma += A::get(i);
            }
            return (double)somma/A::getLen();
        }

        string g(char c, short k){
            string str = "";
            for(int i = 0; i<k; i++){
                str += t;
                str += c;
            }
            return str;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "t=" << t << ", func(3)=" << func(3);
            return os;
        }
};

int main(){
    srand(111222333);

    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        if (rand() % 2 == 0){
            vett[i] = new B(n, rand() % 5 + 1, rand() % 11 + 10, (double)rand() / (RAND_MAX));
        }
        else{
            vett[i] = new C(n, (char)(rand() % ('z' - 'a' + 1) + 'a'), rand() % 5 + 1, rand() % 11 + 10);
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
    int counter = 0;
    for(int i = 0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(C) && counter < 3){
            cout << "i=" << i << ", g('h', 2)=" << ((C*)(vett[i]))->g('h', 2) << endl;
            counter++;
        }
        somma += vett[i]->func(3);
    }
    cout << endl << "Avg(f(3))=" << somma/DIM << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << (*vett[5]) << endl;
    (*vett[5])[0] = 3;
    cout << (*vett[5]) << endl;
}