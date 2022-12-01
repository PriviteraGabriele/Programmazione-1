#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<typeinfo>

#define DIM 50

using namespace std;

class A {
    private:
        short *arr;
        short len;

    public:
        A(short m){
            len = m;
            arr = new short[len];
            for(int i = 0; i<len; i++){
                arr[i] = rand() % 10 + 1;
            }
        }

        short getLen(){
            return len;
        }

        virtual double f(short a) = 0;

        virtual ostream& put(ostream& os) = 0;

    protected:
        short get(short i){
            return arr[i % len];    
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

template<typename T>
class B : public A {
    private:
        T x;

    public:
        B(short m, char c) : A(m){
            if(typeid(x) == typeid(char)){
                x = c;
            }
            else{
                for(int i = 0; i<m; i++){
                    x += c;
                }
            }
        }

        double foo(short s){
            return log(s) + sin(f(s));
        }

        double f(short a){
            double somma = 0;
            int counter = 0;
            for(int i = a; i<getLen(); i++){
                somma += get(i);
                counter++;
            }
            return (double)somma/counter;
        }

        ostream& put(ostream& os){
            if(typeid(x) == typeid(char)){
                os << "B<char> arr=[";
                for(int i = 0; i<getLen(); i++){
                    os << get(i) << " ";
                }
                os << "], x=" << x << ", f(3)=" << f(3);
                return os;
            }
            else{
                os << "B<string> arr=[";
                for(int i = 0; i<getLen(); i++){
                    os << get(i) << " ";
                }
                os << "], x=" << x << ", f(3)=" << f(3);
                return os;
            }
        }
};

class C : public A {
    private:
        int y;

    public:
        C(short n, int k) : A(n){
            y = k;
        }

        double f(short a){
            double r = get(rand() % getLen());
            return ((double)(a + y))/r;
        }

        double g(short w){
            return sin(w + y);
        }

        ostream& put(ostream& os){
            os << "C arr=[";
            for(int i = 0; i<getLen(); i++){
                os << get(i) << " ";
            }
            os << "], y=" << y << ", f(3)=" << f(3) << ", g(5)=" << g(5);
            return os;
        }

        C* operator++(){
            ++y;
            return this;
        }
};

int main(){
    srand(111222333);

    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        switch (rand() % 3)
        {
        case 0:
            vett[i] = new C(n, rand() % 10 + 1);
            break;
        case 1:
            vett[i] = new B<string>(n, rand() % ('z' - 'a' + 1) + 'a');
            break;
        case 2:
            vett[i] = new B<char>(n, rand() % ('z' - 'a' + 1) + 'a');
        }
    }

    //PUNTO 1
    cout << endl << "PUNTO 1" << endl;
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
        if(typeid(*vett[i]) == typeid(C)){
            somma += ((C*)vett[i])->g(5);
            counter++;
        }
    }
    cout << "Max(f(3))=" << max << ", Avg(g(5))=" << (double)somma/counter << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vett[48] << endl;
    cout << *(++(*((C*)vett[48]))) << endl;

}