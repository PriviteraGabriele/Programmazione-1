#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<typeinfo>
#include<cfloat>

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

        short getLen(){
            return len;
        }

        virtual double func(short i) = 0;

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", arr=[";
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
    obj.put(os);
    return os;
}

class B : public A {
    private:   
        double p;

    public:
        B(short m, int y, int z, double x) : A(m, y, z){
            p = x;
        }

        double func(short i){
            double min = DBL_MAX;
            double max = DBL_MIN;
            for(int i = 0; i<getLen(); i++){
                if(get(i) > max){
                    max = get(i);
                }
                if(get(i) < min){
                    min = get(i);
                }
            }
            return ((double)min/max) + p;
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
            for(int i = 0; i<getLen(); i++){
                somma += get(i);
            }
            return (double)somma/getLen();
        }

        string g(char c, short k){
            string tmp = "";
            for(int i = 0; i<k; i++){
                tmp += t;
                tmp += c;
            }
            return tmp;
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
    cout << "Punto 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double somma = 0;
    int counter = 0;
    for(int i = 0; i<DIM; i++){
        somma += vett[i]->func(3);
        if(typeid(*vett[i]) == typeid(C) && counter < 3){
            cout << "i=" << i << ", g('h', 2)=" << ((C*)vett[i])->g('h', 2) << endl;
            counter++;
        }
    }
    cout << endl << "Avg(func(3))=" << (double)somma/DIM << endl; 

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << (*vett[5]) << endl;
    (*vett[5])[0] = 3;
    cout << (*vett[5]) << endl;
}