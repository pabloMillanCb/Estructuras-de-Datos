#include<string>
#include<iostream>
#include<cmath>
#include <stack>
#include "bintree.h"

using namespace std;

template <typename T>
bool similares(const bintree<T> &arb1, const bintree<T> &arb2) {

    stack<typename bintree<T>::node> pila1, pila2;
    typename bintree<T>::node n1, n2;
    bool iguales = true, r1, l1, r2, l2;

    n1 = arb1.root();
    n2 = arb2.root();

    pila1.push(n1);
    pila2.push(n2);

    while (!pila1.empty() && !pila2.empty() && iguales) {

        l1 = r1 = l2 = r2 = false;
        n1 = pila1.top();
        pila1.pop();
        n2 = pila2.top();
        pila2.pop();

        if (!n1.right().null()){
            pila1.push(n1.right());
            r1 = true;
        }

        if (!n2.right().null()){
            pila2.push(n2.right());
            r2 = true;
        }

        if (!n1.left().null()){
            pila1.push(n1.left());
            l1 = true;
        }

        if (!n2.left().null()){
            pila2.push(n2.left());
            l2 = true;
        }

        iguales = r2 == r1 && l2 == l1;
    }
    
    return iguales;
}

int main() {

    bintree<char> A('G');
    bintree<char>::node n;

    A.insert_left(A.root(), 'E');
    A.insert_right(A.root(), 'M');
    n = A.root().left();
    A.insert_left(n, 'A');
    n = n.left();
    A.insert_left(n, 'I');
    A.insert_right(n, 'B');

    n = A.root().right(); //n = M
    A.insert_left(n, 'C');
    A.insert_right(n, 'K');

    A.insert_left(n.left(), 'L'); //n = C
    A.insert_right(n.left().left(), 'D'); //n = L
    A.insert_right(n.left(), 'F'); //n = C

    A.insert_right(n.right(), 'J');
    A.insert_left(n.right().right(), 'H');

    if (similares(A,A))
        cout << "Son iguales\n";
    else 
        cout << "No son iguales\n";

    bintree<char> B('A');

    B.insert_left(B.root(), 'A');
    B.insert_right(B.root(), 'A');
    n = B.root().left();
    B.insert_left(n, 'A');
    B.insert_right(n, 'A');

    n = n.right();
    B.insert_right(n, 'A');

    if (similares(A,B))
        cout << "Son iguales\n";
    else 
        cout << "No son iguales\n";
}