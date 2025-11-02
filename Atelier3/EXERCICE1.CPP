#include <iostream>
using namespace std;

struct Element {
    int valeur;
    Element* suivant;
};

class Pile {
private:
    Element* sommet; 

public:
    Pile() {
        sommet = NULL;
    }
    void push(int v) {
       Element* nouveau = new Element;
        nouveau->valeur = v;
        nouveau->suivant = sommet; 
        sommet = nouveau;        
    }


    int pop() {
        if (sommet == NULL) {
            cout << "Pile vide !" << endl;
            return -1;
        } else {
            int val = sommet->valeur;
            Element* temp = sommet;
            sommet = sommet->suivant;
            delete temp;
            return val;
        }
    }
