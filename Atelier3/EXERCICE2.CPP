#include <iostream>
using namespace std;

class Fichier {
private:
    char* P;     
    int longueur;

public:
    Fichier() {
        P = NULL;
        longueur = 0;
        cout << "objet Fichier créé." << endl;
    }

    void Creation(int n) {
        longueur = n;
        P = new char[longueur]; 
        cout << "Mémoire allouée pour " << longueur << " octets." << endl;
    }

    void Remplit() {
        if (P == NULL) {
            cout << "Aucune mémoire allouée !" << endl;
            return;
        }

        for (int i = 0; i < longueur; i++) {
            P[i] = i % 26; 
        }

        cout << "Zone mémoire remplie arbitrairement." << endl;
    }

    void Affiche() {
        if (P == NULL) {
            cout << "Aucune donnée à afficher !" << endl;
            return;
        }

        cout << "Contenu du fichier en mémoire : ";
        for (int i = 0; i < longueur; i++) {
            cout << P[i];
        }
        cout << endl;
    }
 ~Fichier() {
        if (P != NULL) {
            delete[] P; 
            cout << "Mémoire libérée." << endl;
        }
      
};

int main() {
    Fichier* f = new Fichier();

    f->Creation(20);  
    f->Remplit();      
    f->Affiche();       
    delete f;
    return 0;
}
