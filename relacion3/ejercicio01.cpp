#include "bintree.h"
#include <queue>
#include <iostream>
//#include "bintree.hxx"

using namespace std;


/*Uso un arbol auxiliar que voy podando para ir recorriendo el árbol sin
usar iteradores y sin usar llamadas recursivas*/

template <typename T>
typename bintree<T>::node mas_profunda(const bintree<T> &arb) {

    typedef typename bintree<T>::node nodo;

    if (arb.size() < 1)
        return nodo();

    queue<pair<nodo, int>> cola;
    nodo n = arb.root(), nmax;
    int prof = 0, max = -1;

    cola.push(pair<nodo, int>(n, prof));

    while (!cola.empty()) {

        n = cola.front().first;
        prof = cola.front().second;
        cola.pop();

        if (prof > max){ 
            
            max = prof;
            nmax = n;
        }

        if (!n.left().null())
            cola.push( pair<nodo, int>(n.left(), prof+1) );
        if (!n.right().null())
            cola.push( pair<nodo, int>(n.right(), prof+1) );
    }

    return nmax;
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

    cout << "Arbol normal " << *mas_profunda(A) << endl;

    bintree<int> B(7);

    B.insert_left(B.root(), 1);

    cout << "Arbol con 2 elementos: " << *mas_profunda(B) << endl;

    bintree<int> C(7);

    cout << "Arbol con 1 elemento: " << *mas_profunda(C) << endl;

    bintree<int> D;

    cout << "Arbol vacío: ";
    n = mas_profunda(D);

    if (n.null())
        cout << "Se devuelve nodo nulo" << endl;

}
