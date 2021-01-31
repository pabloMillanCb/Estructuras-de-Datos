#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class cola {

private:

    stack<T> pila1;
    stack<T> pila2;

public:

    void push(T i) {

        stack<T> tmp1, tmp2;

        pila1.push(i);
        tmp1 = pila1;

        while (!tmp1.empty()) {
            tmp2.push(tmp1.top());
            tmp1.pop();
        }
        
        pila2 = tmp2;
    }

    void pop() {

        pila2.pop();
        stack<T> tmp1, tmp2 = pila2;

        while (!tmp2.empty()){

            tmp1.push(tmp2.top());
            tmp2.pop();
        }

        pila1 = tmp1;
    }

    int size() {
        return pila1.size();
    }

    T front() {
        return pila2.top();
    }

    bool empty() {
        return pila1.size() == 0;
    }
};

int main() {

    cola<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    queue.push(7);
    queue.push(8);
    queue.push(9);
    queue.push(10);

    while (!queue.empty()) {

        cout << queue.front() << endl;
        queue.pop();

    }




}