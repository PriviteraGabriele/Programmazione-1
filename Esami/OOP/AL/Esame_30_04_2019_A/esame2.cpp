#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<typeinfo>

#define DIM 50

using namespace std;

class A {
    private:
        char* str;
        short len;

    public:
        A(short m, string source){
            len = m;
            str = new char[len];
            for(int i = 0; i<len; i++){
                int rnd = rand() % source.length();
                str[i] = source[rnd];
            }
        }

        short getLen(){
            return len;
        }

        virtual char func(short i) = 0;

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", str = ";
            for(int i = 0; i<len; i++){
                os << str[i];
            }
            os << ", "; 
            return os;
        }

        string operator()(int i1, int i2){
            string tmp = "";
            for(int i = i1; i<i2; i++){
                tmp += str[i];
            }
            return tmp;
        }

    protected:
        char get(short i){
            return str[i % len];
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        short p;
        
    public:
        B(short m, string source) : A(m, source){
            int counter_V = 0;
            for(int i = 0; i<getLen(); i++){
                if(get(i) == 'a' || get(i) == 'e' || get(i) == 'i' || get(i) == 'o' || get(i) == 'u' || get(i) == 'A' || get(i) == 'E' || get(i) == 'I' || get(i) == 'O' || get(i) == 'U'){
                    counter_V++;
                }
            }
            p = ++counter_V;
        }

        char func(short i){
            char tmp = 'X';
            for(int j = i; j<getLen(); j++){
                if(get(j) != 'a' || get(j) != 'e' || get(j) != 'i' || get(j) != 'o' || get(j) != 'u' || get(j) != 'A' || get(j) != 'E' || get(j) != 'I' || get(j) != 'O' || get(j) != 'U'){
                    tmp = get(j);
                    return tmp;
                }
            }
            return tmp;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "p=" << p << ", func(3)=" << func(3);
            return os;
        }
};

class C : public A {
    private:
        char x;

    public:
        C(short n, string source, char y) : A(n, source){
            x = y;
        }

        char func(short i){
            for(int j = i; j<getLen(); j++){
                if(get(j) != 'a' || get(j) != 'e' || get(j) != 'i' || get(j) != 'o' || get(j) != 'u' || get(j) != 'A' || get(j) != 'E' || get(j) != 'I' || get(j) != 'O' || get(j) != 'U' && get(j) > x){
                    return get(j);
                }
            }
            return x;
        }

        string g(char c){
            string tmp = "";
            tmp += x;
            for(int i = 0; i<getLen(); i++){
                tmp += get(i);
            }
            tmp += c;
            return tmp;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "x=" << x << ", func(3)=" << func(3);
            return os;
        }
};

int main(){
    srand(111222333);

    A* vett[DIM];

    string S = "supercalifragilistichespiralidoso";
    for(int i = 0; i < DIM; i++){
        short n = 3 + rand() % 10;
        if(rand() % 2 == 0)
            vett[i] = new B(n, S);
        else
            vett[i] = new C(n, S, (char)(rand() % ( 'z' - 'a' + 1) + 'a'));
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    string concat = "";
    for(int i = 0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(C)){
            concat += ((C*)vett[i])->g('h');
        }
    }
    cout << "concat=" << concat << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << "vett[10]: " << *vett[10] << endl;
    cout << "vett[10](2, 7)=" << (*vett[10])(2, 7) << endl;

}