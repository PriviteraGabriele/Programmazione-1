#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        Point2D(): x(0), y(0) {}
        Point2D(double _x) : x(_x), y(_x) {}
        double getX() {return x;}
        double getY() {return y;}
        friend Point2D operator+(Point2D, Point2D);
};

Point2D operator+(Point2D a, Point2D b){
    return Point2D(a.x+b.x, a.y+b.y);
}

int main() {
    Point2D p1(2,3);
    Point2D p2 = p1+4; //equivalente a Point2D p2 = p1 + Point2D(4);
    cout << "("<<p2.getX() << "," << p2.getY() << ")" << endl;
}