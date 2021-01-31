#include "bintree.h"
#include <queue>
#include <iostream>
#include <list>

using namespace std;

template<typename T>
list<T> intervalo(const bintree<T> &arb, const T &a, const T &b) {

    if (arb.size() < 1 || a > b)
        return list<T>();

    typename bintree<T>::node n = arb.root();
    list<T> salida;
    queue<typename bintree<T>::node> cola;

    cola.push(n);

    while (!cola.empty()) {

        n = cola.front();
        cola.pop();

        if (*n >= a && *n <= b) { //está dentro del intervalo

            salida.push_back(*n);

            if (!n.left().null())  cola.push(n.left());
            if (!n.right().null()) cola.push(n.right());
        }

        else if (*n < a) { //está a la izquierda del intervalo

            if (!n.right().null()) cola.push(n.right());
        }

        else { //está a la derecha del intervalo

            if (!n.left().null())  cola.push(n.left());
        }
    }

    return salida;
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

    list<int> l = intervalo(A, 5, 8);


    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << endl;
    }

    bintree<int> B;

    cout << intervalo(B, 2, 10).size() << endl;
    cout << intervalo(A, 11, 10).size() << endl;
}