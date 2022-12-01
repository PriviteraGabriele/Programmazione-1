#include<iostream>
#include<typeinfo>
#include<climits>
#include<cmath>
#include<cstdlib>
#define DIM 50

using namespace std;

class A {
    private:
        char *base;
        short len;

    protected:
        char get(short i){
            return base[i % len];
        }

    public:
        A(short m){
            len = m;
            base = new char[len];
            for(int i = 0; i<len; i++){
                base[i] = rand() % ('z' - 'a' + 1) + 'a';
            }
        }

        virtual string extract(short x) = 0;

        short getLen(){
            return len;
        }

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", base[";
            for(int i = 0; i<len; i++){
                os << base[i] << " ";
            }
            os << "], ";
            return os;
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        string str;
        double k;

    public:
        B(short m, double p) : A(m){
            k = p;
            string temp = "";
            for(int i = 0; i<getLen(); i++){
                if(A::get(i) == 'a' || A::get(i) == 'e' || A::get(i) == 'i' || A::get(i) == 'o' || A::get(i) == 'u' || A::get(i) == 'A' || A::get(i) == 'E' || A::get(i) == 'I' || A::get(i) == 'O' || A::get(i) == 'U'){
                    temp += A::get(i);
                }
            }
            str = temp;
        }

        double foo(short s){
            return sin(k+s)/log(s+1);
        }

        string extract(short x){
            string s = "";
            for(int i = 0; i<x; i++){
                s += get(rand() % getLen());
            }
            return s;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "str=" << str << ", k=" << k << ", extract(3)=" << extract(3);
            return os;        
        }
};

class C : public A {
    private:
        int y;

    public:
        C(short n, int k) : A(n){
            y = k;
        }

        string extract(short x){
            string z = "";
            int counter = 0;
            for(int i = 0; i<getLen(); i++){
                if(counter < x && A::get(i) != 'a' || A::get(i) != 'e' || A::get(i) != 'i' || A::get(i) != 'o' || A::get(i) != 'u' || A::get(i) != 'A' || A::get(i) != 'E' || A::get(i) != 'I' || A::get(i) != 'O' || A::get(i) != 'U'){
                    z += A::get(i);
                    counter++;
                }
            }
            return z;
        }

        short g(short w){
            return sin(w+y);
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "y=" << y << ", extract(3)=" << extract(3);
            return os;
        }

        //Punto 3, Overloading dell'operatore membro postfisso "++"
        C* operator++(int){
            y++;
            return this;
        }
};

int main(){
    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 10 + rand() % 10;
        switch (rand() % 2){
        case 0:
            vett[i] = new C(n, rand() % 20 + 1);
            break;
        case 1:
            vett[i] = new B(n, rand() / (double)RAND_MAX);
            break;
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
    for(int i = 0; i<DIM; i++){
        somma += ((B*)(vett[i]))->foo(5);
        somma += ((C*)(vett[i]))->g(5);
    }
    cout << "avg(g() + foo())=" << somma/DIM << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << "vett[10]=" << *vett[10] << endl;
    *((*(dynamic_cast<C*>(vett[10])))++);       
    cout << "vett[10]=" << *vett[10] << endl;

}