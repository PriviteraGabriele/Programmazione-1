#include<iostream>
using namespace std;

int main(){
    string n = "casa";
    string *p = &n;

    cout << "n = " << n << endl;
    cout << "*p = " << *p << endl;
    cout << "lunghezza = " << (*p).length() << endl;
    cout << "lunghezza = " << p->length() << endl;


}