#include<iostream>
#include<cstdlib>
#include<cmath>
#include<typeinfo>
#include<climits>

#define DIM 50

using namespace std;

class A {
    private:
        char *ptr;
        short len;

    protected:
        char get(short i){
            return ptr[i % len];
        }

    public:
        A(short m, char c){
            ptr = new char[m];
            int min = (int)'a';
            int max = (int)c;
            for(int i = 0; i<m; i++){
                ptr[i] = (char)(rand() % (max - min + 1) + min);
            }
            len = m;
        }

        virtual string elab(short a, char c) = 0;

        short getLen(){
            return len;
        }

        //Punto 1
        virtual ostream& put(ostream& os){
            os << "ptr=[";
            for(int i = 0; i<len; i++){
                os << ptr[i] << " ";
            }
            os << "], ";
            return os;
        }

        char& operator[](short i){
            return ptr[i % len];
        }
};

//Punto 1 (Overloading dell'operatore <<)
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
            return sin(x+s)/log(x+s);
        }

        string elab(short a, char c){
            string r = "";
            for(int i = 0; i<A::getLen(); i++){
                if(abs(get(i) - c) <= a){       //abs funzione valore assoluto contenuta in cmath
                    r += get(i);
                }
            }
            return r;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "x=" << x << ", elab(5, z)=" << elab(5, 'z');
            return os;
        }
};

template<typename T>
class C : public A {
    private:
        T y;

    public:
        C(short n, double k, char c) : A(n, c){
            if(typeid(y) == typeid(short)){         //Controllo tipo della variabile template
                y = round(100 * k);            //In alternativa uso (100 * k) + 0.5
            }
            else{
                y = k;
            }
        }

        string elab(short a, char c){
            string r = "";
            if(A::getLen() >= a){
                for(int i = 0; i<a; i++){
                    r += c;
                }
            }
            else{
                for(int i = 0; i<A::getLen(); i++){
                    r += get(i);
                }
            }
            return r;
        }

        double g(short w){
            return sin(w+y);
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "y=" << y << ", elab(5, z)=" << elab(5, 'z');
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
        cout << i << ")";
        if(typeid(*vett[i]) == typeid(B)){
            cout << "B ";
        }
        else if(typeid(*vett[i]) == typeid(C<short>)){
            cout << "C<short> ";
        }
        else{
            cout << "C<double> ";
        }
        cout << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double s1 = 0;
    int c1 = 0;
    double s2 = 0;
    int c2 = 0;
    for(int i = 0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(B)){
            s1 += ((B*)vett[i])->foo(5);
            c1++;
        }
        else if(typeid(*vett[i]) == typeid(C<short>)){
            s2 += ((C<short>*)vett[i])->g(5);
            c2++;
        }
    }
    cout << "avg(foo(5))=" << s1/c1 << ", avg(g(5))=" << s2/c2 << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vett[0] << endl;
    (*vett[0])[0] = '*';
    cout << *vett[0] << endl;
}