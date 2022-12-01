#include<iostream>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<typeinfo>
#include<cfloat>

#define DIM 15

using namespace std;

class Wheel {
    private:
        int value;
        int default_value;
        int num_faces;

    public:
        Wheel(int initial_value, int num_faces){
            value = initial_value;
            default_value = initial_value;
            this->num_faces = num_faces;
        }

        void rotate(int turns){
            value = (value + turns) % num_faces;
        }

        int getValue(){
            return value;
        }

        void reset(){
            value = default_value;
        }
};

class AbstractSlotMachine {
    protected:
        Wheel **wheels;
        int num_wheels;
        int prize;
        int num_spins;
        int num_wins;

    public:
        AbstractSlotMachine(int num_wheels, int num_faces){
            prize, num_spins, num_wins = 0;
            this->num_wheels = num_wheels;
            wheels = new Wheel*[num_wheels];
            for(int i = 0; i<num_wheels; i++){
                wheels[i] = new Wheel(rand() % num_faces, num_faces);
            } 
        }

        int getPrize(){
            return prize;
        }

        double getWinRate(){
            return (double)num_wins/num_spins;
        }

        void reset(){
            for(int i = 0; i<num_wheels; i++){
                wheels[i]->reset();
            }
        }

        virtual int spin() = 0;

        virtual ostream& put(ostream& os){
            os << "Class=" << typeid(*this).name() << ", num_wheels=" << num_wheels << ", prize=" << prize << ", num_spins=" << num_spins << ", num_wins=" << num_wins << ", winrate=" << getWinRate() << ", ";
            return os;
        }
};

ostream& operator<<(ostream& os, AbstractSlotMachine& obj){
    return obj.put(os);
}

class ThreeWheelsSlotMachine : public AbstractSlotMachine {
    private:
        int num_max;

    public:
        ThreeWheelsSlotMachine() : AbstractSlotMachine(3, 6) {
            num_max = 0;
        }

        int getNumMax(){
            return num_max;
        }

        int spin(){
            num_spins++;
            int arr[3];
            for(int i = 0; i<num_wheels; i++){
                wheels[i]->rotate(rand() % 8 + 3);
                arr[i] = wheels[i]->getValue();
                prize += arr[i];
            }
            if(arr[0] == arr[1] && arr[1] == arr[2]){
                if(arr[0] == 5){
                    //Il tiro è vincente e i valori ottenuti sono pari al massimo
                    prize *= 2;
                    num_max++;
                }
                //Il tiro è vincente
                num_wins++;
                int premio = prize;
                prize = 0;
                return premio;
            }
            //Il tiro è perdente
            return 0;
        }

        ostream& put(ostream& os){
            AbstractSlotMachine::put(os);
            os << "num_max=" << num_max;
            return os;
        }
};

class TenWheelsSlotMachine : public AbstractSlotMachine {
    public:
        TenWheelsSlotMachine() : AbstractSlotMachine(5, 10) {}

        int spin(){
            int arr[10];
            num_spins++;
            int last = 0;
            for(int i = 0; i<num_wheels; i++){
                int num_turns = rand() % 8 + 3 + round(last / 3);
                last = num_turns;
                wheels[i]->rotate(num_turns);
                arr[i] = wheels[i]->getValue();
                prize += arr[i];
            }
            bool duplicates = false;
            for(int i = 0; i<num_wheels; i++){
                for(int j = i+1; j<num_wheels; j++){
                    if(arr[i] == arr[j]){
                        duplicates = true;
                    }
                }
            }
            if(duplicates){
                //Il tiro non è vincete
                return 0;
            }
            else{
                //Il tiro è vincente
                num_wins++;
                int premio = prize;
                prize = 0;
                return premio;
            }
        }

        ostream& put(ostream& os){
            AbstractSlotMachine::put(os);
            return os;
        }
};

int main(){
    srand(424242);

    AbstractSlotMachine **vec = new AbstractSlotMachine*[DIM];

    for(int i=0; i<DIM; i++){
        if(rand()%2){
            vec[i] = new ThreeWheelsSlotMachine();
        } else{
            vec[i] = new TenWheelsSlotMachine();
        }
    }

    for(int i=0; i<DIM*100; i++){
        vec[rand()%DIM]->spin();
        if(rand()%5==0){
            vec[rand()%DIM]->reset();
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vec[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double max = DBL_MIN;
    for(int i = 0; i<DIM; i++){
        if(vec[i]->getWinRate() > max){
            max = vec[i]->getWinRate();
        }
    }
    cout << "Max(getWinRate())=" << max << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    double somma = 0;
    int counter = 0;
    for(int i = 0; i<DIM; i++){
        if(typeid(*vec[i]) == typeid(ThreeWheelsSlotMachine)){
            somma += ((ThreeWheelsSlotMachine*)vec[i])->getNumMax();
            counter++;
        }
    }
    cout << "Mean(getNumMax())=" << (double)somma/counter << endl;
}