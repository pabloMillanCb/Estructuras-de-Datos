#include<string>
#include<iostream>
#include "bintree.h"
#include<stack>

using namespace std;

bool es_operador(char c) {
    return c == '*' || c == '/' || c == '+' || c == '-';
}

template <typename T>
void postorden(typename bintree<T>::node n) {
    if (!n.left().null()) postorden<T>(n.left());
    if (!n.left().null()) postorden<T>(n.right());
    cout << *n;
}

template <typename T>
bintree<T> construye_arbol(string postfijo) {

    typedef typename bintree<T>::node nodo;
    stack<bintree<T>> arboles;
    stack<T> pila;
    bintree<T> tmp;
    arboles.push(bintree<T>());

    for (int i = 0; i < postfijo.size(); i++) {

        if (es_operador(postfijo[i])) {

            tmp = bintree<T>(postfijo[i]);

            if (!pila.empty()){
                tmp.insert_right(tmp.root(), pila.top());
                pila.pop();
            }

            else {
                tmp.insert_right(tmp.root(), arboles.top());
                arboles.pop();
            }

            if (!pila.empty()){
                tmp.insert_left(tmp.root(), pila.top());
                pila.pop();
            }

            else {
                tmp.insert_left(tmp.root(), arboles.top());
                arboles.pop();
            }

            arboles.push(tmp);
        }

        else
            pila.push(postfijo[i]);
    }

    return arboles.top();
}

int main() {

    bintree<char> arbol;
    string postfijo = "e5+a+84/+";
    arbol = construye_arbol<char>(postfijo);

    bintree<char>::postorder_iterator it = arbol.begin_postorder(); //se que el iterador es ineficiente, lo uso unicamente para comprobar el resultado

    while (it != arbol.end_postorder()) {
        cout << *it;
        ++it;
    }

    cout << endl;

    arbol = construye_arbol<char>("");
    cout << "Arbol vacio: " << arbol.size() << endl;

}