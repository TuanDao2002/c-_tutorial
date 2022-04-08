#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class Point{
    private:
        double x;
        double y;
    
    public:
        Point() : x(0), y(0){};

        Point(double x, double y) {
            this->x = x;
            this->y = y;
        }

        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }

        void inputData() {
            double x, y;
            std::cout << "Enter x: ";
            std::cin >> x;

            std::cout << "Enter y: ";
            std::cin >> y;

            this->x = x;
            this->y = y;
        }

        friend std::istream &operator >> (std::istream &in, Point &point);
        friend std::ostream &operator << (std::ostream &out, Point &point);
        friend double distance(Point p1, Point p2);

        Point operator + (Point &point) {
            Point result;
            result.x = x + point.x;
            result.y = y + point.y;
            return result;
        }

        Point operator - (Point &point) {
            Point result;
            result.x = x - point.x;
            result.y = y - point.y;
            return result;
        }

        std::string toString() {
            std::stringstream sstr;
            sstr << "Point's coordinates: " << x << " " << y;
            return sstr.str();
        }
};

std::istream &operator >> (std::istream &in, Point &point) {
    point.inputData();
    return in;
}

std::ostream &operator << (std::ostream &out, Point &point) {
    std::cout << point.toString() << std::endl;
    return out;
}

double distance(Point p1, Point p2) {
    double distance_val;
    std::stringstream sstr;
    sstr.setf(std::ios::fixed);
    sstr.precision(2);
    sstr << sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

    sstr >> distance_val;
    return distance_val;
}

int main(){
    Point p1, p2;
    std::cin >> p1;
    std::cout << p1 << std::endl;

    std::cin >> p2;
    std::cout << p2 << std::endl;

    Point add_point = p1 + p2;
    std::cout << "p1 + p2 => " << add_point << std::endl;

    Point minus_point = p1 - p2;
    std::cout << "p1 - p2 => " << minus_point << std::endl;

    std::cout << "Distance between p1 and p2: " << distance(p1, p2) << std::endl;
    return 0;
}