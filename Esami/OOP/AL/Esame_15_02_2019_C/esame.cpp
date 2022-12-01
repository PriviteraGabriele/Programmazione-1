#include<iostream>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<typeinfo>
#include<string>

#define DIM 50

using namespace std;

class A {
    private:
        char *str;
        short len;

    public:
        A(short m){
            len = m;
            str = new char[len];
            for(int i = 0; i<len; i++){
                str[i] = rand() % ('z' - 'a' + 1) + 'a';
            }
        }

        short const getLen(){
            return len;
        }

        virtual double const elab(short a) = 0;

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", w= ";
            for(int i = 0; i<len; i++){
                os << str[i];
            }
            os << ", ";
            return os;
        }

    protected:
        char const get(short i){
            return str[i % len];
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        int p;

    protected:
        short* const map(){
            short *vec = new short[getLen()];
            for(int i = 0; i<getLen(); i++){
                if(get(i) != 'a' || get(i) != 'e' || get(i) != 'i' || get(i) != 'o' || get(i) != 'u'){
                    vec[i] = 1;
                }
                else{
                    vec[i] = 0;
                }
            }
            return vec;
        }

    public:
        B(short m, int x) : A(m){
            p = x;
        }

        double const elab(short a){
            double somma = 0;
            for(int i = 0; i<getLen(); i++){
                somma += map()[i];
            }
            return (double)somma/p;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "p=" << p << ", elab(3)=" << elab(3);
            return os;
        }

        B* operator++(int){
            p++;
            return this;
        }
};

class C : public A {
    private:
        char x;

    public:
        C(short n, char c) : A(n){
            x = c;
        }

        double const elab(short r){
            double counter = 0;
            for(int i = (r % getLen()); i<getLen(); i++){
                if(get(i) >= x){
                    counter++;
                }
            }
            return (double)counter/getLen();
        }

        string const g(char c){
            string tmp = "";
            tmp += x;
            tmp += c;
            return tmp;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "x=" << x << ", elab(3)=" << elab(3);
            return os;
        }
};

int main(){
    srand(111222333);

    A *vett[DIM];

    for(int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        if(rand() % 2 == 0){
            vett[i] = new B(n, rand() % 10 + 1);
        }
        else{
            vett[i] = new C(n, (char)(rand() % ('z' - 'a' + 1) + 'a'));
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
    string concat = "";
    for(int i = 0; i<DIM; i++){
        somma += vett[i]->elab(3);
        if(typeid(*vett[i]) == typeid(C)){
            concat += ((C*)(vett[i]))->g('h');
        }
    }
    cout << "Avg(elab(3))=" << (double)somma/DIM << ", concat=" << concat << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << "6): " << *vett[6] << endl;
    cout << "6): " << *((*(dynamic_cast<B*>(vett[6])))++) << endl;

}