#include<iostream>
#include<cmath>
#include<climits>
#include<typeinfo>
#include<cstdlib>

#define DIM 50

using namespace std;

class A {
    private:
        char *str;
        short len;

    public:
        A(short m, string source){
            len = m;
            str = new char[len];
            string tmp = "";
            for(int i = 0; i<source.length(); i++){
                for(int j = 0; j<source.length(); j++){
                    if(source[j] == 'a' || source[j] == 'e' || source[j] == 'i' || source[j] == 'o' || source[j] == 'u' || source[j] == 'A' || source[j] == 'E' || source[j] == 'I' || source[j] == 'O' || source[j] == 'U'){
                        tmp += source[j];
                        source[j] = 0;
                    }
                }
                if(source[i] != 0){
                    tmp += source[i];
                }
            }
            for(int i = 0; i<len; i++){
                str[i] = tmp[i];
            }
        }

        virtual string func(short k) = 0;

        short getLen(){
            return len;
        }

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", str = ";
            for(int i = 0; i<len; i++){
                os << str[i];
            }
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
        short q;

    public:
        B(short m, string source) : A(m, source){
            q = 1 + (rand() % getLen());
        }

        string func(short k){
            string tmp = "";
            for(int i = getLen() - 1; i >= (getLen() - k); i--){
                tmp += get(i);
            }
            return tmp;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << ", q=" << q << ", func(3)=" << func(3);
            return os;
        }
};

class C : public A {
    private:
        char y;
        short K;

    public:
        C(short n, string source, char y) : A(n, source){
            this->y = y;
        }

        string func(short k){
            string tmp = "";
            for(int i = getLen() - k - 1; i>=0; i--){
                tmp += get(i);
            }
            return tmp;
        }

        string g(char c){
            string tmp = "";
            tmp += y;
            for(int i = 0; i<getLen(); i++){
                tmp += get(i);
            }
            tmp += c;
            return tmp;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << ", y=" << y << ", func(3)=" << func(3);
            return os;
        }
};

int main(){
    srand(111222333);

    string S;

    A* vett[DIM];

    short fa = 3;

    for(int i = 0; i < DIM; i++){
        short n = 10 + rand() % 10;
        S = "";
        for(int k = 0; k < 20; k++){
            S += rand() % ('z' - 'a' + 1) + 'a';
        }
        if(rand() % 2 == 0){
            vett[i] = new B(n, S);
        }
        else{
            vett[i] = new C(n, S, (char)(rand() % ('z' - 'a' + 1) + 'a'));
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    for(int i = DIM - 1; i>0; i--){
        if(typeid(*vett[i]) == typeid(C)){
            cout << "g('X')=" << dynamic_cast<C*>(vett[i])->g('X') << endl;
            break;
        }
    }

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << "*vett[5]: " << *vett[5] << endl;
    cout << "(*vett[5])(1, 3)=" << (*vett[5])(1, 3) << endl;

}