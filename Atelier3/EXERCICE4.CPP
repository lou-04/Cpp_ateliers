#include <iostream>
#include <string>
using namespace std;

class Client {
private:
    int id;
    string nom;
    string prenom;

public:
    Client() {
        id = 0;
        nom = "";
        prenom = "";
        cout << "Constructeur Client vide appelé." << endl;
    }

    Client(int i, string n, string p) {
        id = i;
        nom = n;
        prenom = p;
        cout << "Constructeur Client avec valeurs appelé." << endl;
    }

    Client(const Client& c) {
        id = c.id;
        nom = c.nom;
        prenom = c.prenom;
        cout << "Constructeur de copie Client appelé." << endl;
    }

    ~Client() {
        cout << "Destructeur Client appelé pour " << nom << " " << prenom << endl;
    }

    void afficher() {
        cout << "Client [ID=" << id << "] " << nom << " " << prenom << endl;
    }
};

class Compte {
private:
    int numero;
    float solde;
    Client* client;         
    static int totalComptes;   

public:
    Compte() {
        numero = 0;
        solde = 0.0;
        client = NULL;
        totalComptes++;
        cout << "Constructeur Compte vide appelé." << endl;
    }

    Compte(int num, float s, Client* c) {
        numero = num;
        solde = s;
        client = c;
        totalComptes++;
        cout << "Constructeur Compte avec paramètres appelé." << endl;
    }

    Compte(const Compte& c) {
        numero = c.numero;
        solde = c.solde;
        client = c.client;
        totalComptes++;
        cout << "Constructeur de copie Compte appelé." << endl;
    }

    ~Compte() {
        cout << "Destructeur Compte appelé pour le compte n°" << numero << endl;
        totalComptes--;
    }

    void afficher() {
        cout << "\n--- Informations du Compte ---" << endl;
        cout << "Numéro de compte : " << numero << endl;
        cout << "Solde : " << solde << " DH" << endl;
        if (client != NULL) {
            cout << "Titulaire : ";
            client->afficher();
        } else {
            cout << "Aucun client associé." << endl;
        }
        cout << "Nombre total de comptes : " << totalComptes << endl;
    }
    void calculInteret(float taux) {
        solde += solde * taux / 100;
    }
};

int Compte::totalComptes = 0;

int main() {

    Client c1(1, "Richi", "Sofia");
    c1.afficher();

    Compte compte1(1001, 2500.0, &c1);
    compte1.afficher();

    Compte compte2 = compte1;
    compte2.afficher();

    compte1.calculInteret(5);
    compte1.afficher();

    cout << "\nFin du programme principal." << endl;
    return 0;
}
