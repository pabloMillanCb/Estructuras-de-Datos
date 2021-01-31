#include "bintree.h"
#include <stack>
#include <map>
#include <iostream>

using namespace std;

bool es_hoja(bintree<char>::node n) {
    return n.left().null() && n.right().null();
}

double evaluar(bintree<char>::node n, const bintree<char> &arb, const map<char,double> &valores) {

    double salida;

    if (!es_hoja(n)) {

        double v1 = evaluar(n.left(), arb, valores);
        double v2 = evaluar(n.right(), arb, valores);

        switch (*n)
        {
        case '+':
            salida = v1+v2;
            break;
        case '-':
            salida = v1-v2;
            break;
        case '*':
            salida = v1*v2;
            break;
        case '/':
            salida = v1/v2;
            break;
        }
    }

    else
        salida = valores.at(*n);

    return salida;
}

int main() {

    bintree<char> A('+');
    bintree<char>::node n = A.root();

    A.insert_left(n, '+');
    A.insert_right(n, '/');

    A.insert_right(n.left(), 'a');
    A.insert_left(n.left(), '+');
    A.insert_right(n.left().left(), 'f');
    A.insert_left(n.left().left(), 'e');
    
    A.insert_right(n.right(), 'c');
    A.insert_left(n.right(), 'b');

    map<char, double> mapa;
    mapa['a'] = 2.0;
    mapa['b'] = 4.0;
    mapa['c'] = 5.0;
    mapa['f'] = 9.0;
    mapa['e'] = 3.0;

    cout << evaluar(n, A, mapa) << endl;
    cout << evaluar(n.left().left().left(), A, mapa) << endl;
}