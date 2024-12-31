
#include <iostream>
#include <cmath>
class Vecteur3d{
    private:
    float x, y, z;
    public:
    Vecteur3d(float x=0, float y=0, float z=0):x(x),y(y),z(z){}
    float getx(){
        return x;
    }
    float gety(){
        return y;
    }
    float getz(){
        return z;
    }
    void affichage(){
        std::cout<<"("<<x<<","<<y<<","<<z<<")"<<std::endl;
    }
    Vecteur3d somme(Vecteur3d v){
        Vecteur3d v1;
        v1.x = x + v.x;
        v1.y = y + v.y;
        v1.z = z + v.z;
        return v1;
    }
    float produitscalaire(Vecteur3d v){
        return x*v.x + y*v.y + z*v.z;
    }
    bool coincide(Vecteur3d v){
        return (x==v.x && y==v.y && z==v.z);
    }
    float norme(){
        return sqrt(x*x + y*y + z*z);
    }
    static Vecteur3d normaxParValeur( Vecteur3d& v1, Vecteur3d& v2) {
        return (v1.norme() > v2.norme()) ? v1 : v2;
    }

    static Vecteur3d* normaxParAdresse( Vecteur3d* v1, Vecteur3d* v2) {
        return (v1->norme() > v2->norme()) ? v1 : v2;
    }

    static Vecteur3d& normaxParReference( Vecteur3d& v1, Vecteur3d& v2) {
        return (v1.norme() > v2.norme()) ? v1 : v2;
    }
};

int main() {
    Vecteur3d v1(1, 2, 3);
    Vecteur3d v2(4, 5, 6);

    std::cout << "Vecteur 1 : ";
    v1.affichage();
    std::cout << "Vecteur 2 : ";
    v2.affichage();
    Vecteur3d somme = v1.somme(v2);
    std::cout << "Somme des vecteurs : ";
    somme.affichage();
    std::cout << "Produit scalaire : " << v1.produitscalaire(v2) << std::endl;
    std::cout << "Les vecteurs coincident : " << (v1.coincide(v2) ? "Oui" : "Non") << std::endl;
    std::cout << "Norme du vecteur 1 : " << v1.norme() << std::endl;
    std::cout << "Norme du vecteur 2 : " << v2.norme() << std::endl;

    std::cout << "Vecteur avec la plus grande norme (par valeur) : ";
    Vecteur3d maxParValeur = Vecteur3d::normaxParValeur(v1, v2);
    maxParValeur.affichage();

    std::cout << "Vecteur avec la plus grande norme (par adresse) : ";
    Vecteur3d* maxParAdresse = Vecteur3d::normaxParAdresse(&v1, &v2);
    maxParAdresse->affichage();

    std::cout << "Vecteur avec la plus grande norme (par référence) : ";
    Vecteur3d& maxParReference = Vecteur3d::normaxParReference(v1, v2);
    maxParReference.affichage();

    return 0;
}