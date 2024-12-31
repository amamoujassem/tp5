#include<iostream>
#include<cmath>

class Point {
    private:
    double x, y;
    public:
    Point(float x=0, float y=0):x(x),y(y){}
    Point(const Point& p):x(p.x),y(p.y){}
    double getX() const {return x;}
    double getY() const {return y;}
    void setX(double x) {this->x = x;}
    void setY(double y) {this->y = y;}

    void affiche() const {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
    friend bool comparer(const Point& p1, const Point& p2);
    friend double distance(const Point& p1, const Point& p2);
    friend Point milieu(const Point& p1, const Point& p2);
};
    bool comparer(const Point& p1, const Point& p2) {
        return (p1.x == p2.x && p1.y == p2.y);
    }

    double distance(const Point& p1, const Point& p2) {
        float dx = p1.x - p2.x;
        float dy = p1.y - p2.y;
        return sqrt(dx*dx + dy*dy);
    } 
    Point milieu(const Point& p1, const Point& p2) {
        double mx = (p1.x + p2.x) / 2;
        double my = (p1.y + p2.y) / 2;
        return Point(mx, my);
    }

int main() {

    Point p1(3, 4);
    Point p2(6, 8);

    std::cout << "Point 1 : ";
    p1.affiche();
    std::cout << "Point 2 : ";
    p2.affiche();

    std::cout << "Les points sont identiques : " << (comparer(p1, p2) ? "Oui" : "Non") << std::endl;

    std::cout << "Distance entre les points : " << distance(p1, p2) << std::endl;

    Point pMilieu = milieu(p1, p2);
    std::cout << "Milieu du segment : ";
    pMilieu.affiche();

    return 0;
}
