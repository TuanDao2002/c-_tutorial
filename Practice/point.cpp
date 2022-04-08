#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>

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
        friend Point operator + (double num, Point point);
        friend Point operator + (int num, Point point);

        Point operator + (double num) {
            Point temp;
            temp.x = x + num;
            temp.y = y + num;
            
            return temp;
        }

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

        Point operator ++ () {
            x++;
            y++;

            return *this;
        }

        Point operator ++ (int) {
            Point temp = *this;

            x++;
            y++;

            return temp;
        }

        std::string toString() {
            std::stringstream sstr;
            sstr << "x = " << x << ", y = " << y;
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

Point operator + (double num, Point point) {
    Point temp;
    temp.x = num + point.x;
    temp.y = num + point.y;

    return temp;
}

Point operator + (int num, Point point) {
    Point temp;
    temp.x = num + point.x;
    temp.y = num + point.y;

    return temp;
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

    std::cout << "\n10 + p1 => " << (10 + p1).toString() << std::endl;
    std::cout << "11.2 + p2 => " << (11.2 + p2).toString() << std::endl;

    std::cout << "\np1 + 10 => " << (p1 + 10).toString() << std::endl;

    std::cout << "\np1++ => " << (p1++).toString() << std::endl;
    std::cout << "p1 => " << p1.toString() << std::endl;
    std::cout << "++p1 => " << (++p1).toString() << std::endl;

    Point *point_arr = new Point[6];

    std::ifstream infile("points.txt");
    if (!infile) {
        std::cerr << "Cannot open file!!!" << std::endl;
        delete[] point_arr;
        return -1;
    }

    std::string tempStr;
    std::string x_temp, y_temp;
    for (int i = 0; i < 6; i++) {
        // sstr.clear();
        std::getline(infile, x_temp, ',');
        std::getline(infile, y_temp);

        point_arr[i] = Point(stof(x_temp), stof(y_temp));
    }

    std::cout << "\n\nList of points in points.txt: " << std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << point_arr[i].toString() << std::endl;
    }

    delete[] point_arr;
    return 0;
}
