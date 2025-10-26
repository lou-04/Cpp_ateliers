#include <iostream>
using namespace std;

int main() {
    int tab[10];
    int i;
    cout << "Entrez 10 nombres entiers : " << endl;

    for (i = 0; i < 10; i++) {
        cin >> tab[i]
    }

    int max = tab[0];
    int min = tab[0];

    for (i = 1; i < 10; i++) {
        if (tab[i] > max)
            max = tab[i];
        if (tab[i] < min)
            min = tab[i];
    }

    cout << "le plus grand nombre est : " << max << endl;
    cout << "le plus petit nombre est : " << min << endl;

    return 0;
}
