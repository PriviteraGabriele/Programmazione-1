#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<typeinfo>

#define DIM 50

using namespace std;

class A {
    private:
        char *ptr;
        short len;

    public:
        A(short m, char c){
            len = m;
            ptr = new char[len];
            for(int i = 0; i<len; i++){
                ptr[i] = rand() % (c - 'a' + 1) + 'a';
            }
        }

        short getLen(){
            return len;
        }

        virtual string elab(short a, char c) = 0;

        virtual ostream& put(ostream& os) = 0;

        char& operator[](short i){
            return ptr[i % len];
        }

    protected:
        char get(short i){
            return ptr[i % len];
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        double x;

    public:
        B(short m, double y, char c) : A(m, c){
            x = y;
        }

        double foo(short s){
            return (double)sin(x + s)/log(x + s);
        }

        string elab(short a, char c){           //FUNZIONA, non stampa niente perchè i valori inseriti nella chiamata non soddisfano mai 
            string tmp = "";                    // la condizione dell'ultimo if
            for(int i = 0; i<getLen(); i++){
                if(abs(get(i) - c) <= a){
                    tmp += get(i);
                }
            }
            return tmp;
        }

        ostream& put(ostream& os){
            os << "B ptr=[";
            for(int i = 0; i<getLen(); i++){
                os << get(i) << " ";
            }
            os << "], x=" << x << ", elab(5, z)=" << elab(5, 'z') << "\t, foo(5)=" << foo(5);
            return os;
        }
};

template<typename T>
class C : public A {
    private:
        T y;

    public:
        C(short n, double k, char c) : A(n, c){
            if(typeid(y) == typeid(short)){
                y = round(100*k);
            }
            else{
                y = k;
            }
        }

        string elab(short a, char c){
            string tmp = "";
            if(getLen() >= a){
                for(int i = 0; i<a; i++){
                    tmp += c;
                }
                return tmp;
            }
            else{
                for(int i = 0; i<getLen(); i++){
                    tmp += get(i);
                }
                return tmp;
            }
        }

        double g(short w){
            return sin(w + y);
        }

        ostream& put(ostream& os){
            if(typeid(y) == typeid(double)){
                os << "C<double> ptr=[";
                for(int i = 0; i<getLen(); i++){
                    os << get(i) << " ";
                }
                os << "] y=" << y << ", elab(5, z)=" << elab(5, 'z');
                return os;
            }
            else{
                os << "C<short> ptr=[";
                for(int i = 0; i<getLen(); i++){
                    os << get(i) << " ";
                }
                os << "] y=" << y << ", elab(5, z)=" << elab(5, 'z');
                return os;
            }
        }
};

int main(){
    srand(111222333);

    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        switch (rand() % 3){
        case 0:
            vett[i] = new B(n, (double)rand() / RAND_MAX, rand() % ('z' - 'a' + 1) + 'a');
            break;
        case 1:
            vett[i] = new C<double>(n, (double)rand() / RAND_MAX, rand() % ('z' - 'a' + 1) + 'a');
            break;
        case 2:
            vett[i] = new C<short>(n, (double)rand() / RAND_MAX, rand() % ('z' - 'a' + 1) + 'a');
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double somma1 = 0;
    int counter1 = 0;
    double somma2 = 0;
    int counter2 = 0;
    for(int i = 0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(B)){
            somma1 = ((B*)vett[i])->foo(5);
            counter1++;
        }
        if(typeid(*vett[i]) == typeid(C<short>)){
            somma2 += ((C<short>*)vett[i])->g(5);
            counter2++;
        }
    }
    cout << "Avg(foo(5))=" << (double)somma1/counter1 << ", Avg(g(5))=" << (double)somma2/counter2 << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vett[0] << endl;
    (*vett[0])[0] = '*';
    cout << *vett[0] << endl;
}