#include <iostream>
using namespace std;

int main() {
    int taille;
    int *tab = NULL;
    int *carre = NULL;

    cout << "Donnez la taille du tableau : ";
    cin >> taille;
    tab = new int[taille];

    cout << "Entrez " << taille << " nombres entiers :" << endl;
    for (int i = 0; i < taille; i++) {
        cin >> tab[i];
    }

    carre = new int[taille];
    for (int i = 0; i < taille; i++) {
        carre[i] = tab[i] * tab[i];
    }

    delete[] tab;
    tab = NULL; // par précaution

    cout << "Les carres des nombres sont :" << endl;
    for (int i = 0; i < taille; i++) {
        cout << carre[i] << " ";
  
    delete[] carre;
    carre = NULL;

    return 0;
}
