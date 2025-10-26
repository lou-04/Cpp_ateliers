#include <iostream>
using namespace std;

class Voiture {
private:
    string marque;
    string modele;
    int annee;
    float kilometrage;
    float vitesse;

public:
    Voiture() {
        marque = "Inconnue";
        modele = "Inconnu";
        annee = 2000;
        kilometrage = 0;
        vitesse = 0;
    }

    Voiture(string m, string mo, int a, float km, float v) {
        marque = m;
        modele = mo;
        annee = a;
        kilometrage = km;
        vitesse = v;
    }

    void accelerer(float valeur) {
        vitesse = vitesse + valeur; 

    void freiner(float valeur) {
        vitesse = vitesse - valeur;
        if (vitesse < 0) {
            vitesse = 0; 
        }
    }

    void avancer(float distance) {
        kilometrage = kilometrage + distance;
  
    }

    void afficherInfo() {
        cout << "Marque : " << marque << endl;
        cout << "Modele : " << modele << endl;
        cout << "Annee : " << annee << endl;
        cout << "Kilometrage : " << kilometrage << " km" << endl;
        cout << "Vitesse : " << vitesse << " km/h" << endl;
    }
    ~Voiture() {
        cout << "La voiture " << marque << " est detruite." << endl;
    }
};
int main() {
    Voiture v1; 
    v1.afficherInfo();
    cout << endl;

    Voiture v2("Toyota", "Corolla", 2022, 15000, 0);
    v2.afficherInfo();
    cout << "On accelere de 50 km/h" << endl;
    v2.accelerer(50);
    v2.afficherInfo();
    cout << "On freine de 20 km/h" << endl;
    v2.freiner(20);
    v2.afficherInfo();
    cout << "On avance de 100 km" << endl;
    v2.avancer(100);
    v2.afficherInfo();

    return 0;
}
