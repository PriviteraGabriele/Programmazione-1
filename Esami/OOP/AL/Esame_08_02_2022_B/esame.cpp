#include<iostream>
#include<cstdlib>
#include<cmath>
#include<typeinfo>
#include<climits>

#define DIM 50

using namespace std;

class A {
    private:
        char *str;
        short len;

    public:
        A(short w, char c1, char c2){
            len = w;
            str = new char[len];
            for(int i = 0; i<len; i++){
                str[i] = rand() % (c2 - c1 + 1) + c1;
            }
        }

        virtual short f(short k) = 0;

        virtual ostream& put(ostream& os) = 0;

        string operator()(int i1, int i2){
            i1 = abs(i1);
            i2 = abs(i2);
            i1 % len;
            i2 % len;
            string s = "";
            if(i1 <= i2){
                for(int i = i1; i<=i2; i++){
                    s += str[i];
                }
            }
            else{
                for(int i = i2; i<=i1; i++){
                    s += str[i];
                }
            }
            return s;
        }

    protected:
        string extract(short k){
            string s = "";
            for(int i = 0; i<len; i++){
                s += str[i];
            }
            if(k >= len){
                return s;
            }
            return s.substr(len - k, len);
        }
};

//Overloading dell'operatore
ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        char z;

    public:
        B(short m, char c1, char c2) : A(m, c1, c2){
            string s = extract(m/2+1);
            z = s[rand() % s.length()];
        }

        short f(short k){
            int counter = 0;
            string s = extract(k);
            for(int i = 0; i<s.length(); i++){
                if(s[i] <= z){
                    counter++;
                }
            }
            return counter;
        }

        ostream& put(ostream& os){
            os << "B str=" << extract(1000) << ", z=" << z;
            return os;
        }
};

template<typename T>
class C : public A {
    private:
        T ss;

    public:
        C(short w, char c1, char c2) : A(w, c1, c2){
            if(typeid(ss) == typeid(short)){
                ss = w;
            }
            else{
                string s = extract(w/2+1);
                for(int i = 0; i<s.length(); i++){
                    ss += s[i];
                }
            }
        }

        short f(short k){
            string s = extract(k);
            for(int i = 0; i<s.length(); i++){
                if(s[i] >= 'A' && s[i] <= 'Z'){
                    return 1;
                }
            }
            return 0;
        }

        T foo(short x){
            T somma = 0;
            for(int i = 0; i<x; i++){
                somma += ss;
            }
            return somma;
        }

        //Metodo per vedere il tipo del template
        ostream& put(ostream& os){
            if(typeid(ss) == typeid(short)){
                os << "C<short> ";
            }
            else{
                os << "C<string> ";
            }
            os << "str=" << extract(1000) << ", ss=" << ss;
            return os;
        }
};

int main(){
    srand(12345678);

    A* vec[DIM];

    for(unsigned int i = 0; i<DIM; i++){
        int r = rand();
        if(r % 3 == 0){
            vec[i] = new B(rand() % 10 + 5, '0', '9');
        }
        else if(r % 3 == 1){
            vec[i] = new C<string>(rand() % 10 + 5, 'a', 'z');
        }
        else{
            vec[i] = new C<short>(rand() % 20 + 10, 'A', 'Z');
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vec[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    short counter = 0;
    short somma = 0;
    for(int i = 0; i<DIM; i++){
        if(vec[i]->f(5) >= 4){
            counter++;
        }
        if(typeid(*vec[i]) == typeid(C<short>)){
            somma += ((C<short>*)(vec[i]))->foo(3);
        }
    }
    cout << "count(f(5)<=4)=" << counter << ", sum(foo(3)=" << somma << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vec[9] << endl;
    cout << "(*vec[9])(3, 5)=" << (*vec[9])(3, 5) << endl;
}