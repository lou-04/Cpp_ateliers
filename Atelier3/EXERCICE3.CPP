#include <iostream>
using namespace std;

struct Element {
    int valeur;         
    Element* suivant; 
};

class Liste {
private:
    Element* premier;

public:
    Liste() {
        premier = NULL;
    }

    void ajouterDebut(int val) {
        Element* nouveau = new Element; 
        nouveau->valeur = val;
        nouveau->suivant = premier;   
        premier = nouveau;     
    }

    void supprimerDebut() {
        if (premier == NULL) {
            cout << "La liste est déjà vide !" << endl;
            return;
        }

        Element* temp = premier;    
        premier = premier->suivant;  
        delete temp;         
    }

    void afficher() {
        if (premier == NULL) {
            cout << "La liste est vide." << endl;
            return;
        }

        cout << "Contenu de la liste : ";
        Element* courant = premier;
        while (courant != NULL) {
            cout << courant->valeur << " ";
            courant = courant->suivant;
        }
        cout << endl;
    }

    ~Liste() {
        while (premier != NULL) {
            Element* temp = premier;
            premier = premier->suivant;
            delete temp;
        }

    }
};

int main() {
    Liste maListe;

    maListe.ajouterDebut(10);
    maListe.afficher();
    maListe.supprimerDebut();
    maListe.afficher();

    return 0;
}
