#include <iostream>
using namespace std;

int main() {
    int tab[10];
    int *p;

    cout << "entrez 10 nombres entiers : " << endl;

    for (p = tab; p < tab + 10; p++) {
        cin >> *p;
    }

    int *pmax = tab;
    int *pmin = tab;

    for (p = tab + 1; p < tab + 10; p++) {
        if (*p > *pmax)
            pmax = p;
        if (*p < *pmin)
            pmin = p;
    }

    cout << "le plus grand nombre est : " << *pmax << endl;
    cout << "le plus petit nombre est : " << *pmin << endl;

    return 0;
}
