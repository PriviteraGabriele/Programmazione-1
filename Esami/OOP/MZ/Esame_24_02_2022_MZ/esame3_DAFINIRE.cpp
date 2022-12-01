#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<typeinfo>

using namespace std;

template<typename T>
class AbtractVec {
    private:
        T **data;

    protected:
        int max_size;
        int read_index;
        int write_index;

        T* get(int index){
            return data[index];
        }

        bool exists(int index){
            if(data[index]){
                return true;
            }
            return false;
        }

        void set(int i, T x){
            *data[i] = x;
        }

    public:
        AbtractVec(int max_size){
            this->max_size = max_size;
            read_index = 0;
            write_index = 0;
            data = new T*[max_size];
            for(int i = 0; i<max_size; i++){
                data[i] = nullptr;
            }
        }

        virtual T* next() = 0;

        virtual bool insert(T x) = 0;

        int len(){
            int counter = 0;
            for(int i = 0; i<max_size; i++){
                if(data[i]){
                    counter++;
                }
            }
            return counter;
        }

        void shuffle() {
            for(int i = 0; i<max_size; i++) {
                if(data[i]) {
                    T* tmp = nullptr;
                    int index = 0;
                    while(tmp == nullptr || tmp == data[i]) {
                        index = rand() % max_size;
                        tmp = data[index];
                    }
                    data[index] = data[i];
                    data[i] = tmp;
                }
            }
        }
};

template<typename T>
class PlainVec : public AbtractVec {
    public:
        PlainVec(int max_size) : AbtractVec(max_size) {}

        T* next(){
            
        }
}

int main(){

}