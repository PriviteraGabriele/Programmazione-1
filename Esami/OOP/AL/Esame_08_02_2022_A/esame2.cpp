#include<iostream>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<typeinfo>

#define DIM 50

using namespace std;

class A {
    private:
        double *vec;
        short len;

    public:
        A(short w, double a, double b){
            len = w;
            vec = new double[len];
            for(int i = 0; i<len; i++){
                vec[i] = rand() / (double)RAND_MAX * ((b - a + 1) + a);
            }
        }

        //Funzione aggiunta da me per fare la stampa con il tipo del template (Non richiesto dall'esame in questione) [ESERCITAZIONE]
        short getLen(){
            return len;
        }

        virtual bool test(short a) = 0;

        virtual ostream& put(ostream& os) = 0;

        double& operator[](short i){
            return vec[i % len];
        }

    protected:
        double select(double x){
            double somma = 0;
            int counter = 0;
            for(int i = 0; i<=x; i++){
                somma += vec[i];
                counter++;
            }
            return (double)somma/counter;
        }

        //Funzione aggiunta da me per fare la stampa con il tipo del template (Non richiesto dall'esame in questione) [ESERCITAZIONE]
        double get(short i){
            return vec[i % len];
        }
};

ostream& operator<<(ostream& os, A& obj){
    obj.put(os);
    return os;
}

class B : public A {
    private:
        short p;

    public:
        B(short m, short a, short b) : A(m, a, b){
            p = (rand() % (b - a + 1) + a) * (-1);
        }

        bool test(short a){
            if(p >= a){
                return true;
            }
            return false;
        }

        ostream& put(ostream& os){
            os << "B vec=[";
            for(int i = 0; i<getLen(); i++){
                os << get(i) << " ";
            }
            os << "] , p=" << p;
            return os;
        }
};

template<typename T>
class C : public A {
    private:
        T alpha;

    public:
        C(short n, double x, double y) : A(n, x, y){
            if(typeid(alpha) == typeid(short)){
                alpha = n;
            }
            else{
                alpha = rand() / (double)RAND_MAX * (((y - x + 1) + x) * (-1));
            }
        }

        double g(double k){
            return select(k) * 2;
        }

        bool test(short r){
            if(g(r)/alpha >= 1){
                return true;
            }
            return false;
        }

        ostream& put(ostream& os){
            if(typeid(alpha) == typeid(short)){
                os << "C<short> vec=[";
                for(int i = 0; i<getLen(); i++){
                    os << get(i) << " ";
                }
                os << "], alpha=" << alpha;
                return os;
            }
            else{
                os << "C<double> vec=[";
                for(int i = 0; i<getLen(); i++){
                    os << get(i) << " ";
                }
                os << "], alpha=" << alpha << ", g(12)=" << g(12);
                return os;
            }
        }
};

int main(){
    srand(11223367);

    A* vec[DIM];

    for (unsigned short i = 0; i < DIM; i++){
        short r = rand() % 3;
        if(r == 0){
            vec[i] = new C<double>(rand() % 5 + 5, rand() % 5 + 5 + rand() / (RAND_MAX * 1.0), rand() % 10 + 10 + rand() / (RAND_MAX * 1.0));
        }
        else if(r == 1){
            vec[i] = new C<short>(rand() % 5 + 5, rand() % 5 + 5 + rand() / (RAND_MAX * 1.0), rand() % 10 + 10 + rand() / (RAND_MAX * 1.0));
        }
        else{
            vec[i] = new B(rand() % 5 + 5, rand() % 5 + 5, rand() % 15 + 10);
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vec[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double max = 0;
    int counter = 0;
    for(int i = 0; i<DIM; i++){
        if(typeid(*vec[i]) == typeid(C<double>) && ((C<double>*)vec[i])->g(12) > max){
            max = ((C<double>*)vec[i])->g(12);
        }
        if(vec[i]->test(12) == true){
            counter++;
        }
    }
    cout << "Max(g(12))=" << max  << ", Counter(test(12) = true)=" << counter << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vec[2] << endl;
    (*vec[2])[2] = 6.9;
    cout << *vec[2] << endl;

}