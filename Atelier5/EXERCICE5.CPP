#include <iostream>
using namespace std;

template <typename T>
T carre(T x) {
    return x * x;
}

int main() {
   int a = 5;
    cout << "Carré de " << a << " = " << carre(a) << endl;

    double b = 3.14;
    cout << "Carré de " << b << " = " << carre(b) << endl;


    float c = 2.5f;
    cout << "Carré de " << c << " = " << carre(c) << endl;

    return 0;
}
