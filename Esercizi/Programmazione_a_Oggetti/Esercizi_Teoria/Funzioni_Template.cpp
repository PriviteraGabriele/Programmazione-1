#include<iostream>
#include<string>
using namespace std; 

template<typename T>
void print(T x[], int n) {
    for (int i = 0; i<n; i++) {
        cout << x[i];
        if(i!=n-1)
            cout << " - ";
    }
    cout << endl;
}

//Una funzione può avere anche due più tipi template:
template<typename T1, typename T2>
T1* sum(T1 a[], T2 b[], int n) { //prende in input due array di tipo t1 e t2 e un intero n
    T1 *out = new T1(n); //l'array in output è di tipo t1
    for(int i=0; i<n; i++) {
        out[i] = a[i] + b[i];
    }
    return out;
} 

int main(){
    int a[] = {1,2,3};
    double b[] = {2.2, 3.3, 4.4};
    string s[] = {"hello", "world"};

    print<int>(a, 3);
    print<double>(b, 3);
    print<string>(s, 2);

    int *out = sum<int, double>(a, b, 3);
    print<int>(out, 3);
}

