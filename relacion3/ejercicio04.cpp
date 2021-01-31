#include "bintree.h"
#include <stack>
#include <iostream>
//#include "bintree.hxx"

using namespace std;

template<typename T>
void reflexion(bintree<T> &arb) {

    typename bintree<T>::node n = arb.root();
    bintree<T> aux1, aux2;

    if (!n.left().null()){
    
        aux1.assign_subtree(arb, n.left());
        reflexion(aux1);
    }

    if (!n.right().null()){
    
        aux2.assign_subtree(arb, n.right());
        reflexion(aux2);
    }

    arb.insert_left(n, aux2);
    arb.insert_right(n, aux1);

}

int main() {

    bintree<int> A(7);
    bintree<int>::node n, n1, n2;

    A.insert_left(A.root(), 1);
    A.insert_right(A.root(), 9);
    n = A.root().left();
    A.insert_left(n, 6);
    n1 = n.left();
    A.insert_right(n, 8);

    n = n.right();
    A.insert_right(n, 4);
    n2 = n.right();

    n = A.root().right();
    A.insert_left(n, 5);

    cout << "Antes de reflexion:\n";
    cout << *A.root().left() << endl;
    cout << *A.root().left().left() << endl;
    cout << *A.root().left().right() << endl;
    cout << *A.root().left().right().right() << endl;
    cout << *A.root().right() << endl;
    cout << *A.root().right().left() << endl;
    cout << "Tamaño: " << A.size() << endl;


    reflexion(A);

    cout << "\nDespues de reflexion:\n";
    cout << *A.root().right() << endl;
    cout << *A.root().right().right() << endl;
    cout << *A.root().right().left() << endl;
    cout << *A.root().right().left().left() << endl;
    cout << *A.root().left() << endl;
    cout << *A.root().left().right() << endl;
    cout << "Tamaño: " << A.size() << endl;


    bintree<int> B(7);

    reflexion(B);
    cout << "\nTamaño de arbol de tamaño 1 reflexionado:\n";
    cout << B.size() << endl;
}
