#include <iostream>
#include "Point.cpp"

class Cercle : public Point {
    private:
    double rayon;
    Point centre;
    public :
    Cercle(double rayon,const Point &centre) : rayon(rayon),centre(centre.getX(),centre.getY()){}
    Cercle(double rayon,double x, double y) : rayon(rayon),centre(x,y){}
    double getRayon() const { 
        return rayon;
    }
    Point getCentre() const {
        return centre;
    }
    void setRayon(double r){
        rayon = r;
    }
    void setCentre(const Point &c) {
        centre = c;
    }
    void affichage(){
        std::cout<<"cercle de rayon "<<rayon<<" et de centre ";
        centre.affiche();
        std::cout<<std::endl;
    }
    double surface()const{
        return rayon*rayon*M_PI;
    }
    double perimeter()const{
        return 2*rayon*M_PI;
    }
    void translate(double x, double y){
        centre.setX(centre.getX()+x);
        centre.setY(centre.getY()+y);
    }
    bool contient(const Point& p) const {
        double distance = std::sqrt(std::pow(p.getX() - centre.getX(), 2) +
                                std::pow(p.getY() - centre.getY(), 2));
        return distance <= rayon;
    }

    bool egal(const Cercle& autre) const {
        return rayon == autre.rayon &&
               centre.getX() == autre.getCentre().getX() &&
               centre.getY() == autre.getCentre().getY();
    }    

};

int main() {

    Cercle c1(1, 10, 10);
    c1.affichage();

    std::cout << "Périmètre: " << c1.perimeter() << std::endl;
    std::cout << "Surface: " << c1.surface() << std::endl;

    c1.setRayon(c1.getRayon() * 2);
    c1.affichage();
    std::cout << "Périmètre après doublement: " << c1.perimeter() << std::endl;
    std::cout << "Surface après doublement: " << c1.surface() << std::endl;
    c1.translate(-10, -10);
    c1.affichage();
    Point p1(1, 1);
    Point p2(3, 3);
    std::cout << "Le point ";
    p1.affiche();
    std::cout << (c1.contient(p1) ? " est à l'intérieur" : " est à l'extérieur") << " du cercle." << std::endl;

    std::cout << "Le point ";
    p2.affiche();
    std::cout << (c1.contient(p2) ? " est à l'intérieur" : " est à l'extérieur") << " du cercle." << std::endl;

    Cercle c2(2, 0, 0);
    std::cout << "Le cercle est " << (c1.egal(c2) ? "égal" : "différent") << " au cercle c2." << std::endl;

    return 0;
}