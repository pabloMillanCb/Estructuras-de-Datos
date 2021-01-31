#include<string>
#include<iostream>
#include<cmath>
#include <bintree.h>

using namespace std;

template<typename T>
int find_altura(typename bintree<T>::node n) {

    int a1 = 0, a2 = 0;

    if (!n.left().null()) a1 = find_altura<T>(n.left());
    if (!n.right().null()) a2 = find_altura<T>(n.right());

    return max(a1, a2);
}

template<typename T>
bool completo(const bintree<T> &arb){

    if (arb.size() < 1)
        return false;

    int h = -1;

    if (arb.size() > 0) h = find_altura<T>(arb.root());
    return pow(2, h+1) == arb.size()+1;
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

    cout << "Arbol no completo: ";
    if (completo(A)) {
        cout << "Es completo\n";
    }

    else cout << "No es completo\n";

    bintree<char> B('G');

    cout << "Arbol con un solo elemento: ";
    if (completo(B)) {
        cout << "Es completo\n";
    }

    else cout << "No es completo\n";

    bintree<char> C;

    cout << "Arbol vacio: ";
    if (completo(C)) {
        cout << "Es completo\n";
    }

    else cout << "No es completo\n";

    bintree<char> D('G');
    n = B.root();
    D.insert_left(n, 'A');
    D.insert_right(n, 'B');

    D.insert_left(n.left(), 'A');
    D.insert_left(n.right(), 'A');
    D.insert_right(n.left(), 'B');
    D.insert_right(n.right(), 'B');

    cout << "Arbol completo: ";
    if (completo(D)) {
        cout << "Es completo\n";
    }

    else cout << "No es completo\n";

}