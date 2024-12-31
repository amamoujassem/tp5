#include<iostream>
#include<vector>
#include<string>
class Etudiant{
    private:
        static int count;
        int matricule;
        std::string nom;
        int nbrnotes;
        float* tabnotes;
        
    public:
        Etudiant():
            matricule(++count),
            nom(""),
            nbrnotes(0),
            tabnotes(nullptr) {}
        Etudiant(const std::string &nom,int nbrnotes):matricule(++count),nom(nom),nbrnotes(nbrnotes){
            this->tabnotes = new float[nbrnotes];
        }
        ~Etudiant(){
            delete[] tabnotes;
        }
        Etudiant(Etudiant const& e):matricule(++e.count),nom(e.nom),nbrnotes(e.nbrnotes) {
            tabnotes = new float[nbrnotes];
            for(int i=0;i<nbrnotes;i++)
                tabnotes[i] = e.tabnotes[i];
        }
        int getMatricule()const{
            return matricule;
        }
        std::string getNom()const {
            return nom;
        }
        int getNbrNotes(){
            return nbrnotes;
        }
        void setNom(std::string const &nom){
            this->nom = nom;
        }
        void setNbrNotes(int x){
            nbrnotes=x;
            delete[] tabnotes;
            tabnotes = new float[nbrnotes];
        }
        void saisie(){
            std::cout<<"saisir les notes de "<<getNom()<<std::endl;
            for (int i=0;i<nbrnotes;i++){
                std::cout<<"Note "<<i+1<<": ";
                std::cin>>tabnotes[i];
            }
        }
        void affichage()const{
            std::cout<<"Matricule: "<<matricule<<", Nom: "<<nom<<", Nombre de notes: "<<nbrnotes<<std::endl;
            std::cout<<"Notes: ";
            for (int i=0;i<nbrnotes;i++)
                std::cout<<tabnotes[i]<<" ";
            std::cout<<std::endl;
        }
        float moyenne()const{
            float somme=0;
            for (int i=0;i<nbrnotes;i++)
                somme+=tabnotes[i];
            return somme/nbrnotes;
        }
        bool admis()const{
            if (moyenne()>10){
                return true;
            }
            return false;
        }
        bool static comparer(const Etudiant & e1,const Etudiant & e2){
            return e1.moyenne()>e2.moyenne();
        }

};
int Etudiant::count=0;
int main(){
    Etudiant e1 ("Mike Tyson",4);
    Etudiant e2 ("Jake Paul",4);
    e1.saisie();
    e2.saisie();
    e1.affichage();
    e2.affichage();
    std::cout<<e1.getNom()<<" "<<(e1.admis()?"admis":"redoublant")<<std::endl;
    std::cout<<e2.getNom()<<" "<<(e2.admis()?"admis":"redoublant")<<std::endl;
        if (Etudiant::comparer(e1, e2)) {
        std::cout << "Les moyennes sont egaux.\n";
    } else {
        std::cout << "Les moyennes sont differentes.\n";
    }



}