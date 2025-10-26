#include <iostream>
#include <cmath>
using namespace std;

class vecteur3d {
private:
    float x, y, z;

public:
    vecteur3d(float a = 0, float b = 0, float c = 0) {
        x = a;
        y = b;
        z = c;
    }

    void afficher() {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

    vecteur3d somme(vecteur3d v) {
        return vecteur3d(x + v.x, y + v.y, z + v.z);
    }

    void sommeAdr(vecteur3d *v, vecteur3d *res) {
        res->x = x + v->x;
        res->y = y + v->y;
        res->z = z + v->z;
    }

    void sommeRef(vecteur3d &v, vecteur3d &res) {
        res.x = x + v.x;
        res.y = y + v.y;
        res.z = z + v.z;
    }

    float produitScalaire(vecteur3d v) {
        return x * v.x + y * v.y + z * v.z;
    }

    bool coincide(vecteur3d v) {
        return (x == v.x && y == v.y && z == v.z);
    }

    float norme() {
        return sqrt(x*x + y*y + z*z);
    }

    vecteur3d normax(vecteur3d v) {
        if (this->norme() >= v.norme())
            return *this;
        else
            return v;
    }

    void normaxAdr(vecteur3d *v, vecteur3d *res) {
        if (this->norme() >= v->norme())
            *res = *this;
        else
            *res = *v;
    }

    void normaxRef(vecteur3d &v, vecteur3d &res) {
        if (this->norme() >= v.norme())
            res = *this;
        else
            res = v;
    }
};

int main() {
    vecteur3d v1(1,2,3), v2(4,5,6);
    
    cout << "Vecteurs initiaux:" << endl;
    v1.afficher();
    v2.afficher();
    
    vecteur3d v3 = v1.somme(v2);
    cout << "Somme (par valeur) : ";
    v3.afficher();
    
    vecteur3d v4;
    v1.sommeAdr(&v2, &v4);
    cout << "Somme (par adresse) : ";
    v4.afficher();
    
    vecteur3d v5;
    v1.sommeRef(v2, v5);
    cout << "Somme (par référence) : ";
    v5.afficher();
    
    cout << "Produit scalaire : " << v1.produitScalaire(v2) << endl;
 
    cout << "v1 et v2 sont identiques ? " << (v1.coincide(v2) ? "Oui" : "Non") << endl;
    
    cout << "Norme de v1 : " << v1.norme() << endl;
    
    vecteur3d v6 = v1.normax(v2);
    cout << "Vecteur avec norme maximale (par valeur) : ";
    v6.afficher();
    
    vecteur3d v7;
    v1.normaxAdr(&v2, &v7);
    cout << "Vecteur avec norme maximale (par adresse) : ";
    v7.afficher();
    
    vecteur3d v8;
    v1.normaxRef(v2, v8);
    cout << "Vecteur avec norme maximale (par référence) : ";
    v8.afficher();
    
    return 0;
}
