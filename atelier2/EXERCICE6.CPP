#include <iostream>
using namespace std;

void incrementer(int *p) {
    (*p)++; 
}
void permuter(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 5, b = 10;

    cout << "Avant incrementer : a = " << a << endl;
    incrementer(&a);
    cout << "Apres incrementer : a = " << a << endl;

    cout << "Avant permuter : a = " << a << " , b = " << b << endl;
    permuter(&a, &b);
    cout << "Apres permuter : a = " << a << " , b = " << b << endl;

    return 0;
}
\\ avec referance 

#include <iostream>
using namespace std;

void incrementer(int &n) {
    n++;
}

void permuter(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;

    cout << "Avant incrementer : a = " << a << endl;
    incrementer(a);
    cout << "Apres incrementer : a = " << a << endl;

    cout << "Avant permuter : a = " << a << " , b = " << b << endl;
    permuter(a, b);
    cout << "Apres permuter : a = " << a << " , b = " << b << endl;

    return 0;
}

