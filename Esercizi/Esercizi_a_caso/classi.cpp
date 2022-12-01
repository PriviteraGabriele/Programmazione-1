#include<iostream>
using namespace std;
class RectangleV2 {
    int width, height;
  public:
    RectangleV2() { //rettangolo "vuoto"
        width = 0;
        height = 0;
    }
    RectangleV2(int l) { //quadrato di lato l
        width = l;
        height = l;
    }
    RectangleV2(int w, int h) { //quadrato standard
        width = w;
        height = h;
    }
    int area() {return (width*height);}
};

int main(){
    RectangleV2 r1 = 3;
    cout << r1.area() << endl; 
}