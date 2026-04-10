// cspell:disable
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class Point{
    private:
        double x;
        double y;
    public:
        Point(double x, double y){
            this->x = x;
            this->y = y;
        }
    // SETTER and GETTER
    double getX() const{
        return x;
    }
    double getY() const{
         return y;
    }
    void setX(double x){
        this->x = x;
    }
    void setY(double y){
        this->y = y;
    }

   // Method     
    void display(){
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
    double distanceTo(Point other){
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }
    double distanceToOrigin(){
        return sqrt(pow(x, 2) + pow(y, 2));
    }
};
int main(){
    Point A(3, 4);
    A.display();
    double Bx, By;
    cout << "Enter the coordinates of point B (x y): ";
    cin >> Bx >> By;
    Point B(Bx, By);
    B.display();

    cout << fixed << setprecision(2);
    cout << "Distance from A to B: " << A.distanceTo(B) << endl;
    cout << "Distance from A to origin: " << A.distanceToOrigin() << endl;
    return 0;
}
