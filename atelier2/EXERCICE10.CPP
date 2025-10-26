#include <iostream>
using namespace std;

class Complexe {
private:
    float reel;
    float imag;

public:
    Complexe(float r = 0, float i = 0) {
        reel = r;
        imag = i;
    }

    void saisir() {
        cout << "Partie réelle : ";
        cin >> reel;
        cout << "Partie imaginaire : ";
        cin >> imag;
    }

    void afficher() {
        if (imag >= 0)
            cout << reel << " + " << imag << "i" << endl;
        else
            cout << reel << " - " << -imag << "i" << endl;
    }

    Complexe addition(Complexe c) {
        return Complexe(reel + c.reel, imag + c.imag);
    }

    Complexe soustraction(Complexe c) {
        return Complexe(reel - c.reel, imag - c.imag);
    }

    Complexe multiplication(Complexe c) {
        float r = reel * c.reel - imag * c.imag;
        float i = reel * c.imag + imag * c.reel;
        return Complexe(r, i);
    }

    Complexe division(Complexe c) {
        float denom = c.reel * c.reel + c.imag * c.imag;
        if (denom == 0) {
            cout << "Erreur : division par zéro !" << endl;
            return Complexe(0, 0);
        }
        float r = (reel * c.reel + imag * c.imag) / denom;
        float i = (imag * c.reel - reel * c.imag) / denom;
        return Complexe(r, i);
    }

    bool egal(Complexe c) {
        return (reel == c.reel && imag == c.imag);
    }
};

int main() {
    Complexe c1, c2;
    cout << "Saisir le premier nombre complexe :" << endl;
    c1.saisir();
    cout << "Saisir le deuxième nombre complexe :" << endl;
    c2.saisir();

    int choix;
    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Soustraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Vérifier égalité" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        Complexe res;
        switch (choix) {
            case 1:
                res = c1.addition(c2);
                cout << "Résultat : ";
                res.afficher();
                break;
            case 2:
                res = c1.soustraction(c2);
                cout << "Résultat : ";
                res.afficher();
                break;
            case 3:
                res = c1.multiplication(c2);
                cout << "Résultat : ";
                res.afficher();
                break;
            case 4:
                res = c1.division(c2);
                cout << "Résultat : ";
                res.afficher();
                break;
            case 5:
                if (c1.egal(c2))
                    cout << "Les nombres complexes sont égaux." << endl;
                else
                    cout << "Les nombres complexes sont différents." << endl;
                break;
            case 0:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide !" << endl;
        }

    } while (choix != 0);

    return 0;
}
