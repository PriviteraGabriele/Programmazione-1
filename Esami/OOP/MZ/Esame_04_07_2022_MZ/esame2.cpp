#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<typeinfo>
#include<cfloat>

#define DIM 7

using namespace std;

template<typename T>
class AbstractRandomGenerator {
    protected:
        int num_values;
        int tossed;
        T accumuled_values;
        T value;
        T* values;

    public:
        AbstractRandomGenerator(T value, int num_values, T* input_values){
            this->value = value;
            this->num_values = num_values;
            values = new T[num_values];
            for(int i = 0; i<num_values; i++){
                values[i] = input_values[i];
            }
            accumuled_values = value;
            tossed = 0;
        }

        virtual T toss(){
            value = values[rand() % num_values];
            this->tossed++;
            accumuled_values += value;
            return value;
        }

        T getValue(){
            return value;
        }

        int getTossed(){
            return tossed;
        }

        virtual void nudge() = 0;

        virtual ostream& put(ostream& os){
            os << "Class=" << typeid(*this).name() << ", values={";
            for(int i = 0; i<num_values; i++){
                os << values[i] << " ";
            }
            os << "}, value=" << value << ", accumuled_value=" << accumuled_values << ", tossed=" << tossed;
            return os;
        }
};

template<typename T>
ostream& operator<<(ostream& os, AbstractRandomGenerator<T>& obj){
    return obj.put(os);
}

class Dice : public AbstractRandomGenerator<int> {
    private:
        int doubles;

    public:
        Dice() : AbstractRandomGenerator<int>(1, 6, new int[6]{1, 2, 3, 4, 5, 6}){
            doubles = 0;
        }

        void nudge(){
            value += rand() % 3 - 1;
            if(value > 6){
                value = 6;
            }
            else if(value < 1){
                value = 1;
            }
        }

        int toss(){
            int precedent = AbstractRandomGenerator<int>::getValue();
            int current = AbstractRandomGenerator<int>::toss();
            
            if(precedent == current){
                this->doubles++;
            }
            return AbstractRandomGenerator<int>::getValue();
        }

        double getDoubleRate(){
            //double double_tossed = (double)AbstractRandomGenerator<int>::tossed;
            return doubles/(double)tossed;      //oppure questo: doubles/double_tossed o (double)doubles/double_tossed (decommentando double_tossed sopra)
        }

        ostream& put(ostream& os){
            AbstractRandomGenerator<int>::put(os);
            os << ", getDoubleRate()=" << getDoubleRate();
            return os;
        }
};

class Coin : public AbstractRandomGenerator<string> {
    private:
        int nudge_prob;

    public:
        Coin(int nudge_prob) : AbstractRandomGenerator<string>("H", 2, new string[2]{"H", "T"}){
            this->nudge_prob = nudge_prob;
        }

        void nudge(){
            int rnd = rand() % (nudge_prob - 1);
            if(rnd == 0){
                if(value == "H"){
                    value = "T";
                }
                else{
                    value = "H";
                }
            }
        }

        ostream& put(ostream& os){
            AbstractRandomGenerator<string>::put(os);
            return os;
        }
};

int main(){
    srand(424242);

    AbstractRandomGenerator<int>** vec1 = new AbstractRandomGenerator<int>*[DIM];       
    AbstractRandomGenerator<string>** vec2 = new AbstractRandomGenerator<string>*[DIM];     

    for(int i=0; i<DIM; i++){
        vec1[i] = new Dice();
        vec2[i] = new Coin(rand() % 10 + 1);
    }

    for(int i=0; i<100; i++){
        vec1[rand() % DIM]->toss();
        vec2[rand() % DIM]->toss();
        if(rand() % 5 == 0){
            vec1[rand() % DIM]->nudge();
            vec2[rand() % DIM]->nudge();
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i + 1 << ") " << *vec1[i] << endl;
        cout << i + 1 << ") " << *vec2[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    int min = INT_MAX;
    for(int i = 0; i<DIM; i++){
        if(vec2[i]->getTossed() < min){
            min = vec2[i]->getTossed();
        }
    }
    cout << "Min(getTossed())=" << min << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    double max = DBL_MIN;
    for(int i = 0; i<DIM; i++){
            if(((Dice*)vec1[i])->getDoubleRate() > max){
                max = ((Dice*)vec1[i])->getDoubleRate();
            }
    }
    cout << "Max(getDoubleRate())=" << max << endl;
}