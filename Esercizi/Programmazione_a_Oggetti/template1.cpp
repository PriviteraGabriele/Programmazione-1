/* Definire due funzioni template min e max che restituiscano il minore e il maggiore 
di due valori. Testare le due funzioni con i tipi int, double, string. */

#include<iostream>
using namespace std;

//Max
template <class T>
T Maggiore(T a, T b){
    T max;
    
    if(a > b){
        max = a;
    }
    else{
        max = b;
    }
    
    return (max);
}

//Min
template <class T>
T Minore(T a, T b){
    T min;
    
    if(a < b){
        min = a;
    }
    else{
        min = b;
    }
    
    return (min);
}

int main(){
    
    int max1, min1, x1 = 6, x2 = 7;

    double max2, min2, y1 = 10.5, y2 = 10.6;

    string max3, min3, z1 = "casa", z2 = "ortis";
    
    max1 = Maggiore<int>(x1, x2);
    min1 = Minore<int>(x1, x2);

    max2 = Maggiore<double>(y1, y2);
    min2 = Minore<double>(y1, y2);

    max3 = Maggiore<string>(z1, z2);
    min3 = Minore<string>(z1, z2);


    cout << "Maggiore tra interi = " << max1 << endl;
    cout << "Minore tra interi = " << min1 << endl;
    cout << endl;
    cout << "Maggiore tra double = " << max2 << endl;
    cout << "Minore tra double = " << min2 << endl;
    cout << endl;
    cout << "Maggiore tra string = " << max3 << endl;
    cout << "Minore tra string = " << min3 << endl;
}