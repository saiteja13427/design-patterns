#define _USE_MATH_DEFINE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cmath>

using namespace std;

enum class PointType {
    cartesian,
    polar
};

class Point{
    Point(float x, float y): x(x), y(y){}

public:
    float x,y;

    /*
    ** These two methods are the factory methods and forms factory-method design which gives ability to create Point Object using
    ** different inputs.
    */
    static Point NewCartesian(float x, float y){
        return Point(x, y);
    }

    static Point NewPolar(float r, float theta){
        return Point(r*cos(theta), r*sin(theta));
    }

    // NOTE: A nice way to print objects in cpp
    friend ostream &operator<<(ostream &os, const Point &point){
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};

int main(){
    auto p = Point::NewPolar(5, M_PI / 6);
    cout << p << endl; 
}