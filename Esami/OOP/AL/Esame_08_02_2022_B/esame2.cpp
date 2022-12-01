#include<iostream>
#include<cmath>
#include<climits>
#include<cstdlib>
#include<typeinfo>

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
            string tmp = "";
            for(int i = i1; i<=i2; i++){
                tmp += str[i];
            }
            return tmp;
        }

    protected:
        string extract(short k){
            string tmp = "";
            if(k >= len){
                for(int i = 0; i<len; i++){
                    tmp += str[i];
                }
            }
            else{
                for(int i = len - k; i<len; i++){
                    tmp += str[i];
                }
            }
            return tmp;
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        char z;

    public:
        B(short m, char c1, char c2) : A(m, c1, c2){
            z = extract(m/2+1)[rand() % extract(m/2+1).length()];
        }

        short f(short k){
            short counter = 0;
            for(int i = 0; i<extract(k).length(); i++){
                if(extract(k)[i] <= z){
                    counter++;
                }
            }
            return counter;
        }

        ostream& put(ostream& os){
            os << "B str=" << extract(100) << ", z=" << z;
            return os;
        }
};

template<typename T>
class C : public A {
    private:
        T ss;

    public:
        C(short w, char c1, char c2) : A(w, c1, c2){
            if(typeid(ss) == typeid(string)){
                string s = extract(w/2+1);
                for(int i = 0; i<s.length(); i++){
                    ss += s[i];
                }
            }
            else{
                ss = w;
            }
        }

        short f(short k){
            for(int i = 0; i<extract(k).length(); i++){
                if(extract(k)[i] >= 'A' && extract(k)[i] <= 'Z'){
                    return 1;
                }
            }
            return 0;
        }

        T foo(short x){
            T tmp = 0;
            for(int i = 0; i<x; i++){
                tmp += ss;
            }
            return tmp;
        }

        ostream& put(ostream& os){
            if(typeid(ss) == typeid(short)){
                os << "C<short> str=" << extract(100) << ", ss=" << ss;
                return os;
            }
            else{
                os << "C<string> str=" << extract(100) << ", ss=" << ss;
                return os;
            }
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

    // PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    int counter = 0;
    short somma = 0;
    for(int i = 0; i<DIM; i++){
        if(vec[i]->f(5) >= 4){
            counter++;
        }

        if(typeid(*vec[i]) == typeid(C<short>)){
            somma += ((C<short>*)vec[i])->foo(3);
        }
    }
    cout << "Counter(f(5)>=4)=" << counter << ", Somma(foo(3))=" << somma << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vec[9] << endl;
    cout << "*vec[9](3, 5)=" << (*vec[9])(3, 5) << endl;
}