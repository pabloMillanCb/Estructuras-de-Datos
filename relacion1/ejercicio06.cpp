#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

template <typename T>
void insertar(stack<T> &P, int pos, const T &x){

    stack<T> ret;
    int i = 0, size = P.size();

    while (!P.empty()) {
        

        if (i == pos)
            ret.push(x);
        else{
            ret.push(P.top());
            P.pop();
        }
        i++;
    }

    if (size == ret.size())
        ret.push(x);

    while (!ret.empty()) {
        P.push(ret.top());
        ret.pop();
    }
}

int main() {

    stack<int> pila;

    pila.push(2); // 8
    pila.push(5); // 5
    pila.push(3); // 4
    pila.push(4); // 3
    pila.push(5); // 5
    pila.push(8); // 2

    insertar(pila, 6, 100);
    //cout << pila.size() << endl << endl;

    while (!pila.empty()) {

        cout << pila.top() << endl;
        pila.pop();
    }

}