#include "bintree.h"
#include <stack>
#include <iostream>
//#include "bintree.hxx"

using namespace std;

template<typename T>
int altura(const bintree<T> &arb) {

    if (arb.size() == 0) return 0;

    typedef typename bintree<T>::node nodo;
    stack<pair<nodo, int>> pila;
    nodo n = arb.root();
    int prof = 0, max = 0;

    pila.push(pair<nodo, int>(n, prof));

    while (!pila.empty()) {

        n = pila.top().first;
        prof = pila.top().second;
        pila.pop();

        if (prof > max) max = prof;

        if (!n.right().null())
            pila.push( pair<nodo, int>(n.right(), prof+1) );
        if (!n.left().null())
            pila.push( pair<nodo, int>(n.left(), prof+1) );
    }

    return max;
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

    cout << "Altura A: " << altura(A) << endl;

    bintree<char> B('G');
    bintree<char>::node nb;

    B.insert_left(B.root(), 'E');
    B.insert_right(B.root(), 'M');
    nb = B.root().left();
    B.insert_left(nb, 'A');
    nb = nb.left();
    B.insert_left(nb, 'I');
    B.insert_right(nb, 'B');

    nb = B.root().right(); //n = M
    B.insert_left(nb, 'C');
    B.insert_right(nb, 'K');

    B.insert_left(nb.left(), 'L'); //n = C
    B.insert_right(nb.left().left(), 'D'); //n = L
    B.insert_right(nb.left(), 'F'); //n = C

    B.insert_right(nb.right(), 'J');
    B.insert_left(nb.right().right(), 'H');
    B.insert_left(nb.right().right().left(), 'Z');
    B.insert_left(nb.right().right().left().left(), 'Y');

    cout << "Altura B: " << altura(B) << endl;

    bintree<char> C('G');
    cout << "Altura C: " << altura(C) << endl;

    bintree<char> D('G');
    D.insert_left(D.root(), 'T');
    cout << "Altura D: " << altura(D) << endl;

    bintree<char> F;
    cout << "Altura F: " << altura(F) << endl;

    bintree<char> E('G');
    E.insert_left(E.root(), D);
    cout << "Altura E: " << altura(E) << endl;
}