#include <iostream>
#include <cstring> 
using namespace std;

class Ressource {
private:
    int id;
    char titre[50];
    char auteur[50];
    int annee;

public:
    Ressource(int i, const char* t, const char* a, int an) {
        id = i;
        strcpy(titre, t);
        strcpy(auteur, a);
        annee = an;
    }

    virtual void afficherInfos() {
        cout << "ID: " << id << ", Titre: " << titre << ", Auteur: " << auteur << ", Annee: " << annee << endl;
    }

    virtual void telecharger() {
        cout << "Telechargement de la ressource generique..." << endl;
    }

    bool operator==(const Ressource &r) {
        return id == r.id;
    }

    const char* getTitre() { return titre; }
    const char* getAuteur() { return auteur; }
    int getAnnee() { return annee; }
};

class Telechargeable {
public:
    void telecharger() {
        cout << "Telechargement en cours..." << endl;
    }

    void afficherMessage() {
        cout << "Ressource telechargeable avec succes !" << endl;
    }
};

class Livre : public Ressource, public Telechargeable {
private:
    int nbPages

public:
    Livre(int i, const char* t, const char* a, int an, int nb) : Ressource(i, t, a, an) {
        nbPages = nb;
    }

    void afficherInfos() {
        cout << "[LIVRE] ";
        Ressource::afficherInfos();
        cout << "Nombre de pages: " << nbPages << endl;
    }

    void telecharger() {
        cout << "Telechargement du livre: " << getTitre() << endl;
        Telechargeable::afficherMessage();
    }
};

class Magazine : public Ressource, public Telechargeable {
private:
    int numero;

public:
    Magazine(int i, const char* t, const char* a, int an, int num) : Ressource(i, t, a, an) {
        numero = num;
    }

    void afficherInfos() {
        cout << "[MAGAZINE] ";
        Ressource::afficherInfos();
        cout << "Numero: " << numero << endl;
    }

    void telecharger() {
        cout << "Telechargement du magazine: " << getTitre() << endl;
        Telechargeable::afficherMessage();
    }
};

class Video : public Ressource, public Telechargeable {
private:
    int duree;

public:
    Video(int i, const char* t, const char* a, int an, int d) : Ressource(i, t, a, an) {
        duree = d;
    }

    void afficherInfos() {
        cout << "[VIDEO] ";
        Ressource::afficherInfos();
        cout << "Duree: " << duree << " minutes" << endl;
    }

    void telecharger() {
        cout << "Telechargement de la video: " << getTitre() << endl;
        Telechargeable::afficherMessage();
    }
};

class Mediatheque {
private:
    Ressource* ressources[10];
    int compteur;

public:
    Mediatheque() {
        compteur = 0;
    }

    void ajouterRessource(Ressource* r) {
        if (compteur < 10) {
            ressources[compteur] = r;
            compteur++;
        }
    }

    void afficherToutes() {
        for (int i = 0; i < compteur; i++) {
            ressources[i]->afficherInfos();
        }
    }

    // Rechercher par titre
    void rechercher(const char* titre) {
        cout << "Recherche par titre: " << titre << endl;
        for (int i = 0; i < compteur; i++) {
            if (strcmp(ressources[i]->getTitre(), titre) == 0) {
                ressources[i]->afficherInfos();
            }
        }
    }

    // Rechercher par année
    void rechercher(int annee) {
        cout << "Recherche par annee: " << annee << endl;
        for (int i = 0; i < compteur; i++) {
            if (ressources[i]->getAnnee() == annee) {
                ressources[i]->afficherInfos();
            }
        }
    }

    // Rechercher par auteur et année
    void rechercher(const char* auteur, int annee) {
        cout << "Recherche par auteur et annee: " << auteur << ", " << annee << endl;
        for (int i = 0; i < compteur; i++) {
            if (strcmp(ressources[i]->getAuteur(), auteur) == 0 && ressources[i]->getAnnee() == annee) {
                ressources[i]->afficherInfos();
            }
        }
    }
};

int main() {
    Livre l1(1, "Le Petit Prince", "Saint-Exupery", 1943, 120);
    Magazine m1(2, "Science Mag", "Collectif", 2020, 45);
    Video v1(3, "Apprendre C++", "OpenClassrooms", 2023, 90);

    Mediatheque med;
    med.ajouterRessource(&l1);
    med.ajouterRessource(&m1);
    med.ajouterRessource(&v1);

    cout << " Affichage des ressources " << endl;
    med.afficherToutes();

    cout << "Test telechargement " << endl;
    l1.telecharger();
    m1.telecharger();
    v1.telecharger();

    cout << "Test de recherche << endl;
    med.rechercher("Le Petit Prince");
    med.rechercher(2023);
    med.rechercher("Saint-Exupery", 1943);

    cout << "Test de comparaison" << endl;
    if (l1 == m1
        cout << "Les deux ressources ont le meme ID." << endl;
    else
        cout << "Les deux ressources sont differentes." << endl;

    return 0;
}
