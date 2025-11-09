#include <iostream>
#include <cstring>
using namespace std;

class Client {
private:
    char nom[50];
    char CIN[20];
    int idClient;

public:
    Client(const char* n, const char* c, int id) {
        strcpy(nom, n);
        strcpy(CIN, c);
        idClient = id;
    }

    void afficherInfos() {
        cout << "Nom: " << nom << ", CIN: " << CIN << ", ID Client: " << idClient << endl;
    }

    friend class CompteBancaire;
    friend class AgentBancaire;
    friend class Banque;
};

class CompteBancaire {
private:
    int numeroCompte;
    double solde;
    int codeSecret;
    Client* proprietaire; // association avec le client

public:
    CompteBancaire(int num, double s, int code, Client* c) {
        numeroCompte = num;
        solde = s;
        codeSecret = code;
        proprietaire = c;
    }

    void deposer(double montant) {
        if (montant > 0)
            solde += montant;
    }

    void retirer(double montant) {
        if (montant > 0 && montant <= solde)
            solde -= montant;
    }

    void afficherComptePublic() {
        cout << "Compte N°" << numeroCompte << " | Solde: " << solde << " DH" << endl;
    }
    friend class AgentBancaire;
    friend class Banque;
};

class AgentBancaire {
private:
    char nomAgent[50];
    int idAgent;

public:
    AgentBancaire(const char* n, int id) {
        strcpy(nomAgent, n);
        idAgent = id;
    }

    void afficherAgent() {
        cout << "Agent: " << nomAgent << " (ID: " << idAgent << ")" << endl;
    }

    void consulterCodeSecret(CompteBancaire &compte) {
        cout << "Agent " << nomAgent << " consulte le code secret du compte N°"
             << compte.numeroCompte << " : " << compte.codeSecret << endl;
    }

    void transfert(CompteBancaire &src, CompteBancaire &dest, double montant) {
        if (montant > 0 && src.solde >= montant) {
            src.solde -= montant;
            dest.solde += montant;
            cout << "Transfert de " << montant << " DH effectue par l'agent " << nomAgent
                 << " du compte " << src.numeroCompte << " vers " << dest.numeroCompte << endl;
        } else {
            cout << "Transfert echoue : solde insuffisant." << endl;
        }
    }

    friend class Banque;
};

class Banque {
private:
    CompteBancaire* comptes[10];
    Client* clients[10];
    int nbComptes;
    int nbClients;

public:
    Banque() {
        nbComptes = 0;
        nbClients = 0;
    }

    void ajouterClient(Client* c) {
        if (nbClients < 10) {
            clients[nbClients] = c;
            nbClients++;
        }
    }

    void ajouterCompte(CompteBancaire* c) {
        if (nbComptes < 10) {
            comptes[nbComptes] = c;
            nbComptes++;
        }
    }

    void afficherClients() {
        cout << "Liste des Clients\n" << endl;
        for (int i = 0; i < nbClients; i++) {
            clients[i]->afficherInfos();
        }
    }

    void afficherComptes() {
        cout << "Liste des Comptes\n" << endl;
        for (int i = 0; i < nbComptes; i++) {
            comptes[i]->afficherComptePublic();
        }
    }
    void auditInterne() {
        cout << "RAPPORT D'AUDIT INTERNE \n" << endl;
        for (int i = 0; i < nbComptes; i++) {
            CompteBancaire* c = comptes[i];
            cout << "Compte N°" << c->numeroCompte << "  Client: " << c->proprietaire->nom
                 << "  Solde: " << c->solde << " DH  Code secret: " << c->codeSecret << endl;
        }
    }

    friend class AgentBancaire;
};

int main() {

    Client c1("Ali", "AA12345", 1);
    Client c2("Sara", "BB67890", 2);

    CompteBancaire compte1(1001, 5000.0, 1111, &c1);
    CompteBancaire compte2(1002, 8000.0, 2222, &c2);

    AgentBancaire agent("Khalid", 10);

    Banque banque;
    banque.ajouterClient(&c1);
    banque.ajouterClient(&c2);
    banque.ajouterCompte(&compte1);
    banque.ajouterCompte(&compte2);

    banque.afficherClients();
    banque.afficherComptes();

    cout << "Operations bancaires " << endl;
    compte1.deposer(1000);
    compte2.retirer(2000);

    compte1.afficherComptePublic();
    compte2.afficherComptePublic();

    cout << "Transfert entre comptes" << endl;
    agent.transfert(compte1, compte2, 1500);

    cout << "Consultation du code secret" << endl;
    agent.consulterCodeSecret(compte2);

    cout << "Rapport d'audit interne (Banque)" << endl;
    banque.auditInterne();

    return 0;
}
