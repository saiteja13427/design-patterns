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
    class PointFactory {
        public:
        static Point NewCartesian(float x, float y){
            return Point(x, y);
        }

        static Point NewPolar(float r, float theta){
            return Point(r*cos(theta), r*sin(theta));
        }
    };
public:

    float x,y;
    //Singleton factory object so that people can just use PointFactory for Point creation and no one creates an object of PointFactory itself
    static PointFactory Factory;
    // NOTE: A nice way to print objects in cpp
    friend ostream &operator<<(ostream &os, const Point &point){
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }

    // friend class PointFactory; (This should not be done as this breaks OCP open close principle)
    
};

int main(){
    auto p = Point::Factory.NewPolar(5, M_PI / 6);
    cout << p << endl; 
}