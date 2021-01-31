#include "bintree.h"
#include <stack>
#include <iostream>

using namespace std;

template<typename T>
typename bintree<T>::node ancestro_comun(typename bintree<T>::node n1, typename bintree<T>::node n2) {

    stack<typename bintree<T>::node> p1, p2;
    typename bintree<T>::node salida;

    if (n1 == n2) {
        return n1;
    }

    if (n1.null() || n2.null()) {
        return salida;
    }

    while(!n1.null() || !n2.null()) {

        if (!n1.null()){

            p1.push(n1);
            n1 = n1.parent();
        }

        if (!n2.null()){

            p2.push(n2);
            n2 = n2.parent();
        }
    }

    while (p1.size() > 0 && p2.size() > 0 && p1.top() == p2.top()) {

        salida = p1.top();
        p1.pop();
        p2.pop();
    }

    return salida;
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

    cout << "(Arbol normal) El ancestro comun es: " << *ancestro_comun<int>(A.root().left().left(), A.root().left().right().right()) << endl;
    cout << "(Ancestro root) El ancestro comun es: " << *ancestro_comun<int>(A.root().left().left(), A.root().right().left()) << endl;
    cout << "(Mismo nodo) El ancestro comun es: " << *ancestro_comun<int>(A.root().left().left(), A.root().left().left()) << endl;
    cout << "(Nodo Root) El ancestro comun es: " << *ancestro_comun<int>(A.root(), A.root().left().left()) << endl;
    cout << "(Padre directo) El ancestro comun es: " << *ancestro_comun<int>(A.root().left().left(), A.root().left()) << endl;
    cout << "(Nodo null) El ancestro es nulo (1 si sí, 0 si no): " << ancestro_comun<int>(A.root().left().left(), A.root().left().left().right()).null() << endl;


}
