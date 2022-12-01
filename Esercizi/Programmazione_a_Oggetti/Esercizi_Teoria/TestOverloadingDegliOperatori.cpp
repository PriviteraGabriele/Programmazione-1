#include<iostream>
using namespace std;

class Point{
    public:
    float x;
    float y;
    Point *next;

    Point(){
        x = 0;
        y = 0;
    }

    Point(float a, float b){
        x = a; 
        y = b;
    }


    Point operator+ (Point p){
        Point s;

        s.x = x + p.x;
        s.y = y + p.y;

        return s;
    }
};

int main(){
    cout << "*Somma dei punti*" << endl;

    Point a(1, 1);
    Point b(3, 1);

    Point s;

    s = a + b;

    cout << "Le coordinate dei punti sono: " << endl;
    cout << "Punto a: " << a.x << " " << a.y << endl;
    cout << "Punto b: " << b.x << " " << b.y << endl;
    cout << "Punto s: " << s.x << " " << s.y << endl;
}