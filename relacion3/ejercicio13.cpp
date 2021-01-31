#include "bintree.h"
#include <iostream>

using namespace std;

template <typename T>
void aux_alturas(const typename bintree<T>::node &n, int h, int &max, int &suma) {
    h++;
    if (n.left().null() && n.right().null()) {

        if (h > max) max = h;
        suma += h;
    }

    else {

        if (!n.left().null()) aux_alturas<T>(n.left(), h, max, suma);
        if (!n.right().null()) aux_alturas<T>(n.right(), h, max, suma);
    }

}

template <typename T>
double densidad(const bintree<T> &arb) {

    int h = -1, max=0, suma=0;

    if (arb.size() > 1)
        aux_alturas<T>(arb.root(), h, max, suma);
    
    else {

        return arb.size();
    }
    

    return (double) suma/max;
}

int main() {

    bintree<int> A(7);
    bintree<int>::node n;

    A.insert_left(A.root(), 1);
    A.insert_right(A.root(), 9);
    n = A.root().left();
    A.insert_left(n, 6);
    A.insert_right(n, 8);

    n = n.right();
    A.insert_right(n, 4);

    n = A.root().right();
    A.insert_left(n, 5);

    cout << densidad(A) << endl;

    bintree<int> B(7);
    cout << densidad(B) << endl;

    bintree<int> vacio;
    cout << densidad(vacio)<< endl;

    bintree<int> C(7);
    C.insert_right(C.root(), 6);
    C.insert_right(C.root().right(), 5);
    C.insert_right(C.root().right(), 4);
    C.insert_right(C.root().right(), 3);

    cout << densidad(C)<< endl;

}