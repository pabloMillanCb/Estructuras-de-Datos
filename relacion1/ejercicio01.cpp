#include <iostream>
#include <stack>

using namespace std;

template <typename T>
void modificar(stack<T> &P, const T &x, const T &y){

    stack<T> tmp;
    T elem;

    while (!P.empty()) {

        if (P.top() == x)
            tmp.push(y);
        else
            tmp.push(P.top());

        P.pop();
    }

    while (!tmp.empty()) {

        P.push(tmp.top());
        tmp.pop();
    }

}

int main() {

    stack<int> pila, pila2;
    int elem = 5, sust = 7, size;

    pila.push(5);
    pila.push(6);
    pila.push(3);
    pila.push(4);
    pila.push(2);
    pila.push(5);

    pila2 = pila; 

    modificar(pila, elem, sust);

    while(!pila2.empty()){
        cout << pila2.top() << endl;
        pila2.pop();
    }

    cout << "-------------------" << endl;

    while (!pila.empty()){
        cout << pila.top() << endl;
        pila.pop();
    }

}