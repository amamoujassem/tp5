#include<iostream>
#include<cmath>
class Complex{
    private:
    double re;
    double img;
    public:
    Complex(double re=0, double img=0):re(re), img(img){}
    void affichage(){
        std::cout<<re<<" + "<<img<<"i"<<std::endl;
    }
    double module(){
        return sqrt(re*re + img*img);
    }
    Complex conjuge(){
        return Complex(re ,-img);
    }
    Complex opplus(Complex &c){
        return Complex(re+c.re+img+c.img);
    }
    Complex opplusr(double r){
        return Complex(re+r,img);
    }
    Complex opfois(Complex &c){
        return Complex((re*c.re-img*c.img),(re*c.img-img*c.re));
    }
    Complex opfoisr(double r){
        return Complex(re*r,img*r);
    }

};
int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, -2.0); 
    std::cout << "c1 = "; c1.affichage();
    std::cout << "c2 = "; c2.affichage();
    std::cout << "Module de c1: " << c1.module() << std::endl;
    std::cout << "Conjugué de c1: "; c1.conjuge().affichage();
    Complex somme = c1.opplus(c2);
    std::cout << "c1 + c2 = "; somme.affichage();

    Complex sommereel = c1.opplusr(2.0);
    std::cout << "c1 + 2.0 = "; sommereel.affichage();

    Complex produit = c1.opfois(c2);
    std::cout << "c1 * c2 = "; produit.affichage();

    Complex produitreal = c1.opfoisr(2.0);
    std::cout << "c1 * 2.0 = "; produitreal.affichage();
    return 0;
}