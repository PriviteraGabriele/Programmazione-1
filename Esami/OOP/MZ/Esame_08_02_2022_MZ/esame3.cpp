#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<typeinfo>

#define DIM 10

using namespace std;

class AbstractRandomVec {
    protected:
        int* vec;
        int num;

    public:
        AbstractRandomVec(int n, int min, int max){
            num = n;
            vec = new int[num];
            for(int i = 0; i<num; i++){
                vec[i] = rand() % (max - min + 1) + min;
            }
        }

        virtual int count() = 0;

        int* get(int i){
            if(vec[i]){
                return (vec + i);
            }
            else{
                return nullptr;
            }
        }

        int numel(){
            return num;
        }

        float mean(){
            float somma = 0;
            float counter = 0;
            for(int i = 0; i<num; i++){
                if(vec[i]){
                    somma += vec[i];
                    counter++;
                }
            }
            return (float)somma/counter;
        }

        virtual ostream& put(ostream& os){
            os << "Class=" << typeid(*this).name() << ", num=" << num << ", vec=[";
            for(int i = 0; i<num; i++){
                os << vec[i] << " ";
            }
            os << "]";
            return os;
        }
};

ostream& operator<<(ostream& os, AbstractRandomVec& obj){
    return obj.put(os);
}

class TernaryVec : public AbstractRandomVec {
    public:
        TernaryVec(int n) : AbstractRandomVec(n, 0, 2) {}

        int count(){
            int counter = 0;
            for(int i = 0; i<num; i++){
                if(vec[i]){
                    counter++;
                }
            }
            return counter;
        }

        ostream& put(ostream& os){
            AbstractRandomVec::put(os);
            return os;
        }
};

class MultVec : public AbstractRandomVec {
    private:
        double midpoint;
    
    public:
        MultVec(int n, int min, int max, int mul) : AbstractRandomVec(n, min, max){
            num = n;
            for(int i = 0; i<num; i++){
                vec[i] = rand() % (max - min + 1) + min;
                while(vec[i] % mul != 0){
                    vec[i] = rand() % (max - min + 1) + min;
                }
            }
            midpoint = (double)(min + max)/2;
        }

        int count(){
            int counter = 0;
            for(int i = 0; i<num; i++){
                if(vec[i] > midpoint){
                    counter++;
                }
            }
            return counter;
        }

        int countEven(){
            int counter = 0;
            for(int i = 0; i<num; i++){
                if(vec[i] % 2 == 0){
                    counter++;
                }
            }
            return counter;
        }

        ostream& put(ostream& os){
            AbstractRandomVec::put(os);
            os << ", midpoint=" << midpoint;
            return os;
        }
};

int main(){
    srand(424242);

    AbstractRandomVec* vett[DIM];

    for(int i = 0; i<DIM; i++){
        int n = 5 + rand() % 5;
        int m = 5 + rand() % 5;
        int min = rand() % 10 + 5;
        int max = min + rand() % 20;

        switch(rand() % 2){
            case 0:
                vett[i] = new TernaryVec(n);
                break;
            case 1:
                vett[i] = new MultVec(n, min, max, m);
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    int max = INT_MIN;
    for(int i = 0; i<DIM; i++){
        if(vett[i]->count() > max){
            max = vett[i]->count();
        }
    }
    cout << "Max(count())=" << max << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    int somma = 0;
    int counter = 0;
    for(int i = 0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(MultVec)){
            somma += ((MultVec*)vett[i])->countEven();
            counter++;
        }
    }
    cout << "Mean(countEven))=" << (double)somma/counter << endl;
}