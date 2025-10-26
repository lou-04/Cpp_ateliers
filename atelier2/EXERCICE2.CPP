#include <iostream>
using namespace std;

int MultipleDe2(int n) {
    if (n % 2 == 0)
        return 1; // vrai
    else
        return 0; // faux
}

int MultipleDe3(int n) {
    if (n % 3 == 0)
        return 1;
    else
        return 0;
}

int main() {
    int nombre;
    cout << "donnez un entier : ";
    cin >> nombre;

    if (MultipleDe2(nombre))
        cout << "il est pair" << endl;
    if (MultipleDe3(nombre))
        cout << "il est multiple de 3" << endl;
    if (MultipleDe2(nombre) && MultipleDe3(nombre))
        cout << "il est divisible par 6" << endl;

    return 0;
}
