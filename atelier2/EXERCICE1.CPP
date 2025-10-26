#include <iostream>
using namespace std;

void compteur() {
  int Appels = 0;
    Appels++;
    cout << "Appel numéro " << Appels << endl;
}

int main() {
    compteur();
    compteur();
    compteur();
    return 0;
}
