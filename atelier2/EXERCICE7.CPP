#include <iostream>
using namespace std;

void echanger(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void permuter(string str, int debut, int fin) {
    if (debut == fin) {
        cout << str << endl; // Affiche la permutation
    } else {
        for (int i = debut; i <= fin; i++) {
            echanger(str[debut], str[i]);       
            permuter(str, debut + 1, fin);       
            echanger(str[debut], str[i]);     
        }
    }
}

int main() {
    string mot;
    cout << "Entrez une chaine : ";
    cin >> mot;

    cout << "Toutes les permutations sont : " << endl;
    permuter(mot, 0, mot.length() - 1);

    return 0;
}
